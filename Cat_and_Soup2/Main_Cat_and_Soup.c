#include "Cat_and_Soup.h"
#include "Private.h"

char roomwall[ROOM_WIDTH + 1];
char roomarr[ROOM_WIDTH + 1];
char mastername[MAX_LENGTH];
int numberofsoup = 0;
int sppoint = 0;
int feelingpoint = 3;
int slavepoint = 2;
int masterposition = START_POS;
int previousposition = START_POS;

int scratcherposition = NOT_HAVE_POS;
int towerposition = NOT_HAVE_POS;

int mouse = 0;
int laser = 0;
int churu = 0;
int yarn = 0;
int interactionlist[6];

int eventcounter = 1;

void Initialization() {
	srand(time(NULL));
	roomarr[0] = '#';
	roomwall[0] = '#';
	for (int i = ROOM_WIDTH - 2; i; i--) {
		roomarr[i] = ' ';
		roomwall[i] = '#';
	}
	roomarr[ROOM_WIDTH - 1] = '#';
	roomwall[ROOM_WIDTH - 1] = '#';
	roomarr[ROOM_WIDTH] = '\0';
	roomwall[ROOM_WIDTH] = '\0';

	interactionlist[0] = 0;
	interactionlist[1] = 1;
}

void IntroPage() {
	printf("****�߿��̿� ����****\n\n");

	puts("      /\\_/\\ \n"
		" /\\  / o o \\ \n"
		"//\\\\ \\-(*)-/ \n"
		"`  \\/   ^ / \n"
		"   | \\|| || \n"
		"   \\ `|| || \n"
		"    \\)()-()) ");
	printf("�߿����� �̸��� ���� �ּ���: ");
	scanf_s("%s", mastername, MAX_LENGTH);
	printf("�߿����� �̸��� %s�Դϴ�.", mastername);
	Sleep(1300);
	system("cls");
	printf("****�߿��̿� ����****\n\n");
	puts("      /\\_/\\ \n"
		" /\\  / o < \\ \n"
		"//\\\\ \\-(*)-/ \n"
		"`  \\/   ^ / \n"
		"   | \\|| || \n"
		"   \\ `|| || \n"
		"    \\)()-()) ");
	printf("�߿����� �̸��� ���� �ּ���: %s\n", mastername);
	printf("�߿����� �̸��� %s�Դϴ�.", mastername);
	Sleep(300);
	system("cls");
	printf("****�߿��̿� ����****\n\n");
	puts("      /\\_/\\ \n"
		" /\\  / o o \\ \n"
		"//\\\\ \\-(*)-/ \n"
		"`  \\/   ^ / \n"
		"   | \\|| || \n"
		"   \\ `|| || \n"
		"    \\)()-()) ");
	printf("�߿����� �̸��� ���� �ּ���: %s\n", mastername);
	printf("�߿����� �̸��� %s�Դϴ�.", mastername);
	Sleep(400);
	system("cls");
}

void StatusPage() {
	puts("==================== ���� ���� =============");
	printf("������� ���� ����: %d��\n", numberofsoup);
	printf("CP: %d\n", sppoint);
	printf("%s ���(0~3): %d\n  ", mastername, feelingpoint);
	switch (feelingpoint) {
		case 0:
			puts("����� �ſ� ���޴ϴ�.");
			break;
		case 1:
			puts("�ɽ����մϴ�.");
			break;
		case 2:
			puts("�Ļ��� �����ϴ�.");
			break;
		case 3:
			puts("������ �θ��ϴ�");
			break;
		default:
			puts("Feel is not defined");
			break;
	}
	printf("������� ����(0~4): %d\n  ", slavepoint);
	switch (slavepoint) {
		case 0:
			puts("�翡 ���� ������ �Ⱦ��մϴ�.");
			break;
		case 1:
			puts("���� ���Ǳ� ����Դϴ�.");
			break;
		case 2:
			puts("�׷����� �� ���� �����Դϴ�.");
			break;
		case 3:
			puts("�Ǹ��� ����� ���� �ް� �ֽ��ϴ�.");
			break;
		case 4:
			puts("���� �������Դϴ�.");
			break;
		default:
			puts("SlavePoint is not defined");
			break;
	}
	puts("============================================");
	return;
}

void BadFeelingPage() {
	dice = rand() % 6;
	if (dice <= 5 - slavepoint) {
		printf("%s�� ����� �׳� �������ϴ�: %d->",mastername, feelingpoint);
		feelingdown(1);
		printf("%d\n", feelingpoint);
	}
}

