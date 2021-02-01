#include "./MyString.h"


ostream& operator<<(ostream &cout, MyString& str) {
    cout << str.pString ;
    return cout;
}
istream& operator>>(istream &cin, MyString& str) {
    if (str.pString ) {
        delete [] str.pString ;
    }
    char buf[1024];
    cin >> buf;
    str.m_Size = strlen(buf);
    str.pString = new char[str.m_Size + 1];
    strcpy(str.pString, buf);
    return cin;
}
MyString::MyString(const char *str) {
    this->m_Size = strlen(str);
    this->pString = new char[m_Size + 1];
    memcpy(this->pString, str, m_Size);
}

MyString::MyString(const MyString& str) {
    this->m_Size = str.m_Size;
    this->pString = new char[str.m_Size + 1];
    memcpy(this->pString, str.pString, m_Size);
}
MyString&  MyString::operator=(const MyString& str) {
    if (this->pString) {
        delete [] this->pString;
    }
    this->pString = new char[strlen(str.pString) + 1];
    strcpy(this->pString, str.pString);
    return *this;
}
MyString&  MyString::operator=(const char* str) {
    if (this->pString) {
        delete [] this->pString;
    }
    this->pString = new char[strlen(str) + 1];
    strcpy(this->pString, str);
    return *this;
}
char& MyString::operator[](int index) {
    return this->pString[index];
}
MyString MyString::operator+(const MyString& str) {
    int lens = strlen(this->pString) + strlen(str.pString);
    char *buf = new char[lens + 1];
    memset(buf, 0, lens);
    strcat(buf, this->pString);
    strcat(buf,str.pString);
    //调用有参构造
    MyString newStr = buf;
    //释放初始值
    delete [] buf;
    return newStr;
    
}
MyString MyString::operator+(const char * str) {
    int lens = strlen(this->pString) + strlen(str);
    char *buf = new char[lens + 1];
    memset(buf, 0, lens);
    strcat(buf, this->pString);
    strcat(buf,str);
    //调用有参构造
    MyString newStr = buf;
    //释放初始值
    delete [] buf;
    return newStr;
    
}
bool MyString::operator==(const MyString& str) {
    if (strcmp(this->pString, str.pString) == 0 )
        return true;
    else 
        return false;
}
bool MyString::operator==(const char *str) {
    if (strcmp(this->pString, str) == 0 )
        return true;
    else 
        return false;
}
bool MyString::operator>(const MyString& str) {
    return (strcmp(this->pString, str.pString));
}
bool MyString::operator>(const char *str) {
    return (strcmp(this->pString, str));
}

MyString::~MyString() {
    if (this->pString) {
        delete [] this->pString;
    }
}



int main() {

    // MyString s1("abc");
    // MyString s2(s1);
    // cout << s1 << " "<<s2 << endl;
    // cin >> s1;
    // cout << s1 << " "<<s2 << endl;
    MyString str1 = "aaavvv";
    MyString str2 = "";
    cout << str1 << " "<< str2 << endl;
    str2 = str1;
    cout << str1 << " " <<str2 << endl;
    str2 = "i get you";
    cout << str1 << " " <<str2 << endl;
    cout << str1[0] << endl;
    str1[0] = 'z';
    cout << str1[0] << endl;
    MyString str3 = str1 + str2; 
    cout << str3 << endl;
    MyString str4 = str1 + "aaaa"; 
    cout << str4 << endl;
    str3 = "aaa";
    str4 = "aaa";
    if (str3 == str4)
        cout << "相等" << endl;
    else
         cout << "no相等" << endl;
    return 0;




}


