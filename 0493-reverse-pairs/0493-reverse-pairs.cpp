class Solution {
    int count =0;
    void mergeSrt(int l , int r ,vector<int> &nums) {
        if(l < r) {
        int p = l + (r-l)/2;
        mergeSrt(l , p, nums);
        mergeSrt(p+1, r, nums);
        merge(l,p,r,nums);
        }
    }
    
    void merge (int l, int p, int r, vector<int>& nums) {
         
        
        vector<int> result;
        int left = l, mid =p, right = mid+1;
        while(left <= p && right <= r ) {
            if(nums[left] > 2LL*nums[right]) {
                count+= p -left+1;
                right++;
            } else {
                left++;
            }
        }
        
        int i = l, j = p+1;
        while(i <= p && j <=r) {
            if(nums[i] <= nums[j]) {
                result.push_back(nums[i]);
                i++;
            } else {
                result.push_back(nums[j]);
                j++;
            }
        }
        while( i <= p) {
            result.push_back(nums[i]);
            i++;
        }
        while(j<=r) {
            result.push_back(nums[j]);
            j++;
        }
        
     
         for (auto k : result) {
             nums[l] = k;
             l++;
         }
        
    }
    
    
public:
    
    
    int reversePairs(vector<int>& nums) {
        vector<int> duplicate = nums;
        mergeSrt(0 , nums.size() -1 , duplicate);
        for(auto i : duplicate) {
            cout << i <<" ";
        }
        return count;
    }
};