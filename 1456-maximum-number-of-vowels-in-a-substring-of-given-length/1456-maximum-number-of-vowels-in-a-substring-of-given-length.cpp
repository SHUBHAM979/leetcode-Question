class Solution {
public:
    int maxVowels(string s, int k) {
        int count =0, window =0, ans = 0;
        set<char> vowels({'a','i','o','u','e'});
        for(int i =0; i < s.length();i++) {
            if(window < k) {
                window++;
                if(vowels.count(s[i])) count++;
                continue;
            } else {
                ans = max(ans, count);
                if(vowels.count(s[i])) count++;
                if(vowels.count(s[i-k])) count--;
            }
        }
        ans = max(ans, count);
        return ans;
    }
};