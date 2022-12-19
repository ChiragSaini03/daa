#include <bits/stdc++.h>
using namespace std;
vector<char> character = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'k', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
void toposort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, vector<int>> adj)
{
	visited[node] = 1;
	for (auto i : adj[node])
	{
		if (!visited[i])
		{
			toposort(i, visited, s, adj);
		}
	}
	s.push(node);
}
vector<int> topologicalsort(vector<vector<int>> &edges, int n, int e)
{
	unordered_map<int, vector<int>> adj;
	for (int i = 0; i < e; i++)
	{
		int u = edges[i][0] - 'a';
		int v = edges[i][1] - 'a';
		adj[u].push_back(v);
	}
	unordered_map<int, bool> visited;
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			toposort(i, visited, s, adj);
		}
	}
	vector<int> ans;
	while (!s.empty())
	{
		ans.push_back(s.top());
		s.pop();
	}
	return ans;
}
int main()
{
	vector<vector<int>> edges = {{'a', 'b'}, {'b', 'c'}, {'c', 'd'}, {'c', 'e'}, {'d', 'f'}, {'e', 'f'}, {'f', 'g'}, {'f', 'h'}};
	vector<int> ans = topologicalsort(edges, 8, edges.size());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << character[ans[i]] << " ";
	}
	return 0;
}
