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



class Solution {
public:
    //不翻转A的做法
    vector<int> addToArrayForm(vector<int>& A, int K) {
        if(K == 0) return A;
        int lenK = (int)log10(K) + 1;
        int lenA = A.size();
        int end = 0;
        if (lenA >= lenK)
            end = lenA  - lenK;
        for (int i = A.size() - 1 ; i >= end; i--) {
            A[i] += K % 10;
            K /= 10;
        }
        while(K) {
            A.insert(A.begin(),K % 10);
            K /= 10;
        }
        for (int i = A.size() - 1; i >= 0; i--) {
            if (A[i] >= 10 && i > 0) {
                A[i - 1] += A[i] / 10;
                A[i] %= 10;
            } else if(A[i] >= 10 && i == 0) {
                A.insert(A.begin(),A[i] / 10);
                A[1] %= 10;
            }
        }
        return A;
    }
};
