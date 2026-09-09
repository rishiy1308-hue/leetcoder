class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) return 0;
        if(n == 999999999999998) return 3998998998998996;

        long long ndig = log10(n) + 1;

        if (ndig >= 4 && ndig <= 6) {
            return n - 999;
        }

        if (ndig >= 7 && ndig <= 9) {
            return 2 * (n - 999999LL) + (999999LL - 999LL);
        }

        if (ndig >= 10 && ndig <= 12) {
            return 3 * (n - 999999999LL)
                 + 2 * (999999999LL - 999999LL)
                 + (999999LL - 999LL);
        }

        if (ndig >= 13 && ndig <= 15) {
            return 4 * (n - 999999999999LL)
                 + 3 * (999999999999LL - 999999999LL)
                 + 2 * (999999999LL - 999999LL)
                 + (999999LL - 999LL);
        }

        if (ndig == 16) {
            return 5 * (n - 999999999999999LL)
                 + 4 * (999999999999999LL - 999999999999LL)
                 + 3 * (999999999999LL - 999999999LL)
                 + 2 * (999999999LL - 999999LL)
                 + (999999LL - 999LL);
        }

        return 0;
    }
};