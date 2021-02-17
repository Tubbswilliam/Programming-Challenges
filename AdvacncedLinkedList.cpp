//Doubly linked list
#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node*next;
	Node*prev;
};
Node*head;
Node* tempNode(int x) {
	Node*temp = new Node;
	temp->data = x;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;

}
////////////////////////////////////////////////////////////////////////////////////////
void insertAtHead(int x) {
	Node*temp1 = tempNode(x);
	if (head == NULL) {
		head = temp1;
		return;
	}
	head->prev = temp1;
	temp1->next = head;
	head = temp1;
}
//////////////////////////////////////////////////////////////////////////////////////////////
void print() {
	Node*temp = head;
	printf("Forward : ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");

}
/////////////////////////////////////////////////////////////////////////////////////////////////
void ReversePrint() {
	Node* temp = head;
	if (temp == NULL)return;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	//Traversing backward using prev pointer
	printf("Reverse : ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	cout << "\n";
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
	insertAtHead(54);
	insertAtHead(76);
	insertAtHead(23);
	insertAtHead(78);
	insertAtHead(90);
	insertAtHead(99);
	insertAtHead(13);
	print();
	ReversePrint();

	return 0;
}