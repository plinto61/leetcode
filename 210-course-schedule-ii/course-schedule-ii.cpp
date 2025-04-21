class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> depsList(numCourses);

        for (auto prereq : prerequisites) {
            int course = prereq[0], dep = prereq[1];
            depsList[course].push_back(dep);
        }

        // 0 = unvisited, 1 = visiting, 2 = visited;
        vector<int> visited(numCourses, 0);
        stack<int> s;

        function<bool(int)> hasCycle = [&](int course) {
            if (visited[course] == 1)
                return true;
            if (visited[course] == 2)
                return false;

            visited[course] = 1;
            for (int dep : depsList[course]) {
                if (hasCycle(dep))
                    return true;
            }
            visited[course] = 2;
            s.push(course);
            return false;
        };

        for (int course = 0; course < numCourses; course++) {
            if (visited[course] == 0 && hasCycle(course))
                return {};
        }

        vector<int> result(numCourses);

        int i = numCourses;
        while (i > 0) {
            result[--i] = s.top();
            s.pop();
        }

        return result;
    }
};