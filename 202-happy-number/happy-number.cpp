class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1) {
            if (seen.count(n))
                return false;

            seen.insert(n);

            int val = 0;

            while (n > 0) {
                int mod = n % 10;
                val += mod * mod;
                n /= 10;
            }

            n = val;
        }

        return true;
    }
};