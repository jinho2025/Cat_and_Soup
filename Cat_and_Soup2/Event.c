#include"Private.h"

static INPUT_RECORD inputbuffer[128];
static DWORD temp;


void LoanEvent() {
	system("cls");
	int count = 7;
	int per = 0;
	int spacebar = 0;
	for (; count; count--) {
		for (per = 0; per != 13; per++) {
			printf("%s(이)가 당신의 신용정보를 이용해 대출을 하였습니다.\n"
				"당신은 대출을 갚기위해 노가다를 하게 됬습니다.\n\n\n", mastername);
			printf("남은 횟수: %d번\n\n", count);
			for (spacebar = per; spacebar; spacebar--) {
				putchar(' ');
			}
			puts(" ㅁo");
			for (spacebar = per; spacebar; spacebar--) {
				putchar(' ');
			}
			puts("ㅁ/\\");
			for (spacebar = per; spacebar; spacebar--) {
				putchar(' ');
			}
			puts(" /\\");

			puts("\n\n아무키나 반복해서 누르세요.");
			for (spacebar = 20; spacebar;) {
				ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), inputbuffer, 128, &temp);
				for (temp--; ~temp; temp--) {
					if (inputbuffer[temp].EventType == KEY_EVENT) {
						if (!inputbuffer[temp].Event.KeyEvent.bKeyDown) {
							spacebar--;
						}
					}
				}
			}
			system("cls");
		}
	}
	puts("당신은 빌린 대출을 갚았습니다.\n\n>>계속하시려면 enter키를 눌러주세요.");
ENDLOOP:;
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), inputbuffer, 128, &temp);
	for (temp--; ~temp; temp--) {
		if (inputbuffer[temp].EventType == KEY_EVENT) {
			if (inputbuffer[temp].Event.KeyEvent.uChar.AsciiChar == VK_RETURN) {
				return;
			}
		}
	}
	goto ENDLOOP;
	return;
}

DWORD PrintChoiceList(DWORD dwlength, ...) {
	va_list str;
	register DWORD i, r;
	va_start(str, dwlength);
	char* list[5] = { 0 };
	list[(r = rand() % dwlength)] = va_arg(str, char*);
	for (temp = dwlength - 2; ~temp; temp--) {
		while (list[(i = rand() % dwlength)]);
		list[i] = va_arg(str, char*);
	}
	for (i = 0; i<dwlength; i++) {
		printf("%d. %s\n", i+1, list[i]);
	}
	return r;
}

