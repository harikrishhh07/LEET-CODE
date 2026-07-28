class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string firstHalf = s.substr(0, n / 2);
        sort(firstHalf.begin(), firstHalf.end());
        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());
        if (n % 2 == 0) {
            return firstHalf + secondHalf;
        } else {
            char mid = s[n / 2];
            return firstHalf + mid + secondHalf;
        }
    }
};