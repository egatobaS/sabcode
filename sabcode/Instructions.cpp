#include "main.h"

instruct_finder inst_dictionary[49] = { "lds", inst_lds,
"ldcs", inst_ldcs,
"ld", inst_ld,
"ldc", inst_ldc,
"add", inst_add,
"addc", inst_addc,
"div", inst_div,
"divc", inst_divc,
"mul", inst_mul,
"mulc", inst_mulc,
"sub", inst_sub,
"subc", inst_subc,
"or", inst_or,
"orc", inst_orc,
"and", inst_and,
"andc", inst_andc,
"not", inst_not,
"notc", inst_notc,
"xor", inst_xor,
"xorc", inst_xorc,
"st8c", inst_st8c,
"st4c", inst_st4c,
"st2c", inst_st2c,
"st1c", inst_st1c,
"st8", inst_st8,
"st4", inst_st4,
"st2", inst_st2,
"st1", inst_st1,
"rd8c", inst_rd8c,
"rd4c", inst_rd4c,
"rd2c", inst_rd2c,
"rd1c", inst_rd1c,
"rd8", inst_rd8,
"rd4", inst_rd4,
"rd2", inst_rd2,
"rd1", inst_rd1,
"nop", inst_nop,
"ret", inst_ret,
"jmp", inst_jmp,
"jmpc", inst_jmpc,
"ccmp", inst_ccmp, 
"ccmpc", inst_ccmpc, 
"cmp", inst_cmp,
"cmpc", inst_cmpc,
"call", inst_call,
"callc", inst_callc,
"syscall", inst_syscall,
"slwc", inst_slwc,
"srwc", inst_srwc };

instruct_branch_finder inst_branch_dictionary[12] = {
	"beq", inst_beq,
	"bne", inst_bne,
	"ble", inst_ble,
	"bge", inst_bge,
	"bgt", inst_bgt,
	"blt", inst_blt,
	"cbeq", inst_cbeq,
	"cbne", inst_cbne,
	"cble", inst_cble,
	"cbge", inst_cbge,
	"cbgt", inst_cbgt,
	"cblt", inst_cblt
};

int Instruction::getnthBit(int data, int nth)
{
	return ((data) >> nth) & 1;
}

int Instruction::getValueFromBits(int from, int To)
{
	int Value = 0;

	for (int i = from; i < To; ++i)
	{
		Value *= 2;
		if (bits.bits[i])
			++Value;
	}
	return Value;
}

void Instruction::parseInstruction(unsigned int instruction)
{
	for (int i = 31; i > -1; i--)
		bits.bits[31 - i] = getnthBit(instruction, i);
}

inst_opcodes Instruction::getInstructionType()
{
	return (inst_opcodes)getValueFromBits(0, 6);
}


signed int Instruction::getRegister611()
{
	return  getValueFromBits(6, 11);
}

signed short Instruction::getRegister622()
{
	return  getValueFromBits(6, 22);
}

signed short Instruction::getRegister2225()
{
	return  getValueFromBits(22, 25);
}

signed short Instruction::getRegister2532()
{
	return  getValueFromBits(25, 32);
}

signed int Instruction::getRegister1116()
{
	return  getValueFromBits(11, 16);
}

signed int Instruction::getRegister1621()
{
	return  getValueFromBits(16, 21);
}

signed short Instruction::getValue1632()
{
	return  getValueFromBits(16, 32);
}
Instruction::Instruction()
{

}

Instruction::~Instruction()
{

}
