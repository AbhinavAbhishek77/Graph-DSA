
// TC: O(2E+V)
// SC: O(V)
//  Helper function to perform DFS and check for cycles in the directed graph
bool dfs(int node, int visited[], int pathVisited[], vector<int> adj[])
{
    // Mark the current node as visited and add it to the current path
    visited[node] = 1;
    pathVisited[node] = 1;

    // Iterate over all the adjacent nodes
    for (auto adjacentNode : adj[node])
    {
        // If the adjacent node is not visited, perform DFS on it
        if (!visited[adjacentNode])
        {
            // If DFS on the adjacent node returns true, a cycle is found
            if (dfs(adjacentNode, visited, pathVisited, adj) == true)
            {
                return true;
            }
        }
        else
        {
            // If the adjacent node is already visited and is part of the current path, a cycle is found
            if (pathVisited[adjacentNode])
            {
                return true;
            }
        }
    }

    // Remove the current node from the current path (backtracking)
    pathVisited[node] = 0;
    return false;
}

// Function to check if there is a cycle in the directed graph
bool isCyclic(int V, vector<int> adj[])
{
    // Initialize visited and pathVisited arrays to 0
    int visited[V] = {0};
    int pathVisited[V] = {0};

    // Iterate over all the nodes in the graph
    for (int i = 0; i < V; i++)
    {
        // If the node is not visited, perform DFS on it
        if (!visited[i])
        {
            // If DFS on the node returns true, a cycle is found
            if (dfs(i, visited, pathVisited, adj) == true)
            {
                return true;
            }
        }
    }

    // If no cycle is found, return false
    return false;
}

// A2 :Using Topo Sort
//  Function to detect cycle in a directed graph.
// Cycle Detection Using Kahn's Algorithm
bool topoSort(int V, vector<int> adj[])
{
    int indegree[V] = {0};

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    // Check if topological sort is possible (i.e., no cycle in the graph)
    if (cnt != V)
    {
        return true; // Return an empty vector if there's a cycle
    }

    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    return topoSort(V, adj);
}