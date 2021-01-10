/*************************************************************************
	> File Name: debug.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  1/10 11:50:44 2021
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> ans;
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) return ans;
        int start = nums[0];
        string temp = "";
        temp += start + '0';
         for (int i = 0; i < nums.size(); i++) {
            if ( nums[i] == nums[i-1]) continue;
            else {
                if (nums[i] == start)
                    cout << start << endl;
                else  {
                    cout << start << "->" << nums[i] << endl;
                    if (i< nums.size()) start = nums[i+1];
                    else break;
                }
            } 
             
         }
       // cout << temp;
    return ans;
        }
    
};
int main() {
    int nums[] = {0,2,3,4,6,8,9};
    Solution solution;
    Solution.summaryRanges(nums) ;
}
