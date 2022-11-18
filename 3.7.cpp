
//编写一个程序，要求用户按照欧洲风格输入汽油量，然后将其转化为美国风格的耗油量。

#include <iostream>

int main() {

	using namespace std;

	float litre;

	cout << "Litre:";
	cin >> litre;
	cout << "US' velocity is " << (62.14 * 3.785) << endl;

	return 0;

}