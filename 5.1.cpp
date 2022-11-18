
#include <iostream>

int TowSum(int big, int small);

int main() {

	using namespace std;


	int a, b,sum;

	cout << "Enter tow numbers: " << endl;
	cin >> a;
	cin >> b;
	if (max(a, b) == a) {
		sum = TowSum(a, b);
	}
	else {
		sum = TowSum(b, a);
	}

	cout << "The Sum is " << sum << endl;

	return 0;

}

int TowSum(int big, int small) {

	int sum = 0;

	for (; big >= small; ++small) {

		//std::cout << small << std::endl;
		sum = sum + small;

	}

	return sum;

}