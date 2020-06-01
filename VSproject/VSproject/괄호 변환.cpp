#include <string>
#include <vector>
#include<stack>
using namespace std;

bool isBalance() {

}

bool isRigt() {

}

string solve(string w) {
	if (w == "") return "";

	string u, v;
	stack<char> st;
	int num;

	int left = 0, right = 0;
	for (int i = 0; w.size(); i++) {
		if (w[i] == '(') left++;
		else if (w[i] == ')') right++;

		if (left != 0 && right != 0) {
			if (left == right) {
				num = i;
				break;
			}
		}

	}
	u = w.substr(0, num+1);
	v = w.substr(num, w.size() - num - 1);

}

string solution(string p) {
	string answer = "";
	answer = solve(p);
	return answer;
}

/*
"()))((()"

1. �Է��� �� ���ڿ��� ���, �� ���ڿ��� ��ȯ�մϴ�.
2. ���ڿ� w�� �� "�������� ��ȣ ���ڿ�" u, v�� �и��մϴ�.��, u�� "�������� ��ȣ ���ڿ�"�� �� �̻� �и��� �� ����� �ϸ�, v�� �� ���ڿ��� �� �� �ֽ��ϴ�.
3. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�" �̶�� ���ڿ� v�� ���� 1�ܰ���� �ٽ� �����մϴ�.
3 - 1. ������ ��� ���ڿ��� u�� �̾� ���� �� ��ȯ�մϴ�.

4. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�"�� �ƴ϶�� �Ʒ� ������ �����մϴ�.
4 - 1. �� ���ڿ��� ù ��° ���ڷ� '('�� ���Դϴ�.
4 - 2. ���ڿ� v�� ���� 1�ܰ���� ��������� ������ ��� ���ڿ��� �̾� ���Դϴ�.
4 - 3. ')'�� �ٽ� ���Դϴ�.
4 - 4. u�� ù ��°�� ������ ���ڸ� �����ϰ�, ������ ���ڿ��� ��ȣ ������ ����� �ڿ� ���Դϴ�.
4 - 5. ������ ���ڿ��� ��ȯ�մϴ�.
*/