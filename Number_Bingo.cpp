/*
숫자빙고게임
1 ~ 25 까지의 숫자가 있고 이 숫자를 골고루 섞어 5 x 5 로 출력한다.
플레이어는 숫자를 입력한다. 1 ~ 25 사이의 숫자를 입력한다.
0을 입력하면 게임을 종료한다.

숫자를 입력받았으면 숫자목록중 입력받은 숫자를 찾아서 *로 만들어준다.
숫자를 *으로 만든 후 빙고 줄 수를 체크한다. 5 x 5이기 때문에 가로 5줄 세로 5줄 대각선 2줄이 나올 수 있다.
빙고줄이 몇줄인지 체크해서 화면에 보여준다.
5줄 이상일 경우 게임을 종료한다.
*/

#include <iostream>
#include <time.h>

using namespace std;

int main() 
{
	srand((unsigned int)time(0));
	int iNumber[25] = {};
	int iBingo = 0;

	// iNumber 에 0 ~ 25 사이 숫자 저장
	for (int i = 0; i < 25; ++i) {
		iNumber[i] = i + 1;
	}

	// iNumber shuffle
	for (int i = 0; i < 100; ++i) {
		int iTemp, indx1, indx2;
		indx1 = rand() % 25;
		indx2 = rand() % 25;

		iTemp = iNumber[indx1];
		iNumber[indx1] = iNumber[indx2];
		iNumber[indx2] = iTemp;
	}
	while(true) {
		system("cls");

		// iNumber 5 x 5 로 출력
		for (int i = 0; i < 5; ++i) {
			for (int j = 5 * i; j < 5 * i + 5; ++j) {
				if (iNumber[j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[j] << "\t";
			}
			cout << endl;
		}
		cout << "빙고 : " << iBingo << endl;

		if (iBingo >= 5) {
			cout << "빙고 5줄을 완성해 게임을 종료합니다." << endl;
			break;
		}

		// 숫자 입력받음
		cout << "숫자를 입력하세요(종료 : 0) : ";
		int cinput;
		cin >> cinput;

		// 0 누르면 종료, 잘못된 숫자를 입력하면 다시 입력받기
		if (cinput == 0) {
			cout << "0 을 눌러 게임을 종료합니다." << endl;
			break;
		}
		else if ((cinput < 1) || (cinput > 25)) {
			continue;
		}

		// 누른 숫자 별로 나타내기
		for (int i = 0; i < 25; ++i) {
			if (iNumber[i] == cinput) {
				iNumber[i] = INT_MAX;
			}
		}

		int iHorizontal = 0, iVertical = 0, iDiagonal1 = 0, iDiagonal2 = 0;
		iBingo = 0;

		// 빙고체크
		for (int i = 0; i < 5; ++i) {
			iHorizontal = 0;
			iVertical = 0;
			for (int j = 0; j < 5; ++j) {
				// 가로 빙고
				if (iNumber[i * 5 + j] == INT_MAX) 
					++iHorizontal;
				// 세로 빙고
				if (iNumber[j * 5 + i] == INT_MAX) 
					++iVertical;
			}
			if (iHorizontal == 5)
				++iBingo;
			if (iVertical == 5)
				++iBingo;
		}
		
		// \대각선
		for (int i = 0; i < 25; i += 6) {
			if (iNumber[i] == INT_MAX)
				++iDiagonal1;
		}
		if (iDiagonal1 == 5)
			++iBingo;

		// /대각선
		for (int i = 4; i < 21; i += 4) {
			if (iNumber[i] == INT_MAX)
				++iDiagonal2;
		}
		if (iDiagonal2 == 5)
			++iBingo;
	}

	return 0;
}