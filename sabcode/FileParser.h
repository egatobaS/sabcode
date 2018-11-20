#pragma once

struct InstructionStruture
{
	std::string textInstruction;
	std::string instruction;
	std::vector<std::string> operands;
	std::vector<std::string> values;
	unsigned int hexInstruction;

};


struct fileHeader
{
	unsigned int Type;
	unsigned char Padding[4];
	unsigned int Magic;
	unsigned int HeaderLength;
	unsigned int Version;

};

bool replaceText(std::string & token, std::string replace, std::string replacement);
std::vector< InstructionStruture> parseAssemblyFile(const char* Path);
void removeToken(std::string& token, char first, char second);
void removeToken(std::string& token, char first, char second, char third);
void splitInstruction(InstructionStruture* instStack, const std::string& str, const std::string& delim);