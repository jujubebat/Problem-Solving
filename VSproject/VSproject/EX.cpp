#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	map<string, int> m;

	m.insert({ "�ں���", 26 });
	m.insert({ "��Խ�", 24 });
	m.insert({ "�̱���", 28 });
	m.insert({ "�̱���", 25 }); // map�� �ߺ��� ���Ҹ� ������� �ʴ´�. ���� �ڵ�� ���õ�. 

	//�Ʒ��� ���� �迭 ���·� ���Ҹ� �߰��� �� �ִ�.

	/*
	m["�ں���"] = 26;
	m["��Խ�"] = 24;
	m["�̱���"] = 28;
	*/

	cout << m.count("�ں���") << endl;
	cout << m.count("��Խ�") << endl;
	cout << m.count("�̱���") << endl;

	cout << m["�ں���"] << endl;
	cout << m["��Խ�"] << endl;
	cout << m["�̱���"] << endl;

	//���ͷ����͸� ���� map�� �Ʒ��� ���� ��ȸ�� �� �ִ�.
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}

	return 0;
}