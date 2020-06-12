#include<iostream>
#include<algorithm>
using namespace std;

int x, y;
int r, c, t;
int map[50][50];
int airConUpSideXpos;
const int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };

void diffuseDust() {

	int tmpMap[50][50] = { 0 };

	tmpMap[airConUpSideXpos][0] = -1;
	tmpMap[airConUpSideXpos + 1][0] = -1;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) { // �̼������� ���.

				int diffusedCount = 0, diffuseAmount = map[i][j] / 5;

				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (map[nx][ny] == -1) continue; // ���� û���Ⱑ �ִ� ���.
					if (nx >= r || nx < 0 || ny >= c || ny < 0) continue; // ĭ�� ���� ���.

					tmpMap[nx][ny] += diffuseAmount, diffusedCount++;
					//map[nx][ny] += diffuseAmount, diffusedCount++; // Ȯ��, Ȯ�� ���� ����.

				}
				if (diffusedCount > 0) {

					tmpMap[i][j] = map[i][j] - diffuseAmount * diffusedCount;
					if (tmpMap[i][j] < 0) tmpMap[i][j] = 0;

					//map[i][j] -= diffuseAmount * diffusedCount; // ���� ��ġ ������ ���.
					//if (map[i][j] < 0) map[i][j] = 0;
				}
				else
					tmpMap[i][j] = map[i][j];

			}
		}
	}

	/*
	cout << "���� ������" << endl;
	cout << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << tmpMap[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/


	copy(&tmpMap[0][0], &tmpMap[r - 1][c - 1], &map[0][0]);

	//map, 

}

void airConditionerWork() {
	// ���� ���� ��ȯ.

	//�� ���ʿ� �Ʒ� �������� ��ȯ.
	x = airConUpSideXpos - 1, y = 0;
	while (x > 0) {
		map[x][y] = map[x - 1][y], x--;
	}
	//�� ���ʿ� ���� �������� ��ȯ.
	x = 0, y = 0;
	while (y < c - 1) {
		map[x][y] = map[x][y + 1], y++;
	}
	//�� �����ʿ� ���� �������� ��ȯ.
	x = 0, y = c - 1;
	while (x < airConUpSideXpos) {
		map[x][y] = map[x + 1][y], x++;
	}
	//�Ʒ��� �� ������ �������� ��ȯ.
	x = airConUpSideXpos, y = c - 1;
	while (y > 0) {
		if (y == 1) {
			map[x][y] = 0;
		}
		else
			map[x][y] = map[x][y - 1];
		y--;
	}

	// �Ʒ��� ���� ��ȯ
	int airConDownSideXpos = airConUpSideXpos + 1;

	// ���ʿ� ���� �������� ��ȯ.
	x = airConDownSideXpos + 1, y = 0;
	while (x < r - 1) {
		map[x][y] = map[x + 1][y], x++;
	}

	// �Ʒ��� �� ���� �������� ��ȯ.
	x = r - 1, y = 0;
	while (y < c - 1) {
		map[x][y] = map[x][y + 1], y++;
	}

	// ���ʿ� �Ʒ��� ������ ��ȯ. 
	x = r - 1, y = c - 1;
	while (x > airConDownSideXpos) {
		map[x][y] = map[x - 1][y], x--;
	}

	x = airConDownSideXpos, y = c - 1;
	while (y > 0) {
		if (y == 1) {
			map[x][y] = 0;
		}
		else
			map[x][y] = map[x][y - 1];
		y--;
	}

}

void solve() {

	while (t--) {
		diffuseDust();

		/*cout << "���� ������" << endl;
		cout << endl;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/

		airConditionerWork();

		/*cout << "���� û���� ������" << endl;
		cout << endl;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
	}

	int ret = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) ret += map[i][j];
		}
	}

	cout << ret;
}

int main() {
	cin >> r >> c >> t;
	bool flag = true;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1 && flag) { // ���� �������� ù��° ������ �����Ѵ�. 
				airConUpSideXpos = i;  // ������ ���� �κ� X��ǥ ����.
				flag = false;
			}
		}
	}

	solve();
	return 0;
}