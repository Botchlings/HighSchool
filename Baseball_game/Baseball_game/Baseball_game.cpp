/*
야구게임
1 ~ 9 사이의 랜덤한 숫자 3개를 얻어온다. 단, 숫자는 중복되어서는 안된다.
3개의 숫자는 * * *의 형태로 출력되고 이 3개의 숫자를 맞추는 게임이다.
사용자는 이 3개의 숫자를 맞출 때 까지 계속해서 3개의 숫자를 입력한다.
맞춰야 할 숫자가 7 3 8 일 경우
사용자는 3개의 숫자를 계속 입력한다.

입력 : 1 2 4 를 입력했을 경우 1 2 4 중 아무것도 없으므로 Out을 출력한다.
입력 : 7 5 9 를 입력했을 경우 1strike 0ball을 출력한다.
입력 : 7 8 6 을 입력했을 경우 1strike 1ball을 출력한다.

이렇게 출력과 입력을 받으면서 최종적으로 3개의 숫자를 자리까지 모두 일치하게 입력하면 게임이 종료된다.
만약 입력받은 숫자 3개중 1개라도 0이 있을 경우 게임을 종료한다.
*/

#include <iostream>	
#include <time.h>

using namespace std;

int main()
{
	int iPlayer1, iPlayer2, iPlayer3;
	int iStrike = 0, iBall_ = 0;
	int iBall[9] = {};
	srand((unsigned int)time(0));

	while (true) {
		// iBall 배열에 1 ~ 9까지 집어넣음
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

		// 숫자 입력받기
		cout << "공을 던지세요! : ";
		cin >> iPlayer1 >> iPlayer2 >> iPlayer3;

		// 2자리 수를 입력받으면 다시 시작
		if ((iPlayer1 >= 10) || (iPlayer2 >= 10) || (iPlayer3 >= 10)) {
			cout << "1 ~ 9 번 사이의 공을 던져주세요." << endl;
			continue;
		}

        // 0 누르면 게임 꺼짐
		if ((iPlayer1 == 0) || (iPlayer2 == 0) || (iPlayer3 == 0)) {
			cout << "0 번 공을 던져 게임을 종료합니다." << endl;
			break;
		}

		// 같은 숫자 2개는 안된다.
		if ((iPlayer1 == iPlayer2) || (iPlayer2 == iPlayer3) || (iPlayer3 == iPlayer1)) {
			cout << "서로 다른 공을 던져주세요." << endl;
			continue;
		}

		// 스트라이크 점수 측정
		if (iPlayer1 == iBall[0]) {
			iStrike += 1;
		}
		if (iPlayer2 == iBall[1]) {
			iStrike += 1;
		}
		if (iPlayer3 == iBall[2]) {
			iStrike += 1;
		}

		// 볼 점수 측정
		if ((iPlayer1 == iBall[1]) || (iPlayer1 == iBall[2])) {
			iBall_ += 1;
		}
		if ((iPlayer2 == iBall[0]) || (iPlayer2 == iBall[2])) {
			iBall_ += 1;
		}
		if ((iPlayer3 == iBall[0]) || (iPlayer3 == iBall[1])) {
			iBall_ += 1;
		}

		// 점수 보여주기
		cout << "          정답 : " << iBall[0] << " " << iBall[1] << " " << iBall[2] << endl;
		cout << iStrike << "Strike  " << iBall_ << "Ball" << endl;

		// 다 맞추면 게임 꺼짐
		if (iStrike == 3) {
			cout << "세 숫자를 모두 맞혀 게임을 종료합니다." << endl;
			break;
		}

		iStrike = 0;
		iBall_ = 0;

	}

	return 0;
}