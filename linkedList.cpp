//After learning pointers i did linked list to understand clearly their functionality

/*
//The code below shows how to create a node..insert it at the head of the list
//and print the elements from the list
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head;

void insert(int x) {
	Node*temp = new Node;
	temp->data = x;
	temp->next = NULL;
	if (head != NULL)temp->next = head;
	head = temp;
}

void print() {
	Node*temp = head;
	printf("List is : ");
	while (temp != NULL) {
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main() {
	head = NULL;
	printf("How many Numbers?\n");
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Enter a number \n");
		scanf("%d", &x);
		insert(x);
		print();
	}

	return 0;
}

*/

/*

//Inserting an element at the nth position of the list
#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node*next;
};
Node*head;
void insert(int data, int n) {
	Node*temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;
	if (n == 1) {
		temp1->next = head;
		head = temp1;
		return;
	}
	Node*temp2 = head;
	for (int i = 0; i < n - 2; i++) {
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;

}
void print() {
	Node*temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");

}

int main() {
	head = NULL;
	insert(2, 1);
	insert(4, 2);
	insert(5, 3);
	insert(8, 2);
	insert(9, 4);
	print();
	return 0;
}
*/

/*
//Delete a node at nth position
#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node*next;
};
Node*head;
/////////////////////////////////////////////////////////////
void insert(int data) {
	Node*temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if (head != NULL)temp->next = head;
	head = temp;
}
///////////////////////////////////////////////////////
void print() {
	Node*temp = head;
	printf("List is : ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
///////////////////////////////////////////////////////
void Delete(int position) {
	Node*temp1 = head;
	if (position == 1) {
		head = temp1->next;
		delete(temp1);
		return;
	}
	for (int i = 0; i < position - 2; i++) {
		temp1 = temp1->next;
	}
	Node*temp2 = temp1->next;
	temp1->next = temp2->next;
	delete(temp2);

}

int main() {
	head = NULL;
	insert(6);
	insert(7);
	insert(88);
	insert(90);
	insert(43);
	insert(20);
	print();
	int position;
	printf("Enter a position you would like to delete : ");
	scanf("%d", &position);
	Delete(position);
	print();
	return 0;
}
*/

//Reversing a linked list
/*
//using iterative solution
#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node*next;
};
Node*head;

void insert(int data) {
	Node*temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if (head != NULL)temp->next = head;
	head = temp;
}
///////////////////////////////////////////////////////
void print() {
	Node*temp = head;
	printf("List is : ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void Reverse() {
	Node*current, *prev, *next;
	current = head;
	prev = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

int main() {
	head = NULL;
	insert(6);
	insert(7);
	insert(88);
	insert(90);
	insert(43);
	insert(20);
	print();
	Reverse();
	print();

	return 0;
}


*/

/*

//Reversal of linked list using recursion
#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node*next;
};
Node*head;
///////////////////////////////////////////////////////////
void insert(int data) {
	Node*temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if (head != NULL)temp->next = head;
	head = temp;
}
//////////////////////////////////////////////////////
void print() {
	Node*temp = head;
	printf("List is : ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
///////////////////////////////////////////////////////
void Printing_rec(Node *p) {
	if (p == NULL) {
		printf("List is : ");
		return;
	}
	Printing_rec(p->next);
	printf("%d ", p->data);

}
////////////////////////////////////////////////////////
void Reverse_rec(Node*p) {
	if (p->next == NULL) {
		head = p;
		printf("The Reversed list is : ");
		return;
	}
	Reverse_rec(p->next);
	Node*q = p->next;
	q->next = p;
	p->next = NULL;
	printf("%d ", q->data);
}
//////////////////////////////////////////////////////////
int main() {
	head = NULL;
	insert(96);
	insert(75);
	insert(98);
	insert(45);
	insert(45);
	insert(38);
	print();
	//Printing_rec(head);
	//Reverse();
	//print(head);
	Reverse_rec(head);


	return 0;
}*/


//Circular linked list
#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node *next;
};
Node* head = NULL;

void insert(int data) {
	Node *newnode = new Node;
	Node *ptr = head;
	newnode->data = data;
	newnode->next = head;

	if (head != NULL) {
		while (ptr->next != head)
			ptr = ptr->next;
		ptr->next = newnode;
	} else
		newnode->next = newnode;
	head = newnode;
}
void display() {
	Node* ptr;
	ptr = head;
	do {
		cout << ptr->data << " ";
		ptr = ptr->next;
	} while (ptr != head);
}
int main() {
	insert(13);
	insert(17);
	insert(87);
	insert(92);
	insert(39);
	cout << "The circular linked list is: ";
	display();
	return 0;
}