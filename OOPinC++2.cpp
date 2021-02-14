#include<bits\stdc++.h>
using namespace std;
//Dealing with Encapsulation
//using getters and setters
//Dealing with Abstruction
//Dealing with inheritance
class AbstractEmployee() {
	virtual void AskforPromotion() = 0;
}

class Employee: AbstractEmployee {
private:
	string Name;
	string Company;
	int Age;
public:
	//setters or mutator
	void setName(string name) {Name = name;}
	//getter or accessor
	string getName() {return Name;}

	void setCompany(string company) {Company = company;}
	string getCompany() {return Company;}

	void setAge(int age) {Age = age;}
	int getAge() {return Age;}


	void introduceYourself() {
		cout << "Name - " << Name << endl;
		cout << "company - " << Company << endl;
		cout << "Age - " << Age << endl;
	}
	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;

	}
	void AskforPromotion() {
		//You have to implement the funstion
	}
};

//inheritance Employee being the super class and Developer is the derived class
class Developer: public Employee {
public:
	string PrgLang;
	Developer(string name, string company, int age, string PrgLang): Employee(name, company, age) {
		PrgLang = PrgLang;
	}
};