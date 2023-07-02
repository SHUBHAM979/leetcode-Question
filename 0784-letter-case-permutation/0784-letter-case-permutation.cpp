class Solution {
public:
    void rec(int i , string s, set<string>& ans, string minians) {
        if(i == s.size()) {
            ans.insert(minians);
            return;
        }
        char it = s[i];
        string m = minians;
        m += tolower(it);
        
        rec(i+1,s , ans, m );
        minians += toupper(it);
        rec(i+1,s,ans, minians);
        
    }
    
    vector<string> letterCasePermutation(string s) {
        set<string> ans;
        rec(0 ,s , ans, "");
        vector<string> rans;
        for(auto i : ans) {
            rans.push_back(i);
        }
        
        return rans;
        
    }
};