/*************************************************************************
	> File Name: leecode738_位数递增的数.cpp
	> Author: 
	> Mail: 
	> Created Time: 一 12/28 12:42:59 2020
 ************************************************************************/

#include<iostream>
using namespace std;


class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string ans = to_string(N);
        int flag = ans.size(); // 标记
        for (int i = ans.size() - 1; i > 0; i--){
            if (ans[i] < ans[i-1]) {  //从后向前找，第一个逆序的对，后面全部为9.
                flag = i; //记录标记
                ans[i - 1]--;
            }
        }
        for (int i = flag; i < ans.size(); i++){
            ans[i] = '9'; 
        }
        

        return stoi(ans);

    }
};
