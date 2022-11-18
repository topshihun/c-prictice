
//编写一个程序，要求用户输入全球当前的人口和美国当前的人口，并让程序显示美国的人口占全国人口的百分比。

#include <iostream>

int main() {

	using namespace std;

	unsigned long long WorldPopulation, USPopulation;

	cout << "Enter the world's population: ";
	cin >> WorldPopulation;
	cout << "Enter the population of the US: ";
	cin >> USPopulation;
	cout << "The population of the US is " << (double)USPopulation / (double)WorldPopulation * 100 << "% of the world population" << endl;

	return 0;

}