#include<vector>
#include<algorithm>

using namespace std;

struct DisjointSet;
const int MAX_V = 100;
int V; //������ ����
vector<pair<int, int>> adj[MAX_V]; //�׷����� ��������Ʈ. (����� ���� ��ȣ, ���� ����ġ) ���� ��´�.


int kruskal(vector<int, pair<int, int>>& selected) {
	int ret = 0;
	selected.clear();

	// (����ġ, (����1, ����2)) ����� ��´�. 
	vector <pair<int, pair<int, int>>> edges;
	for (int u = 0; u < V; u++) {
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first, cost = adj[u][i].second;
			edges.push_back({ cost, {u,v} });
		}
	}

	//����ġ ������ �����Ѵ�. 
	sort(edges.begin(), edges.end());

	DisjointSet sets(V);

	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;

		//u�� v�� ���� �����̶��, ���� ��ȸ���� ������ �߰����� �ʴ´�.
		if (sets.find(u) == sets.find(v)) continue;
		set.doUnion(u, v);
		selected.push_back({ u,v });
		ret += cost;
	}

	return ret;
}