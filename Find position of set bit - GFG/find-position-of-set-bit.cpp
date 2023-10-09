//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int n) {
        int count =0, ans, i =0;
        while(n !=0) {
            i++;
            if(n & 1 ==1 ) {
                ans = i;
                count++;
            }
            n >>=1;
        }
        if(count ==0 || count >=2)
        return -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends