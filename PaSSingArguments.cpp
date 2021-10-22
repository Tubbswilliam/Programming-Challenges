#include<bits/stdc++.h>
using namespace std;
void passbyVal(int x, int y) {
     int temp = x;
     x = y;
     y = temp;
}

void passByRef(int &x, int&y) {
     int temp = x;
     x = y;
     y = temp;

}

void passByointers(int *x, int *y) {
     int temp = *x;
     *x = *y;
     *y = temp;
}

int main() {
     int a = 9, b = 7;
     cout << "Before swapping :" << "a: " << a << " b: " << b << endl << endl;
     //passbyVal(a, b);
     //passByRef(a, b);
     passByointers(&a, &b);
     cout << "Before swapping :" << "a: " << a << " b: " << b << endl << endl;

     return 0;
}