class Solution {
public:
    int getLastDigit(string& a, string& b) {
        // a^0 = 1
        if (b == "0")
            return 1;

        int base = a.back() - '0';

        // Compute b % 4
        int exp = 0;
        for (char ch : b) {
            exp = (exp * 10 + (ch - '0')) % 4;
        }

        // If divisible by 4, use 4 (cycle length)
        if (exp == 0)
            exp = 4;

        int result = 1;

        // Compute base^exp % 10
        while (exp--) {
            result = (result * base) % 10;
        }

        return result;
    }
};