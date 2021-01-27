#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		set<int>hash_set;
		for (int i = 0; i < nums.size(); i++) {
			hash_set.insert(nums[i]);
		}
		int longestlength = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (!hash_set.count(nums[i] - 1)) {
				int currentNum = nums[i];
				int currentlength = 1;
				while (hash_set.count(currentNum + 1)) {
					currentNum += 1;
					currentlength += 1;
				}
				longestlength = max(currentlength, longestlength);
			}
		}
		return longestlength;
	}
};