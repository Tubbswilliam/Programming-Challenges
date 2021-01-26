class Solution {
    //Helper function to detect the cycle
    bool isCycle(vector<vector<int>>&adj, vector<int>&visited, int curr) {
        if (visited[curr] == 2)return true;
        visited[curr] = 2;
        for (int i = 0; i < adj[curr].size(); ++i) {
            if (visited[adj[curr][i]] != 1)
                if (isCycle(adj, visited, adj[curr][i]))
                    return true;
        }
        visited[curr] = 1;
        return false;

    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Make adjacency matrix
        vector<vector<int>>adj(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        //make the visited array
        vector<int>visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0 && isCycle(adj, visited, i)) return false;
        }
        return true;
    }
};