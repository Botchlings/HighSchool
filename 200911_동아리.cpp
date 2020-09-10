/*
2020.09.11 동아리 활동

입력 출력
조건문 (if, switch)
난수
열거체
반복문 (while)
*/

// 헤더파일 inlcude
#include <iostream>   // 기본 입출력 
#include <ctime>      // 난수 
#include <cstdlib>    // 난수 

// std:: 생략
using namespace std;

/*
열거체 : 연속된 숫자에 이름을 부여할 수 있는 기능이다.
형태 : enum 열거체명 {}
열거체명을 이용해서 열거체 타입의 변수를 선언도 가능하다.
즉, 열거체 자체가 사용자정의 변수 타입이 될 수 있다.
*/

enum NUM
{
	NUM_0, // 아무것도 부여하지 않을 경우 0부터 1씩 차례로 값이 부여된다.
	NUM_1,
	NUM_2,
	NUM_3
};

int main()
{
	int iNumber;
	cout << "숫자를 입력하세요. : ";
	cin >> iNumber;
	cout << "입력하신 숫자는 " << iNumber << "입니다." << endl;

	/*
	if문 : 조건을 체크해주는 기능이다.
	형태 : if(조건식) {}(코드블럭)
	if문은 조건식이 true가 될 경우 코드블럭 안의 코드가 실행된다.
	false일 경우에는 동작되지 않는다.
	*/

	if (true) {
		cout << "참입니다." << endl;
	}

	// if문의 코드블럭이 한줄이면 {} 생략가능
	if (true)
		cout << "참입니다." << endl;

	/*
	else : if 문과 반드시 같이 사용되어야 한다.
	if문 조건이 false일 경우 else가 있다면 else 구문 안의 코드가 동작된다.

	else if : if 문과 반드시 같이 와야하고 if 아래 else 위에 위치한다.
	*/
	cin >> iNumber;
	if (iNumber >= 0 && iNumber < 10)
		cout << "0이상 10미만" << endl;
	else if (iNumber >= 10 && iNumber < 20)
		cout << "10이상 20미만" << endl;
	else
		cout << "20이상 또는 0미만" << endl;

	// 난수 발생
	cout << rand() << endl;
	cout << rand() % 101 << endl;
	cout << (rand() % 10000) / 100.f << endl;

	/*
	switch문 : 분기문의 한 종류이다. if문이 조건문을 체크하는 분기문이라면
	switch문은 값이 뭔지를 체크하는 분기문이다.
	형태 : switch(변수) {}
	       코드블럭 안에는 case break 구문이 들어가게 된다.
		   case 상수: 의 형태로 처리가 되고 변수값이 무엇인지에 따라서 case 뒤에 오는 상수를 비교하게 된다.
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
	형태 : while(조건식) {}
	조건식이 참이면 코드블럭안의 코드가 동작됨.
	반복문 안에서 break를 만나면 반복문을 빠져나오게 된다.
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
