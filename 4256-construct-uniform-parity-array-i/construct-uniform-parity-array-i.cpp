class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1[0]%2;
        bool flag = true;
        for(int i = 0;i<nums1.size();i++){
            if(nums1[i]%2!=n){
                flag = false;
                break;
            }
        }
        if(flag) return true;
        return true;
    }
};