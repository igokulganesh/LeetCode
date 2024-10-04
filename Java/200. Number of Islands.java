class Solution {
    public int numIslands(char[][] grid) {
        int count = 0;

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    connectIslands(grid, i, j);
                }
            }
        }

        return count;
    }

    private void connectIslands(char[][] grid, int i, int j) {
        if (i < 0 || j < 0 || i == grid.length || j == grid[0].length || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        connectIslands(grid, i + 1, j);
        connectIslands(grid, i - 1, j);
        connectIslands(grid, i, j + 1);
        connectIslands(grid, i, j - 1);
    }
}