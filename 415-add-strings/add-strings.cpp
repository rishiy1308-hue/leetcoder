class Solution {
public:
    string addStrings(string num1, string num2) {

        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int carry = 0;

        string ans = "";

        while(end1 >= 0 && end2 >= 0) {

            int i = (num1[end1] - '0') +
                    (num2[end2] - '0') + carry;

            ans.push_back((i % 10) + '0');
            carry = i / 10;

            end1--;
            end2--;
        }

        // num1 still has digits
        while(end1 >= 0) {

            int i = (num1[end1] - '0') + carry;

            ans.push_back((i % 10) + '0');
            carry = i / 10;

            end1--;
        }

        // num2 still has digits
        while(end2 >= 0) {

            int i = (num2[end2] - '0') + carry;

            ans.push_back((i % 10) + '0');
            carry = i / 10;

            end2--;
        }

        // If carry is still left
        if(carry > 0) {
            ans.push_back(carry + '0');
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};