class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int a = min(nums[1], nums[2]);
        int b = max(nums[1], nums[2]);

        for (int i = 3; i < nums.size(); i++) {
            if (nums[i] < a) {
                b = a;
                a = nums[i];
            } else if (nums[i] < b) {
                b = nums[i];
            }
        }
        return nums[0] + a + b;
    }
};
