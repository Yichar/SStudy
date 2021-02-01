#ifndef __MYSTRING__H__
#define __MYSTRING__H__

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;
class MyString {
    friend ostream& operator<<(ostream &cout, MyString& str);
    friend istream& operator>>(istream &cin, MyString& str);
public:

    MyString(const char *str);
    MyString(const MyString& str);
    MyString& operator=(const MyString& str);
    MyString& operator=(const char * str);
    char& operator[](int index);
    MyString operator+(const MyString& str);
    MyString operator+(const char* str);
    bool operator==(const MyString& str);
    bool operator==(const char* str);
    bool operator>(const MyString& str);
    bool operator>(const char* str);
    ~MyString();
     

private:
    char *pString;
    int m_Size;// strlen（） 不统计\0



};
#endif
