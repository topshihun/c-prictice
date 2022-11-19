#include <iostream>
#include <ctime>
using namespace std;
int main() {
	srand(time(0));
	int num = rand() % 100 + 1;
	cout << "猜数游戏" << endl;
	//int i = 0; //次数
	for (int i = 0; i < 10; i++) {
		int count; //猜的的数字
		cout << "请输入数字:";
		cin >> count;
		if (count > num) {
			cerr << "Wrong!" << endl;
			cout << "Too high" << endl;
		}
		else if (count < num) {
			cerr << "Wrong" << endl;
			cout << "Too low" << endl;
		}
		else {
			system("cls");
			cout << "Congratulatiob!" << endl;
			cout << "You 猜了 " << i << "次,棒棒哒。" << endl;
			system("pause");
			return 0;
		}
	}
	cout << "不是吧，不是吧，不会真有人猜了10次还没猜对吧。" << endl;
	cout << "Number is " << num << endl;
	return 0;
}