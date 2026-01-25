class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int index, vector<int>& candidates, int target, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            temp.push_back(candidates[i]);
            dfs(i + 1, candidates, target - candidates[i], temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        dfs(0, candidates, target, temp);
        return ans;
    }
};
