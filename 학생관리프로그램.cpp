#include <iostream>
#include <cstring>

using namespace std;

#define NAME_SIZE		32
#define STUDENT_MAX		10
#define PHONE_SIZE		14
#define ADDRESS_SIZE	128

struct _tagStudent {
	char strName[NAME_SIZE];
	char strAddress[ADDRESS_SIZE];
	char strPhoneNumber[PHONE_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

enum MENU {
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

int main()
{
	_tagStudent tStudentArr[STUDENT_MAX] = {};
	// 배열에 추가된 개수를 저장할 변수를 만들어준다.
	int iStudentCount = 0;
	int iStdNumber = 1;
	char strName[NAME_SIZE] = {};


	while (true) {
		system("cls");

		// 메뉴 출력하기
		cout << "1. 학생등록" << endl;
		cout << "2. 학생삭제" << endl;
		cout << "3. 학생탐색" << endl;
		cout << "4. 학생출력" << endl;
		cout << "5. 종료" << endl;
		cout << "메뉴를 선택하세요. : ";
		int iMenu;
		cin >> iMenu;

		// cin은 만약 오른쪽에 int변수가 오면 정수를 입력해야한다. 오른쪽에 오는 변수타입에 맞춰서 값을 입력해야 
		// 하는데 실수로 정수가 아닌 문자를 입력할 경우 에러가 발생하다. 그렇기 때문에 예외처리로 에러가 발생했는지를
		// 여기서 체크하여 에러가 발생하면 cin내부의 에러버퍼를 비워주고 cin 내부에 입력버퍼가 있는데 입력버퍼는 
		// 입력한 값을 저장해놓고 그 값을 변수에 넣어주는 역할을 한다. 이 입력버퍼에 \n이 남아있으므로
		// 버퍼를 순회하여 \n을 지워준다.
		// 버퍼 : 임시저장공간
		// 먼저 에러를 체크한다. cin.fail()로 체크했을때 에러가 발생할경우 true를 반환한다.

		if (cin.fail()) {
			// 에러버퍼 지우기
			cin.clear();
			// 입력버퍼 \n 지우기
			// 첫번째에는 검색하고자 하는 버퍼크기 두번째에는 찾고자하는 문자를 넣어준다.
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MENU_EXIT)
			break;

		switch (iMenu) {
		case MENU_INSERT:
			system("cls");
			cout << "====================== 학생 추가 ======================" << endl;
			// 학생정보는 이름, 주소, 전화번호, 점수들 입력받고 학번, 총점, 평균은 연산을 통해 계산해준다.

			// 학생이 최대일 경우 더이상 등록안되게 한다.
			if (iStudentCount == STUDENT_MAX) {
				break;
			}

			cout << "이름 : ";
			cin >> tStudentArr[iStudentCount].strName;

			// cin으로 입력을 하면 스페이스바도 문자열의 끝으로 인식한기 때문에 getline을 사용한다.
			// cin과 getline을 같이 사용하면 입력버퍼에 엔터가 들어가 있어서 그냥 진행되는 경우가 있음 
			cin.ignore(1024, '\n');
			cout << "주소 : ";
			cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);
			cout << "전화번호 : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);

			cout << "국어 : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "영어 : ";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "수학 : ";
			cin >> tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].iTotal =
				tStudentArr[iStudentCount].iKor +
				tStudentArr[iStudentCount].iEng +
				tStudentArr[iStudentCount].iMath;
			tStudentArr[iStudentCount].fAvg =
				tStudentArr[iStudentCount].iTotal / 3.f;

			tStudentArr[iStudentCount].iNumber = iStdNumber;

			++iStdNumber;
			++iStudentCount;

			cout << "학생 추가 완료." << endl;

			break;
		case MENU_DELETE:
			system("cls");
			cout << "====================== 학생 삭제 ======================" << endl;

			cin.ignore(1024, '\n');
			cout << "삭제할 학생 이름을 입력하세요. : ";
			cin.getline(strName, NAME_SIZE);

			for (int i = 0; i < iStudentCount; ++i) {
				if (strcmp(tStudentArr[i].strName, strName) == 0) {
					for (int j = i; j < iStudentCount - 1; ++j) {
						tStudentArr[j] = tStudentArr[j + 1];
					}
					--iStudentCount;

					cout << "학생을 삭제하였습니다." << endl;
					break;
				}
			}
			break;
		case MENU_SEARCH:
			system("cls");
			cout << "====================== 학생 탐색 ======================" << endl;

			cin.ignore(1024, '\n');
			cout << "찾으시는 학생 이름을 입력하세요. : ";
			cin.getline(strName, NAME_SIZE);

			// 등록되어 있는 학생 수 만큼 반복하며 학생을 찾는다.
			for (int i = 0; i < iStudentCount; ++i) {
				if (strcmp(tStudentArr[i].strName, strName) == 0) {
					cout << "이름 : " << tStudentArr[i].strName << endl;
					cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
					cout << "주소 : " << tStudentArr[i].strAddress << endl;
					cout << "학번 : " << tStudentArr[i].iNumber << endl;
					cout << "국어 : " << tStudentArr[i].iKor << endl;
					cout << "영어 : " << tStudentArr[i].iEng << endl;
					cout << "수학 : " << tStudentArr[i].iMath << endl;
					cout << "총점 : " << tStudentArr[i].iTotal << endl;
					cout << "평균 : " << tStudentArr[i].fAvg << endl << endl;
					break;
				}
			}


			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "====================== 학생 출력 ======================" << endl;

			// 등록된 학생 수만큼 반복하며 학생정보를 출력한다.
			for (int i = 0; i < iStudentCount; ++i) {
				cout << "이름 : " << tStudentArr[i].strName << endl;
				cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
				cout << "주소 : " << tStudentArr[i].strAddress << endl;
				cout << "번호 : " << tStudentArr[i].iNumber << endl;
				cout << "국어 : " << tStudentArr[i].iKor << endl;
				cout << "영어 : " << tStudentArr[i].iEng << endl;
				cout << "수학 : " << tStudentArr[i].iMath << endl;
				cout << "총점 : " << tStudentArr[i].iTotal << endl;
				cout << "평균 : " << tStudentArr[i].fAvg << endl << endl;
			}
			break;
		default:
			cout << "잘못 입력하였습니다. 다시 입력해주세요." << endl;
			break;
		}

		system("pause");
	}

	return 0;
}
