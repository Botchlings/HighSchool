/*
2020.09.11 ���Ƹ� Ȱ��

�Է� ���
���ǹ� (if, switch)
����
����ü
�ݺ��� (while)
*/

// ������� inlcude
#include <iostream>   // �⺻ ����� 
#include <ctime>      // ���� 
#include <cstdlib>    // ���� 

// std:: ����
using namespace std;

/*
����ü : ���ӵ� ���ڿ� �̸��� �ο��� �� �ִ� ����̴�.
���� : enum ����ü�� {}
����ü���� �̿��ؼ� ����ü Ÿ���� ������ ���� �����ϴ�.
��, ����ü ��ü�� ��������� ���� Ÿ���� �� �� �ִ�.
*/

enum NUM
{
	NUM_0, // �ƹ��͵� �ο����� ���� ��� 0���� 1�� ���ʷ� ���� �ο��ȴ�.
	NUM_1,
	NUM_2,
	NUM_3
};

int main()
{
	int iNumber;
	cout << "���ڸ� �Է��ϼ���. : ";
	cin >> iNumber;
	cout << "�Է��Ͻ� ���ڴ� " << iNumber << "�Դϴ�." << endl;

	/*
	if�� : ������ üũ���ִ� ����̴�.
	���� : if(���ǽ�) {}(�ڵ��)
	if���� ���ǽ��� true�� �� ��� �ڵ�� ���� �ڵ尡 ����ȴ�.
	false�� ��쿡�� ���۵��� �ʴ´�.
	*/

	if (true) {
		cout << "���Դϴ�." << endl;
	}

	// if���� �ڵ���� �����̸� {} ��������
	if (true)
		cout << "���Դϴ�." << endl;

	/*
	else : if ���� �ݵ�� ���� ���Ǿ�� �Ѵ�.
	if�� ������ false�� ��� else�� �ִٸ� else ���� ���� �ڵ尡 ���۵ȴ�.

	else if : if ���� �ݵ�� ���� �;��ϰ� if �Ʒ� else ���� ��ġ�Ѵ�.
	*/
	cin >> iNumber;
	if (iNumber >= 0 && iNumber < 10)
		cout << "0�̻� 10�̸�" << endl;
	else if (iNumber >= 10 && iNumber < 20)
		cout << "10�̻� 20�̸�" << endl;
	else
		cout << "20�̻� �Ǵ� 0�̸�" << endl;

	// ���� �߻�
	cout << rand() << endl;
	cout << rand() % 101 << endl;
	cout << (rand() % 10000) / 100.f << endl;

	/*
	switch�� : �б⹮�� �� �����̴�. if���� ���ǹ��� üũ�ϴ� �б⹮�̶��
	switch���� ���� ������ üũ�ϴ� �б⹮�̴�.
	���� : switch(����) {}
	       �ڵ�� �ȿ��� case break ������ ���� �ȴ�.
		   case ���: �� ���·� ó���� �ǰ� �������� ���������� ���� case �ڿ� ���� ����� ���ϰ� �ȴ�.
	*/

	cin >> iNumber;

	switch (iNumber) {
	case 1: 
		cout << 1 << endl;
		break;
	case 2: 
		cout << 2 << endl;
		break;
	case 3: 
		cout << 3 << endl;
		break;
	default: 
		cout << 0 << endl;
		break;
	}

	switch (iNumber) {
	case NUM_1:
		cout << 1 << endl;
		break;
	case NUM_2:
		cout << 2 << endl;
		break;
	case NUM_3:
		cout << 3 << endl;
		break;
	default:
		cout << 0 << endl;
		break;
	}

	/*
	���� : while(���ǽ�) {}
	���ǽ��� ���̸� �ڵ������ �ڵ尡 ���۵�.
	�ݺ��� �ȿ��� break�� ������ �ݺ����� ���������� �ȴ�.
	*/
	iNumber = 0;
	while (iNumber < 10) {
		if (iNumber == 5) {
			break;
		}

		cout << iNumber << endl;
		++iNumber;
	}

	return 0;
}
