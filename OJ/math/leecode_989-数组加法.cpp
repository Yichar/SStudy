/*

输入：A = [1,2,0,0], K = 34
输出：[1,2,3,4]
解释：1200 + 34 = 1234



*/



class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
      reverse(A.begin(),A.end());
      int index = 0;
      while(K){
          if(index < A.size()){
              K = K + A[index];
              A[index] = K % 10;
          } else {
             A.push_back(K % 10);
          }
          index++;
          K = K / 10;
         }
      reverse(A.begin(),A.end());
      return A;
    }
    
};

