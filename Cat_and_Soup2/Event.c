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
			printf("%s(��)�� ����� �ſ������� �̿��� ������ �Ͽ����ϴ�.\n"
				"����� ������ �������� �밡�ٸ� �ϰ� ����ϴ�.\n\n\n", mastername);
			printf("���� Ƚ��: %d��\n\n", count);
			for (spacebar = per; spacebar; spacebar--) {
				putchar(' ');
			}
			puts(" ��o");
			for (spacebar = per; spacebar; spacebar--) {
				putchar(' ');
			}
			puts("��/\\");
			for (spacebar = per; spacebar; spacebar--) {
				putchar(' ');
			}
			puts(" /\\");

			puts("\n\n�ƹ�Ű�� �ݺ��ؼ� ��������.");
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
	puts("����� ���� ������ ���ҽ��ϴ�.\n\n>>����Ͻ÷��� enterŰ�� �����ּ���.");
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
	printf("����ũ��: %s�� ���ٵ������� ��\n"
		   "          ������ ������ �ɳ���ġ�� �ް� �������.\n\n", mastername);

	for (int i = 1; i<=3; i++) {
		temp = rand() % (QUIZ_LENGTH - i + 1);
		q = quizlist[temp];
		quizlist[temp] = quizlist[QUIZ_LENGTH - i];
		printf("%d�� ����: ", i);
		switch (q) {
			case 0:
				puts("Ű���� �κ��� �ϳ��� ���ڸ� �Է¹޴� ����� �����Ѱ���?\n\n");
				temp = PrintChoiceList(3, "ch = getchar()", "scanf_s(\"%s\",&ch,num)", "scanf(\"%d\",&ch)");
				break;
			case 1:
				puts("y=e^x�� �̺��ϸ�?\n\n");
				temp = PrintChoiceList(5, "e^x", "e*e^x", "e", "e*x", "e/x");
				break;
			case 2:
				printf("y=%dx�� �̺��ϸ�?\n\n\n", temp = rand() % 9 + 1);

				while ((d1 = rand() % 9 + 1) == temp);
				while (((d2 = rand() % 9 + 1) == temp) || d2 == d1);
				temp = PrintChoiceList(3, (char[2]) { temp + 48, '\0' }, (char[2]) { d1 + 48, '\0' }, (char[2]) { d2 + 48, '\0' });
				break;
			case 3:
				printf("%d�� �ƽ�Ű �ڵ� ����?\n\n\n", temp = rand() % 94 + 1 + 32);
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
				printf("num={%d, %d, %d, %d};\nprintf(\"%%d\",num[%d]);�� ��� ����?\n\n\n",
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
				printf("1 ~ %d�� ���� ���ΰ�?\n\n\n",
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
				printf("sizeof(%s)�� ����? \n\n\n",
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
			printf("�����̴�.\n\n");
		}
		else {
			printf("�̴� ������ �ƴϴ�.\nƲ������ �ɳ���ġ�� �޾ƶ�.\n���: %d->", feelingpoint);
			feelingdown(1);
			printf("%d, ����: %d->", feelingpoint, slavepoint);
			slavedown(1);
			printf("%d\n", slavepoint);
			Sleep(2000);
			return;
		}

	}
	printf("���� 3���� ���߾����� ���ٵ��ȴ�.\n ���: %d->", feelingpoint);
	feelingup(1);
	printf("%d\n", feelingpoint);
	Sleep(2000);
	return;
}

void KaitoEvent() {
	printf("�ɵ�: ��ġ���� �����̴�.\n"
		"      �̷� �������� ����ִٴ�.\n"
		"      ���� ���� �̰� Ǯ��.\n\n");
	DWORD d[4], num, r[4], e[4];
	BOOL flag;
	d[0] = rand() % 10;
	d[1] = rand() % 10;
	d[2] = rand() % 10;
	d[3] = rand() % 10;
	//printf("%d%d%d%d\n", d[0], d[1], d[2], d[3]);
	for (int i = 4; ~i; i--) {
		printf("���� ��ȸ %d\n|    |\b\b\b\b\b", i);
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
			puts("\n����\n�ɵ�: ������ Ǯ������.");
			printf("����: %d->", slavepoint);
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
	puts("��������\n�ɵ�: ����. ������ �����.");
	printf("���: %d->", feelingpoint);
	feelingdown(1);
	printf("%d, ����: %d->", feelingpoint, slavepoint);
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

	puts("������ �ĵ带 ����� ������ ����̰���Ÿ�����ϴ�.\n"
		"������ �����: � ������ ���ϴ°�?\n"
		"� ������ �����ұ��?");
	printf("CP: %d , ����: %d\n", sppoint, numberofsoup);
	puts("  0. �ƹ��͵� ���� �ʴ´�.");
	if (churu) {
		puts("  1. ��: " price(PRICE_CHURU)" SOUP (ǰ��)");
	}
	else {
		puts("  1. ��: " price(PRICE_CHURU)" SOUP");
	}
	if (yarn) {
		puts("  2. �н�: " price(PRICE_YARN)" CP (ǰ��)");
	}
	else {
		puts("  2. �н�: " price(PRICE_YARN)" CP");
	}
	puts("  3. �κ�κ�: " price(PRICE_BUNTING)" CP");
	
	int choice;
LOOP:;
	printf(">>");
	scanf_s("%d", &choice);
	switch (choice) {
		case 0:
			return;
		case 1:
			if (churu) {
				puts("�򸣸� �̹� �����߽��ϴ�.");
			}
			else if (numberofsoup < PRICE_CHURU) {
				puts("SOUP�� �����մϴ�.");
			}
			else {
				puts("�򸣸� �����߽��ϴ�.");
				churu = true;
				numberofsoup -= PRICE_CHURU;
			}
			break;
		case 2:
			if (yarn) {
				puts("�нǸ� �̹� �����߽��ϴ�.");
			}
			else if (sppoint < PRICE_YARN) {
				puts("CP�� �����մϴ�.");
			}
			else {
				puts("�нǸ� �����߽��ϴ�.");
				yarn = true;
				sppoint -= PRICE_YARN;
			}
			break;
		case 3:
			if (sppoint < PRICE_BUNTING) {
				puts("CP�� �����մϴ�.");
			}
			else {
				puts("������ ����̰� �κ�κ�������ϴ�.");
				sppoint -= PRICE_BUNTING;
			}
			break;
	}
	goto LOOP;
}