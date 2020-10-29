#include <iostream>
#include <time.h>

using namespace std;

enum MAIN_MENU {
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MAP_TYPE {
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

enum JOB {
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

enum BATTLE {
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
};

enum ITEM_TYPE {
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK
};

enum STORE_MENU {
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
};

#define NAME_SIZE 32
#define ITEM_DESC_LENGTH 512
#define INVENTORY_MAX 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 3

struct _tagItem {
	char		strName[NAME_SIZE];
	char		strTypeName[NAME_SIZE];
	ITEM_TYPE	eType;
	int iMin;
	int iMax;
	int iPrice;
	int iSell;
	char strDesc[ITEM_DESC_LENGTH];
};

struct _tagInventory {
	_tagItem tItem[INVENTORY_MAX];
	int iItemCount;
	float iGold;
};

struct _tagPlayer {
	char	strName[NAME_SIZE];
	char	strJobName[NAME_SIZE];
	JOB		ejob;
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	float	iExp;
	int		iLevel;
	_tagInventory tInventory;
};

struct _tagMonster {
	char	strName[NAME_SIZE];
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iLevel;
	int		iExp;
	int		iGoldMin;
	int		iGoldMax;
};

int main()
{
	srand((unsigned int)time(0));

	// 플레이어 정보 설정
	_tagPlayer tPlayer = {};

	cout << "이름 : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1);

	int iJob = JOB_NONE;
	while (iJob == JOB_NONE) {
		system("cls");
		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << endl << "직업을 선택하세요. : ";
		cin >> iJob;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (iJob <= JOB_NONE || iJob >= JOB_END)
			iJob = JOB_NONE;

	}

	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	tPlayer.ejob = (JOB)iJob;
	tPlayer.tInventory.iGold = 10000;

	switch (tPlayer.ejob) {
	case JOB_KNIGHT:
		strcpy_s(tPlayer.strJobName, "기사");
		tPlayer.iAttackMin = 5;
		tPlayer.iAttackMax = 10;
		tPlayer.iArmorMin = 15;
		tPlayer.iArmorMax = 20;
		tPlayer.iHP = 500;
		tPlayer.iHPMax = 500;
		tPlayer.iMP = 100;
		tPlayer.iMPMax = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(tPlayer.strJobName, "궁수");
		tPlayer.iAttackMin = 10;
		tPlayer.iAttackMax = 15;
		tPlayer.iArmorMin = 10;
		tPlayer.iArmorMax = 15;
		tPlayer.iHP = 400;
		tPlayer.iHPMax = 400;
		tPlayer.iMP = 200;
		tPlayer.iMPMax = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(tPlayer.strJobName, "마법사");
		tPlayer.iAttackMin = 15;
		tPlayer.iAttackMax = 20;
		tPlayer.iArmorMin = 5;
		tPlayer.iArmorMax = 10;
		tPlayer.iHP = 300;
		tPlayer.iHPMax = 300;
		tPlayer.iMP = 300;
		tPlayer.iMPMax = 300;
		break;
	}

	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	strcpy_s(tMonsterArr[0].strName, "고블린");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 5;
	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iHPMax = 100;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iMPMax = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[0].iGoldMax = 1500;

	strcpy_s(tMonsterArr[1].strName, "트롤");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMax = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMax = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iExp = 7000;
	tMonsterArr[1].iGoldMin = 6000;
	tMonsterArr[1].iGoldMax = 8000;

	strcpy_s(tMonsterArr[2].strName, "드래곤");
	tMonsterArr[2].iAttackMin = 400;
	tMonsterArr[2].iAttackMax = 500;
	tMonsterArr[2].iArmorMin = 300;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iHPMax = 30000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iMPMax = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iExp = 30000;
	tMonsterArr[2].iGoldMin = 20000;
	tMonsterArr[2].iGoldMax = 50000;

	_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};

	strcpy_s(tStoreWeapon[0].strName, "칼");
	strcpy_s(tStoreWeapon[0].strTypeName, "무기");
	tStoreWeapon[0].eType = IT_WEAPON;
	tStoreWeapon[0].iMin = 10;
	tStoreWeapon[0].iMax = 15;
	tStoreWeapon[0].iPrice = 10000;
	tStoreWeapon[0].iSell = 1000;
	strcpy_s(tStoreWeapon[0].strDesc, "주워온 칼");

	strcpy_s(tStoreWeapon[1].strName, "도끼");
	strcpy_s(tStoreWeapon[1].strTypeName, "무기");
	tStoreWeapon[1].eType = IT_WEAPON;
	tStoreWeapon[1].iMin = 130;
	tStoreWeapon[1].iMax = 200;
	tStoreWeapon[1].iPrice = 23000;
	tStoreWeapon[1].iSell = 2000;
	strcpy_s(tStoreWeapon[1].strDesc, "강가에서 주운 도끼");

	strcpy_s(tStoreWeapon[2].strName, "지팡이");
	strcpy_s(tStoreWeapon[2].strTypeName, "무기");
	tStoreWeapon[2].eType = IT_WEAPON;
	tStoreWeapon[2].iMin = 450;
	tStoreWeapon[2].iMax = 500;
	tStoreWeapon[2].iPrice = 50000;
	tStoreWeapon[2].iSell = 4500;
	strcpy_s(tStoreWeapon[2].strDesc, "이름만 지팡이");

	strcpy_s(tStoreArmor[0].strName, "천갑옷");
	strcpy_s(tStoreArmor[0].strTypeName, "방어구");
	tStoreArmor[0].eType = IT_WEAPON;
	tStoreArmor[0].iMin = 15;
	tStoreArmor[0].iMax = 20;
	tStoreArmor[0].iPrice = 10000;
	tStoreArmor[0].iSell = 1000;
	strcpy_s(tStoreArmor[0].strDesc, "천으로 만든 갑옷");

	strcpy_s(tStoreArmor[1].strName, "철갑옷");
	strcpy_s(tStoreArmor[1].strTypeName, "방어구");
	tStoreArmor[1].eType = IT_ARMOR;
	tStoreArmor[1].iMin = 75;
	tStoreArmor[1].iMax = 100;
	tStoreArmor[1].iPrice = 23000;
	tStoreArmor[1].iSell = 4500;
	strcpy_s(tStoreArmor[1].strDesc, "철로 만든 갑옷");

	strcpy_s(tStoreArmor[2].strName, "용사냥꾼 갑옷");
	strcpy_s(tStoreArmor[2].strTypeName, "방어구");
	tStoreArmor[2].eType = IT_ARMOR;
	tStoreArmor[2].iMin = 350;
	tStoreArmor[2].iMax = 380;
	tStoreArmor[2].iPrice = 50000;
	tStoreArmor[2].iSell = 25000;
	strcpy_s(tStoreArmor[2].strDesc, "용사냥꾼의 갑옷");

	while (true) {
		system("cls");
		cout << "************************* 로비 *************************" << endl;
		cout << "1. 맵" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 가방"<< endl;
		cout << "4. 종료" << endl;
		cout << endl << "메뉴를 선택하세요. : ";

		int iMenu;
		cin >> iMenu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MM_EXIT)
			break;

		switch (iMenu) {
		case MM_MAP:
			while (true) {
				system("cls");
				cout << "************************* 맵 *************************" << endl;
				cout << "1. 쉬움" << endl;
				cout << "2. 보통" << endl;
				cout << "3. 어려움" << endl;
				cout << "4. 뒤로가기" << endl;
				cout << endl << "맵을 선택하세요. : ";
				cin >> iMenu;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
				}

				if (iMenu == MT_BACK)
					break;

				_tagMonster tMonster = tMonsterArr[iMenu - 1];

				while (true) {
					system("cls");
					switch (iMenu) {
					case MT_EASY:
						cout << "************************* 쉬움 *************************" << endl;
						break;
					case MT_NORMAL:
						cout << "************************* 보통 *************************" << endl;
						break;
					case MT_HARD:
						cout << "************************* 어려움 *************************" << endl;
						break;
					}
					
					// 플레이어 정보 출력
					cout << "======================= Player =======================" << endl;
					cout << "이름 : " << tPlayer.strName << "\t직업 : " << tPlayer.strJobName << endl;
					cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " << tPlayer.iExp << endl;
					cout << "공격력 : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMax <<
						"\t방어력 : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;
					cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax << "\t마나 : " <<
						tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
					cout << "보유 골드 : " << tPlayer.tInventory.iGold << " Gold" << endl;

					// 몬스터 정보 출력
					cout << "======================= Monster =======================" << endl;
					cout << "이름 : " << tMonster.strName << "레벨 : " << tMonster.iLevel << endl;
					cout << "공격력 : " << tMonster.iAttackMin << " - " << tMonster.iAttackMax <<
						"\t방어력 : " << tMonster.iArmorMin << " - " << tMonster.iArmorMax << endl;
					cout << "체력 : " << tMonster.iHP << " / " << tMonster.iHPMax << "\t마나 : " <<
						tMonster.iMP << " / " << tMonster.iMPMax << endl;
					cout << "획득 경험치 : " << tMonster.iExp << "\t획득 골드 : " << tMonster.iGoldMin <<
						" - " << tMonster.iGoldMax << endl << endl;

					cout << "1. 공격" << endl;
					cout << "2. 도망가기" << endl;
					cout << "메뉴를 선택하세요. : ";
					cin >> iMenu;

					if (cin.fail()) {
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}
					else if (iMenu == BATTLE_BACK)
						break;
					
					if (iMenu == BATTLE_ATTACK) {
					
						int iAttack = rand() % (tPlayer.iAttackMax - tPlayer.iAttackMin + 1) + tPlayer.iAttackMin;
						int iArmor = rand() % (tMonster.iArmorMax - tPlayer.iArmorMin + 1) + tMonster.iArmorMin;

						int iDamage = iAttack - iArmor;

						// 삼항연산자 : 조건식 ? true일 때 값 : false일 때 값;
						iDamage = iDamage < 1 ? 1 : iDamage;
						tMonster.iHP -= iDamage;

						cout << endl << tPlayer.strName << " 가 " << tMonster.strName << " 에게 " << iDamage <<
							" 피해를 입혔습니다." << endl;

						if (tMonster.iHP <= 0) {
							cout << tMonster.strName << " 가 죽었습니다." << endl;

							tPlayer.iExp += tMonster.iExp;
							int iGold = (rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) + tMonster.iGoldMin);
							tPlayer.tInventory.iGold += iGold;

							cout << tMonster.iExp << " 경험치와 " << iGold << " 골드를 획득했습니다." << endl;

							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;
						}
						else {

							iAttack = rand() % (tMonster.iAttackMax - tPlayer.iAttackMin + 1) + tMonster.iAttackMin;
							iArmor = rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin + 1) + tPlayer.iArmorMin;

							iDamage = iAttack - iArmor;

						// 삼항연산자 : 조건식 ? true일 때 값 : false일 때 값;
							iDamage = iDamage < 1 ? 1 : iDamage;
							tPlayer.iHP -= iDamage;

						
							cout << endl << tMonster.strName << " 가 " << tPlayer.strName << " 에게 " << iDamage <<
								" 피해를 입혔습니다." << endl;
						}

						if (tPlayer.iHP <= 0) {
							cout << tPlayer.strName << " 가 죽었습니다." << endl;

							float iExp = tPlayer.iExp * 0.1f;
							float iGold = tPlayer.tInventory.iGold * 0.1f;

							tPlayer.iExp -= iExp;
							tPlayer.tInventory.iGold -= iGold;

							cout << iExp << " 경험치와 " << iGold << " 골드를 잃었습니다." << endl;

							tPlayer.iHP = tPlayer.iHPMax;
							tPlayer.iMP = tPlayer.iMPMax;
							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;


							system("pause");
							break;
						}
					}
					system("pause");
				}
			}
			break;
		case MM_STORE:
			while (true) {
				system("cls");
				cout << "************************* 상점 *************************" << endl;
				cout << "1. 무기 상점" << endl;
				cout << "2. 방어구 상점" << endl;
				cout << "3. 뒤로가기" << endl;
				// cout << "4. 뒤로가기" << endl;
				cout << endl << "상점을 선택하세요. : ";
				cin >> iMenu;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else if (iMenu == SM_BACK)
					break;

				switch (iMenu) {
				case SM_WEAPON:
					while (true) {
						system("cls");
						cout << "************************* 무기 상점 *************************" << endl;
						for (int i = 0; i < STORE_WEAPON_MAX; ++i) {
							cout << i + 1 << "." << endl;
							cout << "이름 : " << tStoreWeapon[i].strName << "\t종류 : " << tStoreWeapon[i].strTypeName << endl;
							cout << "공격력 : " << tStoreWeapon[i].iMin << " - " << tStoreWeapon[i].iMax << endl;
							cout << "가격 : " << tStoreWeapon[i].iPrice << endl;
							cout << "설명 : " << tStoreWeapon[i].strDesc << endl << endl;
						}
						cout << STORE_WEAPON_MAX + 1 << ". 뒤로가기" << endl << endl;
						cout << "보유 골드 : " << tPlayer.tInventory.iGold << endl;
						cout << "인벤토리 : " << tPlayer.tInventory.iItemCount << " / " << INVENTORY_MAX << endl;
						cout << "구입할 무기의 번호를 입력하세요. : ";
						cin >> iMenu;

						if (cin.fail()) {
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}
						else if (iMenu == STORE_WEAPON_MAX + 1)
							break;
						if (tPlayer.tInventory.iItemCount < INVENTORY_MAX && tPlayer.tInventory.iGold >= tStoreWeapon[iMenu - 1].iPrice) {
							tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreWeapon[iMenu - 1];
							cout << tStoreWeapon[iMenu - 1].strName << " 을 구매하였습니다." << endl;
							++tPlayer.tInventory.iItemCount;
							tPlayer.tInventory.iGold -= tStoreWeapon[iMenu - 1].iPrice;

							system("pause");
						}
						else if (tPlayer.tInventory.iItemCount >= INVENTORY_MAX || tPlayer.tInventory.iGold < tStoreWeapon[iMenu - 1].iPrice) {
							cout << "골드가 부족하거나 인벤토리가 가득 찼습니다." << endl;
							system("pause");
						}
					}
					break;
				case SM_ARMOR:
					while (true) {
					system("cls");
					cout << "************************* 방어구 상점 *************************" << endl;
					for (int i = 0; i < STORE_ARMOR_MAX; ++i) {
						cout << i + 1 << "." << endl;
						cout << "이름 : " << tStoreArmor[i].strName << "\t종류 : " << tStoreArmor[i].strTypeName << endl;
						cout << "공격력 : " << tStoreArmor[i].iMin << " - " << tStoreArmor[i].iMax << endl;
						cout << "가격 : " << tStoreArmor[i].iPrice << endl;
						cout << "설명 : " << tStoreArmor[i].strDesc << endl << endl;
					}
					cout << STORE_ARMOR_MAX + 1 << ". 뒤로가기" << endl << endl;
					cout << "보유 골드 : " << tPlayer.tInventory.iGold << endl;
					cout << "인벤토리 : " << tPlayer.tInventory.iItemCount << " / " << INVENTORY_MAX << endl;
					cout << "구입할 무기의 번호를 입력하세요. : ";
					cin >> iMenu;

					if (cin.fail()) {
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}
					else if (iMenu == STORE_ARMOR_MAX + 1)
						break;
					if (tPlayer.tInventory.iItemCount < INVENTORY_MAX && tPlayer.tInventory.iGold >= tStoreArmor[iMenu - 1].iPrice) {
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreArmor[iMenu - 1];
						cout << tStoreArmor[iMenu - 1].strName << " 을 구매하였습니다." << endl;
						++tPlayer.tInventory.iItemCount;
						tPlayer.tInventory.iGold -= tStoreArmor[iMenu - 1].iPrice;

						system("pause");
					}
					else if (tPlayer.tInventory.iItemCount >= INVENTORY_MAX || tPlayer.tInventory.iGold < tStoreArmor[iMenu - 1].iPrice) {
						cout << "골드가 부족하거나 인벤토리가 가득 찼습니다." << endl;
						system("pause");
					}
				}
					break;
				}
			}
			break;
		case MM_INVENTORY:
			system("cls");
			for (int i = 0; i < INVENTORY_MAX; ++i) {
				cout << i + 1 << ". " << tPlayer.tInventory.tItem[i].strName << endl;
			}
			system("pause");
			break;
		default:
			cout << "잘못 입력하였습니다." << endl;
			break;
		}
		
	}
	return 0;
}