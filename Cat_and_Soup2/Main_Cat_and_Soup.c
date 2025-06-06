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
	printf("****야옹이와 수프****\n\n");

	puts("      /\\_/\\ \n"
		" /\\  / o o \\ \n"
		"//\\\\ \\-(*)-/ \n"
		"`  \\/   ^ / \n"
		"   | \\|| || \n"
		"   \\ `|| || \n"
		"    \\)()-()) ");
	printf("야옹이의 이름을 지어 주세요: ");
	scanf_s("%s", mastername, MAX_LENGTH);
	printf("야옹이의 이름은 %s입니다.", mastername);
	Sleep(1300);
	system("cls");
	printf("****야옹이와 수프****\n\n");
	puts("      /\\_/\\ \n"
		" /\\  / o < \\ \n"
		"//\\\\ \\-(*)-/ \n"
		"`  \\/   ^ / \n"
		"   | \\|| || \n"
		"   \\ `|| || \n"
		"    \\)()-()) ");
	printf("야옹이의 이름을 지어 주세요: %s\n", mastername);
	printf("야옹이의 이름은 %s입니다.", mastername);
	Sleep(300);
	system("cls");
	printf("****야옹이와 수프****\n\n");
	puts("      /\\_/\\ \n"
		" /\\  / o o \\ \n"
		"//\\\\ \\-(*)-/ \n"
		"`  \\/   ^ / \n"
		"   | \\|| || \n"
		"   \\ `|| || \n"
		"    \\)()-()) ");
	printf("야옹이의 이름을 지어 주세요: %s\n", mastername);
	printf("야옹이의 이름은 %s입니다.", mastername);
	Sleep(400);
	system("cls");
}

void StatusPage() {
	puts("==================== 현재 상태 =============");
	printf("현재까지 만든 수프: %d개\n", numberofsoup);
	printf("CP: %d\n", sppoint);
	printf("%s 기분(0~3): %d\n  ", mastername, feelingpoint);
	switch (feelingpoint) {
		case 0:
			puts("기분이 매우 나쁩니다.");
			break;
		case 1:
			puts("심심해합니다.");
			break;
		case 2:
			puts("식빵을 굽습니다.");
			break;
		case 3:
			puts("골골송을 부릅니다");
			break;
		default:
			puts("Feel is not defined");
			break;
	}
	printf("집사와의 관계(0~4): %d\n  ", slavepoint);
	switch (slavepoint) {
		case 0:
			puts("곁에 오는 것조차 싫어합니다.");
			break;
		case 1:
			puts("간식 자판기 취급입니다.");
			break;
		case 2:
			puts("그럭저럭 쓸 만한 집사입니다.");
			break;
		case 3:
			puts("훌륭한 집사로 인정 받고 있습니다.");
			break;
		case 4:
			puts("집사 껌딱지입니다.");
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
		printf("%s의 기분이 그냥 나빠집니다: %d->",mastername, feelingpoint);
		feelingdown(1);
		printf("%d\n", feelingpoint);
	}
}

