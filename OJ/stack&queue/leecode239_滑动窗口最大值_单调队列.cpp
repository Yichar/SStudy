class Solution {
private:
    class Myqueue {
        public:
            deque<int> que;
            //只有当出队的元素和头相等才删除
            void pop(int value) {
                if( !que.empty() && que.front() == value)
                    que.pop_front();
            }
            //如果入队元素比队尾大，就删除队尾，重复之
            void push(int value) {
                while( !que.empty() && value > que.back()) {
                    que.pop_back();
                }
                que.push_back(value);
            }
            //队首就是当前窗口最大值
            int front() {
                return que.front();
            }
    };
public:
    Myqueue MQ;
    vector<int> ans;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        for(int i = 0; i < k; i++) 
            MQ.push(nums[i]);
        ans.push_back(MQ.front());
        for(int i = k; i < nums.size(); i++) {
            MQ.pop(nums[i-k]);
            MQ.push(nums[i]);
            ans.push_back(MQ.front());
        }
        return ans;
    }
};
