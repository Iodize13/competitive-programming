class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
	queue<int> q;
	q.push(0);
	vector<int> ans;
	vector<bool> vis(adj.size(), 0);
	while(!q.empty()) {
		auto cur = q.top();
		q.pop();
		ans.emplace_back(cur);
		for (auto X: adj[cur]) {
			if (!vis[X]) {
				q.push();
			}
		}
	}
	return ans;
    }
};