void SphinxEvent() {
	#define QUIZ_LENGTH 7
	register int d1, d2, d3, d4;
	int q;
	int quizlist[QUIZ_LENGTH];
	for (temp = QUIZ_LENGTH - 1; ~temp; temp--) {
		quizlist[temp] = temp;
	}
	printf("냥핑크스: %s를 쓰다듬을려는 자\n"
		   "          답하지 않으면 냥냥펀치를 받게 될지어니.\n\n", mastername);

	for (int i = 1; i<=3; i++) {
		temp = rand() % (QUIZ_LENGTH - i + 1);
		q = quizlist[temp];
		quizlist[temp] = quizlist[QUIZ_LENGTH - i];
		printf("%d번 문제: ", i);
		switch (q) {
			case 0:
				puts("키보드 로부터 하나의 문자를 입력받는 방법중 적절한것은?\n\n");
				temp = PrintChoiceList(3, "ch = getchar()", "scanf_s(\"%s\",&ch,num)", "scanf(\"%d\",&ch)");
				break;
			case 1:
				puts("y=e^x을 미분하면?\n\n");
				temp = PrintChoiceList(5, "e^x", "e*e^x", "e", "e*x", "e/x");
				break;
			case 2:
				printf("y=%dx를 미분하면?\n\n\n", temp = rand() % 9 + 1);

				while ((d1 = rand() % 9 + 1) == temp);
				while (((d2 = rand() % 9 + 1) == temp) || d2 == d1);
				temp = PrintChoiceList(3, (char[2]) { temp + 48, '\0' }, (char[2]) { d1 + 48, '\0' }, (char[2]) { d2 + 48, '\0' });
				break;
			case 3:
				printf("%d의 아스키 코드 값은?\n\n\n", temp = rand() % 94 + 1 + 32);
				while ((d1 = rand() % 94 + 1 + 32) == temp);
				while (((d2 = rand() % 94 + 1 + 32) == temp) || d2 == d1);
				temp = PrintChoiceList(3, (char[2]) { temp, '\0' }, (char[2]) { d1, '\0' }, (char[2]) { d2, '\0' });
				break;
			case 4:
				temp = rand() % 40;
				while ((d1 = rand() % 40) == temp);
				while (((d2 = rand() % 40) == temp) || d2 == d1);
				while (((d3 = rand() % 40) == temp) || d3 == d2 || d3 == d1);
				d4 = rand() % 4;
				printf("num={%d, %d, %d, %d};\nprintf(\"%%d\",num[%d]);의 결과 값은?\n\n\n",
					temp, d1, d2, d3, d4);
				switch (d4) {
					case 1:
						d4 = temp;
						temp = d1;
						d1 = d4;
						break;
					case 2:
						d4 = temp;
						temp = d2;
						d2 = d4;
						break;
					case 3:
						d4 = temp;
						temp = d3;
						d3 = d4;
						break;
				}
				temp = PrintChoiceList(4, (char[3]) { (temp / 10) ? (temp / 10) + 48 : ' ', temp % 10 + 48, '\0' }, (char[3]) { (d1 / 10) ? (d1 / 10) + 48 : ' ', d1 % 10 + 48, '\0' }, (char[3]) { (d2 / 10) ? (d2 / 10) + 48 : ' ', d2 % 10 + 48, '\0' }, (char[3]) { (d3 / 10) ? (d3 / 10) + 48 : ' ', d3 % 10 + 48, '\0' });
				break;
			case 5:
				temp = rand() % 44 + 1;
				printf("1 ~ %d의 합은 얼만인가?\n\n\n",
					temp);
				d1 = temp + ((rand() % 2) ? (-1) : (1));
				d2 = temp + ((rand() % 2) ? (-2) : (2));
				temp = (temp * (temp + 1)) >> 1;
				d1 = (d1 * (d1 + 1)) >> 1;
				d2 = (d2 * (d2 + 1)) >> 1;
				temp = PrintChoiceList(3,
					(char[4]) { (temp / 100) ? (temp / 100) + 48 : ' ', ((temp / 10)%10)? ((temp / 10) % 10)+48: (temp / 100) ? '0' : ' ', temp % 10 + 48, '\0' },
					(char[4]) { (d1 / 100) ? (d1 / 100) + 48 : ' ', ((d1 / 10) % 10) ? ((d1 / 10) % 10)+48 : (d1 / 100) ? '0' : ' ', d1 % 10 + 48, '\0'},
					(char[4]) { (d2 / 100) ? (d2 / 100) + 48 : ' ', ((d2 / 10) % 10) ? ((d2 / 10) % 10)+48 : (d2 / 100) ? '0' : ' ', d2 % 10 + 48, '\0'});
				break;
			case 6:
				temp = rand() % 7;
				printf("sizeof(%s)의 값은? \n\n\n",
					((!temp) ? "long long" : (temp == 1) ? "double" : (temp == 2) ?"long":(temp==3)? "int": (temp == 4) ? "float" : (temp == 5) ? "short" : "char"));
				d1 = (temp < 2) ? 8 : (temp < 5) ? 4 : (temp < 6) ? 2 : 1;
				while ((d2 = rand() % 9+1) == d1);
				while (((d3 = rand() % 9+1) == d1) || d3 == d2);
				while (((d4 = rand() % 9+1) == d1) || d4 == d3 || d4 == d2);
				temp = PrintChoiceList(4, (char[2]) { d1 + 48, '\0' }, (char[2]) { d2 + 48, '\0' }, (char[2]) { d3 + 48, '\0' }, (char[2]) { d4 + 48, '\0' });
				break;
		}
		printf(">>");
		scanf_s("%d", &q);
		if (q-1 == temp) {
			printf("정답이다.\n\n");
		}
		else {
			printf("이는 정답이 아니다.\n틀렸으니 냥냥펀치를 받아라.\n기분: %d->", feelingpoint);
			feelingdown(1);
			printf("%d, 관계: %d->", feelingpoint, slavepoint);
			slavedown(1);
			printf("%d\n", slavepoint);
			Sleep(2000);
			return;
		}

	}
	printf("문제 3개를 맞추었으니 쓰다듬어도된다.\n 기분: %d->", feelingpoint);
	feelingup(1);
	printf("%d\n", feelingpoint);
	Sleep(2000);
	return;
}

