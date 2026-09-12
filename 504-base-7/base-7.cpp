class Solution {
public:
    string convertToBase7(int num) {
        int n = abs(num);
        string ans = "";
        if(n == 0) return "0";
        while(n>0){
            int mod = n%7;
            ans.push_back(mod + '0');
            n = n/7;
        }
        if(num<0) ans.push_back('-');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};