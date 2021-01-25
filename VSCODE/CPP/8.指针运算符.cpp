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

class SmartPoint {

public:
    SmartPoint(person *person) {
        this->m_person = person;
    }
private:
    Person * m_person;
    ~SmartPoint() {
        if(this->m_person) {
            delete this->m_person;
            this->m_person = nullptr;
        }
    }
};

class Person {
public:
    Person(int par) {
        this->mpar = par;
    }
    void PrintPerson() {
        cout << "Par:" << this->mpar << endl;
    }

private:
    int mpar;
};

int main()
{
    SmartPoint
   
   system("pause");
   return 0;
}
