class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        int ans = 0;
        while(num>0){
            int mod = num%10;
            ans = ans + mod;
            num = num/10;
            if(num == 0 && ans/10 !=0 ){
                num = ans;
                ans = 0;
            } 
        }
        return ans;
    }
};