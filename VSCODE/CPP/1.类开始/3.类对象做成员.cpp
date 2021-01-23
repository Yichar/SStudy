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

class Phone {
    public:
    Phone(string name):m_Phonename(name){
        cout << "Phone 有参构造"  << endl;
    }

    string m_Phonename;

    ~Phone() {
        cout << "Phone 析构"  << endl;
    }

};
class Game{
    public:
    Game(string name):m_Gamename(name){
        cout << "Game 有参构造"  << endl;
    }
    string m_Gamename;
    ~Game() {
        cout << "Game 析构"  << endl;
    }

};

class Person {

public:
    Person(string name,string pName,string gName):m_Name(name), m_Phone(pName),m_Game(gName){
        cout << "Person 构造"  << endl;
    }
    string m_Name;
    Phone m_Phone;
    Game m_Game;

    ~Person(){
        cout << "Person 析构"  << endl;
    }

};


int main()
{
   Person P("张三", "苹果", "王者荣耀");
   //system("pause");
   return 0;
}
