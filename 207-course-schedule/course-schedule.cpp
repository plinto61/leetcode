class Solution {
    vector<vector<int>> courseDependenciesMatrix;
    int n;

public:
    bool cycleFound(int course) {
        vector<int> dependencies = courseDependenciesMatrix[course];
        for(int i=0; i<n; i++) {
            if(dependencies[i] == 0) continue;
            if(dependencies[i] == -1) return true;
            courseDependenciesMatrix[course][i] = -1;
            if(cycleFound(i)) return true;
            courseDependenciesMatrix[course][i] = 0;
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        courseDependenciesMatrix.assign(numCourses, vector<int>(numCourses, 0));
        for (auto prerequisite : prerequisites) {
            int course = prerequisite[0], dependency = prerequisite[1];
            courseDependenciesMatrix[course][dependency] = 1;
        }
        for (int course = 0; course < numCourses; course++) {
            if(cycleFound(course)) return false;
        }
        return true;
    }
};