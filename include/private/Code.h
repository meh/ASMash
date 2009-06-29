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

#ifndef __ASMASH_PRIVATE_CODE_H
#define __ASMASH_PRIVATE_CODE_H

#include "asmash.h"

#define AA_INSTRLEN 24

#define AA_EAX  0x00
#define AA_ECX  0x01
#define AA_EDX  0x02
#define AA_EBX  0x03
#define AA_ESP  0x04
#define AA_EBP  0x05
#define AA_ESI  0x06
#define AA_EDI  0x07

#define AA_AX   0x00
#define AA_CX   0x01
#define AA_DX   0x02
#define AA_BX   0x03
#define AA_SP   0x04
#define AA_BP   0x05
#define AA_SI   0x06
#define AA_DI   0x07

#define AA_AL   0x00
#define AA_CL   0x01
#define AA_DL   0x02
#define AA_BL   0x03
#define AA_AH   0x04
#define AA_CH   0x05
#define AA_DH   0x06
#define AA_BH   0x07

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void aa_CodeGet_SrcReg   (u8 code, char* srcreg, u8 len, AAOptions flags);
void aa_CodeGet_SrcReg8  (u8 code, char* srcreg, u8 len, AAOptions flags);
void aa_CodeGet_SrcReg16 (u8 code, char* srcreg, u8 len, AAOptions flags);

void aa_CodeGet_DstReg    (u8 code, char* dstreg, u8 len, AAOptions flags);
void aa_CodeGet_DstReg8   (u8 code, char* dstreg, u8 len, AAOptions flags);
void aa_CodeGet_DstrReg16 (u8 code, char* dstreg, u8 len, AAOptions flags);

void aa_Code_Unknown (const unsigned char* code, unsigned int len, char buf[], u8 buflen, AAOptions flags);
void aa_Code_SingleOp (u8 code, char buf[], u8 buflen, AAOptions flags);
void aa_Code_Op_IncDec (u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);

int aa_Code_Interrupt (u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);
int aa_Code_Op_Reg32 (char *op, u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);
int aa_Code_Op_scal32 (char *op, u8 code[], u8 len, char buf[], u8 buflen, AAOptions flags);
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
