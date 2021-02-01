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


class Person {
public:
    Person(int age) {
        this->m_Age = age;
    }
    void showAge() {
        cout << "Person:" << this->m_Age << endl;
    }
    ~Person() {
        cout << "Person析构" << endl;
    }

private:
    int m_Age;
};

class SmartPoint {

public:
    SmartPoint(Person *person) {
        this->m_person = person;
    }
    Person* operator-> () {
        return this->m_person;
    }
    Person& operator* () {
        return *(this->m_person);
    }
     ~SmartPoint() {
        if(this->m_person) {
            delete this->m_person;
            this->m_person = nullptr;
        }
    }
private:
    Person * m_person;
   
};


int main()
{
    SmartPoint sp(new Person(19));
    sp->showAge();
   
   return 0;
}
