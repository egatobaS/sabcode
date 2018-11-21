#include "main.h"

void pushLr(unsigned long long lr)
{
	callstack.push_back(lr);
}

unsigned long long popLr()
{
	unsigned long long end = 0;

	if (!callstack.empty()) {

		end = callstack.back();

		callstack.pop_back();
	}
	else
		end = -1;

	return end;
}

void exec_ldc(unsigned long long* r, unsigned long long val)
{
	*r = val;
}

void exec_lds(unsigned long long* ra, unsigned long long* rb)
{
	*ra = (*rb << 16);
}

void exec_ldcs(unsigned long long* ra, unsigned long long value)
{
	*ra = (value << 16);
}

void exec_ld(unsigned long long* ra, unsigned long long* rb)
{
	*ra = *rb;
}

void exec_add(unsigned long long* ra, unsigned long long* rb, unsigned long long* rc)
{
	*ra = *rb + *rc;
}

void exec_addc(unsigned long long* ra, unsigned long long* rb, unsigned long long value)
{
	*ra = *rb + value;
}

void exec_div(unsigned long long* ra, unsigned long long* rb, unsigned long long* rc)
{
	*ra = *rb / *rc;
}

void exec_divc(unsigned long long* ra, unsigned long long* rb, unsigned long long value)
{
	*ra = *rb / value;
}

void exec_mul(unsigned long long* ra, unsigned long long* rb, unsigned long long* rc)
{
	*ra = *rb * *rc;
}

void exec_mulc(unsigned long long* ra, unsigned long long* rb, unsigned long long value)
{
	*ra = *rb * value;
}

void exec_sub(unsigned long long* ra, unsigned long long* rb, unsigned long long* rc)
{
	*ra = *rb - *rc;
}

void exec_subc(unsigned long long* ra, unsigned long long* rb, unsigned long long value)
{
	*ra = *rb - value;
}

void exec_or(unsigned long long* ra, unsigned long long* rb, unsigned long long* rc)
{
	*ra = *rb | *rc;
}

void exec_orc(unsigned long long* ra, unsigned long long* rb, unsigned long long value)
{
	*ra = *rb | value;
}

void exec_and(unsigned long long* ra, unsigned long long* rb, unsigned long long* rc)
{
	*ra = *rb & *rc;
}

void exec_andc(unsigned long long* ra, unsigned long long* rb, unsigned long long value)
{
	*ra = *rb & value;
}

void exec_not(unsigned long long* ra, unsigned long long* rb)
{
	*ra = ~*rb;
}

void exec_notc(unsigned long long* ra, unsigned long long value)
{
	*ra = ~(unsigned long long)value;
}

void exec_xor(unsigned long long* ra, unsigned long long* rb, unsigned long long* rc)
{
	*ra = *rb ^ *rc;
}

void exec_xorc(unsigned long long* ra, unsigned long long* rb, unsigned long long value)
{
	*ra = *rb ^ value;
}

void exec_st8c(unsigned long long* ra, unsigned long long* rb, unsigned long long value)
{
	memcpy((void*)(*rb + value), (void*)*ra, 0x8);
}

void exec_st4c(unsigned long long* ra, unsigned long long* rb, unsigned long long value)
{
	memcpy((void*)(*rb + value), (void*)*ra, 0x4);
}

void exec_st2c(unsigned long long* ra, unsigned long long* rb, unsigned long long value)
{
	memcpy((void*)(*rb + value), (void*)*ra, 0x2);
}

void exec_st1c(unsigned long long* ra, unsigned long long* rb, unsigned long long value)
{
	memcpy((void*)(*rb + value), (void*)*ra, 0x1);
}

void exec_st8(unsigned long long* ra, unsigned long long* rb, unsigned long long* rc)
{
	memcpy((void*)(*rb + *rc), (void*)*ra, 0x8);
}

void exec_st4(unsigned long long* ra, unsigned long long* rb, unsigned long long* rc)
{
	memcpy((void*)(*rb + *rc), (void*)*ra, 0x4);
}

