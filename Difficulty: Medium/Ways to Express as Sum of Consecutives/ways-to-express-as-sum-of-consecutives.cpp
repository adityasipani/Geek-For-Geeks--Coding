class Solution {
public:
    int getCount(int n) {
        while ((n & 1) == 0) n >>= 1;   // remove all factors of 2

        int oddDivisors = 1;
        for (int p = 3; 1LL * p * p <= n; p += 2) {
            if (n % p == 0) {
                int cnt = 1;
                while (n % p == 0) {
                    n /= p;
                    cnt++;
                }
                oddDivisors *= cnt;
            }
        }
        if (n > 1) oddDivisors *= 2;

        return oddDivisors - 1;
    }
};