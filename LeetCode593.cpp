//Valid square

/*
Given the coordinates of four points in 2D space p1, p2, p3 and p4,
return true if the four points construct a square.
The coordinate of a point pi is represented as [xi, yi].
The input is not given in any order.A valid square has four equal sides
with positive length and four equal angles (90-degree angles).
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
	int getDistance(vector<int>&a, vector<int>&b) {
		return ((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
	}
public:
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		vector<int>sides = {
			getDistance(p1, p2),
			getDistance(p1, p3),
			getDistance(p1, p4),
			getDistance(p2, p3),
			getDistance(p2, p4),
			getDistance(p3, p4),
		};
		unordered_map<int, int>m;
		for (auto&s : sides) {
			if (!m.count(s))m.insert({s, 1});
			else m[s]++;
		}
		if (m.size() != 2)return false;
		for (auto&p : m)return (p.second == 4) || (p.second == 2);
		return false;
	}
};

int main() {

	return 0;
}