class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int min_n =INT_MAX, res =INT_MAX;
        for(auto i : nums) {
            i = i%2 ==0 ? i : i*2;
            pq.push(i);
            min_n = min(min_n, i);
        }
        
        while(pq.top()%2 == 0) {
            int n = pq.top();
            pq.pop();
            pq.push(n/2);
            res = min(res, n - min_n);
            min_n = min(min_n, n/2);
        }
        return min(pq.top()-min_n, res);
        
    }
};