#include<bits\stdc++.h>
class Solution {
	bool dfs(int u, vector<vector<int>>&adj, vector<int>&s, vector<int>&visited) {
		//0-->unvisited
		//1-->being visited
		//2-->completely visited
		visited[u] = 1;
		for (int v : adj[u]) {
			//if the adjacent node is being processed that is they make a back edge
			if (visited[v] == 1)return true;
			//if the adjacent node has not been visited but has a back edge.
			if (visited[v] == 0 && dfs(v, adj, s, visited))return true;
		}
		visited[u] = 2;
		s.push_back(u);
		return false;
	}
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		//Create adjacency matrix
		vector<vector<int>>adj(numCourses);
		for (vector<int>&pre : prerequisites) {
			adj[pre[1]].push_back(pre[0]);
		}
		//create a stack
		vector<int>s;
		//create the visited array
		vector<int>visited(numCourses, 0);
		//Check if there is a cycle
		for (int i = 0; i < numCourses; i++) {
			if (visited[i] == 0 && dfs(i, adj, s, visited))return {};
		}
		//Do topological sorting
		reverse(s.begin(), s.end());
		return s;
	}
};