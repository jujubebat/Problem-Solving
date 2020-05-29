#include<iostream>
using namespace std;

char map[100][100];
int r, c;
int n;
int stick[100];
int visited[100][100];
int cnt = 1;
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,-1,1 };
bool bottomCluster[101];

void dfs(int x, int y) {
	if (!bottomCluster[cnt] && x == r - 1) // ���� ����ִ� Ŭ������ üũ
		bottomCluster[cnt] = true;

	visited[x][y] = cnt;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= r || nx < 0 || ny >= c || ny < 0) continue;
		if (visited[nx][ny]) continue;
		if (map[nx][ny] == '.') continue;
		dfs(nx, ny);
	}

}

void fallMineral() {
	cnt = 1;
	memset(visited, 0, sizeof(visited));
	memset(bottomCluster, 0, sizeof(bottomCluster));
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {

			if (map[i][j] == 'x' && !visited[i][j]) {

				dfs(i, j);
				cnt++;

			}
		}
	}

	if (cnt > 2) { // �и��� Ŭ�����Ͱ� ������. �߷��� �ۿ��Ѵ�. 
		bool flag = false;
		int a = 0;
		while (1) {
			for (int row = r - 1; row > 0; row--) {
				for (int col = 0; col < c; col++) {

					if (map[row][col] == '.' && map[row - 1][col] == 'x') {
						if (!bottomCluster[map[row - 1][col]]) {
							swap(map[row][col], map[row - 1][col]);
							if (row == r - 1) {
								flag = true;
							}
							else if (bottomCluster[map[row - 1][col]]) {
								flag = true;
							}
						}
					}
				}
			}

			if (flag) return;
		}
	}
}

void breakMineral(bool flag, int h) {

	h = r - h;
	if (flag) { //����
		
		for (int col = 0; col < c; col++) {
			if (map[h][col] == 'x') {
				map[h][col] = '.';
				return;
			}
		}

	}
	else {

		for (int col = c-1; col >= 0; col--) {
			if (map[h][col] == 'x') {
				map[h][col] = '.';
				return;
			}
		}

	}

}

void solve() {

	bool flag = true; // ����
	for (int i = 0; i < n; i++) {
		breakMineral(flag, stick[i]);

		if (flag) flag = false;
		else flag = true;

		fallMineral();
	}
}

int main() {

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
	
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> stick[i];
	}
	
	solve();

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout<< map[i][j];
		}
		cout << endl;
	}

	return 0;
}

// �̳׶��� �μ���.
// Ŭ�����Ͱ� ���� ������� �˻�.
// Ŭ�����Ͱ� ����ٸ�, �߷� �ۿ�
// Ŭ�����Ϳ� ���� �߷� �ۿ� ����?.
// �ش�Ŭ�����Ͱ� �ٴ� �Ǵ� �ٸ� Ŭ������ �����Ҷ� ���� 1ĭ�� �߷��ۿ�


/*

........
........
...x.xx.
...xxx..
...xx...
..x.x...
..x...x.
.xxx..x.

*/