void MovePage() {
	switch (feelingpoint) {
		case 0:
			if (masterposition > MIN_POS) {
				masterposition--;
				printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.\n", mastername);
			}
			else {
				feelingup(1);
				printf("%s은(는) 집에서 휴식을 취했습니다.\n", mastername);
			}
			break;
		case 1:
			if (!towerposition && !scratcherposition) {
				feelingdown(1);
				puts("놀 거리가 없어서 기분이 매우 나빠집니다.");
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
					printf("%s은(는) 스크래처를 긁고 놀았습니다.\n기분이 나아졌습니다: 1->2\n", mastername);
					break;
				}
				else {
					towerposition = NOT_HAVE_POS;
					printf("%s은(는) 캣 타워를 뛰어다닙니다.\n기분이 제법 좋아졌습니다: 1->3\n", mastername);
					break;
				}
			}
			if (target & 0x1) {
				printf("%s은(는) 심심해서 스크래처 쪽으로 이동합니다.\n",mastername);

			}
			else
			{
				printf("%s은(는) 심심해서 캣 타워 쪽으로 이동합니다.\n", mastername);
			}
			break;
		case 2:
			printf("%s은(는) 기분좋게 식빵을 굽고 있습니다.\n",mastername);
			break;
		case 3:
			if (masterposition == MAX_POS) {
				numberofsoup++;
				switch (rand() % 3) {
					case 0:
						printf("%s이(가) 감자 수프를 만들었습니다.\n", mastername);
						break;
					case 1:
						printf("%s이(가) 양송이 수프를 만들었습니다.\n", mastername);
						break;
					case 2:
						printf("%s이(가) 브로콜리 수프를 만들었습니다.\n", mastername);
						break;
				}
				printf("수프 갯수: %d개\n", numberofsoup);
			}
			else {
				masterposition++;
				printf("%s은(는) 골골송을 부르며 수프를 만들거 갑니다.\n", mastername);
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
	puts("어떤 상호작용을 하시겠습니까?");
	puts("  0. 아무것도 하지 않음");
	puts("  1. 긁어 주기");
	if (mouse) {
		puts("  2. 장난감 쥐로 놀아 주기");
		interactionlist[2] = 2;
		interactionnumber++;
	}
	if (laser) {
		printf("  %d. 레이저 포인터로 놀아 주기\n", interactionnumber);
		interactionlist[interactionnumber] = 3;
		interactionnumber++;
	}
	if (yarn) {
		printf("  %d. 털실 주기\n", interactionnumber);
		interactionlist[interactionnumber] = 4;
		interactionnumber++;
	}
	if (churu) {
		printf("  %d. 츄르 주기\n", interactionnumber);
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
	printf("%s의 기분과 친밀도에 따라서 CP가 %d생산되었습니다.\n보유 CP: %d 포인트\n",
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

	puts("상점에서 물건을 살 수 있습니다.\n"
		"어떤 물건을 구매할까요?");
	puts("  0. 아무것도 사지 않는다.");
	if (mouse) {
		puts("  1. 장난감 쥐: " price(PRICE_MOUSE)" CP (품절)");
	}
	else {
		puts("  1. 장난감 쥐: " price(PRICE_MOUSE)" CP");
	}
	if (laser) {
		puts("  2. 레이저 포인터: " price(PRICE_LASER)" CP (품절)");
	}
	else {
		puts("  2. 레이저 포인터: " price(PRICE_LASER)" CP");
	}
	if (!scratcherposition) {
		puts("  3. 스크래처: " price(PRICE_SCRATCHER)" CP");
	}
	else {
		puts("  3. 스크래처: " price(PRICE_SCRATCHER)" CP (품절)");
	}
	if (!towerposition) {
		puts("  4. 캣 타워: " price(PRICE_TOWER)" CP");
	}
	else {
		puts("  4. 캣 타워: " price(PRICE_TOWER)" CP (품절)");
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
				puts("장난감 쥐를 이미 구매했습니다."); 
			}
			else if (sppoint < PRICE_MOUSE) {
				puts("CP가 부족합니다.");
			}
			else {
				puts("장난감 쥐를 구매했습니다.");
				mouse = true;
				sppoint -= PRICE_MOUSE;
			}
			break;
		case 2:
			if (laser) {
				puts("레이저 포인터를 이미 구매했습니다."); 
			}
			else if (sppoint < PRICE_LASER) {
				puts("CP가 부족합니다.");
			}
			else {
				puts("레이저 포인터를 구매했습니다.");
				laser = true;
				sppoint -= PRICE_LASER;
			}
			break;
		case 3:
			if (scratcherposition) {
				puts("스크래처를 이미 구매했습니다.");
			}
			else if (sppoint < PRICE_SCRATCHER) {
				puts("CP가 부족합니다.");
			}
			else {
				puts("스크래처를 구매했습니다.");
				do {
					scratcherposition = rand() % (MAX_POS - MIN_POS) + 2;
				}while(towerposition == scratcherposition);
				sppoint -= PRICE_SCRATCHER;
			}
			break;
		case 4:
			if (towerposition) {
				puts("캣 타워를 이미 구매했습니다.");
			}
			else if (sppoint < PRICE_TOWER) {
				puts("CP가 부족합니다.");
			}
			else {
				puts("캣 타워를 구매했습니다.");
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

