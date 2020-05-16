#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[300000];
int sum = 0;

int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	int low = 1, high = 1000000000;
	int ret = 1000000000;
	while (low <= high) {
		cout << low << " " << high << endl;
		int mid = (low + high) / 2; // ������ ������ ��������
		int cnt = 0; // mid �������� �� ���� ������ �� �ִ��� ī��Ʈ

		for (int i = 0; i < m; i++) {
			cnt += arr[i] / mid;
			if (arr[i] % mid)
				cnt++;
		}

		if (n >= cnt) { // n���� ���ų� ���� ������ �� �־���.
			ret = min(ret, mid);
			high = mid - 1; // ������ ���� ���� ������ �ٿ��� �� ���� �����ຸ��!
		}
		else { // n���� ���� ������ �� �־���.
			low = mid + 1; // ������ ���� ���� ������ �÷��� �� ���� �����ຸ��!
		}
	}

	//cout << low;
	cout << ret;
	return 0;
}
