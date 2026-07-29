#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static constexpr long long MAX_K = 1000001; // Capped value to prevent overflow since k <= 10^6

    // Calculates combinations nCr with capping to avoid integer overflow
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        r = min(r, n - r);
        
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - i + 1) / i;
            if (res >= MAX_K) return MAX_K;
        }
        return res;
    }

    // Counts distinct permutations of the remaining left-half frequencies
    long long countPermutations(const vector<int>& freq) {
        int total = 0;
        for (int f : freq) total += f;

        long long ways = 1;
        for (int f : freq) {
            if (f == 0) continue;
            ways *= nCr(total, f);
            if (ways >= MAX_K) return MAX_K; // Cap at MAX_K
            total -= f;
        }
        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> charCount(26, 0);
        for (char c : s) {
            charCount[c - 'a']++;
        }

        // Determine left-half character frequencies and optional middle character
        vector<int> halfFreq(26, 0);
        char midChar = '\0';
        for (int i = 0; i < 26; ++i) {
            halfFreq[i] = charCount[i] / 2;
            if (charCount[i] % 2 != 0) {
                midChar = 'a' + i;
            }
        }

        // Check total unique permutations available
        long long totalWays = countPermutations(halfFreq);
        if (k > totalWays) {
            return ""; // k exceeds available distinct palindromic rearrangements
        }

        int halfLen = n / 2;
        string leftHalf = "";

        // Build left half character-by-character greedily
        for (int pos = 0; pos < halfLen; ++pos) {
            for (int c = 0; c < 26; ++c) {
                if (halfFreq[c] == 0) continue;

                // Trial placement of character 'a' + c
                halfFreq[c]--;
                long long ways = countPermutations(halfFreq);

                if (ways >= k) {
                    leftHalf += (char)('a' + c);
                    break; // Confirmed current character placement
                } else {
                    k -= ways;
                    halfFreq[c]++; // Backtrack and try next alphabet
                }
            }
        }

        // Construct total palindrome from left half
        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());

        if (midChar != '\0') {
            return leftHalf + midChar + rightHalf;
        }
        return leftHalf + rightHalf;
    }
};