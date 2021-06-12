//Remove Duplicates from sorted list 11
/*
Given the head of a sorted linked list, delete all nodes that have
duplicate numbers,leaving only distinct numbers from the original list.
Return the linked list sorted as well.
*/

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next)return head;
		ListNode* nextNode = head->next;
		if (nextNode->val == head->val) {
			while (nextNode && nextNode->val == head->val)nextNode = nextNode->next;
			return deleteDuplicates(nextNode);
		}
		else {
			head->next = deleteDuplicates(nextNode);
			return head;
		}

	}
};

int main() {

	return 0;
}