void MovePage() {
	switch (feelingpoint) {
		case 0:
			if (masterposition > MIN_POS) {
				masterposition--;
				printf("����� �ſ� ���� %s��(��) ������ ���մϴ�.\n", mastername);
			}
			else {
				feelingup(1);
				printf("%s��(��) ������ �޽��� ���߽��ϴ�.\n", mastername);
			}
			break;
		case 1:
			if (!towerposition && !scratcherposition) {
				feelingdown(1);
				puts("�� �Ÿ��� ��� ����� �ſ� �������ϴ�.");
				break;
			}
			int temp;
			int target;
			if (!towerposition) {
				temp = scratcherposition - masterposition;
				target = 0x1;
			}
			else if (!scratcherposition) {
				temp = towerposition - masterposition;
				target = 0x2;
			}
			else {
				temp = scratcherposition - masterposition;
				int temp2 = towerposition - masterposition;
				target = 0x1;
				if (ABS(temp) > ABS(temp2)) {
					temp = temp2;
					target = 0x2;
				}
			}
			if (temp & (~((~(unsigned int)0) >> 1))) {
				masterposition--;
			}
			else if (temp) {
				masterposition++;
			}
			else {
				if (target&0x1) {
					scratcherposition = NOT_HAVE_POS;
					printf("%s��(��) ��ũ��ó�� �ܰ� ��ҽ��ϴ�.\n����� ���������ϴ�: 1->2\n", mastername);
					break;
				}
				else {
					towerposition = NOT_HAVE_POS;
					printf("%s��(��) Ĺ Ÿ���� �پ�ٴմϴ�.\n����� ���� ���������ϴ�: 1->3\n", mastername);
					break;
				}
			}
			if (target & 0x1) {
				printf("%s��(��) �ɽ��ؼ� ��ũ��ó ������ �̵��մϴ�.\n",mastername);

			}
			else
			{
				printf("%s��(��) �ɽ��ؼ� Ĺ Ÿ�� ������ �̵��մϴ�.\n", mastername);
			}
			break;
		case 2:
			printf("%s��(��) ������� �Ļ��� ���� �ֽ��ϴ�.\n",mastername);
			break;
		case 3:
			if (masterposition == MAX_POS) {
				numberofsoup++;
				switch (rand() % 3) {
					case 0:
						printf("%s��(��) ���� ������ ��������ϴ�.\n", mastername);
						break;
					case 1:
						printf("%s��(��) ����� ������ ��������ϴ�.\n", mastername);
						break;
					case 2:
						printf("%s��(��) ����ݸ� ������ ��������ϴ�.\n", mastername);
						break;
				}
				printf("���� ����: %d��\n", numberofsoup);
			}
			else {
				masterposition++;
				printf("%s��(��) ������ �θ��� ������ ����� ���ϴ�.\n", mastername);
			}
			break;
	}

}

void RoomPage() {
	puts(roomwall);
	roomarr[scratcherposition] = 'S';
	roomarr[towerposition] = 'T';
	roomarr[HME_POS] = 'H';
	roomarr[BWL_PO] = 'B';
	roomarr[0] = '#';
	puts(roomarr);
	roomarr[scratcherposition] = ' ';
	roomarr[towerposition] = ' ';
	roomarr[HME_POS] = ' ';
	roomarr[BWL_PO] = ' ';
	roomarr[0] = '#';

	roomarr[previousposition] = '.';
	roomarr[masterposition] = 'C';
	puts(roomarr);
	roomarr[previousposition] = ' ';
	roomarr[masterposition] = ' ';
	puts(roomwall);
	previousposition = masterposition;
	return;
}

void InteractionPage() {
	int interactionnumber = 2;
	int interactionchoice;
	puts("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?");
	puts("  0. �ƹ��͵� ���� ����");
	puts("  1. �ܾ� �ֱ�");
	if (mouse) {
		puts("  2. �峭�� ��� ��� �ֱ�");
		interactionlist[2] = 2;
		interactionnumber++;
	}
	if (laser) {
		printf("  %d. ������ �����ͷ� ��� �ֱ�\n", interactionnumber);
		interactionlist[interactionnumber] = 3;
		interactionnumber++;
	}
	if (yarn) {
		printf("  %d. �н� �ֱ�\n", interactionnumber);
		interactionlist[interactionnumber] = 4;
		interactionnumber++;
	}
	if (churu) {
		printf("  %d. �� �ֱ�\n", interactionnumber);
		interactionlist[interactionnumber] = 5;
		interactionnumber++;
	}
LOOP:;
	printf(">>");
	scanf_s("%d", &interactionchoice);
	if (interactionchoice >= interactionnumber) {
		goto LOOP;
	}
	switch (interactionlist[interactionchoice]) {
		case 0:
			NotThingInteraction();
			break;
		case 1:
			ScratchInteraction();
			break;
		case 2:
			MouseInteraction();
			mouse = false;
			break;
		case 3:
			LaserInteraction();
			laser = false;
			break;
		case 4:
			YarnInteraction();
			yarn = false;
			break;
		case 5:
			ChuruInteraction();
			churu = false;
			break;
	}
}

void MakeSp() {
	sppoint += (feelingpoint - 1) + (slavepoint);
	printf("%s�� ��а� ģ�е��� ���� CP�� %d����Ǿ����ϴ�.\n���� CP: %d ����Ʈ\n",
		mastername, (feelingpoint - 1) + (slavepoint), sppoint);


	//SpecialEvents();
	return;
}

