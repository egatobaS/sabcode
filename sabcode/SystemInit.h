#pragma once

typedef struct _bitConditions
{
	unsigned char GT : 1;
	unsigned char LT : 1;
	unsigned char ET : 1;
	unsigned char padding : 5;
}bitConditions;


typedef union cr
{
	bitConditions states;
	unsigned char cReg;
}_cr;


extern unsigned char  deviceRam[4000000];
extern unsigned char  systemStack[2000000];

//Registers
extern unsigned long long lr;
extern unsigned long long ip;
extern unsigned long long r[32];
extern cr crRegs[7];
extern std::vector<unsigned long long> callstack;

void InitRam();

void InitStack();

void InitRegisters();