
#include <iostream>
#include <string>

int main() {

	using namespace std;

	string Fname;
	string Lname;

	cout << "Enter your first name: ";
	cin >> Fname;
	cout << "Enter your last name: ";
	cin >> Lname;

	Lname = Lname + ", " + Fname;

	cout << "Here's the information in a single string: " << Lname << endl;

	return 0;

}