
import java.util.List;

class Solution {
    int n = 0;
    int m = 0;

    public boolean findSafeWalk(List<List<Integer>> grid, int health) {

        n = grid.size();
        m = grid.get(0).size();
        boolean[][] visited = new boolean[n][m];

        return checkSafe(grid, health, 0, 0, visited);
    }

    private boolean checkSafe(List<List<Integer>> grid, int health, int i, int j, boolean[][] visited) {
        if (i < 0 || j < 0 || i >= n || j >= m || health <= 0 || visited[i][j]) {
            return false;
        }

        health -= grid.get(i).get(j);

        if (i == n - 1 && j == m - 1 && health > 0) {
            return true;
        }

        visited[i][j] = true;
        boolean isSafe = checkSafe(grid, health, i + 1, j, visited) ||
                checkSafe(grid, health, i, j + 1, visited) ||
                checkSafe(grid, health, i - 1, j, visited) ||
                checkSafe(grid, health, i, j - 1, visited);

        visited[i][j] = false;

        return isSafe;
    }
}