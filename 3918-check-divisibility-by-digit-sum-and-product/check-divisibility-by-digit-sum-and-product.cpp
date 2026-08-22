class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int sum = 0;
        while(temp>0){
            int mod = temp%10;
            sum+=mod;
            temp = temp/10;
        }
        temp = n;
        int prod = 1;
        while(temp>0){
            int mod = temp%10;
            prod *= mod;
            temp = temp/10;
        }
        int ans = sum + prod;
        if(n%ans == 0) return true;
        return false;
    }
};