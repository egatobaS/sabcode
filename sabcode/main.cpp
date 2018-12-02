#include "main.h"

/*
usage: sabcode.exe -c script.txt -o out.bin -r -d\n
-c: compiles a specified ascii text file containing sabcode and it will be outputed to a out.bin unless specified otherwise\n
-o: outputs the file out to a specified file\n
-r: runs a specified file or the currently compiled data\n
-d: displays the registers when -r is ran\n
-v: displays the sabcode version\n
-e: executes a specified file
*/

int main(int argc, char *argv[])
{
	//RunInfo ParamInfo = { 0 };
	//
	//std::vector<std::string> params;
	//
	//for (int i = 0; i < argc; i++)
	//	params.push_back(std::string(argv[i]));
	//
	//for (size_t i = 0; i < params.size(); i++)
	//{
	//	if (params[i] == "-c" && params.size() >= (i + 2)) {
	//		ParamInfo.InFilePath = params[i + 1];
	//		ParamInfo.InputFileGiven = true;
	//	}
	//	else if (params[i] == "-o" && params.size() >= (i + 2)) {
	//		ParamInfo.OutFilePath = params[i + 1];
	//		ParamInfo.OutputFileGiven = true;
	//	}
	//	else if (params[i] == "-e" && params.size() >= (i + 2)) {
	//		ParamInfo.ExecuteFile = true;
	//		ParamInfo.InFilePath = params[i + 1];
	//	}
	//	else if (params[i] == "-r") {
	//		ParamInfo.RunCode = true;
	//	}
	//	else if (params[i] == "-d") {
	//		ParamInfo.DisplayRegisters = true;
	//	}
	//	else if (params[i] == "-v") {
	//		printf("sabcode version [%i.%i] made by Sabotage\n", MAJOR_SABCODE_VERSION, MINOR_SABCODE_VERSION);
	//	}
	//	else if (params[i] == "-h" || params[i] == "help" || params[i] == "-help") {
	//
	//		printf("usage: sabcode.exe -c script.txt -o out.bin -r -d\n");
	//		printf("-c: compiles a specified ascii text file containing sabcode and it will be outputed to a out.bin unless specified otherwise\n");
	//		printf("-o: outputs the file out to a specified file\n");
	//		printf("-r: runs a specified file or the currently compiled data\n");
	//		printf("-d: displays the registers when -r is ran\n");
	//		printf("-v: displays the sabcode version\n");
	//	}

	//}

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

	//if (ParamInfo.DisplayRegisters)
	PrintRegister();

	system("pause");

	return 0;
}

