class Solution {
public:
    vector<int> constructRectangle(int area) {
        if(area == 1){
            return {1,1};
        }
        int l = 1;
        int mini = INT_MAX;
        vector<int> ans;
        while(l<= area/2){
            if(area%l == 0){
                int w = area/l;
                if(abs(w-l)<mini){
                    mini = abs(w-l);
                    ans.clear();
                    ans.push_back(l);
                    ans.push_back(w);
                }
            }
            l++;
        }
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        return ans;
    }
};