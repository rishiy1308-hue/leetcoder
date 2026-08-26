class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> ans;
        bool flag = false;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '1'){
                int cnt = 0;
                string res = "";
                for(int j = i;j<s.size();j++){
                    res.push_back(s[j]);
                    if(s[j] == '1'){
                        cnt++;
                        if(cnt == k){
                            flag = true;
                            break;
                        }
                    }
                }
                if(flag){
                    ans.push_back(res);
                    flag = false;;
                }
            }
            else continue;
        }
        if(ans.size() == 0) return "";
        int mini = ans[0].size();
        string fin =ans[0];
        for(int i = 1;i<ans.size();i++){
            if(ans[i].size() < mini ||
   (ans[i].size() == mini && ans[i] < fin)){
    mini = ans[i].size();
    fin = ans[i];
}
        }
        return fin;
    }
};