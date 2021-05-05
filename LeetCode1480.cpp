class Solution {
public:
	vector<int> runningSum(vector<int>& nums) {
		for (int i = 1; i < nums.size(); i++) {
			nums[i] += nums[i - 1];
		}
		return nums;
	}
};

int main() {
// #ifndef ONLINE_JUDGE
// 	//for getting input from input.txt
// 	freopen("input.txt", "r", stdin);
// 	// for writing output to output.txt
// 	freopen("output.txt", "w", stdout);
// #endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}