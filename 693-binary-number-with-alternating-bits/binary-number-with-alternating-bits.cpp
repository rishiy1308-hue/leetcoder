class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit = n%2;
        int cnt = 0;
        while(n>0){
            int biit = n%2;
            if(biit == bit){
                cnt++;
                if(cnt>1) return false;
            }
            else{
                cnt--;
                if(cnt<0) return false;
            }
            n = n/2;
        }
        return true;
    }
};