void exec_st2(unsigned long long* ra, unsigned long long* rb, unsigned long long* rc)
{
	memcpy((void*)(*rb + *rc), (void*)*ra, 0x2);
}

void exec_st1(unsigned long long* ra, unsigned long long* rb, unsigned long long* rc)
{
	memcpy((void*)(*rb + *rc), (void*)*ra, 0x1);
}

void exec_rd8c(unsigned long long* ra, unsigned long long* rb, unsigned long long value)
{
	memcpy((void*)ra, (void*)(*rb + value), 0x8);
}

void exec_rd4c(unsigned long long* ra, unsigned long long* rb, unsigned long long value)
{
	memcpy((void*)ra, (void*)(*rb + value), 0x4);
}

void exec_rd2c(unsigned long long* ra, unsigned long long* rb, unsigned long long value)
{
	memcpy((void*)ra, (void*)(*rb + value), 0x2);

}

void exec_rd1c(unsigned long long* ra, unsigned long long* rb, unsigned long long value)
{
	memcpy((void*)ra, (void*)(*rb + value), 0x1);
}

void exec_rd8(unsigned long long* ra, unsigned long long* rb, unsigned long long* rc)
{
	memcpy((void*)ra, (void*)(*rb + *rc), 0x8);

}

void exec_rd4(unsigned long long* ra, unsigned long long* rb, unsigned long long* rc)
{
	memcpy((void*)ra, (void*)(*rb + *rc), 0x4);
}

void exec_rd2(unsigned long long* ra, unsigned long long* rb, unsigned long long* rc)
{
	memcpy((void*)ra, (void*)(*rb + *rc), 0x2);
}

void exec_rd1(unsigned long long* ra, unsigned long long* rb, unsigned long long* rc)
{
	memcpy((void*)ra, (void*)(*rb + *rc), 0x1);
}

void exec_ccmpc(cr* cr, signed long long* ra, signed short value)
{
	cr->cReg = 0;

	if (*ra == value)
	{
		cr->states.ET = 1;
		return;
	}

	if (*ra > value)
	{
		cr->states.GT = 1;
		return;
	}

	if (*ra < value)
	{
		cr->states.LT = 1;
		return;
	}
}

void exec_ccmp(cr* cr, signed long long* ra, signed long long* rb)
{
	cr->cReg = 0;

	if (*ra == *rb)
	{
		cr->states.ET = 1;
		return;
	}

	if (*ra > *rb)
	{
		cr->states.GT = 1;
		return;
	}

	if (*ra < *rb)
	{
		cr->states.LT = 1;
		return;
	}
}

void exec_cmpc(signed long long* ra, signed short value)
{
	crRegs[0].cReg = 0;

	if (*ra == value)
	{
		crRegs[0].states.ET = 1;
		return;
	}

	if (*ra > value)
	{
		crRegs[0].states.GT = 1;
		return;
	}

	if (*ra < value)
	{
		crRegs[0].states.LT = 1;
		return;
	}
}

void exec_cmp(signed long long* ra, signed long long* rb)
{
	crRegs[0].cReg = 0;

	if (*ra == *rb)
	{
		crRegs[0].states.ET = 1;
		return;
	}

	if (*ra > *rb)
	{
		crRegs[0].states.GT = 1;
		return;
	}

	if (*ra < *rb)
	{
		crRegs[0].states.LT = 1;
		return;
	}
}

void exec_beq(unsigned long long value, unsigned long long* pos)
{
	if (crRegs[0].states.ET == 1)
		*pos = *pos + (value / 0x4);
	else
		*pos = *pos + 1;
}

void exec_bne(unsigned long long value, unsigned long long* pos)
{
	if (crRegs[0].states.ET == 0)
		*pos = *pos + (value / 0x4);
	else
		*pos = *pos + 1;
}

void exec_ble(unsigned long long value, unsigned long long* pos)
{
	if (crRegs[0].states.LT == 1 || crRegs[0].states.ET == 1)
		*pos = *pos + (value / 0x4);
	else
		*pos = *pos + 1;
}

