/*************************************************************************
	> File Name: leecode_1282.cpp
	> Author: 
	> Mail: 
	> Created Time: 五 12/25 11:24:13 2020
 ************************************************************************/

#include<iostream>
class Solution {
public:
    vector<vector<int>> ans;
    struct node{
        int Gtype;
        int num;
        bool operator<(node& a){
            return this->Gtype < a.Gtype;
        }
    };
    vector<node> People;
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        for(int i = 0; i < groupSizes.size(); i++){
            People.push_back({groupSizes[i],i});
        }
        sort(People.begin(),People.end());
        vector<int> temp;
        for(int i = 0; i < People.size(); i++) {
            int T = People[i].Gtype;
            if (temp.size() != T) {
                temp.push_back(People[i].num);}
            if(temp.size() == T)
            {   ans.push_back(temp);
                        temp.clear();
            }

        }

        return ans;
    }
};
