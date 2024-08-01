// Kahn's Algorithm
// BFS
// Kahn's Algorithm is a method for performing a topological sort on a directed acyclic graph (DAG).
// Kahn's Algorithm: Uses BFS and a queue, based on in-degrees.

vector<int> topoSort(int V, vector<int> adj[])
{
    // Create an array to store the in-degree (number of incoming edges) of each vertex
    int indegree[V] = {0};

    // Iterate over all vertices
    for (int i = 0; i < V; i++)
    {
        // For each vertex, iterate over its adjacent vertices
        for (auto it : adj[i])
        {
            // Increment the in-degree of the adjacent vertices
            indegree[it]++;
        }
    }

    // Create a queue to store vertices with in-degree 0
    queue<int> q;
    // Iterate over all vertices
    for (int i = 0; i < V; i++)
    {
        // If a vertex has in-degree 0, add it to the queue
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Create a vector to store the topological order
    vector<int> ans;
    // Process the queue until it's empty
    while (!q.empty())
    {
        // Get the front vertex from the queue
        int node = q.front();
        // Remove the front vertex from the queue
        q.pop();
        // Add the vertex to the topological order
        ans.push_back(node);

        // Iterate over the adjacent vertices of the current vertex
        for (auto it : adj[node])
        {
            // Decrease the in-degree of the adjacent vertices
            indegree[it]--;
            // If the in-degree of an adjacent vertex becomes 0, add it to the queue
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    // Return the topological order
    return ans;
}
