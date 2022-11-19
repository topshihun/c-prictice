#pragma once
#include <iostream>
class circal {
private:
	char* s = NULL;
	char point;
	int set;
public:
	//���캯������ʼ��s�����ݺ�p������
	circal();
	circal(char p);
	//����������ɾ��s�ռ�
	~circal();
	//����s������
	char& at(int n);
	//��ת
	char getChar(int i);
	char getChar();
	//����=����
	void operator=(char c);
};

circal::circal() {
	this->s = new char[27];
	int n = 0;
	for (int i = 'a'; i <= 'z'; i++, n++) {
		this->s[n] = i;
	}
	this->s[n] = '\0';
	this->point = 'a';
	this->set = 0;
}

circal::circal(char p) {
	this->s = new char[27];
	this->set = 0;
	if (p >= 'a' && p <= 'z') {
		int n = 0;
		for (int i = 'a'; i <= 'z'; i++, n++) {
			this->s[n] = i;
		}
		this->set = p - 'a';
	}
	else if (p <= 'Z' && p >= 'A') {
		int n = 0;
		for (int i = 'A'; i <= 'Z'; i++, n++) {
			this->s[n] = i;
		}
		this->set = p - 'A';
	}
	else {
		std::cerr << "eror" << std::endl;
		exit(-1);
	}
	this->s[26] = '\0';
	this->point = p;
}

circal::~circal() {
	delete[] this->s;
}

char& circal::at(int n)
{
	if (n < 0 || n>26) {
		std::cerr << "Out of this circal." << std::endl;
		exit(-1);
	}
	return this->s[n];
}

char circal::getChar(int i) {
	i -= i / 26 * 26;
	this->set += i;
	while (this->set > 25) {
		this->set -= 26;
	}
	while (this->set < 0) {
		this->set += 26;
	}
	return this->s[this->set];
}

char circal::getChar() {
	return this->s[this->set];
}

void circal::operator=(char p) {
	this->set = 0;
	if (p >= 'a' && p <= 'z') {
		int n = 0;
		for (int i = 'a'; i <= 'z'; i++, n++) {
			this->s[n] = i;
		}
		this->set = p - 'a';
	}
	else if (p <= 'Z' && p >= 'A') {
		int n = 0;
		for (int i = 'A'; i <= 'Z'; i++, n++) {
			this->s[n] = i;
		}
		this->set = p - 'A';
	}
	else {
		std::cerr << "eror" << std::endl;
		exit(-1);
	}
	this->s[26] = '\0';
	this->point = p;
}