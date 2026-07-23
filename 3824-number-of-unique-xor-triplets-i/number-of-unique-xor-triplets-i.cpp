class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return n;
        int x = 31 - __builtin_clz(n); // floor(log2(n))
        return 1 << (x + 1);
    }
};