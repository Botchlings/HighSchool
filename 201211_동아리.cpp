#include <iostream>
#include <cstring>	 

using namespace std;

#define NAME_SIZE	32

/*
구조체 : 관련있는 변수들을 모아서 하나의 새로운 변수 타입을 만들어주는 기능이다.
		 사용자정의 변수 타입이다.
형태 : struct 구조체명 {};
배열과 구조체의 공통점 : 1. 데이터 집합이다.
						 2. 연속된 메모리 블럭에 할당한다. 구조체 멤버들은 연속된 메모리 블럭으로 잡히게 된다.

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

	// 구조체 멤버에 접근할때는 . 을 이용해서 접근하게 된다.
	tStudent.iKor = 100;

	//  문자열을 배열에 넣어줄 때에는 단순 대입으로는 불가능하다.
	// strcpy 라는 함수를 이용해서 문자열을 복사해 주어야 한다.
	// strcpy(tStudent.strName, "김수민");
	tStudent.strName[0] = 'K';
	tStudent.strName[1] = 'i';
	tStudent.strName[2] = 'm';
	// 문자열의 끝은 항상 0(NULL)로 끝나야 한다. 그런데 쓰레기 값이 들어가 있는 상태에서 아래처럼 각 배열 요소에
	// 값을 넣어주게 되면 그 값이 출력되고 넣어주지 않은 부분은 쓰레기값으로 출력된다.
	// 왜냐하면 문자열의 끝을 인식할 수 없기 때문이다. 0이 들어가야 하는데 쓰레기 값이 들어가 있기 때문이다.
	// 가급적 문자열을 쓸때는 0으로 초기화 해두고 쓰도록하자.
	tStudent.strName[3] = 0;

	// strcat 함수는 문자열을 붙여주는 기능이다.
	strcat(tStudent.strName, " 문자열 붙이기");

	// strcmp 함수는 두 문자열을 비교하여 같을경우 0을 반환하고 다를 경우 0이 아닌 값을 반환한다.
	strcpy(tStudent.strName, "홍길동");

	cout << "찾으시는 학생 이름을 검색하세요. : ";
	char strName[NAME_SIZE];
	cin >> strName;

	if ((strcmp(tStudent.strName, strName)) == 0)
		cout << "학생을 찾았습니다." << endl;
	else
		cout << "학생을 찾지 못했습니다." << endl;

	cout << "이름 길이 : " << strlen(tStudent.strName) << endl;

	cout << "이름 : " << tStudent.strName << endl;
	cout << "학번 : " << tStudent.iNumber << endl;
	cout << "국어 : " << tStudent.iKor << endl;
	cout << "영어 : " << tStudent.iEng << endl;
	cout << "수학 : " << tStudent.iMath << endl;
	cout << "총점 : " << tStudent.iTotal << endl;
	cout << "평균 : " << tStudent.fAvg << endl;

	return 0;
}
