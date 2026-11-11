class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
       
        int i = 0;
        while(i<n){
            if(bits[i] == 0){
                i++;
                continue;
            }
            else{
                if(i+1 == n-1) return false;
                i = i+2;
            }
        }
        return true;
    }
};