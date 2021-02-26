/*************************************************************************
	> File Name: leccode43_字符串乘法_大数西数相乘.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 三  2/24 15:21:01 2021
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
#include <cstring>
using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> n1(num1.size()+1);
        vector<int> n2(num2.size()+1);
        vector<int> ans(num1.size() + num2.size() + 1);
        if (num1 == "0" || num2 == "0") return "0";
        //第一位存长度，结果默认取 最小值得情况
        n1[0] = num1.size();
        n2[0] = num2.size();
        ans[0] = num1.size() + num2.size() - 1;
        // 倒着存
        for (int i = 1, j = n1[0] - 1; i <= n1[0]; i++, j--)
            n1[i] = num1[j] - '0';
        for (int i = 1, j = n2[0] - 1; i <= n2[0]; i++, j--)
            n2[i] = num2[j] - '0';
        //计算ans每一位
        for (int i = 1; i <= n1[0]; i++) {
            for (int j = 1; j <= n2[0]; j++) {
                ans[i + j - 1] += n1[i] * n2[j];
            }
        }
       //处理进位
        for (int i = 1; i <= ans[0]; i++) {
            if (ans[i] >= 10) {
                ans[i + 1] += ans[i] / 10;
                ans[i] %= 10;
                if (i == ans[0])  {// 最高位需要进位 最后加一位
                    ans.push_back(ans[i] / 10); 
                    ans[i] %= 10;
                    ans[0]++;  //长度+1
                }
            }
        }
        //倒序拼接字符串
        string res;
        for (int i = ans[0]; i >= 1; i--) {
            res += ans[i] + '0';
        }
        return res;
    }
};
