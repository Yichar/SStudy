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


class ChairMan {
public:
    //静态函数访问静态变量
   static ChairMan * getInstace () {
       return singleman;
   }

private:
    ChairMan() {};
   // 防止通过拷贝构造 克隆对象
   ChairMan(const ChairMan&){};
     //类内声明 类外初始化
   static ChairMan *singleman;

};

//加上作用域 相当于是类内访问
ChairMan * ChairMan::singleman = new ChairMan;
void test01() {

ChairMan *c1 = ChairMan::getInstace(); //通过类名访问
ChairMan *c2 = ChairMan::getInstace(); //通过类名访问
 // c1 == c2
}
int main()
{
   
   system("pause");
   return 0;
}
