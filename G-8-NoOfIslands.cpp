 //TC: o(n2)
 //SC: o(n2)

 //In this question all 8 directions are considered
 
 void bfsSolve2(int startRow, int startCol, vector<vector<int>> &visited, vector<vector<char>> &grid) {
    // Mark the starting node as visited
    visited[startRow][startCol] = 1; 
    queue<pair<int, int>> q;
    // Push the starting node into the queue
    q.push({startRow, startCol}); 
    int numRows = grid.size(); 
    int numCols = grid[0].size(); 

    // Until the queue becomes empty
    while(!q.empty()) {
        int currentRow = q.front().first; 
        int currentCol = q.front().second; 
        q.pop(); 

        // Traverse the neighbors and mark them if they are land
        for(int rowOffset = -1; rowOffset <= 1; rowOffset++) {
            for(int colOffset = -1; colOffset <= 1; colOffset++) {
                int neighborRow = currentRow + rowOffset; 
                int neighborCol = currentCol + colOffset; 
                // Check if the neighbor is valid, unvisited, and land
                if(neighborRow >= 0 && neighborRow < numRows && neighborCol >= 0 && neighborCol < numCols 
                && grid[neighborRow][neighborCol] == '1' && !visited[neighborRow][neighborCol]) {
                    visited[neighborRow][neighborCol] = 1; 
                    q.push({neighborRow, neighborCol}); 
                }
            }
        }
    }
}

    // Function to find the number of islands.
    int solve1(vector<vector<char>> &grid) {
        int numRows = grid.size(); 
        int numCols = grid[0].size(); 
        // Create visited array and initialize to 0
        vector<vector<int>> visited(numRows, vector<int>(numCols, 0)); 
        int islandCount = 0; 
        for(int row = 0; row < numRows; row++) {
            for(int col = 0; col < numCols; col++) {
                // If the cell is not visited and is land
                if(!visited[row][col] && grid[row][col] == '1') {
                    islandCount++; 
                    bfsSolve2(row, col, visited, grid); 
                }
            }
        }
        return islandCount; 
    }

    int numIslands(vector<vector<char>>& grid) {
       return solve1(grid);
    }