void KaitoEvent() {
	printf("냥도: 훔치러온 보물이다.\n"
		"      이런 보안으로 잠겨있다니.\n"
		"      어이 조수 이거 풀어.\n\n");
	DWORD d[4], num, r[4], e[4];
	BOOL flag;
	d[0] = rand() % 10;
	d[1] = rand() % 10;
	d[2] = rand() % 10;
	d[3] = rand() % 10;
	//printf("%d%d%d%d\n", d[0], d[1], d[2], d[3]);
	for (int i = 4; ~i; i--) {
		printf("남은 기회 %d\n|    |\b\b\b\b\b", i);
		scanf_s("%d", &num);
		r[0] = (num / 1000) % 10;
		r[1] = (num / 100) % 10;
		r[2] = (num / 10) % 10;
		r[3] = num% 10;
		for (int ri = 0; ri < 4; ri++) {
			e[ri] = 0;
			if (r[ri] == d[ri]) {
				e[ri] = 0x2;
				continue;
			}
			flag = 0;
			for (int di = 0; di < 4; di++) {
				if (r[ri] == d[di]) {
					flag = flag | 0x1;
				}
			}
			if (flag) {
				e[ri] = 0x1;
			}
		}
		if (e[0] & 0x2 && e[1] & 0x2 && e[2] & 0x2 && e[3] & 0x2) {
			puts("\n딸깍\n냥도: 조수여 풀었구나.");
			printf("관계: %d->", slavepoint);
			slaveup(1);
			printf("%d", slavepoint);
			Sleep(2000);
			return;
		}
		printf(" %s%d\033[0m",e[0]&0x2?"\033[0;32m":e[0]?"\033[0;33m":"",r[0]);
		printf("%s%d\033[0m",e[1]&0x2?"\033[0;32m":e[1]?"\033[0;33m":"",r[1]);
		printf("%s%d\033[0m",e[2]&0x2?"\033[0;32m":e[2]?"\033[0;33m":"",r[2]);
		printf("%s%d\033[0m",e[3]&0x2?"\033[0;32m":e[3]?"\033[0;33m":"",r[3]);
		puts("\n");
	}
	puts("위용위용\n냥도: 으악. 작전상 후퇴다.");
	printf("기분: %d->", feelingpoint);
	feelingdown(1);
	printf("%d, 관계: %d->", feelingpoint, slavepoint);
	slavedown(1);
	printf("%d\n", slavepoint);
	Sleep(2000);
	return;
}

void StoreEvent() {
	#pragma region PRICE

	#define _price(X) #X
	#define price(X) _price(X)
	#define PRICE_CHURU 2  //soup
	#define PRICE_YARN 6 //sp
	#define PRICE_BUNTING 4 //sp

	#pragma endregion

	puts("갑작이 후드를 뒤집어쓴 수상한 고양이가나타났습니다.\n"
		"수상한 고양이: 어떤 물건을 원하는가?\n"
		"어떤 물건을 구매할까요?");
	printf("CP: %d , 수프: %d\n", sppoint, numberofsoup);
	puts("  0. 아무것도 사지 않는다.");
	if (churu) {
		puts("  1. 츄르: " price(PRICE_CHURU)" SOUP (품절)");
	}
	else {
		puts("  1. 츄르: " price(PRICE_CHURU)" SOUP");
	}
	if (yarn) {
		puts("  2. 털실: " price(PRICE_YARN)" CP (품절)");
	}
	else {
		puts("  2. 털실: " price(PRICE_YARN)" CP");
	}
	puts("  3. 부비부비: " price(PRICE_BUNTING)" CP");
	
	int choice;
LOOP:;
	printf(">>");
	scanf_s("%d", &choice);
	switch (choice) {
		case 0:
			return;
		case 1:
			if (churu) {
				puts("츄르를 이미 구매했습니다.");
			}
			else if (numberofsoup < PRICE_CHURU) {
				puts("SOUP가 부족합니다.");
			}
			else {
				puts("츄르를 구매했습니다.");
				churu = true;
				numberofsoup -= PRICE_CHURU;
			}
			break;
		case 2:
			if (yarn) {
				puts("털실를 이미 구매했습니다.");
			}
			else if (sppoint < PRICE_YARN) {
				puts("CP가 부족합니다.");
			}
			else {
				puts("털실를 구매했습니다.");
				yarn = true;
				sppoint -= PRICE_YARN;
			}
			break;
		case 3:
			if (sppoint < PRICE_BUNTING) {
				puts("CP가 부족합니다.");
			}
			else {
				puts("수상한 고양이가 부비부비해줘습니다.");
				sppoint -= PRICE_BUNTING;
			}
			break;
	}
	goto LOOP;
}