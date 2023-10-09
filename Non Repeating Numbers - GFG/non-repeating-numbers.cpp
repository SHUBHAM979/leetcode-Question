//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int Xor = 0;
        for(auto i : nums) {
            Xor ^= i;
        }
        int setBit =0;
        while(Xor !=0) {
            if(Xor & 1 == 1) break;
            setBit++;
            Xor >>=1;
        }
        int l = 0, r=0;
        for(auto i : nums) {
            if(i >> setBit & 1 == 1) {
                l^=i;
            }else {
                r^=i;
            }
        }
        if( l <r)
        return {l,r};
        return {r,l};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends