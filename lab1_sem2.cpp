#include <iostream>
#include "lab_string.h"


int main()
{
    Lab_string str0;
    str0 = "abcdef";
    Lab_string str1;
    str1 = "bcdef";
    std::cout << str0 << std::endl;
    char tmp = 'a';
    char rplc = 'y';
    str0.replace(tmp, rplc);
    std::cout << str0 << std::endl;
    if (str0 == str1) std::cout << 1 << std::endl;
    else std::cout << 2 << std::endl;
    std::cout << str0.length() << std::endl;
    str0 = str0 + str1;
    std::cout << str0 << std::endl;
    std::cout << str0.find("de") << std::endl;
    Lab_string str2;
    std::cin >> str2;
    std::cout << str2 << std::endl;
    std::cout << str2.length() << std::endl;
    return 0;
}

