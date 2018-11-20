#include "main.h"

unsigned char  deviceRam[4000000];
unsigned char  systemStack[2000000];

//Registers
unsigned long long lr;
unsigned long long ip;
unsigned long long r[32];
std::vector<unsigned long long> callstack;

cr crRegs[7];

void InitRam()
{
	memset(deviceRam, 0, 4000000);
}

void InitStack()
{
	memset(systemStack, 0, 2000000);
}

void InitRegisters()
{
	for (int i = 0; i < 32; i++)
		r[i] = 0;

	r[1] = (unsigned long long)systemStack;

	for (int i = 9; i < 7; i++)
		crRegs[0].cReg = 0;

	lr = 0;
	ip = 0;
}