#include <iostream>
#include <ctime>
#include <cstdlib> 

using namespace std;

int main()
{
	/*
	for 문 : 반복문의 한 종류이다.
	형태 : for (초기값; 조건식; 증감값) {}
	조건식이 true이면 코드블럭의 코드가 동작된다.
	무한루프를 돌릴때는 for(;;) {} 을 해주면 무한으로 돌아가게 된다.
	for 문에서 초기값은 처음 for문에 진입할 때 딱 1번만 동작된다.
	그 후에 조건식을 체크하고 조건식이 true이면 코드블럭의 코드가 동작된 후에 증감값을 처리한다.
	그후 다시 조건을 체크하고 true면 동작되고 증감 -> 조건 -> 증감 -> 조건의 순서로 처리되다가
	false이거나 break를 만나면 for문을 빠져나가게 된다.
	*/

	// 초기값 : i   조건식 : i < 0   증감값 ++i 
	for (int i = 0; i < 10; ++i) {
		cout << i << endl;
	}

	// 구구단 2단을 출력해보자
	for (int i = 1; i < 10; ++i) {
		cout << "2 * " << i << " = " << 2 * i << endl;
	}

	// 1 ~ 100 사이의 숫자중 짝수만 출력하는 for문을 작성해보자
	for (int iNumber = 2; iNumber <= 100; iNumber += 2) {
		cout << iNumber << endl;
	}

	// 1 ~ 100 사이의 숫자중 3과 7의 공배수만 나타내기
	for (int i = 1; i <= 100; ++i) {
		if ((i % 3 == 0) && (i % 7 == 0))
			cout << i << endl;
	}

	// 중첩 for 문 : for문 안에 또다른 for문이 존재하는 형태이다.
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cout << "i = " << i << " j = " << j << endl;
		}
	}
	
	
	/*
	배열 : 여러개의 변수를 한번에 생성해줄 수 있는 기능.
	형태 : 변수타입 배열명[개수];
	배열의 특징 : 배열은 연속된 메모리 블럭에 공간이 할당된다.
	배열은 인덱스를 이용해서 원하는 부분에 접근하여 값을 저장할 수 있다.
	인덱스는 0부터 (개수-1)까지 있다.
	*/

	// 배열 뿐만 아니라 일반 변수들도 선언을 하고 초기화하지 않을 경우 쓰레기값이 들어가게 된다.
	// int iArray[10] = {1,2,3,4,5,6,7,8,9,10}; 배열 초기화
	// int iArray[10] = {1,2,3,4,5} 0 ~ 4번 까지는 1,2,3,4,5로 초기화 나머지는 0으로 초기화
	// int iArray[10] = {} 모든 인덱스 0으로 초기화

	int iArray[10] = {};
	iArray[1] = 1234;
	
	for (int i = 0; i < 10; ++i) {
		cout << iArray[i] << endl;
	}
	

	/*
	배열 개수를 2개 지정하면 이차원배열이 된다. 3개 지정하면 3차원배열이 된다.
	이차원배열의 개수는 앞의수 * 뒤의수 만큼 처리가 된다. 아래는 10 * 10개의 배열이 생성된다.
	*/
	int iArray2[10][10] = { {1,2,3}, {4,5,6} };
	
	
	//
	//
	// shuffle 
	
	// 10칸 짜리 배열에 1 ~ 10 집어넣기 
	int arr[10] = {};
	
	for (int i = 0; i < 10; ++i) {
		arr[i] = i + 1;
	}
	
	// arr[indx1] 과 arr[indx2]의 자리를 바꿈 
	for (int i = 0; i < 100; ++i) {
		int indx1 = rand() % 10;
		int indx2 = rand() % 10;
		int iTemp;
		
		iTemp = arr[indx1];
		arr[indx1] = arr[indx2];
		arr[indx2] = iTemp;
	}
	
	for (int i = 0; i < 10; ++i) {
		cout << arr[i] << endl;
	}
	
	
	return 0;
 } 
