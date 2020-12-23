/*************************************************************************
	> File Name: leecode435_无重叠区间.cpp
	> Author: 
	> Mail: 
	> Created Time: 三 12/23 11:27:47 2020
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int count = 1;
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int  cut = intervals[0][1]; //分割点
        for(int i = 1; i < intervals.size() ; i++){
            if( cut <= intervals[i][0]){  //如果分割点比下个区间左小，则非交叉
                cut = intervals[i][1];  //更新分割点为下一个区域的右
                count++;
            }
            
        }
        return intervals.size() - count;
    }
};