void exec_bge(unsigned long long value, unsigned long long* pos)
{
	if (crRegs[0].states.GT == 1 || crRegs[0].states.ET == 1)
		*pos = *pos + (value / 0x4);
	else
		*pos = *pos + 1;
}

void exec_blt(unsigned long long value, unsigned long long* pos)
{
	if (crRegs[0].states.LT == 1)
		*pos = *pos + (value / 0x4);
	else
		*pos = *pos + 1;
}

void exec_bgt(unsigned long long value, unsigned long long* pos)
{
	if (crRegs[0].states.GT == 1)
		*pos = *pos + (value / 0x4);
	else
		*pos = *pos + 1;
}

void exec_cbeq(cr* crReg, unsigned long long value, unsigned long long* pos)
{
	if (crReg->states.ET == 1)
		*pos = *pos + (value / 0x4);
	else
		*pos = *pos + 1;
}

void exec_cbne(cr* crReg, unsigned long long value, unsigned long long* pos)
{
	if (crReg->states.ET == 0)
		*pos = *pos + (value / 0x4);
	else
		*pos = *pos + 1;
}

void exec_cble(cr* crReg, unsigned long long value, unsigned long long* pos)
{
	if (crReg->states.LT == 1 || crReg->states.ET == 1)
		*pos = *pos + (value / 0x4);
	else
		*pos = *pos + 1;
}

void exec_cbge(cr* crReg, unsigned long long value, unsigned long long* pos)
{
	if (crReg->states.GT == 1 || crReg->states.ET == 1)
		*pos = *pos + (value / 0x4);
	else
		*pos = *pos + 1;
}

void exec_cblt(cr* crReg, unsigned long long value, unsigned long long* pos)
{
	if (crReg->states.LT == 1)
		*pos = *pos + (value / 0x4);
	else
		*pos = *pos + 1;
}

void exec_cbgt(cr* crReg, unsigned long long value, unsigned long long* pos)
{
	if (crReg->states.GT == 1)
		*pos = *pos + (value / 0x4);
	else
		*pos = *pos + 1;
}

void exec_syscall(unsigned long long* ra)
{
	int calladdr = (int)*ra;
	unsigned long long(*function)(...) = (unsigned long long(*)(...))calladdr;
	r[3] = function(r[3], r[4], r[5], r[6], r[7], r[8], r[9], r[10]);
}

void exec_slwc(unsigned long long* ra, unsigned long long* rb, unsigned long long value)
{
	*ra = (*rb << value);
}

void exec_srwc(unsigned long long* ra, unsigned long long* rb, unsigned long long value)
{
	*ra = (*rb >> value);
}

