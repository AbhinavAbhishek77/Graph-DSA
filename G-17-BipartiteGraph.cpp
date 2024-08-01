// <---------------BFS Approach--------------------->

// My Code
// TC: O(V+E)
// SC: O(V)
bool bfs(int src, vector<int> adj[], vector<int> &col)
{
    col[src] = 0;
    queue<pair<int, int>> q;
    q.push({src, 0});

    while (!q.empty())
    {
        int node = q.front().first;
        int color = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            // not colored
            if (col[it] == -1)
            {
                col[it] = !color;
                q.push({it, col[it]});
            }
            else // colored
            {
                if (col[it] == color)
                {
                    return false;
                }
            }
        }
    }

    return true;
}
bool isBipartite(int V, vector<int> adj[])
{

    vector<int> col(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (col[i] == -1)
        {
            if (!bfs(i, adj, col))
            {
                return false;
            }
        }
    }

    return true;
}

// Striver
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // colors a component
private:
    bool check(int start, int V, vector<int> adj[], int color[])
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                // if the adjacent node is yet not colored
                // you will give the opposite color of the node
                if (color[it] == -1)
                {

                    color[it] = !color[node];
                    q.push(it);
                }
                // is the adjacent guy having the same color
                // someone did color it on some other path
                else if (color[it] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        int color[V];
        for (int i = 0; i < V; i++)
            color[i] = -1;

        for (int i = 0; i < V; i++)
        {
            // if not coloured
            if (color[i] == -1)
            {
                if (check(i, V, adj, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

// <---------------DFS Approach--------------------->

bool dfs(int node, int color, vector<int> adj[], vector<int> &col)
{
    col[node] = color;
    //  queue<pair<int,int>>q;
    //  q.push({src,0});

    //  while(!q.empty())
    //  {
    //      int node=q.front().first;
    //      int color=q.front().second;
    //      q.pop();

    for (auto it : adj[node])
    {
        // not colored
        if (col[it] == -1)
        {
            if (dfs(it, !color, adj, col) == false)
                return false;
            //  col[it]=!color;
            //  q.push({it,col[it]});
        }
        else // colored
        {
            if (col[it] == color)
            {
                return false;
            }
        }
    }
    //  }

    return true;
}
bool isBipartite(int V, vector<int> adj[])
{

    vector<int> col(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (col[i] == -1)
        {
            if (!dfs(i, 0, adj, col))
            {
                return false;
            }
        }
    }

    return true;
}