/*We will need to store a pair,the element and the minimum upto the element

*/

stack<pair<int, int>>st;
//Adding a new element into the stack we first check if it is minimum to the existing minimu.
//Then we push it to the stack
int new_min = st.empty() ? new_elem : min(new_elem, st.top().second);
st.push({new_elem, new_min});

//To remove an element,we just pop the first element from the stack.
int removed_element = st.top().first;
st.pop();

//To find the minimum element, we just pop the second element.
int minimum = st.top().second;


//*We can achieve the above operations by also using a Queue*
//In this strategy we consider storing the elements in a non-decreasing order.
//The smallest element will always be at the hesd of the queue.
deque<int>Q;

//Finding the minimum element
int minimum = Q.front();

//Adding an element
while (!Q.empty() && Q.back() > new_element)
	Q.pop_back();
Q.push_back(new_element);

//Removing an element
if (!Q.empty() && Q.front() == remove_element)
	Q.front();



//On average the above operations will take a time complextity of O(1)

//Queue modififcation(method 2)
/*
We want to be able to remove elements without knowing which element we have to remove. We can accomplish that by
storing the	index for each element in the queue. And we also remember how many elements we already have added and removed.
*/
deque<pair<int, int>>Q;
int cnt_added = 0;
int cnt_removed = 0;

//As usual find the minimum element remains the same
int minimum = Q.front().first;

//Adding an element
while (!Q.empty() && Q.back() > new_element)
	Q.pop_back();
Q.push_back({new_element, cnt_added});
cnt_added++;

//Removing an element
if (!Q.empty() && Q.front().second == cnt_removed)
	Q.pop_front();
cnt_removed++;


//*Queue modification(method 3)*
/*actually store all elements
can remove an element from the front without knowing its value.
simulate a queue using two stacks.*/

stack<pair<int, int>>s1, s2;

//Finding the minimum element
if (s1.empty() || s2.empty())
	minimum = s1.empty() ? s2.top().second : s1.top().second;
else
	minimum = min(s1.top().second, s2.top().second);

//Adding an element
int minimum = s1.empty() ? new_element : min(new_element, s1.top().second);
s1.push({new_element, minimum});

//Removing an element
if (s2.empty()) {
	while (!s1.empty()) {
		int element = s1.top().first;
		s1.pop();
		int minimum = s2.empty() ? element : min(element, s2.top().second);
		s2.push({element, minimum});
	}
}
int remove_element = s2.top().first;
s2.pop();







#include<bits/stdc++.h>
using namespace std;

int main() {



	return 0;
}