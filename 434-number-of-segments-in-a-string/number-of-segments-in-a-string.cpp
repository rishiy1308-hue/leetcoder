class Solution {
public:
    int countSegments(string s) {
        if(s.size() == 0) return 0;
        int cnt = 0;
        for(int i = 0;i<s.size();i++){
            if(i>0 && s[i] == ' ' && s[i-1]!= ' '){
                cnt++;
                continue;
            }
        }
        if(s[s.size()-1] != ' ') {
            cnt++;
        }
        return cnt;
    }
};