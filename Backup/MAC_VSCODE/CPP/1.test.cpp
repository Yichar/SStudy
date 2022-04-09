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

const double PI = 3.14;



class Circle {
public:
    double calculateZC() {
        return 2 * PI * m_R;
    }

    int m_R;


};


class Student {
    public:
        void set_age(int a) {
            this->_age = a;
        }
        void set_name(string name) {
            this->_name = name;
        }
        void show_stu() {
            cout << this->_age << " "<< this->_name << endl;
        }
    private:

        int _age;
        string _name;


};
void test01() {

    Circle C1; 
    C1.m_R = 10;
    cout << C1.calculateZC() << endl;


}

void test02() {

    Student s1;
    s1.set_age(1);
    s1.set_name("xiaoming");
    s1.show_stu();


}
int main()
{
   test02();
  
   return 0;
}
