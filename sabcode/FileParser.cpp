#include "main.h"

const char* illegal_chars = "!@#$^&*()+=[]\'.{}|\"<>?`~";

void splitInstruction(InstructionStruture* instStack, const std::string& str, const std::string& delim)
{
	size_t prev = 0, pos = 0;

	do
	{
		pos = str.find(delim, prev);
		if (pos == std::string::npos) pos = str.length();
		std::string token = str.substr(prev, pos - prev);
		if (!token.empty()) {
			token.erase(std::remove(token.begin(), token.end(), ' '), token.end());

			if (token.find("%r") != -1)
				instStack->operands.push_back(token);
			else if (token.find("%cr") != -1)
				instStack->operands.push_back(token);
			else
				instStack->values.push_back(token);
		}
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());
}


void removeToken(std::string& token, char first, char second)
{
	token.erase(std::remove(token.begin(), token.end(), first), token.end());
	token.erase(std::remove(token.begin(), token.end(), second), token.end());

}

void removeToken(std::string& token, char first, char second, char third)
{
	token.erase(std::remove(token.begin(), token.end(), first), token.end());
	token.erase(std::remove(token.begin(), token.end(), second), token.end());
	token.erase(std::remove(token.begin(), token.end(), third), token.end());
}


bool replaceText(std::string & token, std::string replace, std::string replacement)
{
	size_t f = token.find(replace);

	if (f != -1)
	{
		token.replace(f, replace.length(), replacement);
		return true;
	}


	return false;
}

int dosLineContainillegalChar(std::string line) {

	int icLenght = strlen(illegal_chars);

	for (int i = 0; i < icLenght; i++) {

		if (line.find(illegal_chars[i]) != -1)
			return illegal_chars[i];
	}
	return 0;
}

std::vector< InstructionStruture>  parseAssemblyFile(const char* Path)
{
	
	int lineNumb = 0;

	std::vector< InstructionStruture>instStack;

	std::ifstream infile(Path);

	std::string line;

	while (std::getline(infile, line))
	{
		lineNumb++;
	
		if (!line.size())
			continue;

		if (line.find("//") != -1)
			continue;
		
		if (char badChar = dosLineContainillegalChar(line)) {
			printf("line %i contained: %c\n", lineNumb, badChar);
			continue;
		}

		InstructionStruture inst_s;

		size_t firstInstruct = line.find(' ');

		inst_s.textInstruction = line;

		if (firstInstruct != -1)
		{
			std::string instruction = line.substr(0, firstInstruct).c_str();

			inst_s.instruction = instruction;

			std::string operands = line.substr(firstInstruct);

			splitInstruction(&inst_s, operands, ",");

			instStack.push_back(inst_s);
		}
		else
		{
			inst_s.instruction = line;
			instStack.push_back(inst_s);
		}
	}
	return instStack;
}