#include<bits/stdc++.h>
using namespace std;
//data variables and member functions
//default, parameterized, copy Constructors and destructors
class ComplexNumber {
private:
	int real;
	float imaginary;
public:
	ComplexNumber() {}
	ComplexNumber(int r, float i) {
		real = r;
		imaginary = i;
	}
	void displaydata() {
		cout << "Complex Number is: " << real << " + " << imaginary << "i" << endl << endl;
	}
	int getReal() {
		return real;
	}
	float getImaginary() {
		return imaginary;
	}

};

ComplexNumber sum2complex(ComplexNumber n1, ComplexNumber n2) {
	int rl = n1.getReal() + n2.getReal();
	float img = n1.getImaginary() + n2.getImaginary();
	ComplexNumber tmp(rl, img);
	return tmp;
}

int main() {
	ComplexNumber comp1(10, 5), comp2(14 , - 7), comp3;
	comp1.displaydata();
	comp2.displaydata();
	comp3 = sum2complex(comp1, comp2);
	comp3.displaydata();
	cout << endl;
	ComplexNumber *p = &comp1;
	cout << p->displaydata;

	return 0;
}