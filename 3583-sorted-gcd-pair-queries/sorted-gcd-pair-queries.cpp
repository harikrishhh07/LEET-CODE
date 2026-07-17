class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> cnt(maxVal + 1, 0);
        for (int x : nums) cnt[x]++;

        vector<long long> freq(maxVal + 1, 0);
        for (int v = 1; v <= maxVal; v++)
            for (int m = v; m <= maxVal; m += v)
                freq[v] += cnt[m];

        vector<long long> exact(maxVal + 1, 0);
        for (int v = maxVal; v >= 1; v--) {
            exact[v] = freq[v] * (freq[v] - 1) / 2;
            for (int m = 2 * v; m <= maxVal; m += v)
                exact[v] -= exact[m];
        }

        vector<long long> prefix(maxVal + 1, 0);
        for (int v = 1; v <= maxVal; v++)
            prefix[v] = prefix[v - 1] + exact[v];

        vector<int> res;
        for (long long q : queries) {
            int lo = 1, hi = maxVal;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (prefix[mid] > q) hi = mid;
                else lo = mid + 1;
            }
            res.push_back(lo);
        }
        return res;
    }
};