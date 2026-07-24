class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXV = 2048; 
        vector<char> present(1501, 0);
        for (int x : nums) present[x] = 1;
        vector<int> D;
        for (int v = 1; v <= 1500; v++)
            if (present[v]) D.push_back(v);

        bitset<MAXV> pairXor;
        for (int a : D)
            for (int b : D)
                pairXor[a ^ b] = 1;

        bitset<MAXV> result;
        for (int v = 0; v < MAXV; v++) {
            if (pairXor[v]) {
                for (int c : D)
                    result[v ^ c] = 1;
            }
        }
        return result.count();
    }
};