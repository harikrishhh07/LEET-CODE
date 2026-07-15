class Solution {
public:
    long long gcdOfOddEvenSums(long long n) {
        return __gcd(n * n, n * (n + 1));
    }
};