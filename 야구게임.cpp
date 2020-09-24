/*
�߱�����
1 ~ 9 ������ ������ ���� 3���� ���´�. ��, ���ڴ� �ߺ��Ǿ�� �ȵȴ�.
3���� ���ڴ� * * *�� ���·� ��µǰ� �� 3���� ���ڸ� ���ߴ� �����̴�.
����ڴ� �� 3���� ���ڸ� ���� �� ���� ����ؼ� 3���� ���ڸ� �Է��Ѵ�.
����� �� ���ڰ� 7 3 8 �� ���
����ڴ� 3���� ���ڸ� ��� �Է��Ѵ�.
�Է� : 1 2 4 �� �Է����� ��� 1 2 4 �� �ƹ��͵� �����Ƿ� Out�� ����Ѵ�.
�Է� : 7 5 9 �� �Է����� ��� 1strike 0ball�� ����Ѵ�.
�Է� : 7 8 6 �� �Է����� ��� 1strike 1ball�� ����Ѵ�.
�̷��� ��°� �Է��� �����鼭 ���������� 3���� ���ڸ� �ڸ����� ��� ��ġ�ϰ� �Է��ϸ� ������ ����ȴ�.
���� �Է¹��� ���� 3���� 1���� 0�� ���� ��� ������ �����Ѵ�.
*/

#include <iostream>	
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	int iPlayer1, iPlayer2, iPlayer3;
	int iStrike = 0, iBall_ = 0;
	int iBall[9] = {};

	while (true) {
		// �ʱ�ȭ
		system("cls"); 
		iStrike = 0;
		iBall_ = 0;
		
		// iBall �迭�� 1 ~ 9���� �������
		for (int i = 0; i < 9; ++i) {
			iBall[i] = i + 1;
		}

		// iBall Shuffle
		for (int i = 0; i < 100; ++i) {
			int iTemp, indx1, indx2;

			indx1 = rand() % 9;
			indx2 = rand() % 9;

			iTemp = iBall[indx1];
			iBall[indx1] = iBall[indx2];
			iBall[indx2] = iTemp;
		}

		// ���� �Է¹ޱ�
		cout << "���� ��������! : ";
		cin >> iPlayer1 >> iPlayer2 >> iPlayer3;

		// 2�ڸ� ���� �Է¹����� �ٽ� ����
		if ((iPlayer1 >= 10) || (iPlayer2 >= 10) || (iPlayer3 >= 10)) {
			cout << "1 ~ 9 �� ������ ���� �����ּ���." << endl;
			continue;
		}

        // 0 ������ ���� ����
		if ((iPlayer1 == 0) || (iPlayer2 == 0) || (iPlayer3 == 0)) {
			cout << "0 �� ���� ���� ������ �����մϴ�." << endl;
			break;
		}

		// ���� ���� 2���� �ȵȴ�.
		if ((iPlayer1 == iPlayer2) || (iPlayer2 == iPlayer3) || (iPlayer3 == iPlayer1)) {
			cout << "���� �ٸ� ���� �����ּ���." << endl;
			continue;
		}

		// ��Ʈ����ũ ���� ����
		if (iPlayer1 == iBall[0]) {
			iStrike += 1;
		}
		if (iPlayer2 == iBall[1]) {
			iStrike += 1;
		}
		if (iPlayer3 == iBall[2]) {
			iStrike += 1;
		}

		// �� ���� ����
		if ((iPlayer1 == iBall[1]) || (iPlayer1 == iBall[2])) {
			iBall_ += 1;
		}
		if ((iPlayer2 == iBall[0]) || (iPlayer2 == iBall[2])) {
			iBall_ += 1;
		}
		if ((iPlayer3 == iBall[0]) || (iPlayer3 == iBall[1])) {
			iBall_ += 1;
		}

		// ���� �����ֱ�
		cout << "          ���� : " << iBall[0] << " " << iBall[1] << " " << iBall[2] << endl;
		cout << iStrike << "Strike  " << iBall_ << "Ball" << endl;

		// �� ���߸� ���� ����
		if (iStrike == 3) {
			cout << "�� ���ڸ� ��� ���� ������ �����մϴ�." << endl;
			break;
		}
		
		system("pause"); 
	}

	return 0;
}
