class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> split;
        for(int i=0; i< weights.size()-1;i++) {
            split.push_back(weights[i]+weights[i+1]);
        }
        sort(split.begin(), split.end());
        long long minsum = 0;
        long long maxsum=0;
        for(int i=0; i< k-1; i++) {
            minsum += split[i];
            maxsum += split[split.size() -1 -i];
        }
        minsum += weights[0] + weights[weights.size()-1];
        maxsum += weights[0] + weights[weights.size() -1];
        
        return maxsum - minsum;
        
    }
};