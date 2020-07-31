#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
	int x1, y1, x2, y2;
	bool flag; // true �� ����
	int time;
}robot;

bool visited[100][100][100][100];
const int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

// ���ο� �� ���� ��ǥ�� �������� üũ
bool check(int nx1, int ny1, int nx2, int ny2, vector<vector<int>>& board) {
	int n = board[0].size();
	if (nx1 >= n || nx1 < 0 || ny1 >= n || ny1 < 0) return true;
	if (nx2 >= n || nx2 < 0 || ny2 >= n || ny2 < 0) return true;
	if (board[nx1][ny1] || board[nx2][ny2]) return true;
	if (visited[nx1][ny1][nx2][ny2]) return true;
	return false;
}

int bfs(vector<vector<int>> board) {
	queue<robot> q;
	visited[0][0][0][1] = true;
	q.push({ 0,0,0,1,true,0 });
	int n = board[0].size();

	while (!q.empty()) {
		robot r = q.front();
		q.pop();

		if ((r.x1 == n - 1 && r.y1 == n - 1)
			|| (r.x2 == n - 1 && r.y2 == n - 1)) return r.time;

		int nx1, ny1, nx2, ny2;

		for (int i = 0; i < 4; i++) { // �����¿� �̵�
			nx1 = r.x1 + dx[i];
			ny1 = r.y1 + dy[i];
			nx2 = r.x2 + dx[i];
			ny2 = r.y2 + dy[i];

			if (check(nx1, ny1, nx2, ny2, board)) continue;

			visited[nx1][ny1][nx2][ny2] = true;
			q.push({ nx1, ny1, nx2, ny2, r.flag, r.time + 1 });
		}

		if (r.flag) { // �κ��� ���η� ���� ���
			// �������� ������ ������
			nx1 = r.x1 - 1, ny1 = r.y1, nx2 = r.x1, ny2 = r.y1; // �ݽð� ���� ȸ��

			if (!check(nx1, ny1, nx2, ny2, board) && board[r.x1 - 1][r.y1 + 1] == 0) {
				visited[nx1][ny1][nx2][ny2] = true;
				q.push({ nx1, ny1, nx2, ny2, !r.flag, r.time + 1 });
			}

			nx1 = r.x1, ny1 = r.y1, nx2 = r.x1 + 1, ny2 = r.y1; // �ð� ���� ȸ��
			if (!check(nx1, ny1, nx2, ny2, board) && board[r.x1 + 1][r.y1 + 1] == 0) {
				visited[nx1][ny1][nx2][ny2] = true;
				q.push({ nx1, ny1, nx2, ny2, !r.flag, r.time + 1 });

			}

			//���������� ������ ������
			nx1 = r.x2, ny1 = r.y2, nx2 = r.x2 + 1, ny2 = r.y2; // �ݽð� ���� ȸ��
			if (!check(nx1, ny1, nx2, ny2, board) && board[r.x2 + 1][r.y2 - 1] == 0) {
				visited[nx1][ny1][nx2][ny2] = true;
				q.push({ nx1, ny1, nx2, ny2, !r.flag, r.time + 1 });

			}

			nx1 = r.x2 - 1, ny1 = r.y2, nx2 = r.x2, ny2 = r.y2; // �ð� ���� ȸ��
			if (!check(nx1, ny1, nx2, ny2, board) && board[r.x2 - 1][r.y2 - 1] == 0) {
				visited[nx1][ny1][nx2][ny2] = true;
				q.push({ nx1, ny1, nx2, ny2, !r.flag, r.time + 1 });

			}

		}
		else { // �κ��� ���η� ���� ��� 
			//������ ������ ������
			nx1 = r.x1, ny1 = r.y1, nx2 = r.x1, ny2 = r.y1 + 1;  // �ݽð� ���� ȸ��
			if (!check(nx1, ny1, nx2, ny2, board) && board[r.x1 + 1][r.y1 + 1] == 0) {
				visited[nx1][ny1][nx2][ny2] = true;
				q.push({ nx1, ny1, nx2, ny2, !r.flag, r.time + 1 });
			}

			nx1 = r.x1, ny1 = r.y1 - 1, nx2 = r.x1, ny2 = r.y1;  // �ð� ���� ȸ��
			if (!check(nx1, ny1, nx2, ny2, board) && board[r.x1 + 1][r.y1 - 1] == 0) {
				visited[nx1][ny1][nx2][ny2] = true;
				q.push({ nx1, ny1, nx2, ny2, !r.flag, r.time + 1 });
			}
			//�Ʒ����� ������ ������
			nx1 = r.x2, ny1 = r.y2 - 1, nx2 = r.x2, ny2 = r.y2;  // �ݽð� ���� ȸ��
			if (!check(nx1, ny1, nx2, ny2, board) && board[r.x2 - 1][r.y2 - 1] == 0) {
				visited[nx1][ny1][nx2][ny2] = true;
				q.push({ nx1, ny1, nx2, ny2, !r.flag, r.time + 1 });
			}

			nx1 = r.x2, ny1 = r.y2, nx2 = r.x2, ny2 = r.y2 + 1;  // �ð� ���� ȸ��
			if (!check(nx1, ny1, nx2, ny2, board) && board[r.x2 - 1][r.y2 + 1] == 0) {
				visited[nx1][ny1][nx2][ny2] = true;
				q.push({ nx1, ny1, nx2, ny2, !r.flag, r.time + 1 });
			}
		}
	}

	return -1;
}

int solution(vector<vector<int>> board) {
	return bfs(board);
}