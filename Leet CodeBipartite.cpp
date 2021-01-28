#include<bits\stdc++.h>
using namespace std;
//Colouring or the Bipartite graph problem
/*In this kinda porblem we use the dfs techique;
we have the visited array and the colour array*/

//Below is a Bipartite pseudoCode;
bool dfs(int v, int c)
{
	vis[v] = 1;
	col[v] = c;
	for (int v : ar[u])
	{
		if (vis[v] == 0 && !dfs(v, c ^ 1))return false;
		else {
			if (col[u]) == col[v])return false;
			}
	}
	return true;
}