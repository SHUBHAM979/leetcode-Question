class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.000;
        int k = abs(n);
        double ans =x ;
        int count = 0;
       double dummy =1;
        while(k>1) {
            if(k%2 ==1 ) {
                k--;
               dummy*=ans;
            }
            ans *=ans;
            
            k/=2;
        }
       ans *=dummy;
        
        if(n < 0) {
            ans = 1/ans;
        }
        return ans;
        
        
    }
    
    
};