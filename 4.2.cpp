

#include <iostream>
#include <string>

int main() {

	using namespace std;

	string Fname, Lname;
	char Grade;
	unsigned short Age;

	cout << "What is your first name? ";
	getline(cin, Fname);
	cout << "What is your last name? ";
	cin >> Lname;
	cout << "What letter  grade do you deserve? ";
	cin >> Grade;
	cout << "What is your age? ";
	cin >> Age;
	cout << "Name: " << Fname << ", " << Lname << endl;
	cout << "Grade: " << (char)(Grade + 1) << endl;
	cout << "Age: " << Age << endl;
	

	return 0;

}