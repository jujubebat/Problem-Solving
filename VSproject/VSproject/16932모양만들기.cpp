#include<iostream>
#include<queue>
using namespace std;

typedef struct {
	int x, y;
}pos;

int map[1000][1000];
int ret = 1;
const int dx[] = { -1,1,0, 0 }, dy[] = { 0,0,-1,1 };
int n, m;
bool visited[1000][1000];

int bfs(int sx, int sy) {
	int cnt = 1;
	queue<pos> q;
	visited[sx][sy] = true;

	q.push({ sx,sy });
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
			if (map[nx][ny] == 0) continue;
			if (visited[nx][ny]) continue;

			cnt++;
			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j])
				cout << 1;
			else
				cout << 0;
		}
		cout << endl;
	}
	cout << endl;


	return cnt;
}

void bfsSolve() {

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(map[i][j])
				ret = max(ret, bfs(i,j));
		}
	}
}

void solve() {

	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {

				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
					if (map[nx][ny]) cnt++;
				}

				if (cnt >= 2) {
					// bfs�� ������. 
					map[i][j] = 1;
					bfsSolve();
					map[i][j] = 0;
					if (flag) flag = false;
				}
			}
		}
	}

	if (flag) {
		//bfs ������ �ִ밪�� ã�´�. 
		bfsSolve();
	}

	cout << ret;
}

int main() {
	bool flag = false;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				flag = true;
		}
	}


	if (flag) {
		cout << n * m;
		return 0;
	}

	solve();
	return 0;
}

/*
1 000 000 * 1 000 000
1 000 000 * 1 000 000

�鸸���� 1�� 0���� �ٲ������....
�ð����⵵�� �ʹ� ū��

0�� 1�� �ٲ�پ���.

��� 0�� 1�ιٲ㺸�� dfs / bfs�� ������ �ִ�ũ�� Ȯ��
�ð����⵵�� ����... �ٸ� ���̵���ʿ�
*/

/*
��� 0�� 1�� �ٲ㺸�� �ʰ�
0���� ������ 1�� �ΰ� �̻��ִ� ��쿡�� �ٲ㺻��.
������ 1�̵ΰ� �̻� ���� ��쿡�� �ִ� ��� +1 ��
���ش�.
��� ĭ�� 1�̶�� �׳� ����Ѵ�.

0 0 0 0
1 0 0 0
0 0 1 1

1 1 1 1
1 1 1 1
1 1 1 1 */


