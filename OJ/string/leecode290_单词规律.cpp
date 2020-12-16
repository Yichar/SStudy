class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int start =0;
        vector<string> VS;
        unordered_map<char,string> M1;
        unordered_map<string,char> M2;
        //切分字符串
        for(int i = 0; i < s.size();i++){
                if(s[i] == ' ') {
                    VS.push_back(s.substr(start,i-start));
                    start = i + 1;
                }
                if( i == s.size()-1){
                    VS.push_back(s.substr(start));
                }
        }
        if(pattern.size() != VS.size() ) 
                return false;

        for( int i = 0; i < pattern.size(); i++){
           char temp_char = pattern[i];
           string temp_str = VS[i];
           //出现过的 配对，再次出现的话，必须一致。
           if(M1.count(temp_char) && M1[temp_char] != temp_str)
                return false;
            M1[temp_char] = temp_str;
           if(M2.count(temp_str) && M2[temp_str] != temp_char)
                return false;
            M2[temp_str] = temp_char;
            }
        return true;
      
    }
};