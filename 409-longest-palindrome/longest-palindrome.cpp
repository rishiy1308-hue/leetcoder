class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mpp;

        for(int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
        }

        int ans = 0;
        bool odd = false;

        for(auto it : mpp) {
            if(it.second % 2 == 1) {
                ans += it.second - 1;
                odd = true;
            }
            else {
                ans += it.second;
            }
        }

        if(odd)
            ans++;

        return ans;
    }
};