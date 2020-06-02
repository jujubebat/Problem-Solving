#include <string>
#include <vector>
#include<stack>
using namespace std;

bool isRigt(string s) { // ���� s�� �ùٸ� ���ڿ����� �Ǻ����ش�. 
	stack<char> st;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ')') {
			if (!st.empty() && st.top() == '(')
				st.pop();
			else
				st.push(s[i]);
		}
		else {
			st.push(s[i]);
		}
	}

	if (st.empty())
		return true;
	else
		return false;
}

string solve(string w) {
	if (w == "") return ""; // 1. �Է��� �� ���ڿ��� ���, �� ���ڿ��� ��ȯ�մϴ�. 
	
	string u, v;
	stack<char> st;
	int idx;

	// 2. ���ڿ� w�� �� "�������� ��ȣ ���ڿ�" u, v�� �и��մϴ�.
	// ��, u�� "�������� ��ȣ ���ڿ�"�� �� �̻� �и��� �� ����� �ϸ�, 
	// v�� �� ���ڿ��� �� �� �ֽ��ϴ�.
	int left = 0, right = 0;

	for (int i = 0; w.size(); i++) {
		if (w[i] == '(') left++;
		else if (w[i] == ')') right++;

		if (left != 0 && right != 0) {
			if (left == right) {
				idx = i;
				break;
			}
		}
	}

	u = w.substr(0, idx+1);
	v = w.substr(idx + 1);

	// 3. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�" �̶�� ���ڿ� v�� ���� 1�ܰ���� �ٽ� �����մϴ�.
	if (isRigt(u)) 
		return u + solve(v); // 3-1. ������ ��� ���ڿ��� u�� �̾� ���� �� ��ȯ�մϴ�. 
	else{ // 4. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�"�� �ƴ϶�� �Ʒ� ������ �����մϴ�. 
		
		string tmp = "("; // 4 - 1. �� ���ڿ��� ù ��° ���ڷ� '('�� ���Դϴ�.
		// 4 - 2. ���ڿ� v�� ���� 1�ܰ���� ��������� ������ ��� ���ڿ��� �̾� ���Դϴ�.
		tmp += solve(v); 
		tmp += ")"; // 4-3. ')'�� �ٽ� ���Դϴ�.

		string newU = "";
		// 4-4. u�� ù ��°�� ������ ���ڸ� �����ϰ�, ������ ���ڿ��� ��ȣ ������ ����� �ڿ� ���Դϴ�. 
		for (int i = 1; i < u.size()-1; i++) {
			if (u[i] == '(')
				newU += ")";
			else
				newU += "(";
		}
		return tmp + newU; // 4-5. ������ ���ڿ��� ��ȯ�մϴ�.
	}
}

string solution(string p) {
	string answer = "";
	answer = solve(p);
	return answer;
}