class Solution {
public:
    void rec(int i,string s, string minians, vector<string> &ans){
//         if(index==s.length()){
//             ans.emplace_back(temp);
//             return;
//         }
//         if(!isdigit(temp[index])){
//           temp[index] = toupper(temp[index] );
//           backtrack(index+1, s, temp, ans);
//           temp[index] = tolower(temp[index]);
//           backtrack(index+1, s, temp, ans);
//         } else {
// backtrack(index+1, s, temp, ans);
//         }
        
        
        if(i == s.size()) {
            ans.push_back(minians);
            return;
        }
        if(isdigit(s[i])) {
            minians.push_back(s[i]);
            rec(i+1, s, minians,ans);
            return;
        }
        
        char it = s[i];
        string m = minians;
        m += tolower(it);
        
        rec(i+1,s , m,ans );
        minians += toupper(it);
        rec(i+1,s, minians, ans);
        
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ANS;
        rec(0,s, "", ANS);
        return ANS;
    }
};