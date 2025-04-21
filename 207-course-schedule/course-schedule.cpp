class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> depsList(numCourses);
        for(auto prereq : prerequisites) {
            int course = prereq[0], dep = prereq[1];
            depsList[course].push_back(dep);
        }

        vector<int> state(numCourses, 0); // 0 -> unvisited, 1 -> visiting, 2 -> visited;

        function<bool(int)> hasCycle = [&state, depsList, &hasCycle](int course) -> bool {
            if(state[course] == 2) return false;
            if(state[course] == 1) return true;

            state[course] = 1;
            for(int dep : depsList[course]) {
                if(hasCycle(dep)) return true;
            }
            state[course] = 2;
            return false;
        };

        for(int course = 0; course < numCourses; course++) {
            if(state[course] == 0 && hasCycle(course)) return false;
        }
        return true;
    }
};