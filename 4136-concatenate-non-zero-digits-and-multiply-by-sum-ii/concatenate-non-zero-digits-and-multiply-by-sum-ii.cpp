class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1000000007;

        string t;
        vector<int> pos;
        vector<long long> digitPrefix(1, 0);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                t.push_back(s[i]);
                pos.push_back(i);
                digitPrefix.push_back(digitPrefix.back() + (s[i] - '0'));
            }
        }

        int m = t.size();

        vector<long long> pow10(m + 1, 1), pref(m + 1, 0);

        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int i = 0; i < m; i++)
            pref[i + 1] = (pref[i] * 10 + (t[i] - '0')) % MOD;

        vector<int> nxt(s.size(), m), prv(s.size(), -1);

        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            while (j < m && pos[j] < i) j++;
            nxt[i] = j;
        }

        j = m - 1;
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            while (j >= 0 && pos[j] > i) j--;
            prv[i] = j;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = nxt[q[0]];
            int r = prv[q[1]];

            if (l > r || l == m || r == -1) {
                ans.push_back(0);
                continue;
            }

            int len = r - l + 1;

            long long num = (pref[r + 1] - pref[l] * pow10[len]) % MOD;
            if (num < 0) num += MOD;

            long long sum = digitPrefix[r + 1] - digitPrefix[l];

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};