class Solution {
public:
    bool checkRecord(string s) {
        int absentee = 0;
        int n =s.size();
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'A') absentee++;
            if(s[i] == 'L'){
                if(i+1 < n && i+2<n && s[i+1] == 'L' && s[i+2] == 'L') return false;
            }
        }
        if(absentee >=2) return false;
        return true;
    }
};