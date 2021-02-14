#include<bits\stdc++.h>
using namespace std;
//Today I will try to leanr about dynamic memory allocataion and the pointers
//Then later on i can try to work
//dynamic memory allocation->new keyword and delete keyword
//pointer(p) cout<< gives us an address while *p gives us the value
//pointer arithmetics example p+1....
//pointer to pointer **p....means pointer to a pointer variable
// int x = 5;
// int *p = &x;
// *p = 6;
// int **q = &p;
// int ***r = &q;
// cout << *p << endl;
// cout << *q << endl;
// cout << **q << endl;
// cout << **r << endl;
// cout << ***r << endl;
// ***r = 10;
// cout << "The value of x = " << x << endl;
// **q = *p + 2;
// cout << "The value of x after using *p+2 = " << x << endl;

//Pointers as function arguments

// void increment(int *p) {
// 	cout << p << endl;
// 	*p = *p + 1;
// }

//pointers and arrays
//To get the address of an element in the array we can use &A[i] or A+i
//To get the actual element we can use A[i] or *(A+1)
// int A[] = {2, 4, 5, 8, 1};
// 	//getting the address of the first element in the array
// 	cout << A << endl; //or &A[0]
// 	//getting the value
// 	cout << *A << endl;

//Arrays as function arguments

//Character arrays
//pointers and multiDimensional arrays
// void func(int (*A)[2][2]){}
// 	int c[3][2][2] = {{{2, 5}, {7, 9}}, {{3, 4}, {6, 1}}, {{0, 8}, {11, 13}}};
// 		printf("%d %d %d %d", c, *c, c[0], &c[0][0]);
// 		printf("%d \n", *(c[0][0] + 1));

//Dynamic memory allocation in C - malloc calloc realloc free
// malloc->void *malloc(size_t size)
// void *p=malloc(sizeof(int)) ->void pointers need to be typecasted
// for example we can allocate an int memory as int*p=(int*)malloc(sizeof(int))

// calloc->void *malloc(size_t size num,size_t size)
// calloc imitializes the memory it allocates to zero while in malloc you get garbage values
// for example we can allocate an int memory as int*p=(int*)calloc(3,sizeof(int))
// //when you want to reallocate the memory allocated we use realloc
// realloc->void* realloc(void* ptr,size_t size)

// To deallocate memory we use free
// int n;
// 	printf("Enter size of arra \n");
// 	scanf("%d", &n);
// 	int *A = (int*)malloc(n * sizeof(int)); //dynamic memory allocation
// 	//int *A = (int*)calloc(n, sizeof(int));
// 	//int *B=int*realloc(A,2*n*sizeof(int));
// 	for (int i = 0; i < n; i++) {
// 		A[i] = i + 5;
// 		cout << A[i];
// 	}
// 	free(A);


//Pointers as function returns
//Function pointers


// int Add(int a, int b) {
// 	return a + b;
// }
// int c;
// 	int (*p)(int, int);
// 	p = &Add;
// 	c = (*p)(2, 5);
// 	cout << c;



int main() {

	return 0;
}