class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int  n = nums.size();
        
        vector<string> res;
        if(n==0) return res;
        string x =to_string(nums[0]) ,y;
        bool flag = false;
        for(int i =1; i<n ; i++) {
            if( nums[i] == nums[i-1] +1) {
                continue;
            }else  {
                y = to_string(nums[i-1]);
                string ans = x + "->"+y;
                cout << ans;
               
                    
                if(x == y) res.push_back(x);
                else
                    res.push_back(ans);
                x = to_string(nums[i]);
                if(i == n-1) {
                    res.push_back(x);
                    cout << x;
                    flag = true;
                }
            } 
            
        }
        if(!flag)  {
             y = to_string(nums[n-1]);
             string ans = x + "->"+y;
            if(x == y) res.push_back(x);
            else
            res.push_back(ans);
        }
        return res;
        
    }
};