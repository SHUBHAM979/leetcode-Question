class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> vt;
        for(int i=0; i< profits.size(); i++) {
            vt.push_back(make_pair(capital[i],profits[i]));
        }
        
        sort(vt.begin(), vt.end());
        
        priority_queue<int> pq;
        int ptr =0;
        for(int i =0; i<k; i++) {
            while(ptr<profits.size() && vt[ptr].first<=w) {
                pq.push(vt[ptr].second);
                ptr++;
            }
            if(pq.empty()) break;
            w += pq.top();
             pq.pop();
        }
      return w;
        
        
        
    }
};