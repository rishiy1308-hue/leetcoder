class Solution {
public:
    string reverseVowels(string s) {
        stack<char> st;
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                st.push(s[i]);
                s[i] = '#';
            }
            else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                st.push(s[i]);
                s[i] = '#';
            }
        }
        if(st.empty()) return s;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '#'){
                s[i] =st.top();
                st.pop();
                
            }
            else continue;
        }
        return s;
    }
};