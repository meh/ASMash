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

#include "Arch/IA32/opcodes.h"

const AAOpcodeValue aa_IA32_Opcodes_mov[] = {
    /* movl $scal, %reg */
    { "\xb8", 1, 4, AARegister32Operand, AAScalarOperand }, /* movl $n, %eax */
    { "\xb9", 1, 4, AARegister32Operand, AAScalarOperand }, /* movl $n, %ecx */
    { "\xba", 1, 4, AARegister32Operand, AAScalarOperand }, /* movl $n, %edx */
    { "\xbb", 1, 4, AARegister32Operand, AAScalarOperand }, /* movl $n, %ebx */
    { "\xbc", 1, 4, AARegister32Operand, AAScalarOperand }, /* movl $n, %esp */
    { "\xbd", 1, 4, AARegister32Operand, AAScalarOperand }, /* movl $n, %ebp */
    { "\xbe", 1, 4, AARegister32Operand, AAScalarOperand }, /* movl $n, %esi */
    { "\xbf", 1, 4, AARegister32Operand, AAScalarOperand }, /* movl $n, %edi */

    AA_OPCODE_VALUE_END
};

const AAOpcodeValue aa_IA32_Opcodes_add[] = {
    /* addl (%reg), %reg */
    { "\x01\x00",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %eax, (%eax) */
    { "\x01\x01",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %eax, (%ecx) */
    { "\x01\x02",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %eax, (%edx) */
    { "\x01\x03",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %eax, (%ebx) */
    { "\x01\x04\x24", 3, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %eax, (%esp) */
    { "\x01\x05",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %eax, (%ebp) */
    { "\x01\x06",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %eax, (%esi) */
    { "\x01\x07",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %eax, (%edi) */
    { "\x01\x08",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ecx, (%eax) */
    { "\x01\x09",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ecx, (%ecx) */
    { "\x01\x0a",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ecx, (%edx) */
    { "\x01\x0b",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ecx, (%ebx) */
    { "\x01\x0c\x24", 3, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ecx, (%esp) */
    { "\x01\x0d",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ecx, (%ebp) */
    { "\x01\x0e",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ecx, (%esi) */
    { "\x01\x0f",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ecx, (%edi) */
    { "\x01\x10",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edx, (%eax) */
    { "\x01\x11",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edx, (%ecx) */
    { "\x01\x12",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edx, (%edx) */
    { "\x01\x13",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edx, (%ebx) */
    { "\x01\x14\x24", 3, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edx, (%esp) */
    { "\x01\x15",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edx, (%ebp) */
    { "\x01\x16",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edx, (%esi) */
    { "\x01\x17",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edx, (%edi) */

    AA_OPCODE_VALUE_END
};

const AAOpcode AA_IA32_Opcodes[] = {
    AA_NEW_OPCODE(mov),
    AA_NEW_OPCODE(add),

    AA_OPCODE_END
};

