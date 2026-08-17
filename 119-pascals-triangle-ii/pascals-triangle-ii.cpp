class Solution {
public:
    long long factorial(int val){
        if(val == 0) return 1;

        return (long long)((long long) val*factorial(val-1));
    }
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        long long curr = 1;
        for(int i = 0;i<=rowIndex;i++){
            res.push_back(curr);
            curr = curr*(rowIndex-i)/(i+1);
        }
        return res;
    }
};