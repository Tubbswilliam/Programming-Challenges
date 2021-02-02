#include<bits\stdc++.h>
/*Below is the code of the topological sort but according to the question it required us to
output the output in a lexigraphical order iif the topological sort was possible*/
using namespace std;
vector<int>nodes[10001];
int in[10001];
vector<int>result;

bool kahn(int n) {
	priority_queue<int, vector<int>, greater<int>>PQ;
	for (int i = 1; i <= n; i++)
		PQ.push(i);
	while (!PQ.empty()) {
		int curr = PQ.top();
		result.push_back(curr);
		PQ.pop();
		for (int v : nodes[curr]) {
			in[v]--;
			if (in[v] == 0)
				PQ.push(v);
		}
	}

	return result.size() == n;
}


int main() {
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y, nodes[x].push_back(y);
		in[y]++;
	}
	if (!kahn(n))
		cout << "Sandro fails.";
	else {
		for (int i = 1; i <= result.size(); i++)
			cout << i << " ";
	}

	return 0;
}