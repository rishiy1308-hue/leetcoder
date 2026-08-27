class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> mpp;
        for(int i = 0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(int i = 0;i<t.size();i++){
            if(mpp[t[i]] == 0) return t[i];
                mpp[t[i]]--;
        }
        return '\0';
    }
};