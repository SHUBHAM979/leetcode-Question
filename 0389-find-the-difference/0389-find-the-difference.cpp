class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> mp;
        for(auto i : s) mp[i]++;
        map<char, int> mp2;
        for(auto i: t) mp2[i]++; 
        for(auto i : mp2) {
            if(i.second != mp[i.first]) return i.first;
        }
        return t[0];
    }
};