interrupts exec_vm(Instruction* parser, unsigned int instruction, unsigned long long * pos)
{
	interrupts intp = PROGRAM_INST_EXEC;

	parser->parseInstruction(instruction);

	inst_opcodes codes = parser->getInstructionType();

	switch (codes)
	{
	case inst_lds:
		exec_lds(&r[parser->getRegister611()], &r[parser->getRegister1116()]);
		*pos = *pos + 1;
		break;
	case inst_ldcs:
		exec_ldcs(&r[parser->getRegister611()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_ld:
		exec_ld(&r[parser->getRegister611()], &r[parser->getRegister1116()]);
		*pos = *pos + 1;
		break;
	case inst_ldc:
		exec_ldc(&r[parser->getRegister611()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_add:
		exec_add(&r[parser->getRegister611()], &r[parser->getRegister1116()], &r[parser->getRegister1621()]);
		*pos = *pos + 1;
		break;
	case inst_addc:
		exec_addc(&r[parser->getRegister611()], &r[parser->getRegister1116()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_div:
		exec_div(&r[parser->getRegister611()], &r[parser->getRegister1116()], &r[parser->getRegister1621()]);
		*pos = *pos + 1;
		break;
	case inst_divc:
		exec_divc(&r[parser->getRegister611()], &r[parser->getRegister1116()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_mul:
		exec_mul(&r[parser->getRegister611()], &r[parser->getRegister1116()], &r[parser->getRegister1621()]);
		*pos = *pos + 1;
		break;
	case inst_mulc:
		exec_mulc(&r[parser->getRegister611()], &r[parser->getRegister1116()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_sub:
		exec_sub(&r[parser->getRegister611()], &r[parser->getRegister1116()], &r[parser->getRegister1621()]);
		*pos = *pos + 1;
		break;
	case inst_subc:
		exec_subc(&r[parser->getRegister611()], &r[parser->getRegister1116()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_or:
		exec_or(&r[parser->getRegister611()], &r[parser->getRegister1116()], &r[parser->getRegister1621()]);
		*pos = *pos + 1;
		break;
	case inst_orc:
		exec_orc(&r[parser->getRegister611()], &r[parser->getRegister1116()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_and:
		exec_and(&r[parser->getRegister611()], &r[parser->getRegister1116()], &r[parser->getRegister1621()]);
		*pos = *pos + 1;
		break;
	case inst_andc:
		exec_andc(&r[parser->getRegister611()], &r[parser->getRegister1116()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_not:
		exec_not(&r[parser->getRegister611()], &r[parser->getRegister1116()]);
		*pos = *pos + 1;
		break;
	case inst_notc:
		exec_notc(&r[parser->getRegister611()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_xor:
		exec_xor(&r[parser->getRegister611()], &r[parser->getRegister1116()], &r[parser->getRegister1621()]);
		*pos = *pos + 1;
		break;
	case inst_xorc:
		exec_xorc(&r[parser->getRegister611()], &r[parser->getRegister1116()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_st8c:
		exec_st8c(&r[parser->getRegister611()], &r[parser->getRegister1116()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_st4c:
		exec_st4c(&r[parser->getRegister611()], &r[parser->getRegister1116()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_st2c:
		exec_st2c(&r[parser->getRegister611()], &r[parser->getRegister1116()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_st1c:
		exec_st1c(&r[parser->getRegister611()], &r[parser->getRegister1116()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_st8:
		exec_st8(&r[parser->getRegister611()], &r[parser->getRegister1116()], &r[parser->getRegister1621()]);
		*pos = *pos + 1;
		break;
	case inst_st4:
		exec_st4(&r[parser->getRegister611()], &r[parser->getRegister1116()], &r[parser->getRegister1621()]);
		*pos = *pos + 1;
		break;
	case inst_st2:
		exec_st2(&r[parser->getRegister611()], &r[parser->getRegister1116()], &r[parser->getRegister1621()]);
		*pos = *pos + 1;
		break;
	case inst_st1:
		exec_st1(&r[parser->getRegister611()], &r[parser->getRegister1116()], &r[parser->getRegister1621()]);
		*pos = *pos + 1;
		break;
	case inst_rd8c:
		exec_rd8c(&r[parser->getRegister611()], &r[parser->getRegister1116()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_rd4c:
		exec_rd4c(&r[parser->getRegister611()], &r[parser->getRegister1116()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_rd2c:
		exec_rd2c(&r[parser->getRegister611()], &r[parser->getRegister1116()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_rd1c:
		exec_rd1c(&r[parser->getRegister611()], &r[parser->getRegister1116()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_rd8:
		exec_rd8(&r[parser->getRegister611()], &r[parser->getRegister1116()], &r[parser->getRegister1621()]);
		*pos = *pos + 1;
		break;
	case inst_rd4:
		exec_rd4(&r[parser->getRegister611()], &r[parser->getRegister1116()], &r[parser->getRegister1621()]);
		*pos = *pos + 1;
		break;
	case inst_rd2:
		exec_rd2(&r[parser->getRegister611()], &r[parser->getRegister1116()], &r[parser->getRegister1621()]);
		*pos = *pos + 1;
		break;
	case inst_rd1:
		exec_rd1(&r[parser->getRegister611()], &r[parser->getRegister1116()], &r[parser->getRegister1621()]);
		*pos = *pos + 1;
		break;
	case inst_nop:
		*pos = *pos + 1;
		break;
	case inst_ret:
	{
		unsigned long long lr = popLr();
		if (lr == -1)
			intp = PROGRAM_EXIT;
		else
			*pos = lr;
		break;
	}
	case inst_jmp:
	{
		signed short signedVal = (signed short)r[parser->getRegister611()];
		*pos = *pos + ((size_t)signedVal / 0x4);
		break;
	}
	case inst_jmpc:
	{
		signed short h = parser->getRegister622();
		*pos = (*pos) + (h / 0x4);

		break;
	}
	case inst_ccmp:
		exec_ccmp(&crRegs[parser->getRegister611()], (signed long long*)&r[parser->getRegister1116()], (signed long long*)&r[parser->getRegister1621()]);
		*pos = *pos + 1;
		break;
	case inst_ccmpc:
		exec_ccmpc(&crRegs[parser->getRegister611()], (signed long long*)&r[parser->getRegister1116()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_cmp:
		exec_cmp((signed long long*)&r[parser->getRegister611()], (signed long long*)&r[parser->getRegister1116()]);
		*pos = *pos + 1;
		break;
	case inst_cmpc:
		exec_cmpc((signed long long*)&r[parser->getRegister611()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_call:
	{
		pushLr(*pos + 1);
		signed short NewPostion = (((signed short)r[parser->getRegister611()]) + ((signed short)*pos * 0x4)) / 0x4;
		*pos = NewPostion;
		break;
	}
	case inst_callc:
	{
		pushLr(*pos + 1);
		signed short NewPostion = (((signed short)parser->getRegister622()) + (((signed short)*pos) * 0x4)) / 0x4;
		*pos = NewPostion;
		break;
	}
	case inst_cbranch:
	{
		inst_branchopcodes branchcodes = (inst_branchopcodes)parser->getRegister2532();
		switch (branchcodes)
		{
		case inst_beq:
			exec_beq(parser->getRegister622(), pos);
			break;
		case inst_bne:
			exec_bne(parser->getRegister622(), pos);
			break;
		case inst_ble:
			exec_ble(parser->getRegister622(), pos);
			break;
		case inst_bge:
			exec_bge(parser->getRegister622(), pos);
			break;
		case inst_bgt:
			exec_bgt(parser->getRegister622(), pos);
			break;
		case inst_blt:
			exec_blt(parser->getRegister622(), pos);
			break;
		case inst_cbeq:
			exec_cbeq(&crRegs[parser->getRegister2225()], parser->getRegister622(), pos);
			break;
		case inst_cbne:
			exec_cbne(&crRegs[parser->getRegister2225()], parser->getRegister622(), pos);
			break;
		case inst_cble:
			exec_cble(&crRegs[parser->getRegister2225()], parser->getRegister622(), pos);
			break;
		case inst_cbge:
			exec_cbge(&crRegs[parser->getRegister2225()], parser->getRegister622(), pos);
			break;
		case inst_cbgt:
			exec_cbgt(&crRegs[parser->getRegister2225()], parser->getRegister622(), pos);
			break;
		case inst_cblt:
			exec_cblt(&crRegs[parser->getRegister2225()], parser->getRegister622(), pos);
			break;
		default:
			printf("unsupported Instruction: %i\n", codes);
			break;
		}
		break;
	}
	case inst_syscall:
		exec_syscall(&r[parser->getRegister611()]);
		*pos = *pos + 1;
		break;
	case inst_slwc:
		exec_slwc(&r[parser->getRegister611()], &r[parser->getRegister1116()], parser->getValue1632());
		*pos = *pos + 1;
		break;
	case inst_srwc:
		exec_srwc(&r[parser->getRegister611()], &r[parser->getRegister1116()], parser->getValue1632());
		*pos = *pos + 1;
		break;

	default:
		printf("unsupported Instruction: %i\n", codes);
		*pos = *pos + 1;
		break;
	}
	return intp;
}
