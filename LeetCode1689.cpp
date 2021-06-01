//Partitioning Into Minimum Number Of Deci-Binary Numbers

/*
Given a string n that represents a positive decimal integer,
return the minimum number of positive deci-binary numbers needed so that they sum up to n.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int largestNumber = 0;
        for (int i = 0; i < n.length(); i++) {
            largestNumber = max(largestNumber, n[i] - '0');
        }
        return largestNumber;
    }
};
int main() {
    return 0;
}