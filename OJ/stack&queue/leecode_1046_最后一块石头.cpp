/*************************************************************************
	> File Name: leecode_1046_最后一块石头.cpp
	> Author: 
	> Mail: 
	> Created Time: 三 12/30 09:31:56 2020
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];
        
        priority_queue<int> Q;
        for(int i:stones){
            Q.push(i);
        }
        int first, second;
        while(Q.size() >= 2) {
            first = Q.top();Q.pop();
            second = Q.top();Q.pop();
            if( first - second)
                Q.push(first - second);
        }
        if(Q.size() == 1)
            return Q.top();
        else
            return 0;
        

    }
};
