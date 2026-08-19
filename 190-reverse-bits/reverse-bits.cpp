class Solution {
public:
    int reverseBits(int n) {
        vector<int> byt(32,0);
        int i = 31;
        while(n>0){
            int mod = n%2;
            byt[i] = mod;
            i--;
            n = n/2;
        }
        reverse(byt.begin(),byt.end());
        long long ans = 0;
        long long prod = 1;
        for(int j = 31;j>=0;j--){
            ans += (byt[j]*prod);
            prod*=2;
        }
        return (int)ans;
    }
};