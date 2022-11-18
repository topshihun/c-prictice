
//编写一个程序，要求用户以秒为单位输入整数，然后以天，小时，分钟，秒的方式显示这一段时间。

#include <iostream>

int main() {

	using namespace std;

	unsigned long second, SECOND;
	unsigned long day;
	unsigned long hour, minute;
	const unsigned long number = 60;
	const unsigned long DayHour = 24;

	cout << "Enter the number of seconds:";
	cin >> second;
	
	SECOND = second;
	minute = second / number;
	second = second % number;
	hour = minute / number;
	minute = minute % number;
	day = hour / DayHour;
	hour = hour % DayHour;

	cout << SECOND << " seconds = " << day << " days, " << hour << " hours " << minute << " minutes " << second << " seconds" << endl;

	return 0;

}