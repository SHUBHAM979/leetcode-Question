class Solution {
public:
     bool feasible(vector<int>& weights, int c, int days) {
        int daysNeeded = 1, currentLoad = 0;
        for (int weight : weights) {
            currentLoad += weight;
            if (currentLoad > c) {
                daysNeeded++;
                currentLoad = weight;
            }
        }

        return daysNeeded <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = -1;
        long long sum =0;
        for(auto i : weights) {
            maxi = max(i,maxi);
            sum += i;
        }
        while( maxi < sum) {
            int mid = maxi + (sum - maxi)/2;
            if(feasible(weights, mid ,days)) {
                sum = mid;
            } else {
                maxi = mid+1;
            }
        }
        return maxi;
        
        
    }
};