class Solution {
public:
    int findComplement(int num) {
        int bits = log2(num) + 1;
        long long mask = (1LL << bits) - 1;

        return (~num) & mask;
    }
};