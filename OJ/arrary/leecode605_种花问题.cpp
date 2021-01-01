/*************************************************************************
	> File Name: leecode605_种花问题.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  1/ 1 15:13:39 2021
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    int ans = 0;
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if( n == 0 ) return true;
        flowerbed.insert(flowerbed.begin(),0); //头尾插0
        flowerbed.push_back(0);
      
        int start = 0;
        for(int i = 0;  i < flowerbed.size(); i++) {
            int count = 0;  //记录0个数
            
            while( i + count < flowerbed.size() && flowerbed[i+count] == 0){ 
                count++;
            }
            
            if(count >= 3) ans += ((count + 1 )/ 2) -1;
            i += count;
        }
        return ans >= n;
        
    }
};



class Solution {
public:
    int ans = 0;
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if( n == 0 ) return true;
        flowerbed.insert(flowerbed.begin(),0); //头尾插0
        flowerbed.push_back(0);

        int start = 0;
        //三个0 就多跳一个，插一个树
        for(int i = 0;  i < flowerbed.size() - 2; i++) {
           if(flowerbed[i] == 0 && flowerbed[i+1] == 0 && flowerbed[i+2] == 0) {
                n--;
                i++; //再跳一格
            }
            if(n == 0) return true;
        }
        return false;

    }
};
