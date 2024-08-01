

// Kahn's Algo

// Function to perform topological sort on a directed acyclic graph (DAG)
vector<int> topoSort(int V, vector<int> adj[])
{
    // Array to store the in-degree of each vertex
    int indegree[V];
    // Initialize in-degrees to 0
    for (int i = 0; i < V; i++)
        indegree[i] = 0;

    // Calculate in-degrees of all vertices
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    // Queue to store vertices with in-degree 0
    queue<int> q;
    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Vector to store the topological order
    vector<int> ans;
    // Process the queue
    while (!q.empty())
    {
        // Get the front vertex from the queue
        int node = q.front();
        q.pop();
        // Add the vertex to the topological order
        ans.push_back(node);

        // Decrease the in-degree of all adjacent vertices
        for (auto it : adj[node])
        {
            indegree[it]--;
            // If in-degree of an adjacent vertex becomes 0, enqueue it
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

     // Check if topological sort is possible (i.e., no cycle in the graph)
    if (ans.size() != V) {
        return {}; // Return an empty vector if there's a cycle
    }


    // Return the topological order
    return ans;
}

// Function to find the order of courses to take based on prerequisites
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    // Create an adjacency list representation of the graph
    vector<int> adj[numCourses];
    // Fill the adjacency list with edges representing prerequisites
    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }

    // Perform topological sort to determine the order of courses
    return topoSort(numCourses, adj);
}
