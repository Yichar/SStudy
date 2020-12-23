/********************mZ****************************************************
	> File Name: shape.cpp
	> Author: 
	> Mail: 
	> Created Time: 二 12/22 23:47:40 2020
 ************************************************************************/

#include<iostream>
using namespace std;

class Shape{
    public:
        virtual void CaleArea() = 0;
        virtual ~Shape() {}; 
};

class Circle : public Shape{
    private:
        int _r;
    public:
        Circle(int r = 0) : _r(r){};
        void CaleArea() override{
            std::cout << "Circle area:" << _r * _r << std::endl;
        }
};
class Rectangle : public Shape{
    private:
        int _l;
        int _h;
    public:
        Rectangle(int l = 0,int h = 0) : _l(l),_h(h) {};
        void CaleArea() override{
            std::cout<< "Circle area:" << _l * _h << std::endl;
        }
};


int main() {
    Shape* p = new Circle(5);
    p->CaleArea();
    delete p;

    p = new Rectangle(3,5);
    p->CaleArea();
    delete p;
    return 0;
}
