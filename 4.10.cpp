
#include <iostream>
#include <string>
#include <array>

int main() {

	using namespace std;

	array<float, 3> distance;

	cin >> distance.at(0);
	cin >> distance.at(1);
	cin >> distance.at(2);
	cout << "distance is 3 and average is " << (distance.at(0) + distance.at(1) + distance.at(2)) / 3 << endl;

	return 0;

}