class Solution {
public:
    string removeKdigits(string num, int k) {
        // 保存结果
        string res;
        int len = num.size();
        int m = len - k;
        if(len == k){
            return "0";
        }
        for(int i = 0; i < len; i ++){
            // 如果k不为0且res长度不为0且最后的数大于遍历到的数字
            while(k && res.size() && res.back() > num[i]){
                res.pop_back();
                --k;
            }
            res.push_back(num[i]);
        }
        res.resize(m);
        while(!res.empty() && res[0] == '0'){
            res.erase(res.begin());
        }
        if(!res.empty()){
            return res;
        }else{
            return "0";
        }
    }
};

