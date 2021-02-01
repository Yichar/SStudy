#ifndef __MYARRAY__H
#define __MYARRAY__H

class MyArray {
public:
    MyArray();
    explicit MyArray(int capacity);
    MyArray(const MyArray &arr);
    void SetData(int pos, int val);
    int GetData(int pos);
    void PushBack(int val);
    int GetLength();
    int GetCapcity();
    int GetSize();
    ~MyArray();
private:
    int m_Capactiy;
    int m_Size;
    int *pAdress;

};


#endif