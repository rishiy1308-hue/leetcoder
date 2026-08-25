class Solution {
public:
    string toHex(int num) {
        unsigned int n = num;
        string ans="";
        if(n == 0) return "0";
        while(n>0){
            int mod = n%16;
            if(mod<=9) ans += '0'+mod;
            else{
                ans += 'a'+(mod-10);
            }
            n=n/16;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};