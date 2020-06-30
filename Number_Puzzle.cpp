#include <iostream>
#include <time.h>
#include <conio.h> // console input output 헤더파일이다. 콘솔창에서 입출력하는 기능들을 제공해주는 파일이다.

using namespace std;

int main() {
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 24; ++i) {
		iNumber[i] = i + 1;
	}

	// 가장 마지막 칸은 공백으로 비워둔다. 공백을 의미하는 값으로 특수한 값을 사용할 건데 INT_MAX라는 값을 사용한다.
	// INT_MAX는 이미 정의되어있는 값으로 int로 표현할 수 있는 최대값이다.
	iNumber[24] = INT_MAX;

	// 별이 있는 위치를 만들어준다.
	int iStarindex = 24;

	// 마지막 공백을 제외하고 1 ~ 24 까지의 숫자만 섞어준다.
	// 즉 0 ~ 23번 인덱스까지만 섞어준다.
	for (int i = 0; i < 100; ++i) {
		int iTemp, indx1, indx2;

		indx1 = rand() % 24;
		indx2 = rand() % 24;

		iTemp = iNumber[indx1];
		iNumber[indx1] = iNumber[indx2];
		iNumber[indx2] = iTemp;
	}

	while (true) {

		system("cls");

		// iNumber 을 5x5로 출력한다.
		for (int i = 0; i < 5; ++i) {
			for (int j = i * 5; j < i * 5 + 5; ++j) {
				if (iNumber[j] == INT_MAX) {
					cout << "*" << "\t";
				}
				else
					cout << iNumber[j] << "\t";
			}
			cout << endl;
		}

		// 플레이어가 퍼즐을 맞췄다고 가정한다.
		bool bWin = true;

		// 퍼즐을 맞췄는지 체크한다.
		for (int i = 0; i < 24; ++i) {
			if (iNumber[i] != i + 1) {
				bWin = false;
				break;
			}
		}

		if (bWin == true) {
			cout << "퍼즐을 모두 맞췄습니다." << endl;
			break;
		}

		cout << "| w : 위 | s : 아래 | a : 왼쪽 | d : 오른쪽 | q : 종료 |";
		// _getch() 함수는 문자 1개를 입력받는 함수이다.
		// 이 함수는 Enter을 치지 않더라도 문자를 누르는 순간 바로 그 문자를 반환하고 종료한다.
		char cinput = _getch();

		if ((cinput == 'q') || (cinput == 'Q')) {
			cout << endl << "게임을 종료합니다." << endl;
			break;
		}

		switch (cinput) {
		case 'w':
		case 'W':
			// 가장 윗줄일때는 w를 눌러도 작동해선 안된다.
			if (iStarindex > 4) {
				// 별이 있는 위치에 바로 위에 있는 값을 넣어준다.
				iNumber[iStarindex] = iNumber[iStarindex - 5];
				// 위의 위치에 별을 넣어주어서 2개의 값을 스왑한다.
				iNumber[iStarindex - 5] = INT_MAX;
				// 별이 한칸 위로 올라갔으므로 한칸 위의 인덱스로 만들어준다.
				iStarindex -= 5;
				break;
			}
		case 'a':
		case 'A':
			if (iStarindex % 5 != 0) {
				iNumber[iStarindex] = iNumber[iStarindex - 1];
				iNumber[iStarindex - 1] = INT_MAX;
				--iStarindex;
				break;
			}
		case 's':
		case 'S':
			if (iStarindex < 20) {
				iNumber[iStarindex] = iNumber[iStarindex + 5];
				iNumber[iStarindex + 5] = INT_MAX;
				iStarindex += 5;
				break;
			}
		case 'd':
		case 'D':
			if (iStarindex % 5 != 4) {
				iNumber[iStarindex] = iNumber[iStarindex + 1];
				iNumber[iStarindex + 1] = INT_MAX;
				++iStarindex;
				break;
			}
			break;
		}

	}
	return 0;
}