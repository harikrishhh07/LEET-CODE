class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> freq(26, 0);
        for (string &word : words) {
            for (char c : word) {
                freq[c - 'a']++;
            }
        }
        for (int count : freq) {
            if (count % n != 0) {
                return false;
            }
        }

        return true;
    }
};