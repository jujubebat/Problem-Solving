#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

long long cal(vector<long long> num , vector<char> oper, vector<char> operPirority) {

	// �־��� ������ �켱���� ������ �����ڸ� ���������� Ž���Ѵ�.
	// (operPirority�� ����ִ� ������ ������ �켱���� ������.)
	for (char priority : operPirority) {
		for (int i = 0; i < oper.size(); i++) {
			if (oper[i] == priority) { // �����ڿ� ���ڰ� ����ִ� �� ���͸� Ž���ϸ� ����Ѵ�.
				long long calResult;
				if (priority == '*') {
					calResult = num[i] * num[i + 1];
				}
				else if(priority == '+') {
					calResult = num[i] + num[i + 1];
				}
				else if (priority == '-') {
					calResult = num[i] - num[i + 1];
				}
				num[i] = calResult; 
				num.erase(num.begin() + i + 1);
				oper.erase(oper.begin() + i);
				i--;
			}
		}
	}
	
	return abs(num[0]); // ���밪�� �����Ѵ�. 
}

long long solution(string expression) {

	long long answer = 0;
	vector<char> oper; // �����ڸ� ��� ����
	vector<long long> num; // ���ڸ� ��� ����
	vector<char> operPirority; // ������ �켱������ ��� ����
	
	string tmpNum = "";
	bool check[1000000];
	memset(check, false, sizeof(check));

	// �־��� ǥ���Ŀ��� �����ڿ�, ���ڸ� �����Ѵ�.
	for (int i = 0; i < expression.size(); i++) {
		if (isdigit(expression[i])) { // ���� ������ ��� tmpNum�� �ӽ�����.
			tmpNum += expression[i];
		} else if (expression[i] == '+' // �������ϰ��
			|| expression[i] == '-' 
			|| expression[i] == '*') {

			// ǥ���Ŀ� ������ �����ڸ� �� ������ �ִ´�.
			// operPirority ���ʹ� ������ �켱������ ǥ���ϴ� �뵵�̴�.
			if (!check[expression[i]]) {
				check[expression[i]] = true;
				operPirority.push_back(expression[i]); 
			}

			oper.push_back(expression[i]); // ������ ���Ϳ� �ִ´�.
			num.push_back(stoi(tmpNum)); // tmpNum�� ���ڷ� �ٲ㼭 ���� ���Ϳ� �ִ´�.
			tmpNum = ""; // ���� ���ڸ� ������� tmpNum �ʱ�ȭ
		}
	}

	num.push_back(stoi(tmpNum)); // ������ ���ڸ� �ִ´�.

	// operPirority�� ����ִ� �����ڵ鿡 ���Ͽ� ������ ���Ѵ�.
	// ��� ������ ���Ѵٴ� �� == ��� �켱���� ������ ���Ѵٴ� ��.
	sort(operPirority.begin(), operPirority.end()); 

	do {
		// ���ڸ� ���� ����, �����ڸ� ���� ����, 
		// next_permutation���� ���� ������ �켱������ ����ִ� ���͸�
		// cal �Լ��� ���ڷ� �־��ְ� ���� ������Ѵ�. 
		// ����� ����� ���� �ִ밪 ���θ� Ȯ���ϰ� �����Ѵ�. 
		answer = max(answer, cal(num, oper, operPirority));
	} while (next_permutation(operPirority.begin(), operPirority.end()));

	return answer;
}