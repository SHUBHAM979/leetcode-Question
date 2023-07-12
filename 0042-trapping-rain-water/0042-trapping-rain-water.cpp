class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        vector<int> left(n), right(n);
        int lmaxi = INT_MIN , rmaxi =INT_MIN;
        
        for(int i=0; i< n; i++) {
            lmaxi = max(lmaxi, height[i]);
            left[i] = lmaxi;
            
            rmaxi = max(rmaxi, height[n-1-i]);
            right[n-1-i] = rmaxi;
            
        }
        
        int ans =0;
        for(int i=0; i< n; i++) {
            ans += min(left[i] , right[i]) -height[i];
        }
        
        return ans;
    }
};