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

#ifndef __ASMASH_ARCH_IA32_OPCODES_H
#define __ASMASH_ARCH_IA32_OPCODES_H

#include "types.h"
#include "Arch/Opcode.h"

typedef enum {
    aa_IA32_EAX = 0,
    aa_IA32_ECX,
    aa_IA32_EDX,
    aa_IA32_EBX,
    aa_IA32_ESP,
    aa_IA32_EBP,
    aa_IA32_ESI,
    aa_IA32_EDI
} AA_IA32_InstructionRegisters32;

typedef enum {
    aa_IA32_AX = 0,
    aa_IA32_CX,
    aa_IA32_DX,
    aa_IA32_BX,
    aa_IA32_SP,
    aa_IA32_BP,
    aa_IA32_SI,
    aa_IA32_DI
} AA_IA32_InstructionRegisters16;

typedef enum {
    aa_IA32_AL = 0,
    aa_IA32_CL,
    aa_IA32_DL,
    aa_IA32_BL,
    aa_IA32_AH,
    aa_IA32_CH,
    aa_IA32_DH,
    aa_IA32_BH
} AA_IA32_InstructionRegisters8;

#endif
