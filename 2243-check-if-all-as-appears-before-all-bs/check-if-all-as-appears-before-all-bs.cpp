class Solution {
public:
    bool checkString(string s) {
        if(s.size() == 1) return true;
        for(int i = 1;i<s.size();i++){
            if(s[i] == 'a' && s[i-1] == 'b') return false;
            else if(s[i] == 'b'){
                if(i+1<s.size()){
                    if(s[i+1] == 'a') return false;
                }
            }
        }
        return true;
    }
};