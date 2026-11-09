class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int> mpp;
        int cnt = 0;
        for(int i = 0;i<jewels.size();i++){
            mpp[jewels[i]]++;
        }
        for(int i = 0;i<stones.size();i++){
            if(mpp.find(stones[i])!=mpp.end()) cnt++;
        }
        return cnt;
    }
};