#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

typedef struct {
	int x, y;
}pos;

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

	cout << "�ٴڿ� ����ִ� Ŭ������ ���";
	for (int i = 0; i < 100; i++) {
		if (bottomCluster[i])
			cout << i << " ";
	}
	cout << endl;


	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << visited[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	vector<pos> v;
	
	if (cnt > 2) { // �и��� Ŭ�����Ͱ� ������. �߷��� �ۿ��Ѵ�. 
		// ����߸� Ŭ����Ʈ�� ��ǥ�� �����صд�. 
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {

				if (visited[i][j] != 0 && !bottomCluster[visited[i][j]]) {
					cout << i << j << endl;
					v.push_back({ i,j });
				}

			}
		}

		bool flag = false;

		cout << "v.size() : " <<  v.size();

		while (1){
			for (int i = 0; i < v.size(); i++) {
				map[v[i].x][v[i].y] = '.';
			}

			/*for (int i = 0; i < v.size(); i++) {
				int nx = v[i].x + 1, ny = v[i].y;
				map[nx][ny] = 'x';

				if (nx + 1 == r || map[nx+1][ny] == 'x')
					flag = true;
			}*/

			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					cout << map[i][j];
				}
				cout << endl;
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