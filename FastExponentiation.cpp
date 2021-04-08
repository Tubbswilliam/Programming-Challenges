#include<bits/stdc++.h>
using namespace std;
int fastExpo(int num, int pow) {
	if (pow == 0) {
		return 1;
	}
	else if (pow == 1)return num;
	else {
		int R = fastExpo(num, pow / 2);
		if (pow % 2 == 0)return R * R;
		else
			return R * num * R;
	}
}

int main() {
	int n, pow;
	cin >> n >> pow;
	cout << "The exponentiation of the number is: " << fastExpo(n, pow);
	return 0;
}