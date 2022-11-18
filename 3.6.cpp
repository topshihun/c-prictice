
//编写一个程序，要求用户输入驱车里程和使用汽油量，然后指出汽车耗油量为一加伦的里程

#include <iostream>

int main() {

	using namespace std;

	float gallon, mile;

	cout << "Gallon:";
	cin >> gallon;
	cout << "Mile";
	cin >> mile;
	cout << "Velocity is " << gallon / mile << endl;

	return 0;

}