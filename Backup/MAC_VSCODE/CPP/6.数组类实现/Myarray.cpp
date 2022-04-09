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
#include "MYarray.h"

using namespace std;
MyArray::MyArray() {
   cout << "默认构造" << endl;
   this->m_Capactiy = 100;
   this->pAdress = new int[this->m_Capactiy];
   this->m_Size = 0;
}
MyArray::MyArray(int capcity) {
    cout << "有参构造" << endl;
   this->pAdress = new int[capcity];
   this->m_Capactiy = capcity;
   this->m_Size = 0;
}
MyArray::MyArray(const MyArray &arr) {
    cout << "拷贝构造" << endl;
   this->m_Capactiy = arr.m_Capactiy;
   this->m_Size = arr.m_Size;
   this->pAdress = new int[arr.m_Capactiy];
   memcpy(this->pAdress, arr.pAdress, arr.m_Capactiy);
}
void MyArray::PushBack(int val) {
   this->pAdress[this->m_Size] = val;
   this->m_Size++;
}
void MyArray::SetData(int pos, int val) {
   this->pAdress[pos] = val;
}
int MyArray::GetData(int pos) {
   return this->pAdress[pos];
}
int MyArray::GetSize() {
   return this->m_Size;
}

int MyArray::GetCapcity() {
   return this->m_Capactiy;
}
MyArray::~MyArray() {
   cout << "析构函数"  << endl;
   if (this->pAdress != nullptr) {
      delete [ ] this->pAdress;
   }
}

void test01() {
   MyArray arr;
   for (int i = 0; i < 20; i++)
      arr.PushBack(i);
   for (int i = 0; i < arr.GetSize(); i++)
      cout << arr.GetData(i) << endl;
   MyArray arr2(arr);
   for (int i = 0; i < arr2.GetSize(); i++)
      cout << arr2.GetData(i) << endl;

}
int main()
{
   
   test01();
   return 0;
}
