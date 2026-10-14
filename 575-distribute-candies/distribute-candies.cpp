class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(),candyType.end());
        int type = 0;
        int n = candyType.size();
        for(int i = 0;i<n;i++){
            if(i==0){
                type++;
            }
            else if(candyType[i] == candyType[i-1]) continue;
            else{
                if(type<n/2) type++;
            }
        }
        return type;
    }
};