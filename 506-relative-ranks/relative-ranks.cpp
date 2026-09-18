class Solution { 
public: 
    vector<string> findRelativeRanks(vector<int>& score) { 
        vector<int> num = score; 
        vector<string> ans(score.size()); 
        sort(num.begin(), num.end()); 

        int n = num.size(); 
        map<int,int> mpp; 

        for(int i = 0; i < num.size(); i++){ 
            mpp[num[i]] = n - i; 
        } 

        for(int i = 0; i < score.size(); i++){ 
            if(mpp[score[i]] == 1){ 
                ans[i] = "Gold Medal"; 
            } 
            else if(mpp[score[i]] == 2){ 
                ans[i] = "Silver Medal"; 
            } 
            else if(mpp[score[i]] == 3){ 
                ans[i] = "Bronze Medal"; 
            } 
            else {
                ans[i] = to_string(mpp[score[i]]);
            }
        } 

        return ans; 
    } 
};