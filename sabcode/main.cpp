#include "main.h"


int main()
{
	InitRam();
	InitStack();
	InitRegisters();

	Instruction* parser = new Instruction();

	std::vector< InstructionStruture> instStack = parseAssemblyFile("script.txt");

	std::vector<unsigned int> rawOpcodes = Compile(instStack);

	for (ip = 0; ip < rawOpcodes.size();)
	{
		if (exec_vm(parser, rawOpcodes[(unsigned int)ip], &ip) == PROGRAM_EXIT)
			break;
	}

	PrintRegister();

	system("pause");
	return 0;
}

