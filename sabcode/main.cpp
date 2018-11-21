#include "main.h"

int main()
{
	InitRam();
	InitStack();
	InitRegisters();

	Instruction* parser = new Instruction();

	std::vector< InstructionStruture> RawinstStack = parseAssemblyFile("script.txt");

	std::vector<parsediInstructionInfo> Processedinsts = checkInstruction(RawinstStack);

	std::vector< InstructionStruture> FinalinstStack;

	for (size_t i = 0; i < Processedinsts.size(); i++)
		FinalinstStack.push_back(Processedinsts[i].Instruction);

	std::vector<unsigned int> rawOpcodes = Compile(FinalinstStack);
	
	for (ip = 0; ip < rawOpcodes.size();)
	{
		if (exec_vm(parser, rawOpcodes[(unsigned int)ip], &ip) == PROGRAM_EXIT)
			break;
	}

	PrintRegister();

	system("pause");
	return 0;
}

