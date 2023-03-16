class Solution {
public:
     int reverse(int x) {
        
        string l ="";
        string result = to_string(x);
        int i=0;
        if(result[i] == '-') {
            i++;
            l ='-' +l;
        }
        int j=result.size()-1;
        while(j>=i) {
            l += result[j];
            j--;
        }
        long long  r = stol(l);
        cout << r;
        if( r< -2147483648||r > 2147483647) return 0;
        return r;
        
    }
};