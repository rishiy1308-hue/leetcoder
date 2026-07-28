class Solution {
public:
    int maxProduct(int n) {
        string s= to_string(n);
        sort(s.begin(),s.end());
        int last=s.size()-1;
        int slast=s.size()-2;
        return (s[last]-'0')*(s[slast]-'0');
    }
};