class Solution {
public:
   
  static  bool compareSecondElement(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareSecondElement);
        int k =INT_MIN , ans =0;
        for(auto i : intervals) {
            if(i[0] >= k) {
                k = i[1];
            } else ans++;
        }
        return ans;
    }
};