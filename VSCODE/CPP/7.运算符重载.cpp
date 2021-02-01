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
    Person(int a,int b):a(a),b(b){}
    int a;
    int b;
};

ostream & operator<<(ostream &cout, Person &a) {
    cout << a.a << a.b ;
    return cout;
}

void test01() {
    Person p1(10,10);

cout << p1 << endl;



}
int main()
{
   
    test01();
   return 0;
}
