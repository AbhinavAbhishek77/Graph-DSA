vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    // Step 1: Initialize the adjacency list for the graph
    vector<int> adj[N];
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        // Since the graph is undirected, add both directions
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 2: Initialize the visited and distance arrays
    vector<int> vis(N, 0);    // To keep track of visited nodes
    vector<int> dist(N, 1e9); // To store distances, initialized to a large number (infinity)

    // Step 3: Initialize the queue for BFS
    queue<int> q;
    q.push(src);   // Start BFS from the source node
    dist[src] = 0; // Distance from source to itself is 0
    vis[src] = 1;  // Mark the source node as visited

    // Step 4: Perform BFS
    while (!q.empty())
    {
        int node = q.front(); // Get the front node from the queue
        q.pop();              // Remove the front node from the queue

        // Iterate over all the adjacent nodes of the current node
        for (auto it : adj[node])
        {
            // If the adjacent node has not been visited
            if (!vis[it])
            {
                dist[it] = dist[node] + 1; // Update the distance to the adjacent node
                q.push(it);                // Push the adjacent node to the queue
                vis[it] = 1;               // Mark the adjacent node as visited
            }
            // This else block is not necessary as we don't need to update the distance of the current node here
            // else {
            //     dist[node] = min(dist[node], dist[it] + 1);
            // }
        }
    }

    // Step 5: Post-process the distance array
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 1e9)
        {
            dist[i] = -1; // If a node is unreachable, set its distance to -1
        }
    }

    // Return the final distance array
    return dist;
}
