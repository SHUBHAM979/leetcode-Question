//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
vector<int> ans;

    void rec(int i, int sum ,vector<int> arr, int N) {
        if(i ==N) { ans.push_back(sum);

        return ;
        }        
        rec(i+1, sum + arr[i], arr, N);
        rec(i+1,sum, arr,N);
        
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        
         rec(0,0, arr,N);
         return ans;
        // Write Your Code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends