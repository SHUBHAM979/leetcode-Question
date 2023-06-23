//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int reccu(int i, int w, int val[], int wt[], int n, vector<vector<int>> & dp) {
        if( i == n) {
            return 0;
        }
        if(dp[i][w] != -1) return dp[i][w];
        int x = 0 + reccu(i+1, w, val, wt ,n,dp);
        if(w >= wt[i]) {
            x = max(x , val[i] + reccu(i+1, w - wt[i], val, wt, n,dp));
        }
        return dp[i][w] = x;
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n, vector<int>(W+1, 0));
      // return reccu(0,W,val, wt,n, dp);
      for(int j=0; j <=W;j++) {
          if(j < wt[0]) {
              dp[0][j] =0;
          }else {
              dp[0][j]= val[0];
              //cout << "hello";
          }
      }
      for(int i =1; i <n ; i++) {
          for(int j =0; j <=W; j++) {
              int x = 0 + dp[i-1][j];
                if(j >= wt[i]) {
                    x = max(x , val[i] + dp[i-1][ j - wt[i]]);
                }
                dp[i][j]= x;
          }
      }
      
    //   for(int i=0; i< n; i++) {
    //       for(int j=0; j<=W; j++) {
    //           cout << dp[i][j] << " ";
    //       }
    //       cout << "\n";
    //   }
      return dp[n-1][W];
      
      
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends