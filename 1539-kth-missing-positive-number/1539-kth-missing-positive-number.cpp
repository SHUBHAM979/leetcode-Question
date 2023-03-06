class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int miss =0;
        int ans=1;
        int prev = ans;
        for(int i=0; i< arr.size() && miss < k ;i++, ans++) {
            while(ans != arr[i] && miss < k) {
               prev = ans;
                cout << ans << " ";
                ans++;
                miss++;
                
            }
            
        }
        ans--;
        if(miss <k)  prev = ans + k-miss;
        return prev;
        
    }
};