class Solution {
public:
     int left_search(vector<int> nums,int len,int target){
            int l = 0, r = len-1;
            while( l != r ) {
                int mid = (l+r)/2;
                if(nums[mid]<target)
                    l = mid + 1;
                else
                    r = mid;   }
            return nums[l]==target?l:-1; //如果没找到就返回-1
        }
        int right_search(vector<int> nums,int len,int target) {
            int l = 0, r = len-1;
            while( l != r ){
                int mid =(l+r+1)/2; //右边界+1处理
                if(nums[mid] > target)
                    r = mid - 1;
                else
                    l = mid;    }
            return nums[l]==target?l:-1;
        }
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0) return {-1,-1};
        int L=left_search(nums,len,target);
        int R=right_search(nums,len,target);
        return {L,R};
    }
};
