class Solution {
public:
    int sums(vector<int> nums){
        int ans = 0;
        for(int i:nums){
            ans += i;
        }
        return ans;
    }
    int candy(vector<int>& ratings) {
        vector<int> nums(ratings.size(),1);
        //从前往后，找右大于左
        for(int i = 1; i <nums.size() ; i++){
            if(ratings[i] > ratings[i -1])
                nums[i] = nums[i-1] + 1;
        }
        //从后往前遍历，找左大于右
        for(int i = nums.size() - 2; i >= 0; i--){
            if(ratings[i] > ratings[i+1])
                 nums[i] = max(nums[i+1] + 1,nums[i]); //要比右边大
                
        }
        return sums(nums);
    }
};
