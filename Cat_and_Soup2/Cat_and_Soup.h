#ifndef __CAT_AND_SOUP__
#define __CAT_AND_SOUP__
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH - 2)

#define MIN_POS 1
#define MAX_POS (ROOM_WIDTH - 2)
#define NOT_HAVE_POS 0
#define NOT_HAVE 0

#define START_POS MIN_POS

#define MAX_LENGTH 128

#define MAX_FEELING_POINT 3
#define MAX_SLAVE_POINT 4

#define ABS(X) ((X & (~((~0) >> 1))) ? (-X) : (X))

#define feelingdown(X) \
	feelingpoint -= X;\
	if(feelingpoint & (~((~(unsigned int)0)>>1))) feelingpoint = 0;
#define feelingup(X) \
	feelingpoint += X;\
	if (feelingpoint > MAX_FEELING_POINT) feelingpoint = MAX_FEELING_POINT;
#define slavedown(X) \
	slavepoint -= X;\
	if (slavepoint & (~((~(unsigned int)0)>>1))) slavepoint = 0;
#define slaveup(X) \
	slavepoint += X;\
	if (slavepoint > MAX_SLAVE_POINT) slavepoint = MAX_SLAVE_POINT;

extern char roomwall[ROOM_WIDTH + 1];
extern char roomarr[ROOM_WIDTH + 1];
extern char mastername[MAX_LENGTH];
extern int numberofsoup;
extern int sppoint;
extern int feelingpoint;
extern int slavepoint;

extern int masterposition;
extern int previousposition;
extern int scratcherposition;
extern int towerposition;

extern int mouse;
extern int laser;
extern int churu;
extern int yarn;
extern int interactionlist[6];

extern int eventcounter;

extern void Initialization();
extern void IntroPage();
extern void StatusPage();
extern void BadFeelingPage();
extern void MovePage();
extern void RoomPage();
extern void InteractionPage();
extern void MakeSp();
extern void StorePage();
extern void Cat_and_Soup_Event();
extern void Cat_and_Soup();

//--------------------------------------


extern int dice;


extern void NotThingInteraction();
extern void ScratchInteraction();
extern void MouseInteraction();
extern void LaserInteraction();
extern void ChuruInteraction();
extern void YarnInteraction();



#endif