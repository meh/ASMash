/**
 * The files in this directory and elsewhere which refer to this LICENCE
 * file are part of ASMash, the library for disassembling/assembling
 * binary code.
 *
 * Copyright (C) 2009 meh. and BlackLight
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

AA_OPCODES(IA32, mov) = {
    /* movl $scal, %reg32 */

    /* movl $n, %eax */
    AA_OPCODE(IA32, mov, "\xb8", 1, 4,
        AA_OPCODE_OPERAND(AAScalarOperand, AANone),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),
        
    /* movl $n, %ecx */
    AA_OPCODE(IA32, mov, "\xb9", 1, 4,
        AA_OPCODE_OPERAND(AAScalarOperand, AANone),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),
    
    /* movl $n, %edx */
    AA_OPCODE(IA32, mov, "\xba", 1, 4,
        AA_OPCODE_OPERAND(AAScalarOperand, AANone),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),
    
    /* movl $n, %ebx */
    AA_OPCODE(IA32, mov, "\xbb", 1, 4,
        AA_OPCODE_OPERAND(AAScalarOperand, AANone),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),
            
    /* movl $n, %esp */
    AA_OPCODE(IA32, mov, "\xbc", 1, 4,
        AA_OPCODE_OPERAND(AAScalarOperand, AANone),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),
            
    /* movl $n, %ebp */
    AA_OPCODE(IA32, mov, "\xbd", 1, 4,
        AA_OPCODE_OPERAND(AAScalarOperand, AANone),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* movl $n, %esi */
    AA_OPCODE(IA32, mov, "\xbe", 1, 4,
        AA_OPCODE_OPERAND(AAScalarOperand, AANone),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),
        
    /* movl $n, %edi */
    AA_OPCODE(IA32, mov, "\xbf", 1, 4,
        AA_OPCODE_OPERAND(AAScalarOperand, AANone),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    AA_OPCODES_END
};

#if 0

const char* aa_IA32_Opcodes_add_name = "add";

const AAOpcode aa_IA32_Opcodes_add[] = {
    /* addb %reg8, (%reg32) */

    { /* addb %al, (%eax) */
        AA_OPCODE(add, "\x00\x00", 2, 0),
        AA_OPCODE_OPERAND(AARegister8Operand,            aa_IA32_AL),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, aa_IA32_EAX)
    },

    { /* addb %al, (%ecx) */
        AA_OPCODE(add, "\x00\x01", 2, 0),
        AA_OPCODE_OPERAND(AARegister8Operand, aa_IA32_AL),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, aa_IA32_ECX)
    },
    
    {
        aa_IA32_Opcodes_add_name, "\x00\x02",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %al, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x00\x03",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %al, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x00\x04\x24", 3, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %al, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x00\x05",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %al, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x00\x06",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %al, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x00\x07",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %al, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x00\x08",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %cl, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x00\x09",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %cl, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x00\x0a",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %cl, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x00\x0b",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %cl, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x00\x0c\x24", 3, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %cl, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x00\x0d",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %cl, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x00\x0e",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %cl, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x00\x0f",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %cl, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x00\x10",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dl, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x00\x11",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dl, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x00\x12",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dl, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x00\x13",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dl, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x00\x14\x24", 3, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dl, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x00\x15",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dl, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x00\x16",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dl, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x00\x17",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dl, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x00\x18",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bl, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x00\x19",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bl, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x00\x1a",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bl, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x00\x1b",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bl, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x00\x1c\x24", 3, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bl, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x00\x1d",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bl, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x00\x1e",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bl, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x00\x1f",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bl, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x00\x20",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ah, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x00\x21",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ah, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x00\x22",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ah, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x00\x23",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ah, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x00\x24\x24", 3, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ah, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x00\x25",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ah, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x00\x26",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ah, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x00\x27",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ah, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x00\x28",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ch, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x00\x29",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ch, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x00\x2a",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ch, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x00\x2b",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ch, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x00\x2c\x24", 3, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ch, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x00\x2d",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ch, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x00\x2e",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ch, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x00\x2f",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %ch, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x00\x30",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dh, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x00\x31",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dh, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x00\x32",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dh, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x00\x33",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dh, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x00\x34\x24", 3, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dh, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x00\x35",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dh, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x00\x36",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dh, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x00\x37",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %dh, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x00\x38",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bh, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x00\x39",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bh, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x00\x3a",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bh, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x00\x3b",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bh, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x00\x3c\x24", 3, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bh, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x00\x3d",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bh, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x00\x3e",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bh, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x00\x3f",     2, 0, AARegister8Operand, AAMemoryFromRegister32Operand }, /* addb %bh, (%edi) */

    /* addb %reg8, n(%reg32) */
    { aa_IA32_Opcodes_add_name, "\x00\x40",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %al, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x00\x41",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %al, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x00\x42",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %al, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x00\x43",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %al, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x00\x44\x24", 3, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %al, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x00\x45",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %al, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x00\x46",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %al, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x00\x47",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %al, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x00\x48",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %cl, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x00\x49",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %cl, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x00\x4a",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %cl, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x00\x4b",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %cl, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x00\x4c\x24", 3, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %cl, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x00\x4d",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %cl, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x00\x4e",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %cl, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x00\x4f",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %cl, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x00\x50",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dl, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x00\x51",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dl, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x00\x52",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dl, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x00\x53",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dl, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x00\x54\x24", 3, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dl, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x00\x55",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dl, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x00\x56",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dl, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x00\x57",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dl, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x00\x58",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bl, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x00\x59",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bl, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x00\x5a",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bl, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x00\x5b",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bl, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x00\x5c\x24", 3, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bl, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x00\x5d",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bl, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x00\x5e",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bl, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x00\x5f",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bl, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x00\x60",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ah, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x00\x61",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ah, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x00\x62",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ah, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x00\x63",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ah, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x00\x64\x24", 3, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ah, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x00\x65",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ah, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x00\x66",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ah, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x00\x67",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ah, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x00\x68",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ch, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x00\x69",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ch, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x00\x6a",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ch, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x00\x6b",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ch, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x00\x6c\x24", 3, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ch, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x00\x6d",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ch, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x00\x6e",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ch, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x00\x6f",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ch, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x00\x70",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dh, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x00\x71",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dh, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x00\x72",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dh, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x00\x73",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dh, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x00\x74\x24", 3, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dh, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x00\x75",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dh, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x00\x76",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dh, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x00\x77",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %dh, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x00\x78",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bh, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x00\x79",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bh, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x00\x7a",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bh, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x00\x7b",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bh, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x00\x7c\x24", 3, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bh, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x00\x7d",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bh, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x00\x7e",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bh, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x00\x7f",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %bh, (%edi) */

    /* addl %reg32, (%reg32) */
    { aa_IA32_Opcodes_add_name, "\x01\x00",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %eax, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x01\x01",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %eax, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x01\x02",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %eax, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x01\x03",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %eax, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x01\x04\x24", 3, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %eax, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x01\x05",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %eax, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x01\x06",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %eax, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x01\x07",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %eax, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x01\x08",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ecx, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x01\x09",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ecx, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x01\x0a",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ecx, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x01\x0b",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ecx, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x01\x0c\x24", 3, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ecx, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x01\x0d",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ecx, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x01\x0e",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ecx, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x01\x0f",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ecx, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x01\x10",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edx, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x01\x11",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edx, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x01\x12",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edx, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x01\x13",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edx, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x01\x14\x24", 3, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edx, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x01\x15",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edx, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x01\x16",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edx, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x01\x17",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edx, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x01\x18",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebx, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x01\x19",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebx, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x01\x1a",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebx, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x01\x1b",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebx, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x01\x1c\x24", 3, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebx, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x01\x1d",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebx, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x01\x1e",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebx, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x01\x1f",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebx, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x01\x20",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esp, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x01\x21",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esp, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x01\x22",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esp, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x01\x23",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esp, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x01\x24\x24", 3, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esp, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x01\x25",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esp, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x01\x26",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esp, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x01\x27",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esp, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x01\x28",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebp, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x01\x29",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebp, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x01\x2a",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebp, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x01\x2b",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebp, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x01\x2c\x24", 3, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebp, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x01\x2d",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebp, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x01\x2e",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebp, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x01\x2f",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %ebp, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x01\x30",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esi, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x01\x31",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esi, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x01\x32",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esi, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x01\x33",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esi, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x01\x34\x24", 3, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esi, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x01\x35",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esi, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x01\x36",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esi, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x01\x37",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %esi, (%edi) */
    { aa_IA32_Opcodes_add_name, "\x01\x38",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edi, (%eax) */
    { aa_IA32_Opcodes_add_name, "\x01\x39",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edi, (%ecx) */
    { aa_IA32_Opcodes_add_name, "\x01\x3a",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edi, (%edx) */
    { aa_IA32_Opcodes_add_name, "\x01\x3b",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edi, (%ebx) */
    { aa_IA32_Opcodes_add_name, "\x01\x3c\x24", 3, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edi, (%esp) */
    { aa_IA32_Opcodes_add_name, "\x01\x3d",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edi, (%ebp) */
    { aa_IA32_Opcodes_add_name, "\x01\x3e",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edi, (%esi) */
    { aa_IA32_Opcodes_add_name, "\x01\x3f",     2, 0, AARegister32Operand, AAMemoryFromRegister32Operand }, /* addl %edi, (%edi) */

    /* addl %reg32, n(%reg32) */
    { aa_IA32_Opcodes_add_name, "\x01\x40",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %eax, n(%eax) */
    { aa_IA32_Opcodes_add_name, "\x01\x41",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %eax, n(%ecx) */
    { aa_IA32_Opcodes_add_name, "\x01\x42",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %eax, n(%edx) */
    { aa_IA32_Opcodes_add_name, "\x01\x43",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %eax, n(%ebx) */
    { aa_IA32_Opcodes_add_name, "\x01\x44\x24", 3, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %eax, n(%esp) */
    { aa_IA32_Opcodes_add_name, "\x01\x45",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %eax, n(%ebp) */
    { aa_IA32_Opcodes_add_name, "\x01\x46",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %eax, n(%esi) */
    { aa_IA32_Opcodes_add_name, "\x01\x47",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %eax, n(%edi) */
    { aa_IA32_Opcodes_add_name, "\x01\x48",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ecx, n(%eax) */
    { aa_IA32_Opcodes_add_name, "\x01\x49",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ecx, n(%ecx) */
    { aa_IA32_Opcodes_add_name, "\x01\x4a",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ecx, n(%edx) */
    { aa_IA32_Opcodes_add_name, "\x01\x4b",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ecx, n(%ebx) */
    { aa_IA32_Opcodes_add_name, "\x01\x4c\x24", 3, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ecx, n(%esp) */
    { aa_IA32_Opcodes_add_name, "\x01\x4d",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ecx, n(%ebp) */
    { aa_IA32_Opcodes_add_name, "\x01\x4e",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ecx, n(%esi) */
    { aa_IA32_Opcodes_add_name, "\x01\x4f",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ecx, n(%edi) */
    { aa_IA32_Opcodes_add_name, "\x01\x50",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edx, n(%eax) */
    { aa_IA32_Opcodes_add_name, "\x01\x51",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edx, n(%ecx) */
    { aa_IA32_Opcodes_add_name, "\x01\x52",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edx, n(%edx) */
    { aa_IA32_Opcodes_add_name, "\x01\x53",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edx, n(%ebx) */
    { aa_IA32_Opcodes_add_name, "\x01\x54\x24", 3, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edx, n(%esp) */
    { aa_IA32_Opcodes_add_name, "\x01\x55",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edx, n(%ebp) */
    { aa_IA32_Opcodes_add_name, "\x01\x56",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edx, n(%esi) */
    { aa_IA32_Opcodes_add_name, "\x01\x57",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edx, n(%edi) */
    { aa_IA32_Opcodes_add_name, "\x01\x58",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebx, n(%eax) */
    { aa_IA32_Opcodes_add_name, "\x01\x59",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebx, n(%ecx) */
    { aa_IA32_Opcodes_add_name, "\x01\x5a",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebx, n(%edx) */
    { aa_IA32_Opcodes_add_name, "\x01\x5b",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebx, n(%ebx) */
    { aa_IA32_Opcodes_add_name, "\x01\x5c\x24", 3, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebx, n(%esp) */
    { aa_IA32_Opcodes_add_name, "\x01\x5d",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebx, n(%ebp) */
    { aa_IA32_Opcodes_add_name, "\x01\x5e",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebx, n(%esi) */
    { aa_IA32_Opcodes_add_name, "\x01\x5f",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebx, n(%edi) */
    { aa_IA32_Opcodes_add_name, "\x01\x60",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esp, n(%eax) */
    { aa_IA32_Opcodes_add_name, "\x01\x61",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esp, n(%ecx) */
    { aa_IA32_Opcodes_add_name, "\x01\x62",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esp, n(%edx) */
    { aa_IA32_Opcodes_add_name, "\x01\x63",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esp, n(%ebx) */
    { aa_IA32_Opcodes_add_name, "\x01\x64\x24", 3, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esp, n(%esp) */
    { aa_IA32_Opcodes_add_name, "\x01\x65",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esp, n(%ebp) */
    { aa_IA32_Opcodes_add_name, "\x01\x66",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esp, n(%esi) */
    { aa_IA32_Opcodes_add_name, "\x01\x67",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esp, n(%edi) */
    { aa_IA32_Opcodes_add_name, "\x01\x68",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebp, n(%eax) */
    { aa_IA32_Opcodes_add_name, "\x01\x69",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebp, n(%ecx) */
    { aa_IA32_Opcodes_add_name, "\x01\x6a",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebp, n(%edx) */
    { aa_IA32_Opcodes_add_name, "\x01\x6b",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebp, n(%ebx) */
    { aa_IA32_Opcodes_add_name, "\x01\x6c\x24", 3, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebp, n(%esp) */
    { aa_IA32_Opcodes_add_name, "\x01\x6d",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebp, n(%ebp) */
    { aa_IA32_Opcodes_add_name, "\x01\x6e",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebp, n(%esi) */
    { aa_IA32_Opcodes_add_name, "\x01\x6f",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %ebp, n(%edi) */
    { aa_IA32_Opcodes_add_name, "\x01\x70",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esi, n(%eax) */
    { aa_IA32_Opcodes_add_name, "\x01\x71",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esi, n(%ecx) */
    { aa_IA32_Opcodes_add_name, "\x01\x72",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esi, n(%edx) */
    { aa_IA32_Opcodes_add_name, "\x01\x73",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esi, n(%ebx) */
    { aa_IA32_Opcodes_add_name, "\x01\x74\x24", 3, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esi, n(%esp) */
    { aa_IA32_Opcodes_add_name, "\x01\x75",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esi, n(%ebp) */
    { aa_IA32_Opcodes_add_name, "\x01\x76",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esi, n(%esi) */
    { aa_IA32_Opcodes_add_name, "\x01\x77",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %esi, n(%edi) */
    { aa_IA32_Opcodes_add_name, "\x01\x78",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edi, n(%eax) */
    { aa_IA32_Opcodes_add_name, "\x01\x79",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edi, n(%ecx) */
    { aa_IA32_Opcodes_add_name, "\x01\x7a",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edi, n(%edx) */
    { aa_IA32_Opcodes_add_name, "\x01\x7b",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edi, n(%ebx) */
    { aa_IA32_Opcodes_add_name, "\x01\x7c\x24", 3, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edi, n(%esp) */
    { aa_IA32_Opcodes_add_name, "\x01\x7d",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edi, n(%ebp) */
    { aa_IA32_Opcodes_add_name, "\x01\x7e",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edi, n(%esi) */
    { aa_IA32_Opcodes_add_name, "\x01\x7f",     2, 1, AARegister32Operand, AAMemoryOffsetFromRegister32Operand }, /* addb %edi, n(%edi) */

    /* addl %reg32, %reg32 */
    { aa_IA32_Opcodes_add_name, "\x01\xc0",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %eax, %eax */
    { aa_IA32_Opcodes_add_name, "\x01\xc1",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %eax, %ecx */
    { aa_IA32_Opcodes_add_name, "\x01\xc2",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %eax, %edx */
    { aa_IA32_Opcodes_add_name, "\x01\xc3",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %eax, %ebx */
    { aa_IA32_Opcodes_add_name, "\x01\xc4\x24", 3, 1, AARegister32Operand, AARegister32Operand }, /* addb %eax, %esp */
    { aa_IA32_Opcodes_add_name, "\x01\xc5",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %eax, %ebp */
    { aa_IA32_Opcodes_add_name, "\x01\xc6",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %eax, %esi */
    { aa_IA32_Opcodes_add_name, "\x01\xc7",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %eax, %edi */
    { aa_IA32_Opcodes_add_name, "\x01\xc8",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ecx, %eax */
    { aa_IA32_Opcodes_add_name, "\x01\xc9",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ecx, %ecx */
    { aa_IA32_Opcodes_add_name, "\x01\xca",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ecx, %edx */
    { aa_IA32_Opcodes_add_name, "\x01\xcb",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ecx, %ebx */
    { aa_IA32_Opcodes_add_name, "\x01\xcc\x24", 3, 1, AARegister32Operand, AARegister32Operand }, /* addb %ecx, %esp */
    { aa_IA32_Opcodes_add_name, "\x01\xcd",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ecx, %ebp */
    { aa_IA32_Opcodes_add_name, "\x01\xce",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ecx, %esi */
    { aa_IA32_Opcodes_add_name, "\x01\xcf",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ecx, %edi */
    { aa_IA32_Opcodes_add_name, "\x01\xd0",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edx, %eax */
    { aa_IA32_Opcodes_add_name, "\x01\xd1",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edx, %ecx */
    { aa_IA32_Opcodes_add_name, "\x01\xd2",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edx, %edx */
    { aa_IA32_Opcodes_add_name, "\x01\xd3",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edx, %ebx */
    { aa_IA32_Opcodes_add_name, "\x01\xd4\x24", 3, 1, AARegister32Operand, AARegister32Operand }, /* addb %edx, %esp */
    { aa_IA32_Opcodes_add_name, "\x01\xd5",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edx, %ebp */
    { aa_IA32_Opcodes_add_name, "\x01\xd6",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edx, %esi */
    { aa_IA32_Opcodes_add_name, "\x01\xd7",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edx, %edi */
    { aa_IA32_Opcodes_add_name, "\x01\xd8",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebx, %eax */
    { aa_IA32_Opcodes_add_name, "\x01\xd9",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebx, %ecx */
    { aa_IA32_Opcodes_add_name, "\x01\xda",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebx, %edx */
    { aa_IA32_Opcodes_add_name, "\x01\xdb",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebx, %ebx */
    { aa_IA32_Opcodes_add_name, "\x01\xdc\x24", 3, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebx, %esp */
    { aa_IA32_Opcodes_add_name, "\x01\xdd",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebx, %ebp */
    { aa_IA32_Opcodes_add_name, "\x01\xde",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebx, %esi */
    { aa_IA32_Opcodes_add_name, "\x01\xdf",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebx, %edi */
    { aa_IA32_Opcodes_add_name, "\x01\xe0",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esp, %eax */
    { aa_IA32_Opcodes_add_name, "\x01\xe1",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esp, %ecx */
    { aa_IA32_Opcodes_add_name, "\x01\xe2",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esp, %edx */
    { aa_IA32_Opcodes_add_name, "\x01\xe3",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esp, %ebx */
    { aa_IA32_Opcodes_add_name, "\x01\xe4\x24", 3, 1, AARegister32Operand, AARegister32Operand }, /* addb %esp, %esp */
    { aa_IA32_Opcodes_add_name, "\x01\xe5",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esp, %ebp */
    { aa_IA32_Opcodes_add_name, "\x01\xe6",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esp, %esi */
    { aa_IA32_Opcodes_add_name, "\x01\xe7",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esp, %edi */
    { aa_IA32_Opcodes_add_name, "\x01\xe8",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebp, %eax */
    { aa_IA32_Opcodes_add_name, "\x01\xe9",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebp, %ecx */
    { aa_IA32_Opcodes_add_name, "\x01\xea",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebp, %edx */
    { aa_IA32_Opcodes_add_name, "\x01\xeb",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebp, %ebx */
    { aa_IA32_Opcodes_add_name, "\x01\xec\x24", 3, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebp, %esp */
    { aa_IA32_Opcodes_add_name, "\x01\xed",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebp, %ebp */
    { aa_IA32_Opcodes_add_name, "\x01\xee",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebp, %esi */
    { aa_IA32_Opcodes_add_name, "\x01\xef",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %ebp, %edi */
    { aa_IA32_Opcodes_add_name, "\x01\xf0",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esi, %eax */
    { aa_IA32_Opcodes_add_name, "\x01\xf1",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esi, %ecx */
    { aa_IA32_Opcodes_add_name, "\x01\xf2",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esi, %edx */
    { aa_IA32_Opcodes_add_name, "\x01\xf3",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esi, %ebx */
    { aa_IA32_Opcodes_add_name, "\x01\xf4\x24", 3, 1, AARegister32Operand, AARegister32Operand }, /* addb %esi, %esp */
    { aa_IA32_Opcodes_add_name, "\x01\xf5",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esi, %ebp */
    { aa_IA32_Opcodes_add_name, "\x01\xf6",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esi, %esi */
    { aa_IA32_Opcodes_add_name, "\x01\xf7",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %esi, %edi */
    { aa_IA32_Opcodes_add_name, "\x01\xf8",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edi, %eax */
    { aa_IA32_Opcodes_add_name, "\x01\xf9",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edi, %ecx */
    { aa_IA32_Opcodes_add_name, "\x01\xfa",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edi, %edx */
    { aa_IA32_Opcodes_add_name, "\x01\xfb",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edi, %ebx */
    { aa_IA32_Opcodes_add_name, "\x01\xfc\x24", 3, 1, AARegister32Operand, AARegister32Operand }, /* addb %edi, %esp */
    { aa_IA32_Opcodes_add_name, "\x01\xfd",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edi, %ebp */
    { aa_IA32_Opcodes_add_name, "\x01\xfe",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edi, %esi */
    { aa_IA32_Opcodes_add_name, "\x01\xff",     2, 1, AARegister32Operand, AARegister32Operand }, /* addb %edi, %edi */

    /* addb (%reg32), reg8 */
    { aa_IA32_Opcodes_add_name, "\x02\x00",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%eax), %al */
    { aa_IA32_Opcodes_add_name, "\x02\x01",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%eax), %cl */
    { aa_IA32_Opcodes_add_name, "\x02\x02",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%eax), %dl */
    { aa_IA32_Opcodes_add_name, "\x02\x03",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%eax), %bl */
    { aa_IA32_Opcodes_add_name, "\x02\x04",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%eax), %ah */
    { aa_IA32_Opcodes_add_name, "\x02\x05",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%eax), %ch */
    { aa_IA32_Opcodes_add_name, "\x02\x06",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%eax), %dh */
    { aa_IA32_Opcodes_add_name, "\x02\x07",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%eax), %bh */
    { aa_IA32_Opcodes_add_name, "\x02\x08",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ecx), %al */
    { aa_IA32_Opcodes_add_name, "\x02\x09",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ecx), %cl */
    { aa_IA32_Opcodes_add_name, "\x02\x0a",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ecx), %dl */
    { aa_IA32_Opcodes_add_name, "\x02\x0b",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ecx), %bl */
    { aa_IA32_Opcodes_add_name, "\x02\x0c",     3, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ecx), %ah */
    { aa_IA32_Opcodes_add_name, "\x02\x0d",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ecx), %ch */
    { aa_IA32_Opcodes_add_name, "\x02\x0e",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ecx), %dh */
    { aa_IA32_Opcodes_add_name, "\x02\x0f",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ecx), %bh */
    { aa_IA32_Opcodes_add_name, "\x02\x10",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%edx), %al */
    { aa_IA32_Opcodes_add_name, "\x02\x11",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%edx), %cl */
    { aa_IA32_Opcodes_add_name, "\x02\x12",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%edx), %dl */
    { aa_IA32_Opcodes_add_name, "\x02\x13",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%edx), %bl */
    { aa_IA32_Opcodes_add_name, "\x02\x14",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%edx), %ah */
    { aa_IA32_Opcodes_add_name, "\x02\x15",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%edx), %ch */
    { aa_IA32_Opcodes_add_name, "\x02\x16",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%edx), %dh */
    { aa_IA32_Opcodes_add_name, "\x02\x17",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%edx), %bh */
    { aa_IA32_Opcodes_add_name, "\x02\x18",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ebx), %al */
    { aa_IA32_Opcodes_add_name, "\x02\x19",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ebx), %cl */
    { aa_IA32_Opcodes_add_name, "\x02\x1a",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ebx), %dl */
    { aa_IA32_Opcodes_add_name, "\x02\x1b",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ebx), %bl */
    { aa_IA32_Opcodes_add_name, "\x02\x1c",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ebx), %ah */
    { aa_IA32_Opcodes_add_name, "\x02\x1d",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ebx), %ch */
    { aa_IA32_Opcodes_add_name, "\x02\x1e",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ebx), %dh */
    { aa_IA32_Opcodes_add_name, "\x02\x1f",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ebx), %bh */
    { aa_IA32_Opcodes_add_name, "\x02\x20\x24", 3, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%esp), %al */
    { aa_IA32_Opcodes_add_name, "\x02\x21\x24", 3, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%esp), %cl */
    { aa_IA32_Opcodes_add_name, "\x02\x22\x24", 3, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%esp), %dl */
    { aa_IA32_Opcodes_add_name, "\x02\x23\x24", 3, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%esp), %bl */
    { aa_IA32_Opcodes_add_name, "\x02\x24\x24", 3, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%esp), %ah */
    { aa_IA32_Opcodes_add_name, "\x02\x25\x24", 3, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%esp), %ch */
    { aa_IA32_Opcodes_add_name, "\x02\x26\x24", 3, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%esp), %dh */
    { aa_IA32_Opcodes_add_name, "\x02\x27\x24", 3, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%esp), %bh */
    { aa_IA32_Opcodes_add_name, "\x02\x28",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ebp), %al */
    { aa_IA32_Opcodes_add_name, "\x02\x29",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ebp), %cl */
    { aa_IA32_Opcodes_add_name, "\x02\x2a",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ebp), %dl */
    { aa_IA32_Opcodes_add_name, "\x02\x2b",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ebp), %bl */
    { aa_IA32_Opcodes_add_name, "\x02\x2c",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ebp), %ah */
    { aa_IA32_Opcodes_add_name, "\x02\x2d",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ebp), %ch */
    { aa_IA32_Opcodes_add_name, "\x02\x2e",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ebp), %dh */
    { aa_IA32_Opcodes_add_name, "\x02\x2f",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%ebp), %bh */
    { aa_IA32_Opcodes_add_name, "\x02\x30",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%esi), %al */
    { aa_IA32_Opcodes_add_name, "\x02\x31",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%esi), %cl */
    { aa_IA32_Opcodes_add_name, "\x02\x32",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%esi), %dl */
    { aa_IA32_Opcodes_add_name, "\x02\x33",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%esi), %bl */
    { aa_IA32_Opcodes_add_name, "\x02\x34",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%esi), %ah */
    { aa_IA32_Opcodes_add_name, "\x02\x35",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%esi), %ch */
    { aa_IA32_Opcodes_add_name, "\x02\x36",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%esi), %dh */
    { aa_IA32_Opcodes_add_name, "\x02\x37",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%esi), %bh */
    { aa_IA32_Opcodes_add_name, "\x02\x38",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%edi), %al */
    { aa_IA32_Opcodes_add_name, "\x02\x39",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%edi), %cl */
    { aa_IA32_Opcodes_add_name, "\x02\x3a",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%edi), %dl */
    { aa_IA32_Opcodes_add_name, "\x02\x3b",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%edi), %bl */
    { aa_IA32_Opcodes_add_name, "\x02\x3c",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%edi), %ah */
    { aa_IA32_Opcodes_add_name, "\x02\x3d",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%edi), %ch */
    { aa_IA32_Opcodes_add_name, "\x02\x3e",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%edi), %dh */
    { aa_IA32_Opcodes_add_name, "\x02\x3f",     2, 0, AAMemoryFromRegister32Operand, AARegister8Operand }, /* addb (%edi), %bh */

    /* addb n(%reg32), reg8 */
    { aa_IA32_Opcodes_add_name, "\x02\x40",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb n(%eax), %al */
    { aa_IA32_Opcodes_add_name, "\x02\x41",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb n(%eax), %cl */
    { aa_IA32_Opcodes_add_name, "\x02\x42",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb n(%eax), %dl */
    { aa_IA32_Opcodes_add_name, "\x02\x43",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb n(%eax), %bl */
    { aa_IA32_Opcodes_add_name, "\x02\x44",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb n(%eax), %ah */
    { aa_IA32_Opcodes_add_name, "\x02\x45",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb n(%eax), %ch */
    { aa_IA32_Opcodes_add_name, "\x02\x46",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb n(%eax), %dh */
    { aa_IA32_Opcodes_add_name, "\x02\x47",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb n(%eax), %bh */
    { aa_IA32_Opcodes_add_name, "\x02\x48",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb n(%ecx), %al */
    { aa_IA32_Opcodes_add_name, "\x02\x49",     2, 1, AARegister8Operand, AAMemoryOffsetFromRegister32Operand }, /* addb n(%ecx), %cl */
    { aa_IA32_Opcodes_add_name, "\x02\x4a",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ecx), %dl */
    { aa_IA32_Opcodes_add_name, "\x02\x4b",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ecx), %bl */
    { aa_IA32_Opcodes_add_name, "\x02\x4c",     3, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ecx), %ah */
    { aa_IA32_Opcodes_add_name, "\x02\x4d",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ecx), %ch */
    { aa_IA32_Opcodes_add_name, "\x02\x4e",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ecx), %dh */
    { aa_IA32_Opcodes_add_name, "\x02\x4f",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ecx), %bh */
    { aa_IA32_Opcodes_add_name, "\x02\x50",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%edx), %al */
    { aa_IA32_Opcodes_add_name, "\x02\x51",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%edx), %cl */
    { aa_IA32_Opcodes_add_name, "\x02\x52",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%edx), %dl */
    { aa_IA32_Opcodes_add_name, "\x02\x53",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%edx), %bl */
    { aa_IA32_Opcodes_add_name, "\x02\x54",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%edx), %ah */
    { aa_IA32_Opcodes_add_name, "\x02\x55",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%edx), %ch */
    { aa_IA32_Opcodes_add_name, "\x02\x56",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%edx), %dh */
    { aa_IA32_Opcodes_add_name, "\x02\x57",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%edx), %bh */
    { aa_IA32_Opcodes_add_name, "\x02\x58",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ebx), %al */
    { aa_IA32_Opcodes_add_name, "\x02\x59",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ebx), %cl */
    { aa_IA32_Opcodes_add_name, "\x02\x5a",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ebx), %dl */
    { aa_IA32_Opcodes_add_name, "\x02\x5b",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ebx), %bl */
    { aa_IA32_Opcodes_add_name, "\x02\x5c",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ebx), %ah */
    { aa_IA32_Opcodes_add_name, "\x02\x5d",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ebx), %ch */
    { aa_IA32_Opcodes_add_name, "\x02\x5e",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ebx), %dh */
    { aa_IA32_Opcodes_add_name, "\x02\x5f",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ebx), %bh */
    { aa_IA32_Opcodes_add_name, "\x02\x60\x24", 3, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%esp), %al */
    { aa_IA32_Opcodes_add_name, "\x02\x61\x24", 3, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%esp), %cl */
    { aa_IA32_Opcodes_add_name, "\x02\x62\x24", 3, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%esp), %dl */
    { aa_IA32_Opcodes_add_name, "\x02\x63\x24", 3, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%esp), %bl */
    { aa_IA32_Opcodes_add_name, "\x02\x64\x24", 3, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%esp), %ah */
    { aa_IA32_Opcodes_add_name, "\x02\x65\x24", 3, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%esp), %ch */
    { aa_IA32_Opcodes_add_name, "\x02\x66\x24", 3, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%esp), %dh */
    { aa_IA32_Opcodes_add_name, "\x02\x67\x24", 3, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%esp), %bh */
    { aa_IA32_Opcodes_add_name, "\x02\x68",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ebp), %al */
    { aa_IA32_Opcodes_add_name, "\x02\x69",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ebp), %cl */
    { aa_IA32_Opcodes_add_name, "\x02\x6a",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ebp), %dl */
    { aa_IA32_Opcodes_add_name, "\x02\x6b",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ebp), %bl */
    { aa_IA32_Opcodes_add_name, "\x02\x6c",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ebp), %ah */
    { aa_IA32_Opcodes_add_name, "\x02\x6d",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ebp), %ch */
    { aa_IA32_Opcodes_add_name, "\x02\x6e",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ebp), %dh */
    { aa_IA32_Opcodes_add_name, "\x02\x6f",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%ebp), %bh */
    { aa_IA32_Opcodes_add_name, "\x02\x70",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%esi), %al */
    { aa_IA32_Opcodes_add_name, "\x02\x71",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%esi), %cl */
    { aa_IA32_Opcodes_add_name, "\x02\x72",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%esi), %dl */
    { aa_IA32_Opcodes_add_name, "\x02\x73",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%esi), %bl */
    { aa_IA32_Opcodes_add_name, "\x02\x74",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%esi), %ah */
    { aa_IA32_Opcodes_add_name, "\x02\x75",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%esi), %ch */
    { aa_IA32_Opcodes_add_name, "\x02\x76",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%esi), %dh */
    { aa_IA32_Opcodes_add_name, "\x02\x77",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%esi), %bh */
    { aa_IA32_Opcodes_add_name, "\x02\x78",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%edi), %al */
    { aa_IA32_Opcodes_add_name, "\x02\x79",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%edi), %cl */
    { aa_IA32_Opcodes_add_name, "\x02\x7a",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%edi), %dl */
    { aa_IA32_Opcodes_add_name, "\x02\x7b",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%edi), %bl */
    { aa_IA32_Opcodes_add_name, "\x02\x7c",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%edi), %ah */
    { aa_IA32_Opcodes_add_name, "\x02\x7d",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%edi), %ch */
    { aa_IA32_Opcodes_add_name, "\x02\x7e",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%edi), %dh */
    { aa_IA32_Opcodes_add_name, "\x02\x7f",     2, 1, AAMemoryOffsetFromRegister32Operand, AARegister8Operand }, /* addb n(%edi), %bh */

    /* addl $n, %eax */
    { aa_IA32_Opcodes_add_name, "\x04", 1, 1, AARegister8Operand, AAScalarOperand },
    { aa_IA32_Opcodes_add_name, "\x05", 1, 2, AARegister16Operand, AAScalarOperand },
    { aa_IA32_Opcodes_add_name, "\x05", 1, 4, AARegister32Operand, AAScalarOperand },

    AA_OPCODE_VALUE_END
};

#endif

const AAOpcodeList AA_IA32_Opcodes[] = {
    AA_NEW_OPCODELIST(IA32, mov),
/*    AA_NEW_OPCODE(add), */

    AA_OPCODELIST_END
};

