#include<iostream>
#include<queue>
#include<cstring>
#include<unordered_map>
#include<algorithm>
using namespace std;

typedef struct {
	int x, y, f, c;
}pos;

int n, m, fuel;
int map[20][20];
int personMap[20][20]; // �մ� ��ġ ��ǥ
int tx, ty;
const int dx[] = { -1,0,1,0 }, dy[] = { 0,-1,0,1 };
int succes = 0;
unordered_map<int, pair<int, int>> destInfo;

bool comp(pos a, pos b) {
	if (a.f == b.f) {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		else
			return a.x < b.x;
	}
	else
		return a.f > b.f;
}

bool goToDest(int destNum) {  // ���� �������� false ����
	int check[20][20];
	int cnt = 0;
	memset(check, 0, sizeof(check));
	queue<pos> q;
	q.push({ tx,ty, fuel, 0 });
	check[tx][ty] = 1;

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y,
			f = q.front().f, c = q.front().c;
		q.pop();

		if (destInfo[destNum].first == x
			&& destInfo[destNum].second == y) {// �մ��� ���������� ���.
			
			tx = x, ty = y;
			f += c * 2; // �Ҹ��� ������ 2�� ����.
			fuel = f;

			return true;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i], nf = f, nc = c;
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (map[nx][ny]) continue;
			if (check[nx][ny]) continue;
			if (nf == 0) continue;
			nf--;
			nc++; // ���� �Ҹ� üũ
			check[nx][ny] = 1;
			q.push({ nx, ny, nf, nc });
		}
	}

	return false;
}

bool ridePerson() { // ���� �������� false ����
	int destNum = -1;
	int check[20][20];
	memset(check, 0, sizeof(check));
	queue<pos> q;
	q.push({ tx,ty,fuel });
	check[tx][ty] = 1;

	vector<pos> candi;
	int maxVal = -0x7fffffff;

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, f = q.front().f;
		q.pop();

		if (personMap[x][y] > 0) { // �մ��� �߰��ϸ� ����.
			if (maxVal <= f) {
				maxVal = f;
				candi.push_back({ x, y, f });
			}
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i], nf = f;
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (map[nx][ny]) continue;
			if (check[nx][ny]) continue;
			if (nf == 0) continue;
			nf--;
			check[nx][ny] = true;
			q.push({ nx, ny, nf });
		}
	}

	if (candi.size() == 0) return false; // �մ��� �߰� ���Ұ��.

	sort(candi.begin(), candi.end(), comp);

	int x = candi[0].x, y = candi[0].y, f = candi[0].f;
	destNum = personMap[x][y];
	tx = x, ty = y;
	personMap[x][y] = 0;
	fuel = f;

	return goToDest(destNum); // �մ��� �¿�� �������� ���.
}

int solve() {
	for (int i = 0; i < m; i++) {
		if (ridePerson() == false) {
			return -1;
		}
	}
	return fuel;
}

int main() {
	cin >> n >> m >> fuel;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	cin >> tx >> ty;
	tx--, ty--;

	for (int i = 1; i <= m; i++) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		personMap[sx - 1][sy - 1] = i;
		destInfo[i] = { ex - 1 , ey - 1 };
	}

	cout << solve();
	return 0;
}