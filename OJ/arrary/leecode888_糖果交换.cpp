/*************************************************************************
	> File Name: leecode888_糖果交换.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 一  2/ 1 13:40:15 2021
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


class Solution {
public:
    std::unordered_set<int>::iterator it;
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int suma = accumulate(A.begin(),A.end(), 0);
        int sumb = accumulate(B.begin(),B.end(), 0);
        //suma + B[i] - A[i] = sumb - B[i] + A[i]
        //A[i] = (suma - sumb + 2B[i]) / 2;
       // int delta = sumb - suma;
        unordered_set<int> SA(A.begin(), A.end());
        for (int i = 0; i <  B.size(); i++) {
            int temp = suma - sumb + 2 * B[i];
            if ((SA.find(temp/2)) != SA.end()) 
                     return {temp/2,B[i]};
    
        }
        return {0,0};
    }
};
