#include<iostream>
#include<algorithm>
using namespace std;

int arr[300000];

int main() {
	int n, b, w;
	cin >> n >> b >> w;

	for (int i = 0; i < n; i++) {
		char ch;
		cin >> ch;

		if (ch == 'W') arr[i] = 1;
	}

	int ret = 0;
	int low = 0, high = 0;
	int white = 0, black = 0;

	while (high <= n) {
		//cout << "���൹" << white << " " << black << endl;
		if (white >= w && black <= b) { // ������ �����Ѵٸ�,
			//cout << "���൹" << white << " " << black << endl;
			//cout << low << " " << high << endl;
			ret = max(ret, high - low); // ���� ���� �����ϰ�,
			if (arr[high++]) // �� �� ������ �ִ��� Ȯ���غ���.
				white++;
			else
				black++;
		}
		else if (white < w) { // �� ���൹�� ���ڶ��,
			if (arr[high++]) // ������ �÷�����.
				white++;
			else
				black++;
		}
		else if (black > b) { // ���� ���൹�� ������,
			if (arr[low++]) // ������ �ٿ�����.
				white--;
			else
				black--;
		}
	}

	cout << ret;

	return 0;
}

// �������ͷ� ���� ���캸�鼭, ���ǿ� �´� �������� ����