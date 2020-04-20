#include<iostream>
#include<bitset>
using namespace std;

int main() {
	puts("[��Ʈ ���� �⺻]\n");
	cout << "���� 6�� 32bit�� ��� : " << bitset<32>(6) << endl;
	cout << "���� 4�� 32bit�� ��� : " << bitset<32>(4) << endl;
	cout << "6�� 4�� and ���� : " << bitset<32>(6 & 4) << endl;
	cout << "6�� ���������� 1�� shfit : "<< bitset<32>(6 >> 1) << endl;
	cout << "4�� �������� 2�� shfit : "<<bitset<32>(4 << 2) << endl;

	puts("\n[20���� ������ �ִ� ������ ����] : ��Ʈ����ũ�� ���� ���� ������ ���� �� �ִ�.\n");

	puts("1.�� ���� ���ϱ�(������ �ϳ��� �� ���� ���)");
	int pizza = 0;
	cout << bitset<32>(pizza) << "\n\n";

	puts("2.���� ���� ���ϱ�(������ 20���� �� ���� ���)");
	pizza = (1 << 20) - 1;
	cout << bitset<32>(pizza) << "\n\n";

	puts("3.���ڿ� 7�� ���� �߰��ϱ�");
	int p = 7;
	pizza = 0;
	pizza |= (1 << p); 
	cout << bitset<32>(pizza) << "\n\n";

	puts("4.���ڿ� 7�� ������ ���Ե��ִ��� Ȯ���ϱ�");
	if (pizza & (1 << p)) cout << "7�� ���� ���ԵǾ� �ֽ��ϴ�.\n\n";
	
	puts("5.���ڿ� 7�� ���� �����ϱ�");
	pizza &= ~(1 << p);
	cout << bitset<32>(pizza) << "\n\n";

	puts("6.4���� ������ ������ ���� ��, ���ڸ� ����� ����� ��");
	pizza= 15;
	for (int subset = pizza; subset; subset -=1 ) {
		cout << bitset<32>(subset) << " : " << subset << endl;
	}

	return 0;
}