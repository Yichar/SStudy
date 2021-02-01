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


class Point {

public:
    void setX(int x) {
        m_X = x;
    }
    void setY(int y) {
        m_Y = y;
    }
    int getX() {
        return m_X;
    }
    int getY() {
        return m_Y;
    }
private:

    int m_X;
    int m_Y;
};
class Circle {
public:
    void setR(int r) {
        m_R = r;
    }
    int getR() {
        return m_R;
    }
    void setCenter(Point p) {
        m_Center = p;
    }
    Point getCenter() {
        return m_Center;
    }
    void isInCircle(Point p) {
    cout << this->getCenter().getX();
    cout << p.getX();
    int tempx = (this->getCenter().getX() - p.getX());
    int tempy = (this->getCenter().getY() - p.getY());
    int distance = tempx * tempx + tempy * tempy;
    if ((distance * distance) <= (this->getR() * this->getR())) {
        cout << "在圆内" << endl;
    }
    else {
        cout << "在圆外" << endl;
    }
    return;
}

private:
    int m_R;
    Point m_Center;

};
void isInCircle(Circle c, Point p) {
    cout << c.getCenter().getX();
    cout << p.getX();
    int tempx = (c.getCenter().getX() - p.getX());
    int tempy = (c.getCenter().getY() - p.getY());
    int distance = tempx * tempx + tempy * tempy;
    if ((distance * distance) <= (c.getR() * c.getR())) {
        cout << "在圆内" << endl;
    }
    else {
        cout << "在圆外" << endl;
    }
    return;
}
    
int main()
{
   Circle c;
   Point p1;
   Point p2;
   p1.setX(10);
   p1.setY(10);

   p2.setY(5);
   p2.setX(5);
   c.setCenter(p1);
   c.setR(1);
   isInCircle(c, p2);
   c.isInCircle(p2);
   return 0;
}
