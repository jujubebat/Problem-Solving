#include<vector>
using namespace std;

struct OptimazedDisjointSet {

	vector<int> parent, rank;

	//n���� ���Ұ� ������ ���տ� ���ԵǾ� �ֵ��� �ʱ�ȭ�Ѵ�. 
	OptimazedDisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	//find(u)�� ���� u�� ���ϴ� Ʈ���� ��Ʈ�� ã�Ƴ´�. �̶� parnet[u]�� ã�Ƴ� ��Ʈ�� �ƿ� �ٲ� ������,
	//�������� find(u)�� ȣ��Ǿ��� ���� ��θ� ���� �ö� �� ���� �ٷ� ��Ʈ�� ã�� �� �ִ�.
	//��, �θ��带 ��Ʈ���� �ٲ������ ���̴�. 
	//������� ���� ���п� u���� ��Ʈ���� �ö󰡴� ��λ� �ִ� ��� ���鿡�� ��� ���� ����ȭ�� �ڵ����� ����ȴ�.
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	//�� ���� Ʈ���� ��ĥ ��, �׻� ���̰� �� ���� Ʈ���� �� ���� Ʈ�� �׿� ���� �ִ´�.
	//�׷����μ� Ʈ���� ���̰� �������� ��Ȳ�� �����Ѵ�. (���� Ʈ�� ����)
	void doUnion(int u, int v) {
		u = find(u);
		v = find(v);

		if (u == v) return; //u�� v�� �̹� ���� ���տ� ���ϴ� ��츦 �ɷ�����.
		if (rank[u] > rank[v]) swap(u, v); //���� rank[v]�� �׻� rank[u] �̻��̹Ƿ� u�� v�� �ڽ����� �ִ´�.
		parent[u] = v; 
		if (rank[u] == rank[v]) rank[v]++; //�� Ʈ���� ���̰� ���� ��쿡�� Ʈ���� ���̸� 1 �÷��ش�.
	}

};

