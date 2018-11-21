#include "main.h"

int getIntFromBits(bool* bits, int len)
{
	int Value = 0;

	for (int i = 0; i < len; i++)
	{
		Value *= 2;
		if (bits[i])
			++Value;
	}
	return Value;
}

/*
op = 0 - 6
*/
unsigned int inst_compile(inst_opcodes op)
{
	bool localbits[32] = { 0 };
	unsigned int mask = 1 << (sizeof(unsigned char) * 8 - 1);

	mask >>= 1;
	mask >>= 1;

	for (int i = 0; i < 6; i++) {
		if ((op & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	return  getIntFromBits(localbits, 32);
}


/*
op = 0 - 6
reg = 6 - 22
*/
unsigned int inst_compile(inst_opcodes op, unsigned short value)
{
	bool localbits[32] = { 0 };
	unsigned int mask = 1 << (sizeof(unsigned char) * 8 - 1);

	mask >>= 1;
	mask >>= 1;

	for (int i = 0; i < 6; i++) {
		if ((op & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	mask = 1 << (sizeof(unsigned short) * 8 - 1);

	for (int i = 6; i < 22; i++) {
		if ((value & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	return  getIntFromBits(localbits, 32);
}


/*
op = 0 - 6
reg = 6 - 11
*/
unsigned int inst_compile(inst_opcodes op, unsigned char reg)
{
	bool localbits[32] = { 0 };
	unsigned int mask = 1 << (sizeof(unsigned char) * 8 - 1);

	mask >>= 1;
	mask >>= 1;

	for (int i = 0; i < 6; i++) {
		if ((op & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	mask = 1 << (sizeof(unsigned char) * 8 - 1);

	mask >>= 1;
	mask >>= 1;
	mask >>= 1;

	for (int i = 6; i < 11; i++) {
		if ((reg & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	return  getIntFromBits(localbits, 32);
}

/*
op = 0 - 6
reg = 6 - 11
value = 16  - 32
*/
unsigned int inst_compile(inst_opcodes op, unsigned char reg, unsigned short value)
{
	bool localbits[32] = { 0 };
	unsigned int mask = 1 << (sizeof(unsigned char) * 8 - 1);

	mask >>= 1;
	mask >>= 1;

	for (int i = 0; i < 6; i++) {
		if ((op & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	mask = 1 << (sizeof(unsigned char) * 8 - 1);

	mask >>= 1;
	mask >>= 1;
	mask >>= 1;

	for (int i = 6; i < 11; i++) {
		if ((reg & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	mask = 1 << (sizeof(unsigned short) * 8 - 1);

	for (int i = 16; i < 32; i++) {
		if ((value & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	return  getIntFromBits(localbits, 32);
}

/*
op = 0 - 6
reg1 = 6 - 11
reg2 = 11  - 16
*/
unsigned int inst_compile(inst_opcodes op, unsigned char reg1, unsigned char reg2)
{
	bool localbits[32] = { 0 };
	unsigned int mask = 1 << (sizeof(unsigned char) * 8 - 1);

	mask >>= 1;
	mask >>= 1;

	for (int i = 0; i < 6; i++) {
		if ((op & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	mask = 1 << (sizeof(unsigned char) * 8 - 1);

	mask >>= 1;
	mask >>= 1;
	mask >>= 1;

	for (int i = 6; i < 11; i++) {
		if ((reg1 & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	mask = 1 << (sizeof(unsigned char) * 8 - 1);

	mask >>= 1;
	mask >>= 1;
	mask >>= 1;

	for (int i = 11; i < 16; i++) {
		if ((reg2 & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	return  getIntFromBits(localbits, 32);
}

/*
op = 0 - 6
reg1 = 6 - 11
reg2 = 11  - 16
reg3 = 16  - 21
*/
unsigned int inst_compile(inst_opcodes op, unsigned char reg1, unsigned char reg2, unsigned char reg3)
{
	bool localbits[32] = { 0 };
	unsigned int mask = 1 << (sizeof(unsigned char) * 8 - 1);

	mask >>= 1;
	mask >>= 1;

	for (int i = 0; i < 6; i++) {
		if ((op & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	mask = 1 << (sizeof(unsigned char) * 8 - 1);

	mask >>= 1;
	mask >>= 1;
	mask >>= 1;

	for (int i = 6; i < 11; i++) {
		if ((reg1 & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	mask = 1 << (sizeof(unsigned char) * 8 - 1);

	mask >>= 1;
	mask >>= 1;
	mask >>= 1;

	for (int i = 11; i < 16; i++) {
		if ((reg2 & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	mask = 1 << (sizeof(unsigned char) * 8 - 1);

	mask >>= 1;
	mask >>= 1;
	mask >>= 1;

	for (int i = 16; i < 21; i++) {
		if ((reg3 & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	return  getIntFromBits(localbits, 32);
}

/*
op = 0 - 6
reg1 = 6 - 11
reg2 = 11  - 16
value = 16  - 32
*/
unsigned int inst_compile(inst_opcodes op, unsigned char reg1, unsigned char reg2, unsigned short value)
{
	bool localbits[32] = { 0 };
	unsigned int mask = 1 << (sizeof(unsigned char) * 8 - 1);

	mask >>= 1;
	mask >>= 1;

	for (int i = 0; i < 6; i++) {
		if ((op & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	mask = 1 << (sizeof(unsigned char) * 8 - 1);

	mask >>= 1;
	mask >>= 1;
	mask >>= 1;

	for (int i = 6; i < 11; i++) {
		if ((reg1 & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	mask = 1 << (sizeof(unsigned char) * 8 - 1);

	mask >>= 1;
	mask >>= 1;
	mask >>= 1;

	for (int i = 11; i < 16; i++) {
		if ((reg2 & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	mask = 1 << (sizeof(unsigned short) * 8 - 1);


	for (int i = 16; i < 32; i++) {
		if ((value & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	return  getIntFromBits(localbits, 32);
}


/*
op = 0 - 6
value = 6 - 22
cr = 22  - 25
type = 25  - 32
*/
unsigned int inst_compile(inst_opcodes op, unsigned short value, unsigned char cr, unsigned char type)
{
	bool localbits[32] = { 0 };


	//opcode
	unsigned int mask = 1 << (sizeof(unsigned char) * 8 - 1);
	mask >>= 1;
	mask >>= 1;
	for (int i = 0; i < 6; i++) {
		if ((op & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	mask = 1 << (sizeof(unsigned short) * 8 - 1);

	for (int i = 6; i < 22; i++) {
		if ((value & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	//cr
	mask = 1 << (sizeof(unsigned char) * 8 - 1);
	mask >>= 1;
	mask >>= 1;
	mask >>= 1;
	mask >>= 1;
	mask >>= 1;
	for (int i = 22; i < 25; i++) {
		if ((cr & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	//type
	mask = 1 << (sizeof(unsigned char) * 8 - 1);
	mask >>= 1;
	for (int i = 25; i < 32; i++) {
		if ((type & mask) == 0)
			localbits[i] = 0;
		else
			localbits[i] = 1;

		mask >>= 1;
	}

	return  getIntFromBits(localbits, 32);
}

std::vector<unsigned int> Compile(std::vector< InstructionStruture>  instStack)
{

	std::vector<unsigned int> rawOpcodes;
	for (size_t i = 0; i < instStack.size(); i++)
	{
		bool branch_found = false;
		bool inst_found = false;

		int dictionaryId = 0;

		for (int e = 0; e < 49; e++)
		{
			if (inst_dictionary[e].inst == instStack[i].instruction)
			{
				inst_found = true;
				dictionaryId = e;
				break;
			}
		}

		for (int e = 0; e < 12; e++)
		{
			if (inst_branch_dictionary[e].inst == instStack[i].instruction) {
				branch_found = true;
				dictionaryId = e;
				break;
			}
		}

		if (branch_found)
		{
			if (instStack[i].operands.size() == 0 && instStack[i].values.size() == 1)
			{
				bool isHex = replaceText(instStack[i].values[0], "0x", "");

				unsigned int compiled_inst = inst_compile(inst_cbranch, isHex ? (unsigned short)std::stol(instStack[i].values[0], nullptr, 16) : (unsigned short)atoi(instStack[i].values[0].c_str()), 0, inst_branch_dictionary[dictionaryId].opcd);

				rawOpcodes.push_back(compiled_inst);

			}
			else if (instStack[i].operands.size() == 1 && instStack[i].values.size() == 1)
			{
				if (instStack[i].operands[0].find("%cr") != -1)
					removeToken(instStack[i].operands[0], '%', 'c', 'r');
				else
					removeToken(instStack[i].operands[0], '%', 'r');

				bool isHex = replaceText(instStack[i].values[0], "0x", "");

				unsigned int compiled_inst = inst_compile(inst_cbranch, isHex ? (unsigned short)std::stol(instStack[i].values[0], nullptr, 16) : (unsigned short)atoi(instStack[i].values[0].c_str()), (unsigned char)atoi(instStack[i].operands[0].c_str()),  (unsigned char)inst_branch_dictionary[dictionaryId].opcd);

				rawOpcodes.push_back(compiled_inst);
			}
			else
				printf("instruction not implemented yet [%s]\n", instStack[i].textInstruction.c_str());
		}
		else if (inst_found)
		{
			if (instStack[i].operands.size() == 0 && instStack[i].values.size() == 0)
			{
				unsigned int compiled_inst = inst_compile(inst_dictionary[dictionaryId].opcd);

				rawOpcodes.push_back(compiled_inst);

			}
			else if (instStack[i].operands.size() == 0 && instStack[i].values.size() == 1)
			{
				bool isHex = replaceText(instStack[i].values[0], "0x", "");

				unsigned int compiled_inst = inst_compile(inst_dictionary[dictionaryId].opcd, isHex ? (unsigned short)std::stol(instStack[i].values[0], nullptr, 16) : (unsigned short)atoi(instStack[i].values[0].c_str()));

				rawOpcodes.push_back(compiled_inst);

			}
			else if (instStack[i].operands.size() == 1 && instStack[i].values.size() == 0)
			{
				if (instStack[i].operands[0].find("%cr") != -1)
					removeToken(instStack[i].operands[0], '%', 'c', 'r');
				else
					removeToken(instStack[i].operands[0], '%', 'r');

				unsigned int compiled_inst = inst_compile(inst_dictionary[dictionaryId].opcd, (unsigned char)atoi(instStack[i].operands[0].c_str()));

				rawOpcodes.push_back(compiled_inst);

			}
			else if (instStack[i].operands.size() == 1 && instStack[i].values.size() == 1)
			{
				if (instStack[i].operands[0].find("%cr") != -1)
					removeToken(instStack[i].operands[0], '%', 'c', 'r');
				else
					removeToken(instStack[i].operands[0], '%', 'r');

				bool isHex = replaceText(instStack[i].values[0], "0x", "");

				unsigned int compiled_inst = inst_compile(inst_dictionary[dictionaryId].opcd, atoi(instStack[i].operands[0].c_str()), isHex ? (unsigned short)std::stol(instStack[i].values[0], nullptr, 16) : (unsigned short)atoi(instStack[i].values[0].c_str()));

				rawOpcodes.push_back(compiled_inst);
			}
			else if (instStack[i].operands.size() == 2 && instStack[i].values.size() == 1)
			{
				if (instStack[i].operands[0].find("%cr") != -1)
					removeToken(instStack[i].operands[0], '%', 'c', 'r');
				else
					removeToken(instStack[i].operands[0], '%', 'r');

				removeToken(instStack[i].operands[1], '%', 'r');

				bool isHex = replaceText(instStack[i].values[0], "0x", "");

				unsigned int compiled_inst = inst_compile(inst_dictionary[dictionaryId].opcd, atoi(instStack[i].operands[0].c_str()), atoi(instStack[i].operands[1].c_str()), isHex ? (unsigned short)std::stol(instStack[i].values[0], nullptr, 16) : (unsigned short)atoi(instStack[i].values[0].c_str()));

				rawOpcodes.push_back(compiled_inst);
			}
			else if (instStack[i].operands.size() == 2 && instStack[i].values.size() == 0)
			{
				if (instStack[i].operands[0].find("%cr") != -1)
					removeToken(instStack[i].operands[0], '%', 'c', 'r');
				else
					removeToken(instStack[i].operands[0], '%', 'r');

				removeToken(instStack[i].operands[1], '%', 'r');

				unsigned int compiled_inst = inst_compile(inst_dictionary[dictionaryId].opcd, atoi(instStack[i].operands[0].c_str()), (unsigned char)atoi(instStack[i].operands[1].c_str()));

				rawOpcodes.push_back(compiled_inst);
			}
			else if (instStack[i].operands.size() == 3 && instStack[i].values.size() == 0)
			{
				if (instStack[i].operands[0].find("%cr") != -1)
					removeToken(instStack[i].operands[0], '%', 'c', 'r');
				else
					removeToken(instStack[i].operands[0], '%', 'r');

				removeToken(instStack[i].operands[1], '%', 'r');
				removeToken(instStack[i].operands[2], '%', 'r');

				unsigned int compiled_inst = inst_compile(inst_dictionary[dictionaryId].opcd, (unsigned char)atoi(instStack[i].operands[0].c_str()), (unsigned char)atoi(instStack[i].operands[1].c_str()), (unsigned char)atoi(instStack[i].operands[2].c_str()));

				rawOpcodes.push_back(compiled_inst);
			}
			else
				printf("instruction not implemented yet [%s]\n", instStack[i].textInstruction.c_str());
		}
		else
		{
			printf("unsupported instruction found File Line: %s opcode: %s numof Operands: %i numof values: %i\n", instStack[i].textInstruction.c_str(), instStack[i].instruction.c_str(), (unsigned int)instStack[i].operands.size(), (unsigned int)instStack[i].values.size());
		}
	}

	return rawOpcodes;
}

