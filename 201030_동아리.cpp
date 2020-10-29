#include <iostream>
#include <cstring>	 

using namespace std;

#define NAME_SIZE	32

/*
����ü : �����ִ� �������� ��Ƽ� �ϳ��� ���ο� ���� Ÿ���� ������ִ� ����̴�.
		 ��������� ���� Ÿ���̴�.
���� : struct ����ü�� {};
�迭�� ����ü�� ������ : 1. ������ �����̴�.
						 2. ���ӵ� �޸� ���� �Ҵ��Ѵ�. ����ü ������� ���ӵ� �޸� ������ ������ �ȴ�.

*/

struct _tagStudent {
	char	strName[NAME_SIZE];
	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAvg;
};

int main() 
{
	_tagStudent tStudent;
	_tagStudent tStudentArr[100] = {};

	// ����ü ����� �����Ҷ��� . �� �̿��ؼ� �����ϰ� �ȴ�.
	tStudent.iKor = 100;

	//  ���ڿ��� �迭�� �־��� ������ �ܼ� �������δ� �Ұ����ϴ�.
	// strcpy_s ��� �Լ��� �̿��ؼ� ���ڿ��� ������ �־�� �Ѵ�.
	// strcpy_s(tStudent.strName, "�����");
	tStudent.strName[0] = 'K';
	tStudent.strName[1] = 'i';
	tStudent.strName[2] = 'm';
	// ���ڿ��� ���� �׻� 0(NULL)�� ������ �Ѵ�. �׷��� ������ ���� �� �ִ� ���¿��� �Ʒ�ó�� �� �迭 ��ҿ�
	// ���� �־��ְ� �Ǹ� �� ���� ��µǰ� �־����� ���� �κ��� �����Ⱚ���� ��µȴ�.
	// �ֳ��ϸ� ���ڿ��� ���� �ν��� �� ���� �����̴�. 0�� ���� �ϴµ� ������ ���� �� �ֱ� �����̴�.
	// ������ ���ڿ��� ������ 0���� �ʱ�ȭ �صΰ� ����������.
	tStudent.strName[3] = 0;

	// strcat_s �Լ��� ���ڿ��� �ٿ��ִ� ����̴�.
	strcat(tStudent.strName, " ���ڿ� ���̱�");

	// strcmp �Լ��� �� ���ڿ��� ���Ͽ� ������� 0�� ��ȯ�ϰ� �ٸ� ��� 0�� �ƴ� ���� ��ȯ�Ѵ�.
	strcpy(tStudent.strName, "ȫ�浿");

	cout << "ã���ô� �л� �̸��� �˻��ϼ���. : ";
	char strName[NAME_SIZE];
	cin >> strName;

	if ((strcmp(tStudent.strName, strName)) == 0)
		cout << "�л��� ã�ҽ��ϴ�." << endl;
	else
		cout << "�л��� ã�� ���߽��ϴ�." << endl;

	cout << "�̸� ���� : " << strlen(tStudent.strName) << endl;

	cout << "�̸� : " << tStudent.strName << endl;
	cout << "�й� : " << tStudent.iNumber << endl;
	cout << "���� : " << tStudent.iKor << endl;
	cout << "���� : " << tStudent.iEng << endl;
	cout << "���� : " << tStudent.iMath << endl;
	cout << "���� : " << tStudent.iTotal << endl;
	cout << "��� : " << tStudent.fAvg << endl;

	return 0;
}
