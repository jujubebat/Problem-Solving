


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct {
	int num, dir;
	int x, y;
	int count;
}fish;

const int dx[] = {-1,-1,0,1,1,1,0,-1 }, dy[] = {0,-1,-1,-1,0,1,1,1 };
int ret = -1;

void fishMoving(vector<vector<fish>>& map, vector<fish>& fishList) {
	cout << "fishMoving" << endl;
	for (int i = 0; i < 16; i++) { // ��ȣ ������� ����� Ž��.
		cout << "i : " << i << endl;
		int num = fishList[i].num, dir = fishList[i].dir;
		int x = fishList[i].x, y = fishList[i].y;

		if (num == 0) continue; // ���� ������ ��ŵ.
		cout << "i2 : " << i << endl;

		int nx, ny, ndir;
		bool flag = false; // �̵� ���� ���� �÷���.

		for (int k = dir, cnt = 0; ;k++, cnt++) { // �̵� ������ ���� Ž��
			if (cnt > 8) break; // ��� ������ Ž�������� �ߴ�. 
			cout << "cnt : " << cnt << endl;
			nx = x + dx[k % 8], ny = y + dy[k % 8], ndir = k % 8;
			if (nx >= 4 || nx < 0 || ny >= 4 || ny < 0) continue; // �̵��� ��ġ�� ������ ����� ��ŵ.
			if (map[nx][ny].num == -1) continue; // �̵��� ��ġ�� �� ������ ��ŵ.
			flag = true; break; // �̵������� ��ġ�� ã���� �ߴ�.
		}
		cout << "����" << endl;

		if (flag) { // �̵� �����ϴٸ�
			map[x][y].dir = ndir; // ������ ������� ���� ����.

			if (map[nx][ny].num == 0) { // ����Ⱑ �̵��� ��ġ�� ������� ���.
				fishList[i].dir = ndir; // �̵� ��ų ������� �����, ��ġ ����.
				fishList[i].x = nx;
				fishList[i].y = ny;
			}
			else if (map[nx][nx].num > 0) { // �ٸ� ����Ⱑ �������.
				fish tmp = fishList[i];

				fishList[i].dir = ndir;  // �̵� ��ų ������� �����, ��ġ ����.
				fishList[i].x = nx;
				fishList[i].y = ny;

				fishList[map[nx][nx].num - 1].x = tmp.x; // ������ġ�� �ִ� ����� ��ġ ��ǥ ���� 
				fishList[map[nx][nx].num - 1].y = tmp.y;
			}

			swap(map[x][y], map[nx][ny]);
		}

		cout << "���� ��" << endl;
	}
}

void solve(vector<vector<fish>> map, fish shark, vector<fish> fishList) {
	cout << "ȣ��" << endl;
	ret = max(ret, shark.count);
	
	vector<vector<fish>> afterFishMovedMap = map;
	vector<fish> afterFishMovedFishList = fishList;
	// �ǽ� ����
	fishMoving(afterFishMovedMap, afterFishMovedFishList);

	cout << "���� ��2" << endl;

	int nx = shark.x, ny = shark.y, ncount = shark.count;

	while (1) {

		nx += dx[shark.dir], ny += dy[shark.dir];

		if (nx >= 4 || nx < 0 || ny >= 4 || ny < 0) break; // �̵��� ��ġ�� ������ ����� ��ŵ.

		cout << nx << " " << ny << " " << shark.dir << endl;

		if (map[nx][ny].num == 0) continue; // ����Ⱑ ���� ĭ�̸�, ��ŵ.

		vector<vector<fish>> afterSharkMovedMap = afterFishMovedMap;
		vector<fish> afterSharkMovedFishList = afterFishMovedFishList;

		afterSharkMovedMap[shark.x][shark.y] = { 0,0,0,0,0 }; // ���� ��� ��ġ ����.
		cout << "�ֹ�1" << endl;
		fish nShark = { -1, shark.dir, nx, ny, ncount + map[nx][ny].num }; // ���Ӱ� ������Ʈ �� ���.
		
		// ���� ����Ʈ ������Ʈ(���� ����� 0���� �ʱ�ȭ)
		if(afterSharkMovedMap[nx][ny].num > 0)
			afterSharkMovedFishList[afterSharkMovedMap[nx][ny].num - 1] = { 0,0,0,0,0 };
		cout << "�ֹ�2" << endl;

		// ��� �̵�.
		afterSharkMovedMap[nx][ny] = nShark;  
		cout << "�ֹ�2" << endl;

        // map�� �ִ� ��� ��ġ �ٲ��ְ�, �ִ� �� �����ؾ���. 
		solve(afterSharkMovedMap, nShark, afterSharkMovedFishList);
	}

}

bool comp(fish a, fish b) {
	return a.num < b.num;
}

int main() {
	vector<vector<fish>> map(4, vector<fish>(4)); // 4x4 map
	vector<fish> fishList; // ����� ����Ʈ

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			map[i][j] = { a,b-1,i,j }; // map�� ����⸦ �־��ش�.
			fishList.push_back({ a,b-1,i,j }); // ���� ���� ����Ʈ�� �����.
		}
	}

	// ����� ��ȣ������ �������� ����.
	sort(fishList.begin(), fishList.end(), comp);

	// û�ҳ� ���� ���� (0,0)�� �ִ� ����⸦ �Դ´�. 
	// ���� -1 �̸�, ���� ������� ������ ������, ��ǥ�� (0,0)���� ����.
	// count�� ���� ������� ��ȣ�� �����Ѵ�.
	fish shark = { -1,map[0][0].dir,0,0,map[0][0].num}; 
	
	fishList[0] = { 0,0,0,0,0 }; // ����� ����Ʈ ������Ʈ
	map[0][0] = { -1,0,0,0,0 }; // �� ������Ʈ

	solve(map, shark, fishList);

	cout << ret;

	return 0;
}


/*
4x4 ����
�� ������ ��ȣ�� ������ ������ �ִ�. (��ȣ�� ~ 16)
8���� ������ �ִ�.
���� 0,0 ���� �����Ѵ�.
������ ��ȣ�� ���� �������� ������� �̵��Ѵ�.
������ �� ĭ�� �̵��Ѵ�. �̵� ������ ĭ�� ��ĭ �Ǵ� �ٸ� ����Ⱑ �ִ�ĭ
����Ⱑ �̵��� �� ���� ĭ�� �� �ְų� ������ ����� ���
�� ������ ������ �̵��� �� �ִ� ĭ�� ���Ҷ����� 45�� �ݽð� ȸ���� �Ѵ�.
������ �̵��� �� �ִ� ĭ�� ������ �̵����� �ʴ´�.
����Ⱑ �ٸ� ����Ⱑ �ִ� ĭ���� �̵��� ���� ������ ��ġ�� �ٲٴ� ������� �̵��Ѵ�.

������� �̵��� ��� ������ �� �̵��Ѵ�. ���� ���⿡ �ִ� ĭ���� �̵��� �� �ִµ�
�� ���� ���� ĭ�� �̵��� �� �ִ�. �� ����Ⱑ �ִ� ĭ���� �̵��ߴٸ�, �� ĭ�� �ִ� ����⸦�԰�
�� ������� ������ ������. ����Ⱑ ���� ĭ���δ� �̵��� �� ����.
�� �̵��� �� �ִ� ĭ�� ������ �����ΰ���.
*/