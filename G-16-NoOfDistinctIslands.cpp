// TC: o(n*m*log(n*m)) + o(n*m*4)
// SC: o(n*m)
// Using DFS
void dfsSolve(int row, int col, vector<pair<int, int>> &vec,
              vector<vector<int>> &vis, vector<vector<int>> &grid, int baserow, int basecol)
{
    vis[row][col] = 1;
    vec.push_back({row - baserow, col - basecol});
    int n = grid.size();
    int m = grid[0].size();
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, -1, 0, 1};

    for (int i = 0; i < 4; i++)
    {
        int frow = row + drow[i];
        int fcol = col + dcol[i];

        if (frow >= 0 && frow < n && fcol >= 0 && fcol < m &&
            !vis[frow][fcol] && grid[frow][fcol] == 1)
        {
            dfsSolve(frow, fcol, vec, vis, grid, baserow, basecol);
        }
    }
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> vec;
                dfsSolve(i, j, vec, vis, grid, i, j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}