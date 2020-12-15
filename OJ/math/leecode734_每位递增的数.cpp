class Solution {
public:
    
    
    int monotoneIncreasingDigits(int N) {
       int num = 111111111;
       int ans = 0 ;
       for(int i = 1; i <= 9; i++) {
           while( num + ans > N && num) {
               num /= 10;
           }
           ans += num;
       }
            
        return ans;
        
    }
};
