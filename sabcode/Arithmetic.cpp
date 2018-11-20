#include "main.h"

void Mul(unsigned long long* a, unsigned long long b, unsigned long long c)
{
	*a = b * c;
}

void Sum(unsigned long long* a, unsigned long long b, unsigned long long c)
{
	*a = b + c;
}

void Sub(unsigned long long* a, unsigned long long b, unsigned long long c)
{
	*a = b - c;
}

void Div(unsigned long long* a, unsigned long long b, unsigned long long c)
{
	*a = b / c;
}

void Not(unsigned long long* a, unsigned long long b)
{
	*a = ~b;
}

void Or(unsigned long long * a, unsigned long long b, unsigned long long c)
{
	*a = b | c;

}

void Xor(unsigned long long* a, unsigned long long b, unsigned long long c)
{
	*a = b ^ c;
}

void And(unsigned long long *a, unsigned long long b, unsigned long long c)
{
	*a = b & c;
}

void Shift_Left(unsigned long long *a, unsigned long long b, unsigned long long c)
{
	*a = b << c;
}

void Shift_Right(unsigned long long *a, unsigned long long b, unsigned long long c)
{
	*a = b >> c;
}