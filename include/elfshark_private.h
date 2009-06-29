/**
 * The files in this directory and elsewhere which refer to this LICENCE
 * file are part of ElfShark, the library for disassembling/assembling
 * binary code.
 *
 * Copyright (C) 2009 BlackLight and meh. [http://meh.doesntexist.org]
 *
 * ElfShark is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 3 or (at your option) any later 
 * version.
 *
 * ElfShark is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with ElfShark; if not, write to the Free Software Foundation, Inc.,
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

#ifndef __ELFSHARK_PRIVATE_H
#define __ELFSHARK_PRIVATE_H

#define ES_INSTRLEN 24

#define ES_EAX  0x00
#define ES_ECX  0x01
#define ES_EDX  0x02
#define ES_EBX  0x03
#define ES_ESP  0x04
#define ES_EBP  0x05
#define ES_ESI  0x06
#define ES_EDI  0x07

#define ES_AX   0x00
#define ES_CX   0x01
#define ES_DX   0x02
#define ES_BX   0x03
#define ES_SP   0x04
#define ES_BP   0x05
#define ES_SI   0x06
#define ES_DI   0x07

#define ES_AL   0x00
#define ES_CL   0x01
#define ES_DL   0x02
#define ES_BL   0x03
#define ES_AH   0x04
#define ES_CH   0x05
#define ES_DH   0x06
#define ES_BH   0x07

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void es_get_srcreg   (u8 code, char srcreg[], u8 len, u8 opts);
void es_get_srcreg8  (u8 code, char srcreg[], u8 len, u8 opts);
void es_get_srcreg16 (u8 code, char srcreg[], u8 len, u8 opts);

void es_get_dstreg   (u8 code, char dstreg[], u8 len, u8 opts);
void es_get_dstreg8  (u8 code, char dstreg[], u8 len, u8 opts);
void es_get_dstreg16 (u8 code, char dstreg[], u8 len, u8 opts);

void es_unknown (u8 code[], u8 len, char buf[], u8 buflen, u8 opts);
void es_single_op (u8 code, char buf[], u8 buflen, u8 opts);
void es_op_incdec (u8 code[], u8 len, char buf[], u8 buflen, u8 opts);

int es_interrupt (u8 code[], u8 len, char buf[], u8 buflen, u8 opts);
int es_op_reg32 (char *op, u8 code[], u8 len, char buf[], u8 buflen, u8 opts);
int es_op_scal32 (char *op, u8 code[], u8 len, char buf[], u8 buflen, u8 opts);
int es_op_reg32_inv (char* op, u8 code[], u8 len, char buf[], u8 buflen, u8 opts);
int es_op_scal81 (u8 code[], u8 len, char buf[], u8 buflen, u8 opts);
int es_op_scal83 (u8 code[], u8 len, char buf[], u8 buflen, u8 opts);
int es_op_jmp (char* op, u8 code[], u8 len, char buf[], u8 buflen, u32 addr, u8 opts);
int es_op_jmp_ff (char *op, u8 code[], u8 len, char buf[], u8 buflen, u8 opts);
int es_op_pushpop (char* op, u8 code[], u8 len, char buf[], u8 buflen, u8 opts);
int es_op_scal8 (char *op, u8 code[], u8 len, char buf[], u8 buflen, u8 opts);
int es_op_reg8  (char *op, u8 code[], u8 len, char buf[], u8 buflen, u8 opts);
int es_op_lea32 (char *op, u8 code[], u8 len, char buf[], u8 buflen, u8 opts);
int es_op_inout (u8 code[], u8 len, char buf[], u8 buflen, u8 opts);
int es_op_notneg (char *op, u8 code[], u8 len, char buf[], u8 buflen, u8 opts);
int es_op_muldiv (char *op, u8 code[], u8 len, char buf[], u8 buflen, u8 opts);
int es_op_rotsh (char *op, u8 code[], u8 len, char buf[], u8 buflen, u8 opts);

#endif
