//Function to return list containing vertices in Topological order. 
	void dfs(int node,int vis[], vector<int> adj[],stack<int>&st)
	{
	    vis[node]=1;
	    
	    for(auto it:adj[node])
	    {
	        if(!vis[it])
	        {
	            dfs(it,vis,adj,st);
	        }
	    }
	    
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int vis[V]={0};
	    stack<int>st;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i,vis,adj,st);
	        }
	    }
	    
	    vector<int>ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}



//Cycle detect Directed Graph
// DFS-Based Algorithm: Uses a stack and the recursive nature of DFS.
//  Time Complexity: O(V+E)+O(V),
// Space Complexity: O(2N) + O(N) ~ O(2N): O(2N) for the visited array
// and the stack carried during DFS calls and O(N) for recursive stack space, where N = no. of nodes.

bool dfs(int node, int vis[], int pathvis[], vector<int> adj[])
{
    vis[node] = 1;
    pathvis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, vis, pathvis, adj) == true)
                return true;
        }
        else
        {
            if (pathvis[it])
            {
                return true;
            }
        }
    }

    pathvis[node] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int pathvis[V] = {0};

    for (int i = 0; i < V; i++)
    {

        if (!vis[i])
        {
            if (dfs(i, vis, pathvis, adj) == true)
                return true;
        }
    }

    return false;
}