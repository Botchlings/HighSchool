﻿// Lotto_Program

#include <iostream>
#include <time.h>

using namespace std;

int main() {
	int iLotto[45] = {};
	srand((unsigned int)time(0));

	for (int i = 0; i < 45; ++i) {
		iLotto[i] = i + 1;
	}

	// Swap 알고리즘
	/*int iNum1 = 1, iNum2 = 2, iNum3 = 3;
	iNum3 = iNum1;
	iNum1 = iNum2;
	iNum2 = iNum3;*/

	// Shuffle
	int iTemp, indx1, indx2;
	// 100번 정도 골고루 섞어준다.
	for (int i = 0; i < 100; ++i) {
		indx1 = rand() % 45;
		indx2 = rand() % 45;

		iTemp = iLotto[indx1];
		iLotto[indx1] = iLotto[indx2]; 
		iLotto[indx2] = iTemp;
	}

	for (int i = 0; i < 6; ++i) {
		cout << iLotto[i] << "\t";
	}

	cout << "보너스 번호 : " << iLotto[6] << endl;


	return 0;
}