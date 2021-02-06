#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

template<class T>
class myArray {
public:
   //有参构造
    myArray(int capacity) {
       this->m_Size = 0;
       this->m_Capacity = capacity;
       this->pAddress = new T[capacity];
    }
    myArray(const myArray &arr) {
       this->m_Size = arr.m_Size; 
       this->m_Capacity = arr.m_Capacity;
       this->pAddress = new T[this->m_Caoacity];
       memcpy(this->pAddress, arr.pAddress ,sizeof(T));
    }
    T& operator= (const myArray &arr){
       if (this->pAddress)
            delete [] this->pAddress;
       this->pAddress = new T[arr.m_Capacity];
       this->m_Capacity = arr.m_Capacity;
       this->m_Size = arr.m_Size; 
       memcpy(this->pAddress, arr.pAddress ,sizeof(T));
       return *this;
    }
    T& operator[](int index) {
       return this->pAddress[index];
    }
    
    int getCapacity() {
       return this->m_Capacity;
    }
    int getSize() {
       return this->m_Size;
    }
    void push_back(const int val) {
       if (this->m_Capactiy <= this->m_Size)
         return;
       

         this->pAddress[this->m_Size];
         this->m_Size++;
    }
    ~myArray() {
      
       if (this->pAddress) {
          delete [] pAddress;
        }
    }
private:
   T *pAddress;
   int m_Size;
   int m_Capacity;

};



