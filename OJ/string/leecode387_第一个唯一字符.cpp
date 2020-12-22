class Solution {
public:
    int record[26] = {0};
    int firstUniqChar(string s) {
        for(char c:s)    
            record[c-'a']++;
        for(int i = 0; i < s.size(); i++){
            if(record[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
