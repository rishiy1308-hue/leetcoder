class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(int i=0;i<word.size();i++){
            freq[word[i]-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
        int cnt=1;
        int ans=0;
        for(int i=0;i<26;i++){
            if(cnt<=8){
                ans+=freq[i];
                cnt++;
            }
            else if(cnt>8 && cnt<=16){
                ans+=(freq[i]*2);
                cnt++;
            }
            else if(cnt>16 && cnt<=24){
                ans+=(freq[i]*3);
                cnt++;
            }
            else{
                ans+=(freq[i]*4);
            }
        }
        return ans;
    }
};