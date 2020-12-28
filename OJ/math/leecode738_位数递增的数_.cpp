/*************************************************************************
	> File Name: leecode738_位数递增的数_.cpp
	> Author: 
	> Mail: 
	> Created Time: 一 12/28 13:08:31 2020
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    
//数学方法
//从9个1开始加，一直加到1个1
    int monotoneIncreasingDigits(int N) {
       int num = 111111111;
       int ans = 0 ;
       for(int i = 1; i <= 9; i++) {
           while( num + ans > N && num) {
               num /= 10;
           }
           ans += num;
       }
            
        return ans;
        
    }
};

