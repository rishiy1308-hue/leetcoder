class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        int last = -1;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {
                st.push(i);
            }
            else {
                if(!st.empty()) {
                    st.pop();

                    if(!st.empty()) {
                        ans = max(ans, i - st.top());
                    }
                    else {
                        ans = max(ans, i - last);
                    }
                }
                else {
                    last = i;
                }
            }
        }

        return ans;
    }
};