//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int mcm(int i, int j, int arr[],vector<vector<int>> &dp) {
        if(i == j) return 0;
        int  ans= 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i; k< j; k++) {
            int step = arr[i-1]* arr[k]*arr[j] + mcm(i, k ,arr,dp) +mcm(k+1, j, arr,dp);
            if(step <0) step =INT_MAX;
            ans = min(ans, step);
        }
        
        return dp[i][j] = ans;
    }

    
    int matrixMultiplication(int N, int arr[])    {
        vector<vector<int>> dp(N,vector<int>(N ,-1));
        
        return mcm(1, N-1, arr, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends