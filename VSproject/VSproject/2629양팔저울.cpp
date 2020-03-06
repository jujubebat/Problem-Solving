/*#include<iostream>
using namespace std;

int weights[30];
int beads[7];
bool d[15001];
int n, k;

void solve(int cnt, int beadWeight) {
	if (cnt > n) return;
	if (d[beadWeight]) return;

	d[beadWeight] = true;
	d[beads[cnt + 1]] = true;

	solve(cnt+1, beadWeight);//case1
	solve(cnt + 1, beadWeight + beads[cnt]);//case2
	solve(cnt + 1, abs(beadWeight - beads[cnt]));
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> weights[i];
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> beads[i];
	}

	solve(0,0);

	for (int i = 0; i < k; i++) {
	
			if (d[beads[i]])
				printf("Y ");
			else
				printf("N ");
	}

	return 0;
}*/

#include <iostream>

#include <cstring> //memset

#include <algorithm>

using namespace std;



const int MAX = 30;



int weightNum, marbleNum; //�� ����, ���� ����

int weight[MAX]; //��

int marble[7]; //����

int cache[MAX + 1][MAX * 500 + 1]; //���� ����, ���� ������ ���� �� �ִ� ����



void preCalculate(int currentWeightNum, int currentWeight) //���� ���� ����, ���� ����� �� ����

{

	//���� ���

	if (currentWeightNum > weightNum)

		return;



	int &result = cache[currentWeightNum][currentWeight];

	if (result != -1)

		return;



	cache[currentWeightNum][currentWeight] = 1; //���� ������� ���� ���



	//������ ���� ������ �����ϰ� �ش� �߸� ������ ���� ���￡ �ø� ���

	preCalculate(currentWeightNum + 1, currentWeight + weight[currentWeightNum]);

	//������ ���� ������ ���������� �ش� �߸� ��� ���￡�� �ø��� ���� ���

	preCalculate(currentWeightNum + 1, currentWeight);

	//������ ���� ������ �����ϰ� �ش� �߸� ���� �ʿ� �ִ� ���￡ �ø� ���

	preCalculate(currentWeightNum + 1, abs(currentWeight - weight[currentWeightNum]));

}



int main(void)

{

	cin >> weightNum;

	for (int i = 0; i < weightNum; i++)

		cin >> weight[i];



	cin >> marbleNum;

	for (int i = 0; i < marbleNum; i++)

		cin >> marble[i];



	memset(cache, -1, sizeof(cache));

	preCalculate(0, 0); //��� ������ ��츦 ����



	for (int i = 0; i < marbleNum; i++)

	{

		if (marble[i] > MAX * 500) //500g �� 30���� �߰��� �ͺ��� ���ſ� �����̶��

			cout << "N ";

		else if (cache[weightNum][marble[i]] == 1)

			cout << "Y ";

		else

			cout << "N ";

	}


	for (int i = 0; i < weightNum; i++) {
		for (int j = 0; j < marbleNum; j++) {
			printf("%d %d %d\n", i,j,cache[weightNum][marble[j]]);
		}
	}

	cout << endl;

	return 0;



}

