#pragma once

enum interrupts
{
	PROGRAM_EXIT = 1,
	PROGRAM_RETURN = 2,
	PROGRAM_INST_EXEC = 3,
};

interrupts exec_vm(Instruction* parser, unsigned int instruction, unsigned long long * pos);