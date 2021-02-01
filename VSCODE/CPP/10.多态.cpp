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
    virtual void Speak() {
        cout << "动物在说话" << endl;
    }
};

class Cat: public Animal {
public:
    void Speak() {
        cout << "小猫在说话" << endl;
    }
};

class Dog : public Animal  {
public:
    void Speak() {
        cout << "小狗在说话" << endl;
    }
};




void doSpeak(Animal& animal) {
    animal.Speak();
}
int main()
{
   Cat cat;
   doSpeak(cat);
   Dog dog;
   doSpeak(dog);
   
   return 0;
}
