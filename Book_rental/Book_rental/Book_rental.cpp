/*
도서 대여 프로그램 만들기
1. 책등록
2. 책 대여
3. 책 반납
4. 책 목록
5. 종료

책 구조체는 이름, 대여금액, 책번호, 대여여부가 필요하다.
책목록을 선택하면 책 정보를 출력해준다.
*/

#include <iostream>

using namespace std;

#define BOOK_NAME	50
#define BOOK_MAX	10

struct _tagBookRental {
	char strBookName[BOOK_NAME];
	int iNumber;
	int iPrice;
	bool bStatus;
};

enum MENU {
	BOOK_REGISTRATION = 1,
	BOOK_RENTAL,
	BOOK_RETURN,
	BOOK_LIST,
	EXIT
};

int main()
{
	_tagBookRental tBookArr[BOOK_MAX] = {};
	int iBookCount = 0;
	int iRentalNumber;

	while (true) {
		system("cls");

		cout << "1. 책 등록" << endl;
		cout << "2. 책 대여" << endl;
		cout << "3. 책 반납" << endl;
		cout << "4. 책 목록" << endl;
		cout << "5. 종료" << endl << endl;
		int iMenu;
		cout << "메뉴를 선택해주세요. : ";
		cin >> iMenu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == EXIT)
			break;

		switch (iMenu) {
		case BOOK_REGISTRATION:
			system("cls");
			cout << "==================== 책 등록 ====================" << endl;

			if (iBookCount == BOOK_MAX) {
				cout << "책장이 가득 찼습니다." << endl;
				break;
			}

			tBookArr[iBookCount].iNumber = iBookCount + 1;
			cout << tBookArr[iBookCount].iNumber << "번 책" << endl;

			cout << "책 이름 : ";
			cin.ignore(1024, '\n');
			cin.getline(tBookArr[iBookCount].strBookName, BOOK_NAME);

			cout << "대출 가격(원) : ";
			cin >> tBookArr[iBookCount].iPrice;

			tBookArr[iBookCount].bStatus = false;

			++iBookCount;

			cout << endl << "등록 완료" << endl;
			break;
		case BOOK_RENTAL:
			system("cls");
			cout << "==================== 책 대여 ====================" << endl;

			for (int i = 0; i < iBookCount; ++i) {
				cout << i + 1 << ". " << tBookArr[i].strBookName << endl;
			}
			cout << "대출하실 책의 번호를 입력해주세요. : ";
			cin >> iRentalNumber;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(BOOK_NAME, '\n');
				cout << "번호를 다시 입력해주세요" << endl;
			}
			else {
				if (tBookArr[iRentalNumber - 1].bStatus == false)
					cout << tBookArr[iRentalNumber - 1].strBookName << " 이(가) 대여되었습니다." << endl;
				else
					cout << "이미 대여된 책입니다." << endl;

				tBookArr[iRentalNumber - 1].bStatus = true;
			}
			break;
		case BOOK_RETURN:
			system("cls");
			cout << "==================== 책 반납 ====================" << endl;

			for (int i = 0; i < iBookCount; ++i) {
				cout << i + 1 << ". " << tBookArr[i].strBookName << endl;
			}
			cout << "반납하실 책의 번호를 입력해 주세요. : ";
			cin >> iRentalNumber;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(BOOK_NAME, '\n');
				cout << "번호를 다시 입력해 주세요" << endl;
			}
			else {
				if (tBookArr[iRentalNumber - 1].bStatus == true)
					cout << tBookArr[iRentalNumber - 1].strBookName << " 이(가) 반납되었습니다." << endl;
				else
					cout << "이미 반납되거나 대여되지 않은 책입니다." << endl;

				tBookArr[iRentalNumber - 1].bStatus = false;
			}
			break;
		case BOOK_LIST:
			system("cls");
			cout << "==================== 책 목록 ====================" << endl;

			for (int i = 0; i < iBookCount; ++i) {
				cout << tBookArr[i].iNumber << "번" << endl;
				cout << tBookArr[i].strBookName << endl;
				cout << "대여 가격 : " << tBookArr[i].iPrice << endl;
				if (tBookArr[i].bStatus == false)
					cout << "대여 상태 : X" << endl << endl;
				else
					cout << "대여 상태 : O" << endl << endl;
			}
			break;
		}
		system("pause");
	}
	return 0;
}