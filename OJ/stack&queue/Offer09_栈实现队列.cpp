class CQueue {
public:
    stack<int> S1;
    stack<int> S2;
    CQueue() {

    }
    
    void appendTail(int value) {  
        S1.push(value);
    }
    int deleteHead() {
        if(S1.empty() && S2.empty()) 
            return -1;
        if( S2.empty()) {   //out 栈如果 是空的，要从in 栈 取
            while(!S1.empty()) {
                S2.push(S1.top());
                S1.pop();
            }
        }
        //此时一定有元素
        int ans= S2.top() ;
        S2.pop();
        return ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */