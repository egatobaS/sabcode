#pragma once

unsigned int inst_compile(inst_opcodes op, unsigned short value);
unsigned int inst_compile(inst_opcodes op, unsigned char reg);
unsigned int inst_compile(inst_opcodes op, unsigned char reg, unsigned short value);
unsigned int inst_compile(inst_opcodes op, unsigned char reg1, unsigned char reg2);
unsigned int inst_compile(inst_opcodes op, unsigned char reg1, unsigned char reg2, unsigned char reg3);
unsigned int inst_compile(inst_opcodes op, unsigned char reg1, unsigned char reg2, unsigned short value);
unsigned int inst_compile(inst_opcodes op, unsigned short value, unsigned char cr, unsigned char type);

std::vector<unsigned int> Compile(std::vector< InstructionStruture> instStack);
