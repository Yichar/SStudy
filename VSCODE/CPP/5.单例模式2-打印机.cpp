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

class Printer {
public:
    static Printer * getInstance() {
        return singlePrinter;
    }
    static void setPname(const string name) {
        Pname = name;
    }
    static string Pname;
    void printText(string text) {
        m_count++;
        cout << text << endl;
    }
    int m_count;
private:
    Printer(){
         m_count = 0;
         cout << "打印机构造" << endl;};
    Printer(const Printer &){};
    static Printer * singlePrinter;
    
   
};
Printer * Printer::singlePrinter = new Printer();

int main()
{
   Printer *p1 = Printer::getInstance();
   string s1 = "ab";
   p1->printText("后裔");
   p1->printText("安其拉");
   Printer *p2 = Printer::getInstance();
   cout << p2->m_count;
    //  p1->setPname(s1);
  // cout << p1->Pname;
   return 0;
}
