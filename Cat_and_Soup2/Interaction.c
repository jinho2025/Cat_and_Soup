#include"Cat_and_Soup.h"


int dice;

#define PRINT_DOWN_EVENT(NUMERATOR, DENOMINATOR) puts(#NUMERATOR"/"# DENOMINATOR"의 확률로 친밀도가 떨어집니다.");
#define PRINT_UP_EVENT(NUMERATOR, DENOMINATOR) puts(#NUMERATOR"/"# DENOMINATOR"의 확률로 친밀도가 높아집니다.");
#define PRINT_UP_EVENT2(NUMERATOR, DENOMINATOR) puts(#NUMERATOR"/"# DENOMINATOR"의 확률로 친밀도가 2높아집니다.");
#define DICE_ROLL rand()%6+1; PRINT_DICE_ROLL
#define PRINT_DICE_ROLL \
puts("주사위를 굴립니다. 또르륵...");\
printf("%d(가)이 나욌습니다.",dice);
#define PRINT_SLAVE_DOWN puts("친밀도가 떨어집니다.");
#define PRINT_SLAVE_DOWNFIXED puts("다행히 친밀도가 떨어지지 않있습니다.");
#define PRINT_SLAVE_UPFIXED puts("친밀도는 그대로입니다.");
#define PRINT_SLAVE_UP puts("친밀도는 높이집니다.");
#define PRINT_NOW_SALVE printf("현재 친밀도: %d\n",slavepoint);


void NotThingInteraction() {

	puts("이무것도 하지 않았습니다.");
	printf("%s의 기분이 나빠졌습니다: %d->", mastername, feelingpoint);
	feelingdown(1);
	printf("%d\n", feelingpoint);

	PRINT_DOWN_EVENT(5 , 6);
	dice = DICE_ROLL;
	if (dice <= 5) {
		slavedown(1);
		PRINT_SLAVE_DOWN;
	}
	else {
		PRINT_SLAVE_DOWNFIXED;
	}
	PRINT_NOW_SALVE;
	return;
}

void ScratchInteraction() {
	
	printf("%s의 턱을 긁어주었습니다.\n""%s의 기분은 그대로 입니다: %d\n",
		mastername, mastername, feelingpoint);
	PRINT_UP_EVENT(5, 6);
	dice = DICE_ROLL;
	if (dice >= 5) {
		slaveup(1);
		PRINT_SLAVE_UP;
	}
	else {
		PRINT_SLAVE_UPFIXED;
	}
	PRINT_NOW_SALVE;
	return;
}

void MouseInteraction() {

	printf("장난감 쥐로 %s와 놀아 주었습니다입니다.\n""%s의 기분이 조금 좋아졌습니다: %d->",
		mastername, mastername, feelingpoint);
	feelingup(1);
	printf("%d\n", feelingpoint);
	PRINT_UP_EVENT(4, 6);
	dice = DICE_ROLL;
	if (dice >= 4) {
		slaveup(1);
		PRINT_SLAVE_UP;
	}
	else {
		PRINT_SLAVE_UPFIXED;
	}
	PRINT_NOW_SALVE;
	return;
}

void LaserInteraction() {

	printf("레이저 포인터로 %s와 신나게 놀아 주었습니다.\n""%s의 기분이 꽤 좋아졌습니다: %d->",
		mastername, mastername, feelingpoint);
	feelingup(2);
	printf("%d\n", feelingpoint);
	PRINT_UP_EVENT(2, 6);
	dice = DICE_ROLL;
	if (dice >= 2) {
		slaveup(1);
		PRINT_SLAVE_UP;
	}
	else {
		PRINT_SLAVE_UPFIXED;
	}
	PRINT_NOW_SALVE;
	return;
}

void ChuruInteraction(){
	printf("츄르를 %s에게 먹여주었습니다.\n""%s의 기분이 꽤 좋아졌습니다: %d->",
		mastername, mastername, feelingpoint);
	feelingup(2);
	printf("%d\n", feelingpoint);
	PRINT_UP_EVENT2(4, 6);
	dice = DICE_ROLL;
	PRINT_SLAVE_UP;
	if (dice >= 4) {
		slaveup(2);
	}
	else {
		slaveup(1);
	}
	PRINT_NOW_SALVE;
	return;
}

void YarnInteraction() {
	printf("%s가 털실을 빙빙 돌리며 놀고 있습니다.\n""%s의 기분이 꽤 좋아졌습니다: %d->",
		mastername, mastername, feelingpoint);
	feelingup(2);
	printf("%d\n", feelingpoint);
	PRINT_UP_EVENT2(3, 6);
	dice = DICE_ROLL;
	if (dice >= 3) {
		slaveup(2);
		PRINT_SLAVE_UP;
	}
	else {
		slavedown(1);
		PRINT_SLAVE_DOWN;
	}
	PRINT_NOW_SALVE;
	return;
}
