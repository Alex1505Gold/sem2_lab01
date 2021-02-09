#include "lab_string.h"
#include <iostream>
Lab_string::Lab_string()
{
	data = new char[1];
	data[0] = '\0';
}

Lab_string::Lab_string(const Lab_string& str)
{
	unsigned int i = 0;
	while (str.data[i] != '\0')
	{
		i++;
	}
	data = new char[i + 1];
	i = 0;
	while (str.data[i] != '\0')
	{
		data[i] = str.data[i];
		i++;
	}
	data[i] = '\0';
}

Lab_string::Lab_string(const char* str)
{
	unsigned int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	data = new char[i + 1];
	i = 0;
	while (str[i] != '\0')
	{
		data[i] = str[i];
		i++;
	}
	data[i] = '\0';
}

Lab_string::~Lab_string()
{
	delete [] data;
}

unsigned int Lab_string::length()
{
	unsigned int i = 0;
	while (data[i] != '\0')
	{
		i++;
	}
	return i;
}

int Lab_string::find(const Lab_string& str)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int size_sub = 0;
	while (str.data[i] != '\0')
	{
		size_sub++;
		i++;
	}
	i = 0;
	bool if_find = false;
	while (data[i] != '\0')
	{
		if (data[i] == str.data[j])
		{
			unsigned int k = i;
			if_find = true;
			while (data[k] != '\0' && str.data[j] != '\0')
			{
				if (data[k] != str.data[j] && str.data[j] != '\0')
				{
					if_find = false;
					j = 0;
					break;
				}
				k++;
				j++;
			}
		}
		if (if_find) break;
		i++;
	}
	if (if_find) return i;
	else return -1;
}

void Lab_string::replace(char& tmp, char& rplc)
{
	unsigned int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] == tmp) data[i] = rplc;
		i++;
	}
}

char Lab_string::operator[](const int& i)
{
	return data[i];
}

Lab_string& Lab_string::operator+(const Lab_string& str)
{
	unsigned int i = 0;
	while (data[i] != '\0')
	{
		i++;
	}
	char* tmp = new char[i + 1];
	i = 0;
	while (data[i] != '\0')
	{
		tmp[i] = data[i];
		i++;
	}
	tmp[i] = '\0';
	unsigned int j = 0;
	while (str.data[j] != '\0')
	{
		j++;
	}
	std::cout << j << std::endl;
	delete [] data;
	data = new char[i + j + 1];
	for (int k = 0; k < i; ++k)
	{
		data[k] = tmp[k];
	}
	for (int k = 0; k < j; ++k)
	{
		data[k + i] = str.data[k];
	}
	data[j + i] = '\0';
	delete [] tmp;
	return *this;
}

Lab_string& Lab_string:: operator= (const Lab_string& str)
{
	if (this != &str)
	{
		unsigned int i = 0;
		while (str.data[i] != '\0')
		{
			i++;
		}
		delete[] data;
		data = new char[i + 1];
		i = 0;
		while (str.data[i] != '\0')
		{
			data[i] = str.data[i];
			i++;
		}
		data[i] = '\0';
	}
	return *this;
}

bool Lab_string::operator==(const Lab_string& right)
{
	bool equal = true;
	unsigned int i = 0;
	unsigned int j = 0;
	while (data[i] != '\0')
	{
		i++;
	}
	while (right.data[j] != '\0')
	{
		j++;
	}
	if (i != j) equal = false;
	else
	{
		for (int k = 0; k < i; k++)
		{
			if (data[k] != right.data[k])
			{
				equal = false;
				break;
			}
		}
	}
	return equal;
}

std::ostream& operator<<(std::ostream& out, Lab_string& str)
{
	unsigned int i = 0;
	while (str[i] != '\0')
	{
		out << str[i];
		++i;
	}
	return out;
}

/*
std::istream& operator>>(std::istream& in, Lab_string& str)
{
	
}
*/