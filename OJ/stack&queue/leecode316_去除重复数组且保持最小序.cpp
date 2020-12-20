class Solution {
public:
    int count[26] = {0};
    int check[26] = {0}; //标记栈内是否有该字符
    stack<char> S;
    string removeDuplicateLetters(string s) {
        string ans;
        for(char c:s){
            count[c-'a']++;
        }
       for(char c:s) {
           count[c-'a']--;
            if( check[c-'a'] == 1) //已经有了，就自动忽略
                continue;
            while(!S.empty() && c < S.top() ){  //栈非空，且当前字符更小
                if(count[S.top() - 'a'] == 0) break; //如果是最后一个当前字符，不能去掉
                else{  //否则丢掉
                    check[S.top() - 'a'] = 0;
                    S.pop();
                }
            }
            S.push(c);
            check[c-'a'] = 1;
        }
        while(!S.empty()){
            ans += S.top();
            S.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
