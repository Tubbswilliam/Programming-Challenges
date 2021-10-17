#include<bits/stdc++.h>
using namespace std;

/*
//Function template
template<typename t>
void print(t val) {
	cout << "The value is: " << val << endl;
}

int main() {
	print<int>(5);
	print<float>(10.2233);
	print<string>("Nairobi");
	return 0;
}

*/
//Class template
template<typename t>
class Weight {
private:
	t kg;
public:
	void setData(t x) {
		kg = x;
	}
	t getdata() {
		return kg;
	}

};

int main() {
	Weight <int>obj1;
	obj1.setData(5);
	cout << "Value is: " << obj1.getdata() << endl;

	Weight <string>obj2;
	obj2.setData("William");
	cout << "Value is: " << obj2.getdata() << endl;

	return 0;
}



