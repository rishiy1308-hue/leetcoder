class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n == 0) return false;

        if(n%4 ==1 || n%4 == 2 || n%4 == 3) return false;
        int temp = n;
        while(temp%4 == 0){
            temp = temp/4;
        }
        if(temp == 1) return true;
        return false;
    }
};