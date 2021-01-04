/*************************************************************************
	> File Name: leecode509_斐波那契.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 一  1/ 4 09:52:01 2021
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int fib(int N) {
        int n_2=0, n_1=1, n=1;
        if(N==0)
            return 0;
        if(N==1)
            return 1;
        for(int i=2;i<N+1;i++)
        {
            n=n_1+n_2;
            n_2=n_1;
            n_1=n;
        }
    return n;
    }
};

