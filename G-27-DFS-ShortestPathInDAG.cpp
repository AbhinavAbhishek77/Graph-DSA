// A1
//    Shortest path from any src :
//  1.Perform toposort and store the order in a stack
//  2.Once the source node is given, pop the elements in the stack until the stack's top is the source
//  3. Rest is the same .

// Eg :
// For src 5--->  dist=[4,6,2,5,1,0,inf]
// 6->inf because you cannot reach 6 from 5

// TC: O(N+M)
// SC: O(N)

// Function to perform topological sort on the graph
void topo(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
{
    vis[node] = 1; // Mark the current node as visited

    // Recursively visit all the adjacent nodes
    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            topo(it.first, adj, vis, st);
        }
    }

    // Push the current node to the stack after visiting all its adjacent nodes
    st.push(node);
}

// Function to find the shortest path from the source node in a DAG
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[N]; // Adjacency list to store graph
    vector<int> vis(N, 0);         // Visited array to keep track of visited nodes

    // Create Adjacency List from the edges
    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }

    stack<int> st; // Stack to store topological order
    // Perform topological sort on all nodes
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            topo(i, adj, vis, st);
        }
    }

    vector<int> dist(N, 1e9); // Distance array initialized with a large value (infinity)
    dist[0] = 0;              // Distance to the source node is 0

    // Process nodes in topological order
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        // Update the distances of adjacent nodes
        for (auto it : adj[node])
        {
            int val = it.first;
            int wt = it.second;
            if (dist[node] + wt < dist[val])
            {
                dist[val] = dist[node] + wt;
            }
        }
    }

    // Replace all distances that remain infinity with -1 (indicating unreachable nodes)
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 1e9)
            dist[i] = -1;
    }

    return dist; // Return the final distance array
}

// A2
//  Time Complexity : 𝑂(𝑁 +𝑀)
//  Space Complexity : O(N+M)
// N=>Number of Nodes , M=>Number ofedges

// Depth-First Search (DFS) function to find the shortest path
void dfs(int node, const vector<pair<int, int>> adj[], int sum, vector<int> &ans, vector<bool> &visited)
{
    visited[node] = true;
    ans[node] = min(ans[node], sum);

    // traverse all its neighbours
    for (auto it : adj[node])
    {

        if (!visited[it.first] || (sum + it.second) < ans[it.first])
            dfs(it.first, adj, sum + it.second, ans, visited);
    }
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{

    vector<pair<int, int>> adj[N];
    vector<int> ans(N, INT_MAX);
    vector<bool> visited(N, false);

    // Create Adjacency List
    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }
    int sum = 0;
    dfs(0, adj, sum, ans, visited);
    for (int i = 0; i < N; i++)
    {
        if (ans[i] == INT_MAX)
            ans[i] = -1;
    }
    return ans;
}