#pragma once
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>

#include "Arithmetic.h"
#include "Utils.h"
#include "Instructions.h"
#include "FileParser.h"
#include "SystemInit.h"
#include "Compiler.h"
#include "vm.h"

#define MAJOR_SABCODE_VERSION 0
#define MINOR_SABCODE_VERSION 1

struct RunInfo
{
	bool InputFileGiven;
	bool OutputFileGiven;
	std::string OutFilePath;
	std::string InFilePath;
	bool RunCode;
	bool DisplayRegisters;
	bool ExecuteFile;
	std::string InExecutePath;
};


int main(int argc, char *argv[]);