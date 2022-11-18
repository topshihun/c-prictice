
#include <iostream>
#include <cstring>


int main() {

	using namespace std;

	char a[520] = { 0 };
	int i = 0;

	cout << "Enter words (to stop, type the word done):" << endl;

	for (; strcmp(a, "done") != 0; i++) {
		cin >> a;
	}
	
	cout << "You entered a total of " << i - 1 << " words";

	return 0;

}
