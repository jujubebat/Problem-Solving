//////////���� Ǯ�� ����///////////////

/*
while(1){
���̵� �Լ�(1������ k�������� �̵���Ű��)
 -����� ���
 -�������� ���
 -�Ķ����� ���
���� 4�� �׿��ִ��� �˻�
 -���� 4�� �׿��ִٸ�, �ϼ� ���
}
*/

#include<iostream>
#include<vector>

using namespace std;

typedef struct {
	int num, d;
	int x, y;
}piece;

int n, k;
int map[12][12]; //0 ���, 1 ������, 2 �Ķ��� 
int res = 0;
vector<int> pieceMap[12][12]; 
piece pieceInfo[11]; //�� ������ ���� �迭

void whiteMoving(int p, int nx, int ny) {
	int x = pieceInfo[p].x, y = pieceInfo[p].y,idx=0;
	for (int i = 0; i < pieceMap[x][y].size(); i++) {//p�� ���� ��ǥ���� ����� ��ȸ
		if (p == pieceMap[x][y][i]) { //p�� �߰��ϸ�,
			idx = i;
			for (int j = i; j < pieceMap[x][y].size(); j++) {//p�� p���� ������ ���ο� ��ǥ�� �ű�
				int cur = pieceMap[x][y][j];
				pieceMap[nx][ny].push_back(cur);
				pieceInfo[cur].x = nx, pieceInfo[cur].y = ny;
			}
			break;
		}
	}
	pieceMap[x][y].erase(pieceMap[x][y].begin() + idx, pieceMap[x][y].end());
}

void redMoving(int p, int nx, int ny) {
	int x = pieceInfo[p].x, y = pieceInfo[p].y, idx = 0;
	for (int i = 0; i < pieceMap[x][y].size(); i++) {//p�� ���� ��ǥ���� ����� ��ȸ
		if (p == pieceMap[x][y][i]) { //p�� �߰��ϸ�,
			idx = i;
			for (int j = pieceMap[x][y].size() - 1; j >= i; j--) {//p�� p���� ������ ���ο� ��ǥ�� �ű�
				int cur = pieceMap[x][y][j];
				pieceMap[nx][ny].push_back(cur);
				pieceInfo[cur].x = nx, pieceInfo[cur].y = ny;
			}
			break;
		}
	}
	pieceMap[x][y].erase(pieceMap[x][y].begin() + idx, pieceMap[x][y].end());
}

void blueMoving(int p) {
	int d = pieceInfo[p].d, x= pieceInfo[p].x, y = pieceInfo[p].y;
	int nx, ny;

	if (d == 1) {//������
		nx = x, ny = y - 1;
		pieceInfo[p].d = 2;
	}
	else if (d == 2) {//����
		nx = x, ny = y + 1;
		pieceInfo[p].d = 1;
	}
	else if (d == 3) {//����
		nx = x+1, ny = y;
		pieceInfo[p].d = 4;
	}
	else if (d == 4) {//�Ʒ��� 
		nx = x-1, ny = y;
		pieceInfo[p].d = 3;
	}

	//�ݴ��� ĭ �˻�
	if (nx >= n || nx < 0 || ny >= n || ny < 0 || map[nx][ny] == 2) 
		return;
	else if (map[nx][ny] == 0) {
		whiteMoving(p, nx, ny);
	}
	else if (map[nx][ny] == 1) {
		redMoving(p, nx, ny);
	}
}

//���� : 1 ��, 2 ��, 3 ��, 4 �� 
void movingPiece(int p, int nx, int ny) {
	if (nx >= n || nx < 0 || ny >= n || ny < 0 || map[nx][ny] == 2) { // �Ķ��� or ü���� �ܺ�
		blueMoving(p);
	}
	else if (map[nx][ny] == 0) { // ���
		whiteMoving(p, nx, ny);
	}
	else if (map[nx][ny] == 1) {// ������
		redMoving(p, nx, ny);
	}
}

void movingAll() {//���� ����� ���� ��ġ�� ���� ���� ��ǥ
	for (int i = 1; i <= k; i++) {
		int x = pieceInfo[i].x, y = pieceInfo[i].y, d = pieceInfo[i].d;
		if (d == 1) {//������
			movingPiece(i, x, y + 1);
		}
		else if (d == 2) {//����
			movingPiece(i, x, y - 1);
		}
		else if (d == 3) {//����
			movingPiece(i, x - 1, y);
		}
		else if (d == 4) {//�Ʒ��� 
			movingPiece(i, x + 1, y);
		}
	}
}

bool isFourStack() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (pieceMap[i][j].size() >= 4)
				return true;
		}
	}
	return false;
}

void solve() {
	while (1) {
		movingAll();
		res++;
		if (res >= 1000) {
			printf("-1");
			return;
		}
		if (isFourStack())
			break;
	}
	printf("%d", res);
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int x, y, d;
	for (int i = 1; i <= k; i++) {
		cin >> x >> y >> d;
		x -= 1, y -= 1;
		pieceInfo[i] = { i, d, x, y };
		pieceMap[x][y].push_back(i);
	}
	solve();
}