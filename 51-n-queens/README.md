<h2><a href="https://leetcode.com/problems/n-queens">N-Queens</a></h2> <img src='https://img.shields.io/badge/Difficulty-Hard-red' alt='Difficulty: Hard' /><hr><p>The <strong>n-queens</strong> puzzle is the problem of placing <code>n</code> queens on an <code>n x n</code> chessboard such that no two queens attack each other.</p>

<p>Given an integer <code>n</code>, return <em>all distinct solutions to the <strong>n-queens puzzle</strong></em>. You may return the answer in <strong>any order</strong>.</p>

<p>Each solution contains a distinct board configuration of the n-queens&#39; placement, where <code>&#39;Q&#39;</code> and <code>&#39;.&#39;</code> both indicate a queen and an empty space, respectively.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/queens.jpg" style="width: 600px; height: 268px;" />
<pre>
<strong>Input:</strong> n = 4
<strong>Output:</strong> [[&quot;.Q..&quot;,&quot;...Q&quot;,&quot;Q...&quot;,&quot;..Q.&quot;],[&quot;..Q.&quot;,&quot;Q...&quot;,&quot;...Q&quot;,&quot;.Q..&quot;]]
<strong>Explanation:</strong> There exist two distinct solutions to the 4-queens puzzle as shown above
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> [[&quot;Q&quot;]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 9</code></li>
</ul>

Solution:

class Solution {
public:
    // Stores all valid board configurations
    vector<vector<string>> ans;

    // Current chessboard
    vector<string> board;

    // Helper arrays for fast safety checks
    vector<int> col;    // checks column conflicts
    vector<int> diag1;  // checks main diagonal (\)
    vector<int> diag2;  // checks anti-diagonal (/)

    // Backtracking function to place queens row by row
    void solve(int row, int n) {
        // If all rows are filled, we found a valid solution
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try placing a queen in each column of the current row
        for (int c = 0; c < n; c++) {

            // If column or diagonals are already occupied, skip
            if (col[c] || diag1[row + c] || diag2[row - c + n - 1])
                continue;

            // Place queen at (row, c)
            board[row][c] = 'Q';

            // Mark column and diagonals as occupied
            col[c] = 1;
            diag1[row + c] = 1;
            diag2[row - c + n - 1] = 1;

            // Recur for the next row
            solve(row + 1, n);

            // Backtrack: remove the queen
            board[row][c] = '.';
            col[c] = 0;
            diag1[row + c] = 0;
            diag2[row - c + n - 1] = 0;
        }
    }

    // Main function called by LeetCode
    vector<vector<string>> solveNQueens(int n) {

        // Initialize empty board with '.'
        board = vector<string>(n, string(n, '.'));

        // Initialize helper arrays with 0 (not occupied)
        col = vector<int>(n, 0);
        diag1 = vector<int>(2 * n - 1, 0);
        diag2 = vector<int>(2 * n - 1, 0);

        // Start backtracking from row 0
        solve(0, n);

        // Return all valid solutions
        return ans;
    }
};

