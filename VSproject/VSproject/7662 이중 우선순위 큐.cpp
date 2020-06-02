/*
������ ����


�켱���� ť�� ����� �ִ밪�� �ּҰ� ���. 
ť�� ����ٸ�, Empty ���
*/
// 1 1 1

// �����Ҷ� map, max heap, min heap�� ������ ����
// �켱���� ���� ���� ������ ���� max heap���� ������ ���� map ����
// �켱���� ���� ���� ������ ���� min heap���� ������ ���� map ����

#include<iostream>
#include<queue>
#include<map>
using namespace std;

int main() {
	
	int t;

	cin >> t;

	while (t--) {
		int k;

		map<int, int> m; // ������, ���� 
		priority_queue<int> maxHeap;
		priority_queue<int> minHeap;

		cin >> k;
		for (int i = 0; i < k; i++) {
			char op; int num;
			cin >> op >> num;

			if (op == 'I') {
				m[num]++;
				maxHeap.push(num);
				minHeap.push(-num);
			}
			else if (op == 'D') {
				if (num == 1 && !maxHeap.empty()) {
					//cout << "fuck1" << endl;
					while (!maxHeap.empty() && m[maxHeap.top()] <= 0) {
						maxHeap.pop();
					}
					//cout << "fuck2" << endl;

					if (!maxHeap.empty()) {
						m[maxHeap.top()]--;
						maxHeap.pop();
					}
					//cout << "fuck3" << endl;

				}
				else if (num == -1 && !minHeap.empty()) {
					while (!minHeap.empty() && m[-minHeap.top()] <= 0) {
						minHeap.pop();
					}
					if (!minHeap.empty()) {
						m[-minHeap.top()]--;
						minHeap.pop();
					}
					
				}
			}
		}

		while (!maxHeap.empty() && m[maxHeap.top()] <= 0) {
			maxHeap.pop();
		}

		while (!minHeap.empty() && m[-minHeap.top()] <= 0) {
			minHeap.pop();
		}

		if (maxHeap.empty() || minHeap.empty()) {
			cout << "EMPTY" << endl;
		}
		else {
			cout << maxHeap.top() << " " << -minHeap.top();
		}

	}

	return 0;
}