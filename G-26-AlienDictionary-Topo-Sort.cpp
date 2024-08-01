//Topo-Sort
  //Follow-Up: Not possible, if larger string appears before shorter string and everything matches
  // Not possible, If there is a cyclic dependency

  //TestCase:
//     N = 5, K = 4
// dict = {"baa","abcd","abca","cab","cad"}
// indegree: 0-2, 1-0, 2-1, 3-1

// https://takeuforward.org/data-structure/alien-dictionary-topological-sort-g-26/

string solve(vector<int> adj[], int n, int k) {
    // Create an indegree vector to store the number of incoming edges for each node
    int indegree[k] = {0};

    // Calculate the indegree for each node by iterating over the adjacency list
    for (int i = 0; i < k; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    // Initialize a queue to store nodes with indegree 0 (no incoming edges)
    queue<int> q;
    for (int i = 0; i < k; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Initialize an empty string to store the topological order
    string topo = "";

    // Perform Kahn's algorithm for topological sorting
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        // Convert the node number to the corresponding character and add to the result string
        topo += (node + 'a');

        // Iterate over the neighbors of the current node
        for (auto it : adj[node]) {
            // Decrease the indegree of the neighbor
            indegree[it]--;
            // If the indegree of the neighbor becomes 0, add it to the queue
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    // Return the resulting topological order
    return topo;
}

string findOrder(string dict[], int N, int K) {
    // Create an adjacency list for the graph
    vector<int> adj[K];

    // Build the graph from the dictionary
    for (int i = 0; i < N - 1; i++) {
        // Compare each word with the next word
        for (int j = 0; j < min(dict[i].size(),dict[i+1].size()); j++) {
            // Find the first differing character
            if (dict[i][j] != dict[i + 1][j]) {
                // Add a directed edge from the character in the first word to the character in the second word
                adj[dict[i][j] - 'a'].push_back(dict[i + 1][j] - 'a');
                break; // Stop at the first differing character
            }
        }
    }

    // Call the solve function to get the topological order
    return solve(adj, N, K);
}
