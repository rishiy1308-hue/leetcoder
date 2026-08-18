class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,int> mpp;
        for(int i = 0;i<=(nums.size()-k);i++){
            set<int> st;
            for(int j = i;j<(k+i);j++){
                st.insert(nums[j]);
            }
            for(auto it:st) mpp[it]++;
        }
        int maxi = -1;
        for(auto it:mpp){
            if(it.second == 1) maxi =max(maxi,it.first);
        }
        return maxi;
    }
};