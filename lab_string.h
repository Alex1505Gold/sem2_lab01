#pragma once
#include <iostream>
class Lab_string
{
	char* data;
public:
	Lab_string();
	Lab_string(const Lab_string& str);
	Lab_string(const char* str);
	~Lab_string();
	Lab_string& operator= (const Lab_string& str);
	bool operator==(const Lab_string& right);
	unsigned int length();
	int find(const Lab_string& str);
	void replace(char& tmp, char& rplc);
	char operator[](const int& i);
	Lab_string& operator+(const Lab_string& str);
};

std::ostream& operator<<(std::ostream& out, Lab_string& str);
//std::istream& operator>>(std::istream& in, Lab_string& str);