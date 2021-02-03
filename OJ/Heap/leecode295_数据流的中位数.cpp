/*************************************************************************
	> File Name: leecode295_数据流的中位数.cpp
	> Author: Yichar
	> Mail: 
	> Created Time: 三  2/ 3 16:13:18 2021
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


class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    void addNum(int num) {
        //一样多，则先入左堆，将左堆顶入右堆
        if(HLmax.size() == HRmin.size()) {
            HLmax.insert(num);
            HRmin.insert(*(HLmax.begin()));
            HLmax.erase(HLmax.begin());
            //此时必然右堆多，先入右堆，然后右堆顶入左堆
            } else {
                HRmin.insert(num);
                HLmax.insert(*(HRmin.begin()));
                HRmin.erase(HRmin.begin());
            }
    }        
    
    double findMedian() {
        if(HLmax.size() != HRmin.size())
            return *(HRmin.begin());
        else 
            return (*(HLmax.begin()) + *(HRmin.begin())) / 2.0;
    }
    //左边大顶堆，从大到小
    //右边小顶堆，从小到大
    multiset<int,greater<int>> HLmax;
    multiset<int,less<int>> HRmin;
};

