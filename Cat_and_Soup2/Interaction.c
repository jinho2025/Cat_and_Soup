#include"Cat_and_Soup.h"


int dice;

#define PRINT_DOWN_EVENT(NUMERATOR, DENOMINATOR) puts(#NUMERATOR"/"# DENOMINATOR"�� Ȯ���� ģ�е��� �������ϴ�.");
#define PRINT_UP_EVENT(NUMERATOR, DENOMINATOR) puts(#NUMERATOR"/"# DENOMINATOR"�� Ȯ���� ģ�е��� �������ϴ�.");
#define PRINT_UP_EVENT2(NUMERATOR, DENOMINATOR) puts(#NUMERATOR"/"# DENOMINATOR"�� Ȯ���� ģ�е��� 2�������ϴ�.");
#define DICE_ROLL rand()%6+1; PRINT_DICE_ROLL
#define PRINT_DICE_ROLL \
puts("�ֻ����� �����ϴ�. �Ǹ���...");\
printf("%d(��)�� ������ϴ�.",dice);
#define PRINT_SLAVE_DOWN puts("ģ�е��� �������ϴ�.");
#define PRINT_SLAVE_DOWNFIXED puts("������ ģ�е��� �������� ���ֽ��ϴ�.");
#define PRINT_SLAVE_UPFIXED puts("ģ�е��� �״���Դϴ�.");
#define PRINT_SLAVE_UP puts("ģ�е��� �������ϴ�.");
#define PRINT_NOW_SALVE printf("���� ģ�е�: %d\n",slavepoint);


void NotThingInteraction() {

	puts("�̹��͵� ���� �ʾҽ��ϴ�.");
	printf("%s�� ����� ���������ϴ�: %d->", mastername, feelingpoint);
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
	
	printf("%s�� ���� �ܾ��־����ϴ�.\n""%s�� ����� �״�� �Դϴ�: %d\n",
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

	printf("�峭�� ��� %s�� ��� �־����ϴ��Դϴ�.\n""%s�� ����� ���� ���������ϴ�: %d->",
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

	printf("������ �����ͷ� %s�� �ų��� ��� �־����ϴ�.\n""%s�� ����� �� ���������ϴ�: %d->",
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
	printf("�򸣸� %s���� �Կ��־����ϴ�.\n""%s�� ����� �� ���������ϴ�: %d->",
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
	printf("%s�� �н��� ���� ������ ��� �ֽ��ϴ�.\n""%s�� ����� �� ���������ϴ�: %d->",
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
