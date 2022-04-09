
#include "myArray.hpp"
using namespace std;
int main() {


    myArray<int> myArr(10);
    for(int i = 0; i < 10; i++) {
        myArr.push_back(i);
    }
    cout << myArr.getSize() << endl;
    cout << myArr.getCapacity() << endl;

}