#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
	//match string
	regex r1(".*@.*");
	string str1;
	cin >> str1;
	if (regex_match(str1, r1))
		cout << "Match @ succeed!" << endl;
	else
		cout << "Match @ failed!" << endl;
	//search string
	regex r2("<.*?>");
	string str2;
	cin >> str2;
	string::const_iterator begin = str2.begin();
	string::const_iterator end = str2.end();
	smatch m1;
	while (regex_search(begin, end, m1, r2)) {
		begin = m1[0].second;
		cout << m1[0].str() << endl;
	}
	//use sregex_iterator
	regex r3("<.*?>");
	string str3;
	cin >> str3;
	sregex_iterator beg1(str3.begin(), str3.end(), r3);
	sregex_iterator end1;
	for (; beg1 != end1; beg1++) {
		cout << beg1->str() << endl;
	}
	//replace string
	regex r4("1");
	string str4;
	cin >> str4;
	string res = regex_replace(str4, r4, "2");
	cout << res << endl;
	return 0;
}
