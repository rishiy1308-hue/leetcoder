class Solution {
public:
    bool checkPerfectNumber(int num) {
        int i = 1;
        int cnt = 0;
        while(i<=num/2){
            if(num%i == 0){
                cnt += i;
            }
            i++;
        }
        if(cnt == num) return true;
        return false;
    }
};