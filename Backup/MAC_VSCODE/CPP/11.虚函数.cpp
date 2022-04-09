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


class Animal {
public:
    Animal() {
         cout << "动物构造" << endl;
    }
    virtual void Speak() {
        cout << "动物在说话" << endl;
    }
     virtual ~Animal() {
         cout << "动物析构" << endl;
     };
};

class Cat: public Animal {
public:
    char* m_Name;
    Cat(const char * str) {
        this->m_Name = new char[strlen(str) + 1 ];
        strcpy(this->m_Name,str);
         cout << "小猫构造" << endl;
    }
    void Speak() {
        cout << this->m_Name <<"小猫在说话" << endl;
    }
    ~Cat() {
        if(this->m_Name)
            delete [] this->m_Name;
         cout << "小猫析构" << endl;
    }
};


int main() {

    Animal *animal = new Cat("tom");
    delete animal;


}