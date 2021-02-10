/*************************************************************************
	> File Name: leecode992_K个不同整数子数组.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 二  2/ 9 21:04:39 2021
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
 //转换成为求解「最多存在 KK 个不同整数的子区间的个数」与 「最多存在 K - 1K−1 个不同整数的子区间的个数」
    int GetMostDistinct(vector<int>& A, int K) {
        unordered_map<int, int> mp;
        int left = 0, right = 0, ret = 0;
        while (right < A.size()) {
            ++mp[A[right++]];
            while (mp.size() > K) {
                --mp[A[left]];
                if (mp[A[left]] == 0) mp.erase(A[left]);
                ++left;
            }
            // 如果这里改成 ret = max(ret, right - left)，那么此函数就是 LeetCode 904 题的解：求长度最大的子数组（此子数组中包含不同整数个数最多为K）
            ret += right - left;
        }
        return ret;
    }

    int subarraysWithKDistinct(vector<int>& A, int K) {
        return GetMostDistinct(A, K) - GetMostDistinct(A, K - 1);
    }
};
