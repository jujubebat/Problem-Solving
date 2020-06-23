#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct {
	int num, dir, x, y, eatCount; // ����� ��ȣ, x, y, ����, ���� ���� 
}fish;

const int dx[] = { -1,-1,0,1,1,1,0,-1 }, dy[] = { 0,-1,-1,-1,0,1,1,1 };
int ret = -1;

void fishMoving(vector<vector<int>>& map, vector<fish>& fishList) {
	for (int i = 0; i < 16; i++) { // ��ȣ ������� ����� Ž��.
		int num = fishList[i].num, dir = fishList[i].dir;
		int x = fishList[i].x, y = fishList[i].y;

		if (num == 0) continue; // ���� ������ ��ŵ.
		int nx, ny, ndir;
		bool flag = false; // �̵� ���� ���� �÷���.

		for (int k = dir, cnt = 0; ; k++, cnt++) { // �̵� ������ ���� Ž��
			if (cnt > 9) break; // ��� ������ Ž�������� �ߴ�. 
			ndir = k % 8, nx = x + dx[ndir], ny = y + dy[ndir];
			if (nx >= 4 || nx < 0 || ny >= 4 || ny < 0) continue; // �̵��� ��ġ�� ������ ����� ��ŵ.
			if (map[nx][ny] == -1) continue; // �̵��� ��ġ�� �� ������ ��ŵ.
			flag = true; break; // �̵������� �ּ� ��ġ�� ã���� �ߴ�.
		}

		if (flag) { // �̵� �����ϴٸ�
			fishList[num - 1] = { num, ndir, nx, ny };
			if (map[nx][ny] > 0) { // ����Ⱑ �̵��� ��ġ�� ����Ⱑ ���� ���.
				fishList[map[nx][ny] - 1].x = x;
				fishList[map[nx][ny] - 1].y = y;
			}
			swap(map[nx][ny], map[x][y]); // �̵� 
		}
	}
}

void solve(vector<vector<int>> map, vector<fish> fishList, fish shark) {
	ret = max(ret, shark.eatCount);
	vector<vector<int>> afterFishMovedMap = map; // ����Ⱑ �������� ��
	vector<fish> afterFishMovedFishList = fishList; // ����Ⱑ �������� ����� ����Ʈ

	fishMoving(afterFishMovedMap, afterFishMovedFishList);

	int x = shark.x, y = shark.y, dir = shark.dir, eatCount = shark.eatCount;
	bool flag = false;

	for (int i = 0; i <= 3; i++) {
		int nx = x + dx[dir] * i, ny = y + dy[dir] * i;
		if (nx >= 4 || nx < 0 || ny >= 4 || ny < 0) continue;
		if (map[nx][ny] == 0) continue; // ����Ⱑ ���� ĭ�̸�, ��ŵ.

		vector<vector<int>> afterSharkMovedMap = afterFishMovedMap;
		vector<fish> afterSharkMovedFishList = afterFishMovedFishList;

		fish nShark = { -1, dir, nx, ny, eatCount + afterSharkMovedMap[nx][ny] }; // ���Ӱ� ������Ʈ �� ���.

		afterSharkMovedFishList[map[nx][ny] - 1] = { 0,0,0,0,0 }; // ����� ����Ʈ���� ����� ���� ó��.
		afterSharkMovedMap[x][y] = 0;
		afterSharkMovedMap[nx][ny] = -1;

		solve(afterSharkMovedMap, afterSharkMovedFishList, nShark);
	}
}

bool comp(fish a, fish b) {
	return a.num < b.num;
}

int main() {
	vector<vector<int>> map(4, vector<int>(4, 0)); // 4x4 map
	vector<fish> fishList; // ����� ����Ʈ

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			map[i][j] = a; // map�� ����⸦ �־��ش�.
			fishList.push_back({ a, b - 1, i, j }); // ���� ���� ����Ʈ�� �����.
		}
	}
	sort(fishList.begin(), fishList.end(), comp);
	fish shark = { -1, fishList[map[0][0] - 1].dir, 0, 0, map[0][0] };
	fishList[map[0][0] - 1] = { 0, 0, 0, 0, 0 }; // ���� ����� 0����
	map[0][0] = -1; // �� �ִ� ��ġ�� -1

	solve(map, fishList, shark);
	cout << ret;

	return 0;
}

