class Solution {
public:
    bool checkDiv(int val,int t){
        int prod=1;
        while(val>0){
            int mod=val%10;
            prod*=mod;
            val=val/10;
        }
        if(prod%t == 0) return true;
        return false;
    }
    int smallestNumber(int n, int t) {
        bool flag = false;
        int val=n;
        while(val<=100 && !flag){
            if(checkDiv(val,t)) flag=true;
            else val++;
        }
        return val;
    }
};