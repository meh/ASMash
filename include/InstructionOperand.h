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

#ifndef __ASMASH_INSTRUCTIONOPERAND_H
#define __ASMASH_INSTRUCTIONOPERAND_H

typedef enum {
    AANoneOperand,

    AARegister8Operand,
    AARegister16Operand,
    AARegister32Operand,
    AARegister64Operand,

    AAMemoryFromRegister8Operand,
    AAMemoryFromRegister16Operand,
    AAMemoryFromRegister32Operand,
    AAMemoryFromRegister64Operand,

    AAMemoryOffsetFromRegister8Operand,
    AAMemoryOffsetFromRegister16Operand,
    AAMemoryOffsetFromRegister32Operand,
    AAMemoryOffsetFromRegister64Operand,

    AAMemoryOperand,

    AAScalarOperand
} AAInstructionOperandType;

#define AA_OPERAND_IS_REGISTER(operand) (operand->type == AARegisterOperand)

typedef struct AAInstructionOperand {
    AAInstructionOperandType type;
    unsigned int             value;
} AAInstructionOperand;

AAInstructionOperand* AA_NewInstructionOperand (AAInstructionOperandType type, unsigned int value);

void AA_DestroyInstructionOperand (AAInstructionOperand* operand);

#endif
