
#include <iostream>
#include <cstring>

int main() {

	using namespace std;

	char Fname[41];
	char Lname[20];

	cout << "Enter your first name: ";
	cin >> Fname;
	cout << "Enter your last name: ";
	cin >> Lname;

	strcat_s(Lname, ", ");
	strcat_s(Lname, Fname);

	cout << "Here's the information in a single string: " << Lname << endl;

	return 0;

}