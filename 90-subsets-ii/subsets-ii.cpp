class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int index, vector<int>& nums, vector<int>& temp) {
        ans.push_back(temp);
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            dfs(i + 1, nums, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        dfs(0, nums, temp);
        return ans;
    }
};
