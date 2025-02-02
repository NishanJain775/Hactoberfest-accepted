//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int> dist(V,1e8);
        dist[S]=0;
        for(int i=0;i<V-1;i++)
        {
            for(int j=0;j<adj.size();j++)
            {
                if(dist[adj[j][1]]>dist[adj[j][0]]+adj[j][2])
                {
                    dist[adj[j][1]]=dist[adj[j][0]]+adj[j][2];
                }
            }
        }
        for(int j=0;j<adj.size();j++)
        {
            if(dist[adj[j][1]]>dist[adj[j][0]]+adj[j][2])
            {
                return {};
                // dist[adj[j][1]]=dist[adj[j][0]]+adj[j][2];
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
