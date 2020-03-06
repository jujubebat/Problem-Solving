//�ڱ⺸�� 1 ���� ���� ������, 
//�ڽ��� ��ġ���� -L ��ŭ �ڽŸ�ŭ ũ�Ⱑ �ִ� ���� �ִ��� Ȯ��
//�ڱ⺸�� 1 ���� ���� ������, 
//�ڽ��� ��ġ���� +L ��ŭ �ڽŸ�ŭ ũ�Ⱑ �ִ� ���� �ִ��� Ȯ��
//���� Ȯ���ϴٰ� �ȵǴ� ��찡 ������, Ż��

#include<iostream>
using namespace std;

int map[100][100];
int res = 0;
int N, L;

bool checkRow(int row){
	bool check[100] = { false };
	int cnt;
	for (int j = 0; j < N-1; j++) {
		if (map[row][j] == map[row][j + 1] - 1) {// ���� ���� 1���� ��
			cnt = 1;
			while (j - cnt >= 0) {
				if (map[row][j] + 1 == map[row][j - cnt]) {
					if (check[j - cnt]) return false; //�̹� ���θ� ��������, x
					check[j - cnt] = true;
					cnt++;
				}
				else break;
			}
			if (cnt != L) return false;
			if (j + cnt != 0 && map[row][j + cnt - 1] != map[row][j] + 1)
				return false;
		}
		else if (map[row][j] == map[row][j + 1] + 1) { //���� ���� 1���� ��
			cnt = 1;
			while (j + cnt < N) {
				if (map[row][j] - 1 == map[row][j + cnt]) {
					if (check[j + cnt]) return false;  //�̹� ���θ� ��������, x
					check[j + cnt] = true;
					cnt++;
				}
				else break;
			}
			if (cnt != L) return false;
			if (j + cnt != N - 1 && map[row][j + cnt + 1] != map[row][j] - 1)
				return false;
		}
		else
			return false;
			
	}
}

bool checkColumn(int col) {
	int row=0;
	bool check[100] = { false };
	int cnt;
	for (int j = 0; j < N - 1; j++) {
		if (map[row][j] == map[row][j] - 1) {// ���� ���� 1���� ��
			cnt = 1;
			while (j - cnt >= 0) {
				if (map[row][j] + 1 == map[row][j - cnt]) {
					if (check[j - cnt]) return false; //�̹� ���θ� ��������, x
					check[j - cnt] = true;
					cnt++;
				}
				else break;
			}
			if (cnt != L) return false;
			if (j + cnt != 0 && map[row][j + cnt - 1] != map[row][j] + 1)
				return false;
		}
		else if (map[row][j] == map[row][j] + 1) { //���� ���� 1���� ��
			cnt = 1;
			while (j + cnt < N) {
				if (map[row][j] - 1 == map[row][j + cnt]) {
					if (check[j + cnt]) return false;  //�̹� ���θ� ��������, x
					check[j + cnt] = true;
					cnt++;
				}
				else break;
			}
			if (cnt != L) return false;
			if (j + cnt != N - 1 && map[row][j + cnt + 1] != map[row][j] - 1)
				return false;
		}
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		if (checkRow(i))
			res++;

		//if (checkColumn(i))
			//res++;
	}
}

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	printf("%d", res);
	return 0;
}