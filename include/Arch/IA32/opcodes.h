/**
 * The files in this directory and elsewhere which refer to this LICENCE
 * file are part of ASMash, the library for disassembling/assembling
 * binary code.
 *
 * Copyright (C) 2009 BlackLight and meh.
 *
 * ASMash is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 3 or (at your option) any later 
 * version.
 *
 * ASMash is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with ASMash; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 *
 * As a special exception, if other files instantiate templates or use
 * macros or inline functions from these files, or you compile these
 * files and link them with other works to produce a work based on these
 * files, these files do not by themselves cause the resulting work to be
 * covered by the GNU General Public License. However the source code for
 * these files must still be made available in accordance with section (3)
 * of the GNU General Public License.
 *
 * This exception does not invalidate any other reasons why a work based on
 * this file might be covered by the GNU General Public License.
 */

#ifndef __ASMASH_PRIVATE_INSTRUCTION_H
#define __ASMASH_PRIVATE_INSTRUCTION_H

#include "types.h"

typedef enum {
    aaEAX = 0,
    aaECX,
    aaEDX,
    aaEBX,
    aaESP,
    aaEBP,
    aaESI,
    aaEDI
} AAInstructionRegisters32;
    aaAX = 0,
    aaCX,
    aaDX,
    aaBX,
    aaSP,
    aaBP,
    aaSI,
    aaDI
typedef enum {

} AAInstructionRegisters16;

typedef enum {
    aaAL = 0,
    aaCL,
    aaDL,
    aaBL,
    aaAH,
    aaCH,
    aaDH,
    aaBH
} AAInstructionRegisters8;

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void aa_BytecodeGet_SrcReg   (u8 code, char* srcreg, u8 len, AAOptions flags);
void aa_BytecodeGet_SrcReg8  (u8 code, char* srcreg, u8 len, AAOptions flags);
void aa_BytecodeGet_SrcReg16 (u8 code, char* srcreg, u8 len, AAOptions flags);

void aa_BytecodeGet_DstReg    (u8 code, char* dstreg, u8 len, AAOptions flags);
void aa_BytecodeGet_DstReg8   (u8 code, char* dstreg, u8 len, AAOptions flags);
void aa_BytecodeGet_DstrReg16 (u8 code, char* dstreg, u8 len, AAOptions flags);

void aa_Bytecode_Unknown (const u8* code, u32 length, char buf[], u8 buflen, AAOptions flags);
void aa_Bytecode_SingleOp (u8 code, char buf[], u8 buflen, AAOptions flrc/.Bytecode.c.swpgs);
void aa_Bytecode_Op_IncDec (u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);

int aa_Bytecode_Interrupt (u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);
int aa_Bytecode_Op_Reg32 (char *op, u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);
int aa_Bytecode_Op_scal32 (char *op, u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);
int aa_op_reg32_inv (char* op, u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);
int aa_op_scal81 (u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);
int aa_op_scal83 (u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);
int aa_op_jmp (char* op, u8 code[], u8 len, char buf[], u8 buflen, u32 addr, AAOptions flags);
int aa_op_jmp_ff (char *op, u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);
int aa_op_pushpop (char* op, u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);
int aa_op_scal8 (char *op, u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);
int aa_op_reg8  (char *op, u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);
int aa_op_lea32 (char *op, u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);
int aa_op_inout (u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);
int aa_op_notneg (char *op, u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);
int aa_op_muldiv (char *op, u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);
int aa_op_rotsh (char *op, u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);

#endif
