// 가위 바위 보
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

enum SRP{
  SRP_END,
  SRP_S,
  SRP_R,
  SRP_P
};

int main()
{
  int iPlayer;

  while(true)
  {
    int iAI = (rand() % 3) + 1;  // AI 결정 

    system("cls");   // 터미널창 다 지움 
    cout << "| 1. 가위 | 2. 바위 | 3. 보 | 0. 종료 |" << endl;
    cout << "번호를 선택하세요. : ";
    cin >> iPlayer;

    if(iPlayer == SRP_END) {
      break;
    }
    else if(iPlayer < SRP_END || iPlayer > SRP_P) {
    	cout << "잘못된 값을 입력하였습니다." << endl;
    	system("pause"); // 일시정지 
    	continue; // 반복문의 처음으로 이동 
	}

    switch(iPlayer) {
      case SRP_S:
        cout << "플레이어 : 가위" << endl;
        break;
      case SRP_R:
        cout << "플레이어 : 바위" << endl;
        break;
      case SRP_P:
        cout << "플레이어 : 보" << endl;
        break;
    }

    switch(iAI) {
      case SRP_S:
        cout << "AI : 가위" << endl;
        break;
      case SRP_R:
        cout << "AI : 바위" << endl;
        break;
      case SRP_P:
        cout << "AI : 보" << endl;
        break;
    }

    int iWin = iPlayer - iAI;

    if(iWin == 1 || iWin == -2){
      cout << "플레이어 승리" << endl;
    } 
    else if(iWin == 0){
      cout << "비김" << endl;
    } 
    else {
      cout << "AI 승리" << endl;
    }

    system("pause");
  }

  return 0;
}
