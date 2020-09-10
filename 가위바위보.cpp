// ���� ���� ��
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
    int iAI = (rand() % 3) + 1;  // AI ���� 

    system("cls");   // �͹̳�â �� ���� 
    cout << "| 1. ���� | 2. ���� | 3. �� | 0. ���� |" << endl;
    cout << "��ȣ�� �����ϼ���. : ";
    cin >> iPlayer;

    if(iPlayer == SRP_END) {
      break;
    }
    else if(iPlayer < SRP_END || iPlayer > SRP_P) {
    	cout << "�߸��� ���� �Է��Ͽ����ϴ�." << endl;
    	system("pause"); // �Ͻ����� 
    	continue; // �ݺ����� ó������ �̵� 
	}

    switch(iPlayer) {
      case SRP_S:
        cout << "�÷��̾� : ����" << endl;
        break;
      case SRP_R:
        cout << "�÷��̾� : ����" << endl;
        break;
      case SRP_P:
        cout << "�÷��̾� : ��" << endl;
        break;
    }

    switch(iAI) {
      case SRP_S:
        cout << "AI : ����" << endl;
        break;
      case SRP_R:
        cout << "AI : ����" << endl;
        break;
      case SRP_P:
        cout << "AI : ��" << endl;
        break;
    }

    int iWin = iPlayer - iAI;

    if(iWin == 1 || iWin == -2){
      cout << "�÷��̾� �¸�" << endl;
    } 
    else if(iWin == 0){
      cout << "���" << endl;
    } 
    else {
      cout << "AI �¸�" << endl;
    }

    system("pause");
  }

  return 0;
}
