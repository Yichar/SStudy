class Solution {
public:
    double func(double x,int n){
        if ( n == 0 )
            return 1;
         double t = myPow(x,n/2);
        if(n % 2 == 0)
            return t * t;
        else
            return x * t * t;
    }
    double myPow(double x, int n) {
        if(n > 0)
            return func(x,n);
        if(n < 0)
            return 1.0/func(x,-(n+1))/x; //防止n溢出
        else 
            return 1;
       
    }
};
