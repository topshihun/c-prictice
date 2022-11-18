
#include <iostream>


int main() {

	using namespace std;

	string month[3][12] = { { "1January","1February","1March","1April","1May","1June","1July","1August","1September","1October","1November","1December" }, 
		{ "2January","2February","2March","2April","2May","2June","2July","2August","2September","2October","2November","2December" }, 
		{ "3January","3February","3March","3April","3May","3June","3July","3August","3September","3October","3November","3December" } };
	int num[3][12] = { 0 };

	for (int y = 0; y < 3; y++) {
		for (int i = 0; i < 12; i++) {

			cout << month[y][i] << ":";
			cin >> num[y][i];

		}
	}

	for (int y = 0; y < 3; y++) {
		for (int i = 0; i < 12; i++) {
			cout << month[y][i] << ":" << num[y][i] << endl;
		}
	}

	

	return 0;

}
