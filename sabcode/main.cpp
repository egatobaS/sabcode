#include "main.h"

/*
usage: sabcode.exe -c script.txt -o out.bin -r -d
-c: compiles a specified ascii text file containing sabcode and it will be outputed to a out.bin unless specified otherwise
-o: outputs the file out to a specified file
-r: runs a specified file or the currently compiled data 
-d: displays the registers when -r is ran
*/

int main(int argc, char *argv[])
{
	printf("sabcode version [%i.%i] made by Sabotage\n", MAJOR_SABCODE_VERSION, MINOR_SABCODE_VERSION);

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

