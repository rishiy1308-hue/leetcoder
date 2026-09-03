class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0, even = 0;
        int minEven = INT_MAX, minOdd = INT_MAX;
        for(int i = 0;i<nums1.size();i++){
            if(nums1[i]%2 == 0){
                even++;
                minEven = min(minEven,nums1[i]);
            }
            else{
                odd++;
                minOdd = min(minOdd,nums1[i]);
            }
        }
        if(odd == 0 || odd == nums1.size()) return true;
        bool flag = true;
        for(int i = 0;i<nums1.size();i++){
            if(nums1[i]%2 == 1) continue;
            else{
                if(nums1[i]-minOdd>=1) continue;
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(flag) return true;
        for(int i = 0;i<nums1.size();i++){
            if(nums1[i]%2 == 0) continue;
            else{
                if(nums1[i]-minOdd>=1) continue;
                else return false;
            }
        }
        return true;
    }
};