给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例 :

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释 :

//被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。
//如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

//解题思路
//判断O是否最终会被填充，只要这个O能沿着旁边的O到四条边就不会被填充。
//所以我们可以从四条边上的O入手，将其改成K，然后遍历旁边的O 也改成K。
//最终只要没有变成K的O将被填充，遍历数组把K改成O，其他的都改成X。

class Solution {
	int[] dx = { 1, -1, 0, 0 };
	int[] dy = { 0, 0, 1, -1 };
	public void solve(char[][] board) 
	{
		//遍历边上的O
		//这里可以只遍历四条边，但是好像影响不大。
		for (int i = 0; i<board.length; i++)
		{
			for (int j = 0; j<board[0].length; j++)
			{
				if ((i == 0 || j == 0 || i == board.length - 1 || j == board[0].length - 1) && board[i][j] == 'O')
				{
					helper(board, i, j);
				}
			}
		}
		//把K改成O，其他改成X

		for (int i = 0; i<board.length; i++)
		{
			for (int j = 0; j<board[0].length; j++)
			{
				board[i][j] = board[i][j] == 'K' ? 'O' : 'X';
			}
		}
	}
	void helper(char[][] board, int i, int j)
	{
		board[i][j] = 'K';
		for (int k = 0; k<4; k++)
		{
			int x = i + dx[k];
			int y = j + dy[k];
			if (x >= 0 && y >= 0 && x<board.length&&y<board[0].length&&board[x][y] == 'O')
			{
				helper(board, x, y);
			}
		}
	}
}