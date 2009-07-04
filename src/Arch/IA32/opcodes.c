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
    /* addb %reg8, (%reg32) */
    { "\x00\x00",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %al, (%eax) */
    { "\x00\x01",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %al, (%ecx) */
    { "\x00\x02",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %al, (%edx) */
    { "\x00\x03",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %al, (%ebx) */
    { "\x00\x04\x24", 3, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %al, (%esp) */
    { "\x00\x05",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %al, (%ebp) */
    { "\x00\x06",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %al, (%esi) */
    { "\x00\x07",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %al, (%edi) */
    { "\x00\x08",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %cl, (%eax) */
    { "\x00\x09",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %cl, (%ecx) */
    { "\x00\x0a",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %cl, (%edx) */
    { "\x00\x0b",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %cl, (%ebx) */
    { "\x00\x0c\x24", 3, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %cl, (%esp) */
    { "\x00\x0d",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %cl, (%ebp) */
    { "\x00\x0e",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %cl, (%esi) */
    { "\x00\x0f",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %cl, (%edi) */
    { "\x00\x10",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dl, (%eax) */
    { "\x00\x11",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dl, (%ecx) */
    { "\x00\x12",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dl, (%edx) */
    { "\x00\x13",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dl, (%ebx) */
    { "\x00\x14\x24", 3, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dl, (%esp) */
    { "\x00\x15",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dl, (%ebp) */
    { "\x00\x16",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dl, (%esi) */
    { "\x00\x17",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dl, (%edi) */
    { "\x00\x18",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bl, (%eax) */
    { "\x00\x19",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bl, (%ecx) */
    { "\x00\x1a",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bl, (%edx) */
    { "\x00\x1b",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bl, (%ebx) */
    { "\x00\x1c\x24", 3, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bl, (%esp) */
    { "\x00\x1d",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bl, (%ebp) */
    { "\x00\x1e",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bl, (%esi) */
    { "\x00\x1f",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bl, (%edi) */
    { "\x00\x20",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ah, (%eax) */
    { "\x00\x21",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ah, (%ecx) */
    { "\x00\x22",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ah, (%edx) */
    { "\x00\x23",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ah, (%ebx) */
    { "\x00\x24\x24", 3, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ah, (%esp) */
    { "\x00\x25",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ah, (%ebp) */
    { "\x00\x26",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ah, (%esi) */
    { "\x00\x27",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ah, (%edi) */
    { "\x00\x28",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ch, (%eax) */
    { "\x00\x29",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ch, (%ecx) */
    { "\x00\x2a",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ch, (%edx) */
    { "\x00\x2b",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ch, (%ebx) */
    { "\x00\x2c\x24", 3, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ch, (%esp) */
    { "\x00\x2d",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ch, (%ebp) */
    { "\x00\x2e",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ch, (%esi) */
    { "\x00\x2f",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ch, (%edi) */
    { "\x00\x30",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dh, (%eax) */
    { "\x00\x31",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dh, (%ecx) */
    { "\x00\x32",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dh, (%edx) */
    { "\x00\x33",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dh, (%ebx) */
    { "\x00\x34\x24", 3, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dh, (%esp) */
    { "\x00\x35",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dh, (%ebp) */
    { "\x00\x36",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dh, (%esi) */
    { "\x00\x37",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dh, (%edi) */
    { "\x00\x38",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bh, (%eax) */
    { "\x00\x39",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bh, (%ecx) */
    { "\x00\x3a",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bh, (%edx) */
    { "\x00\x3b",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bh, (%ebx) */
    { "\x00\x3c\x24", 3, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bh, (%esp) */
    { "\x00\x3d",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bh, (%ebp) */
    { "\x00\x3e",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bh, (%esi) */
    { "\x00\x3f",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bh, (%edi) */

    /* addb %reg8, n(%reg32) */
    { "\x00\x40",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %al, (%eax) */
    { "\x00\x41",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %al, (%ecx) */
    { "\x00\x42",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %al, (%edx) */
    { "\x00\x43",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %al, (%ebx) */
    { "\x00\x44\x24", 3, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %al, (%esp) */
    { "\x00\x45",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %al, (%ebp) */
    { "\x00\x46",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %al, (%esi) */
    { "\x00\x47",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %al, (%edi) */
    { "\x00\x48",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %cl, (%eax) */
    { "\x00\x49",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %cl, (%ecx) */
    { "\x00\x4a",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %cl, (%edx) */
    { "\x00\x4b",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %cl, (%ebx) */
    { "\x00\x4c\x24", 3, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %cl, (%esp) */
    { "\x00\x4d",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %cl, (%ebp) */
    { "\x00\x4e",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %cl, (%esi) */
    { "\x00\x4f",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %cl, (%edi) */
    { "\x00\x50",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dl, (%eax) */
    { "\x00\x51",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dl, (%ecx) */
    { "\x00\x52",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dl, (%edx) */
    { "\x00\x53",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dl, (%ebx) */
    { "\x00\x54\x24", 3, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dl, (%esp) */
    { "\x00\x55",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dl, (%ebp) */
    { "\x00\x56",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dl, (%esi) */
    { "\x00\x57",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dl, (%edi) */
    { "\x00\x58",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bl, (%eax) */
    { "\x00\x59",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bl, (%ecx) */
    { "\x00\x5a",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bl, (%edx) */
    { "\x00\x5b",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bl, (%ebx) */
    { "\x00\x5c\x24", 3, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bl, (%esp) */
    { "\x00\x5d",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bl, (%ebp) */
    { "\x00\x5e",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bl, (%esi) */
    { "\x00\x5f",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bl, (%edi) */
    { "\x00\x60",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ah, (%eax) */
    { "\x00\x61",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ah, (%ecx) */
    { "\x00\x62",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ah, (%edx) */
    { "\x00\x63",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ah, (%ebx) */
    { "\x00\x64\x24", 3, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ah, (%esp) */
    { "\x00\x65",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ah, (%ebp) */
    { "\x00\x66",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ah, (%esi) */
    { "\x00\x67",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ah, (%edi) */
    { "\x00\x68",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ch, (%eax) */
    { "\x00\x69",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ch, (%ecx) */
    { "\x00\x6a",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ch, (%edx) */
    { "\x00\x6b",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ch, (%ebx) */
    { "\x00\x6c\x24", 3, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ch, (%esp) */
    { "\x00\x6d",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ch, (%ebp) */
    { "\x00\x6e",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ch, (%esi) */
    { "\x00\x6f",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ch, (%edi) */
    { "\x00\x70",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dh, (%eax) */
    { "\x00\x71",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dh, (%ecx) */
    { "\x00\x72",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dh, (%edx) */
    { "\x00\x73",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dh, (%ebx) */
    { "\x00\x74\x24", 3, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dh, (%esp) */
    { "\x00\x75",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dh, (%ebp) */
    { "\x00\x76",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dh, (%esi) */
    { "\x00\x77",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dh, (%edi) */
    { "\x00\x78",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bh, (%eax) */
    { "\x00\x79",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bh, (%ecx) */
    { "\x00\x7a",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bh, (%edx) */
    { "\x00\x7b",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bh, (%ebx) */
    { "\x00\x7c\x24", 3, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bh, (%esp) */
    { "\x00\x7d",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bh, (%ebp) */
    { "\x00\x7e",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bh, (%esi) */
    { "\x00\x7f",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bh, (%edi) */

    /* addl %reg32, (%reg32) */
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
    { "\x01\x18",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebx, (%eax) */
    { "\x01\x19",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebx, (%ecx) */
    { "\x01\x1a",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebx, (%edx) */
    { "\x01\x1b",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebx, (%ebx) */
    { "\x01\x1c\x24", 3, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebx, (%esp) */
    { "\x01\x1d",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebx, (%ebp) */
    { "\x01\x1e",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebx, (%esi) */
    { "\x01\x1f",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebx, (%edi) */
    { "\x01\x20",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esp, (%eax) */
    { "\x01\x21",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esp, (%ecx) */
    { "\x01\x22",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esp, (%edx) */
    { "\x01\x23",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esp, (%ebx) */
    { "\x01\x24\x24", 3, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esp, (%esp) */
    { "\x01\x25",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esp, (%ebp) */
    { "\x01\x26",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esp, (%esi) */
    { "\x01\x27",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esp, (%edi) */
    { "\x01\x28",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebp, (%eax) */
    { "\x01\x29",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebp, (%ecx) */
    { "\x01\x2a",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebp, (%edx) */
    { "\x01\x2b",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebp, (%ebx) */
    { "\x01\x2c\x24", 3, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebp, (%esp) */
    { "\x01\x2d",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebp, (%ebp) */
    { "\x01\x2e",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebp, (%esi) */
    { "\x01\x2f",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebp, (%edi) */
    { "\x01\x30",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esi, (%eax) */
    { "\x01\x31",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esi, (%ecx) */
    { "\x01\x32",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esi, (%edx) */
    { "\x01\x33",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esi, (%ebx) */
    { "\x01\x34\x24", 3, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esi, (%esp) */
    { "\x01\x35",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esi, (%ebp) */
    { "\x01\x36",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esi, (%esi) */
    { "\x01\x37",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esi, (%edi) */
    { "\x01\x38",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edi, (%eax) */
    { "\x01\x39",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edi, (%ecx) */
    { "\x01\x3a",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edi, (%edx) */
    { "\x01\x3b",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edi, (%ebx) */
    { "\x01\x3c\x24", 3, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edi, (%esp) */
    { "\x01\x3d",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edi, (%ebp) */
    { "\x01\x3e",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edi, (%esi) */
    { "\x01\x3f",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edi, (%edi) */

    /* addl %reg32, n(%reg32) */
    { "\x01\x40",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %eax, (%eax) */
    { "\x01\x41",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %eax, (%ecx) */
    { "\x01\x42",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %eax, (%edx) */
    { "\x01\x43",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %eax, (%ebx) */
    { "\x01\x44\x24", 3, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %eax, (%esp) */
    { "\x01\x45",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %eax, (%ebp) */
    { "\x01\x46",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %eax, (%esi) */
    { "\x01\x47",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %eax, (%edi) */
    { "\x01\x48",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ecx, (%eax) */
    { "\x01\x49",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ecx, (%ecx) */
    { "\x01\x4a",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ecx, (%edx) */
    { "\x01\x4b",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ecx, (%ebx) */
    { "\x01\x4c\x24", 3, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ecx, (%esp) */
    { "\x01\x4d",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ecx, (%ebp) */
    { "\x01\x4e",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ecx, (%esi) */
    { "\x01\x4f",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ecx, (%edi) */
    { "\x01\x50",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edx, (%eax) */
    { "\x01\x51",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edx, (%ecx) */
    { "\x01\x52",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edx, (%edx) */
    { "\x01\x53",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edx, (%ebx) */
    { "\x01\x54\x24", 3, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edx, (%esp) */
    { "\x01\x55",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edx, (%ebp) */
    { "\x01\x56",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edx, (%esi) */
    { "\x01\x57",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edx, (%edi) */
    { "\x01\x58",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebx, (%eax) */
    { "\x01\x59",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebx, (%ecx) */
    { "\x01\x5a",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebx, (%edx) */
    { "\x01\x5b",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebx, (%ebx) */
    { "\x01\x5c\x24", 3, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebx, (%esp) */
    { "\x01\x5d",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebx, (%ebp) */
    { "\x01\x5e",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebx, (%esi) */
    { "\x01\x5f",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebx, (%edi) */
    { "\x01\x60",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esp, (%eax) */
    { "\x01\x61",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esp, (%ecx) */
    { "\x01\x62",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esp, (%edx) */
    { "\x01\x63",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esp, (%ebx) */
    { "\x01\x64\x24", 3, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esp, (%esp) */
    { "\x01\x65",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esp, (%ebp) */
    { "\x01\x66",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esp, (%esi) */
    { "\x01\x67",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esp, (%edi) */
    { "\x01\x68",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebp, (%eax) */
    { "\x01\x69",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebp, (%ecx) */
    { "\x01\x6a",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebp, (%edx) */
    { "\x01\x6b",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebp, (%ebx) */
    { "\x01\x6c\x24", 3, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebp, (%esp) */
    { "\x01\x6d",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebp, (%ebp) */
    { "\x01\x6e",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebp, (%esi) */
    { "\x01\x6f",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebp, (%edi) */
    { "\x01\x70",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esi, (%eax) */
    { "\x01\x71",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esi, (%ecx) */
    { "\x01\x72",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esi, (%edx) */
    { "\x01\x73",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esi, (%ebx) */
    { "\x01\x74\x24", 3, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esi, (%esp) */
    { "\x01\x75",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esi, (%ebp) */
    { "\x01\x76",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esi, (%esi) */
    { "\x01\x77",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esi, (%edi) */
    { "\x01\x78",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edi, (%eax) */
    { "\x01\x79",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edi, (%ecx) */
    { "\x01\x7a",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edi, (%edx) */
    { "\x01\x7b",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edi, (%ebx) */
    { "\x01\x7c\x24", 3, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edi, (%esp) */
    { "\x01\x7d",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edi, (%ebp) */
    { "\x01\x7e",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edi, (%esi) */
    { "\x01\x7f",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edi, (%edi) */

    /* addl %reg32, %reg32 */
    { "\x01\xc0",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %eax, %eax */
    { "\x01\xc1",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %eax, %ecx */
    { "\x01\xc2",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %eax, %edx */
    { "\x01\xc3",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %eax, %ebx */
    { "\x01\xc4\x24", 3, 1, AARegister32Operand, AARegister32Operand }, /* addb %eax, %esp */
    { "\x01\xc5",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %eax, %ebp */
    { "\x01\xc6",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %eax, %esi */
    { "\x01\xc7",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %eax, %edi */
    { "\x01\xc8",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ecx, %eax */
    { "\x01\xc9",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ecx, %ecx */
    { "\x01\xca",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ecx, %edx */
    { "\x01\xcb",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ecx, %ebx */
    { "\x01\xcc\x24", 3, 1, AARegister32Operand, AARegister32Operand }, /* addb %ecx, %esp */
    { "\x01\xcd",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ecx, %ebp */
    { "\x01\xce",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ecx, %esi */
    { "\x01\xcf",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ecx, %edi */
    { "\x01\xd0",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edx, %eax */
    { "\x01\xd1",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edx, %ecx */
    { "\x01\xd2",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edx, %edx */
    { "\x01\xd3",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edx, %ebx */
    { "\x01\xd4\x24", 3, 1, AARegister32Operand, AARegister32Operand }, /* addb %edx, %esp */
    { "\x01\xd5",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edx, %ebp */
    { "\x01\xd6",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edx, %esi */
    { "\x01\xd7",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edx, %edi */
    { "\x01\xd8",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebx, %eax */
    { "\x01\xd9",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebx, %ecx */
    { "\x01\xda",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebx, %edx */
    { "\x01\xdb",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebx, %ebx */
    { "\x01\xdc\x24", 3, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebx, %esp */
    { "\x01\xdd",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebx, %ebp */
    { "\x01\xde",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebx, %esi */
    { "\x01\xdf",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebx, %edi */
    { "\x01\xe0",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esp, %eax */
    { "\x01\xe1",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esp, %ecx */
    { "\x01\xe2",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esp, %edx */
    { "\x01\xe3",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esp, %ebx */
    { "\x01\xe4\x24", 3, 1, AARegister32Operand, AARegister32Operand }, /* addb %esp, %esp */
    { "\x01\xe5",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esp, %ebp */
    { "\x01\xe6",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esp, %esi */
    { "\x01\xe7",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esp, %edi */
    { "\x01\xe8",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebp, %eax */
    { "\x01\xe9",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebp, %ecx */
    { "\x01\xea",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebp, %edx */
    { "\x01\xeb",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebp, %ebx */
    { "\x01\xec\x24", 3, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebp, %esp */
    { "\x01\xed",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebp, %ebp */
    { "\x01\xee",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebp, %esi */
    { "\x01\xef",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebp, %edi */
    { "\x01\xf0",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esi, %eax */
    { "\x01\xf1",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esi, %ecx */
    { "\x01\xf2",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esi, %edx */
    { "\x01\xf3",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esi, %ebx */
    { "\x01\xf4\x24", 3, 1, AARegister32Operand, AARegister32Operand }, /* addb %esi, %esp */
    { "\x01\xf5",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esi, %ebp */
    { "\x01\xf6",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esi, %esi */
    { "\x01\xf7",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esi, %edi */
    { "\x01\xf8",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edi, %eax */
    { "\x01\xf9",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edi, %ecx */
    { "\x01\xfa",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edi, %edx */
    { "\x01\xfb",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edi, %ebx */
    { "\x01\xfc\x24", 3, 1, AARegister32Operand, AARegister32Operand }, /* addb %edi, %esp */
    { "\x01\xfd",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edi, %ebp */
    { "\x01\xfe",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edi, %esi */
    { "\x01\xff",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edi, %edi */

    /* addl $n, %eax */
    { "\x05", 1, 4, AARegister32Operand, AAScalarOperand },

    AA_OPCODE_VALUE_END
};

const AAOpcode AA_IA32_Opcodes[] = {
    AA_NEW_OPCODE(mov),
    AA_NEW_OPCODE(add),

    AA_OPCODE_END
};

