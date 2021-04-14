//This prmality test works in o(n)
/*#include<bits/stdc++.h>
using namespace std;
bool prime(int n) {
	if (n == 1)return false;
	for (int i = 2; i < n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	cout << boolalpha << prime(n);
	return 0;
}
*/

//Using the theorem that a divisor pair(a,b)has one of the divisors
//below the sqrt(n)and the other one above sqrt(n), we can improve the
//time complexity of the algorithm to O(sqrt(n))

#include<bits/stdc++.h>
using namespace std;
bool prime(int n) {
	if (n == 1)return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	cout << boolalpha << prime(n);

	return 0;
}

//HackerRank problem on primality test L and R