void StorePage() {
	#pragma region PRICE

	#define _price(X) #X
	#define price(X) _price(X)
	#define PRICE_MOUSE 1
	#define PRICE_LASER 2
	#define PRICE_SCRATCHER 4
	#define PRICE_TOWER 6

	#pragma endregion

	puts("�������� ������ �� �� �ֽ��ϴ�.\n"
		"� ������ �����ұ��?");
	puts("  0. �ƹ��͵� ���� �ʴ´�.");
	if (mouse) {
		puts("  1. �峭�� ��: " price(PRICE_MOUSE)" CP (ǰ��)");
	}
	else {
		puts("  1. �峭�� ��: " price(PRICE_MOUSE)" CP");
	}
	if (laser) {
		puts("  2. ������ ������: " price(PRICE_LASER)" CP (ǰ��)");
	}
	else {
		puts("  2. ������ ������: " price(PRICE_LASER)" CP");
	}
	if (!scratcherposition) {
		puts("  3. ��ũ��ó: " price(PRICE_SCRATCHER)" CP");
	}
	else {
		puts("  3. ��ũ��ó: " price(PRICE_SCRATCHER)" CP (ǰ��)");
	}
	if (!towerposition) {
		puts("  4. Ĺ Ÿ��: " price(PRICE_TOWER)" CP");
	}
	else {
		puts("  4. Ĺ Ÿ��: " price(PRICE_TOWER)" CP (ǰ��)");
	}
	int choice;
LOOP:;
	printf(">>");
	scanf_s("%d", &choice);
	switch (choice) {
		case 0:
			return;
		case 1:
			if (mouse) {
				puts("�峭�� �㸦 �̹� �����߽��ϴ�."); 
			}
			else if (sppoint < PRICE_MOUSE) {
				puts("CP�� �����մϴ�.");
			}
			else {
				puts("�峭�� �㸦 �����߽��ϴ�.");
				mouse = true;
				sppoint -= PRICE_MOUSE;
			}
			break;
		case 2:
			if (laser) {
				puts("������ �����͸� �̹� �����߽��ϴ�."); 
			}
			else if (sppoint < PRICE_LASER) {
				puts("CP�� �����մϴ�.");
			}
			else {
				puts("������ �����͸� �����߽��ϴ�.");
				laser = true;
				sppoint -= PRICE_LASER;
			}
			break;
		case 3:
			if (scratcherposition) {
				puts("��ũ��ó�� �̹� �����߽��ϴ�.");
			}
			else if (sppoint < PRICE_SCRATCHER) {
				puts("CP�� �����մϴ�.");
			}
			else {
				puts("��ũ��ó�� �����߽��ϴ�.");
				do {
					scratcherposition = rand() % (MAX_POS - MIN_POS) + 2;
				}while(towerposition == scratcherposition);
				sppoint -= PRICE_SCRATCHER;
			}
			break;
		case 4:
			if (towerposition) {
				puts("Ĺ Ÿ���� �̹� �����߽��ϴ�.");
			}
			else if (sppoint < PRICE_TOWER) {
				puts("CP�� �����մϴ�.");
			}
			else {
				puts("Ĺ Ÿ���� �����߽��ϴ�.");
				do {
					towerposition = rand() % (MAX_POS - MIN_POS) + 2;
				} while (towerposition == scratcherposition);
				sppoint -= PRICE_TOWER;
			}
			break;
	}
	goto LOOP;
}

void Cat_and_Soup_Event() {
	system("cls");
	return;
	if (eventcounter == 3) {
		switch (rand() % NUMBEROFEVENT) {
			case 0:
				LoanEvent();
				break;
			case 1:
				SphinxEvent();
				break;
			case 2:
				KaitoEvent();
				break;
			case 3:
				StoreEvent();
		}
		eventcounter = 1;
		return;
	}
	eventcounter++;
	return;
}

void Cat_and_Soup() {
	#pragma region GAP
	#define _GAP0
	#define _GAP1 puts("");
	#define _GAP2 puts("\n");
	#define _GAP3 puts("\n\n");
	#define _GAP4 puts("\n\n\n");
	#define _GAP5 puts("\n\n\n\n");
	#define _GAP6 puts("\n\n\n\n\n");
	#define GAP(X) _GAP##X
	#pragma endregion

	Initialization();
	IntroPage();
	StatusPage();
	GAP(1)
	RoomPage();
	GAP(1)
	InteractionPage();
	GAP(1)
	MakeSp();
	GAP(1)
	StorePage();
	Cat_and_Soup_Event();
	Sleep(500);
	system("cls");
LOOP:;
	StatusPage();
	GAP(1)
	BadFeelingPage();
	MovePage();
	GAP(1)
	RoomPage();
	GAP(1)
	InteractionPage();
	GAP(1)
	MakeSp();
	GAP(1)
	StorePage();
	GAP(1)
	Cat_and_Soup_Event();
	Sleep(500);
	system("cls");
	goto LOOP;

	return;
}

