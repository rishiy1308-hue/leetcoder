class Solution {
public:
    bool wordPattern(string pattern, string s) {

        int n = s.size();
        vector<string> cont;
        string ans = "";

        for(int i = 0; i < n; i++) {

            if(s[i] != ' ') {
                ans.push_back(s[i]);
            }

            if(s[i] == ' ') {
                cont.push_back(ans);
                ans = "";
            }

            if(i == n - 1) {
                cont.push_back(ans);
            }
        }

        if(pattern.size() != cont.size())
            return false;

        map<char, string> mpp;
        map<string, char> rev;

        for(int i = 0; i < pattern.size(); i++) {

            // character already exists
            if(mpp.find(pattern[i]) != mpp.end()) {

                if(mpp[pattern[i]] != cont[i])
                    return false;
            }

            // character doesn't exist yet
            else {

                // word is already mapped to another character
                if(rev.find(cont[i]) != rev.end())
                    return false;

                mpp[pattern[i]] = cont[i];
                rev[cont[i]] = pattern[i];
            }
        }

        return true;
    }
};