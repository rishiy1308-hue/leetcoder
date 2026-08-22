class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i = 0;i<ans.size();i++){
            int cnt = 0;
            int temp = i;
            while(temp>0){
                int bit = temp&1;
                if(bit == 1) cnt++;
                temp = temp>>1;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};