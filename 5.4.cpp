
#include <iostream>


int main() {

	using namespace std;

	double Cleo = 105,Daphne = 110;
	int year = 1;

	for (; Cleo < Daphne;year++) {
		Cleo = (Cleo * 0.05) + Cleo;
		Daphne = Daphne + 10;
	}

	cout << "Pass " << year << " ,Cleo pass Daphne." << endl;
	cout << "Cleo is " << Cleo << endl;
	cout << "Daphen is " << Daphne << endl;

	return 0;

}
