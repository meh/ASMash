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

/*
 * lulzJS ftw, cut like over 9000 % of time i would need:
 *
 * >>> lines = new File("a.txt", File.Mode.Read).readAll(); undefined
 * >>> lol = new File("tragay.txt", File.Mode.Write)
 * => #<File: path="tragay.txt", permission=600 size=0, position=0>
 * >>> for each (line in lines) { line = line.replace(/\s+{\saa.*?\s*?(".*?"),\s*?(\d+),\s*?(\d+),\s*?(\w+),\s*?(\w+).*(\/\*.*)$/, "    $6\n    AA_OPCODE(IA32, add, $1, $2, $3,\n        AA_OPCODE_OPERAND($4, AA_OPCODE_REGISTER(IA32, {source})),\n        AA_OPCODE_OPERAND($5, AA_OPCODE_REGISTER(IA32, {dest}))),"); matches = line.match(/\/\* \w+ .*?%(\w+).*?%(\w+)/); if (!matches) continue; if (matches[2]) source = matches[1].toUpperCase(); else source = 'AANone'; if(matches[2]) dest = matches[2].toUpperCase(); else dest='AANone'; lol.writeLine(line.format({source: source, dest: dest})+"\n"); }
 * => null
 * >>> lol.close()
 *
 * And trasformed the old syntax in the new one :D
 */

AA_OPCODES(IA32, add) = {
    /* addb %reg8, (%reg32) */

    /* addb %al, (%eax) */
    AA_OPCODE(IA32, add, "\x00\x00", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %al, (%ecx) */
    AA_OPCODE(IA32, add, "\x00\x01", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),
    
    /* addb %al, (%edx) */
    AA_OPCODE(IA32, add,  "\x00\x02", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %al, (%ebx) */
    AA_OPCODE(IA32, add, "\x00\x03", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand,AA_OPCODE_REGISTER(IA32, AL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %al, (%esp) */
    AA_OPCODE(IA32, add, "\x00\x04\x24", 3, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %al, (%ebp) */
    AA_OPCODE(IA32, add, "\x00\x05", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %al, (%esi) */
    AA_OPCODE(IA32, add, "\x00\x06", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %al, (%edi) */
    AA_OPCODE(IA32, add, "\x00\x07", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %cl, (%eax) */
    AA_OPCODE(IA32, add,  "\x00\x08", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %cl, (%ecx) */
    AA_OPCODE(IA32, add, "\x00\x09", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %cl, (%edx) */
    AA_OPCODE(IA32, add, "\x00\x0a", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %cl, (%ebx) */
    AA_OPCODE(IA32, add, "\x00\x0b", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %cl, (%esp) */
    AA_OPCODE(IA32, add, "\x00\x0c\x24", 3, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %cl, (%ebp) */
    AA_OPCODE(IA32, add, "\x00\x0d", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %cl, (%esi) */
    AA_OPCODE(IA32, add, "\x00\x0e", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %cl, (%edi) */
    AA_OPCODE(IA32, add, "\x00\x0f", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %dl, (%eax) */
    AA_OPCODE(IA32, add, "\x00\x10", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %dl, (%ecx) */
    AA_OPCODE(IA32, add, "\x00\x11", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %dl, (%edx) */
    AA_OPCODE(IA32, add, "\x00\x12", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %dl, (%ebx) */
    AA_OPCODE(IA32, add, "\x00\x13", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %dl, (%esp) */
    AA_OPCODE(IA32, add, "\x00\x14\x24", 3, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %dl, (%ebp) */
    AA_OPCODE(IA32, add, "\x00\x15", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %dl, (%esi) */
    AA_OPCODE(IA32, add, "\x00\x16", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %dl, (%edi) */
    AA_OPCODE(IA32, add, "\x00\x17", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %bl, (%eax) */
    AA_OPCODE(IA32, add, "\x00\x18", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %bl, (%ecx) */
    AA_OPCODE(IA32, add, "\x00\x19", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %bl, (%edx) */
    AA_OPCODE(IA32, add, "\x00\x1a", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %bl, (%ebx) */
    AA_OPCODE(IA32, add, "\x00\x1b", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %bl, (%esp) */
    AA_OPCODE(IA32, add, "\x00\x1c\x24", 3, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %bl, (%ebp) */
    AA_OPCODE(IA32, add, "\x00\x1d", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %bl, (%esi) */
    AA_OPCODE(IA32, add, "\x00\x1e", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %bl, (%edi) */
    AA_OPCODE(IA32, add, "\x00\x1f", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %ah, (%eax) */
    AA_OPCODE(IA32, add, "\x00\x20", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %ah, (%ecx) */
    AA_OPCODE(IA32, add, "\x00\x21", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %ah, (%edx) */
    AA_OPCODE(IA32, add, "\x00\x22", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %ah, (%ebx) */
    AA_OPCODE(IA32, add, "\x00\x23", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %ah, (%esp) */
    AA_OPCODE(IA32, add, "\x00\x24\x24", 3, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %ah, (%ebp) */
    AA_OPCODE(IA32, add, "\x00\x25", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %ah, (%esi) */
    AA_OPCODE(IA32, add, "\x00\x26", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %ah, (%edi) */
    AA_OPCODE(IA32, add, "\x00\x27", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %ch, (%eax) */
    AA_OPCODE(IA32, add, "\x00\x28", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %ch, (%ecx) */
    AA_OPCODE(IA32, add, "\x00\x29", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %ch, (%edx) */
    AA_OPCODE(IA32, add, "\x00\x2a", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %ch, (%ebx) */
    AA_OPCODE(IA32, add, "\x00\x2b", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %ch, (%esp) */
    AA_OPCODE(IA32, add, "\x00\x2c\x24", 3, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %ch, (%ebp) */
    AA_OPCODE(IA32, add, "\x00\x2d", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %ch, (%esi) */
    AA_OPCODE(IA32, add, "\x00\x2e", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %ch, (%edi) */
    AA_OPCODE(IA32, add, "\x00\x2f", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %dh, (%eax) */
    AA_OPCODE(IA32, add, "\x00\x30", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %dh, (%ecx) */
    AA_OPCODE(IA32, add, "\x00\x31", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %dh, (%edx) */
    AA_OPCODE(IA32, add, "\x00\x32", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %dh, (%ebx) */
    AA_OPCODE(IA32, add, "\x00\x33", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %dh, (%esp) */
    AA_OPCODE(IA32, add, "\x00\x34\x24", 3, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %dh, (%ebp) */
    AA_OPCODE(IA32, add, "\x00\x35", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %dh, (%esi) */
    AA_OPCODE(IA32, add, "\x00\x36", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %dh, (%edi) */
    AA_OPCODE(IA32, add, "\x00\x37", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %bh, (%eax) */
    AA_OPCODE(IA32, add, "\x00\x38", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %bh, (%ecx) */
    AA_OPCODE(IA32, add, "\x00\x39", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %bh, (%edx) */
    AA_OPCODE(IA32, add, "\x00\x3a", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %bh, (%ebx) */
    AA_OPCODE(IA32, add, "\x00\x3b", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %bh, (%esp) */
    AA_OPCODE(IA32, add, "\x00\x3c\x24", 3, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %bh, (%ebp) */
    AA_OPCODE(IA32, add, "\x00\x3d", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %bh, (%esi) */
    AA_OPCODE(IA32, add, "\x00\x3e", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %bh, (%edi) */
    AA_OPCODE(IA32, add, "\x00\x3f", 2, 0,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %reg8, n(%reg32) */

    /* addb %al, (%eax) */
    AA_OPCODE(IA32, add, "\x00\x40", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %al, (%ecx) */
    AA_OPCODE(IA32, add, "\x00\x41", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %al, (%edx) */
    AA_OPCODE(IA32, add, "\x00\x42", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %al, (%ebx) */
    AA_OPCODE(IA32, add, "\x00\x43", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %al, (%esp) */
    AA_OPCODE(IA32, add, "\x00\x44\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %al, (%ebp) */
    AA_OPCODE(IA32, add, "\x00\x45", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %al, (%esi) */
    AA_OPCODE(IA32, add, "\x00\x46", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %al, (%edi) */
    AA_OPCODE(IA32, add, "\x00\x47", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %cl, (%eax) */
    AA_OPCODE(IA32, add, "\x00\x48", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %cl, (%ecx) */
    AA_OPCODE(IA32, add, "\x00\x49", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %cl, (%edx) */
    AA_OPCODE(IA32, add, "\x00\x4a", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %cl, (%ebx) */
    AA_OPCODE(IA32, add, "\x00\x4b", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %cl, (%esp) */
    AA_OPCODE(IA32, add, "\x00\x4c\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %cl, (%ebp) */
    AA_OPCODE(IA32, add, "\x00\x4d", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %cl, (%esi) */
    AA_OPCODE(IA32, add, "\x00\x4e", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %cl, (%edi) */
    AA_OPCODE(IA32, add, "\x00\x4f", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %dl, (%eax) */
    AA_OPCODE(IA32, add, "\x00\x50", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %dl, (%ecx) */
    AA_OPCODE(IA32, add, "\x00\x51", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %dl, (%edx) */
    AA_OPCODE(IA32, add, "\x00\x52", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %dl, (%ebx) */
    AA_OPCODE(IA32, add, "\x00\x53", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %dl, (%esp) */
    AA_OPCODE(IA32, add, "\x00\x54\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %dl, (%ebp) */
    AA_OPCODE(IA32, add, "\x00\x55", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %dl, (%esi) */
    AA_OPCODE(IA32, add, "\x00\x56", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %dl, (%edi) */
    AA_OPCODE(IA32, add, "\x00\x57", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %bl, (%eax) */
    AA_OPCODE(IA32, add, "\x00\x58", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %bl, (%ecx) */
    AA_OPCODE(IA32, add, "\x00\x59", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %bl, (%edx) */
    AA_OPCODE(IA32, add, "\x00\x5a", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %bl, (%ebx) */
    AA_OPCODE(IA32, add, "\x00\x5b", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %bl, (%esp) */
    AA_OPCODE(IA32, add, "\x00\x5c\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %bl, (%ebp) */
    AA_OPCODE(IA32, add, "\x00\x5d", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %bl, (%esi) */
    AA_OPCODE(IA32, add, "\x00\x5e", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %bl, (%edi) */
    AA_OPCODE(IA32, add, "\x00\x5f", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %ah, (%eax) */
    AA_OPCODE(IA32, add, "\x00\x60", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %ah, (%ecx) */
    AA_OPCODE(IA32, add, "\x00\x61", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %ah, (%edx) */
    AA_OPCODE(IA32, add, "\x00\x62", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %ah, (%ebx) */
    AA_OPCODE(IA32, add, "\x00\x63", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %ah, (%esp) */
    AA_OPCODE(IA32, add, "\x00\x64\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %ah, (%ebp) */
    AA_OPCODE(IA32, add, "\x00\x65", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %ah, (%esi) */
    AA_OPCODE(IA32, add, "\x00\x66", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %ah, (%edi) */
    AA_OPCODE(IA32, add, "\x00\x67", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %ch, (%eax) */
    AA_OPCODE(IA32, add, "\x00\x68", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %ch, (%ecx) */
    AA_OPCODE(IA32, add, "\x00\x69", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %ch, (%edx) */
    AA_OPCODE(IA32, add, "\x00\x6a", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %ch, (%ebx) */
    AA_OPCODE(IA32, add, "\x00\x6b", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %ch, (%esp) */
    AA_OPCODE(IA32, add, "\x00\x6c\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %ch, (%ebp) */
    AA_OPCODE(IA32, add, "\x00\x6d", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %ch, (%esi) */
    AA_OPCODE(IA32, add, "\x00\x6e", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %ch, (%edi) */
    AA_OPCODE(IA32, add, "\x00\x6f", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %dh, (%eax) */
    AA_OPCODE(IA32, add, "\x00\x70", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %dh, (%ecx) */
    AA_OPCODE(IA32, add, "\x00\x71", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %dh, (%edx) */
    AA_OPCODE(IA32, add, "\x00\x72", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %dh, (%ebx) */
    AA_OPCODE(IA32, add, "\x00\x73", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %dh, (%esp) */
    AA_OPCODE(IA32, add, "\x00\x74\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %dh, (%ebp) */
    AA_OPCODE(IA32, add, "\x00\x75", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %dh, (%esi) */
    AA_OPCODE(IA32, add, "\x00\x76", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %dh, (%edi) */
    AA_OPCODE(IA32, add, "\x00\x77", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %bh, (%eax) */
    AA_OPCODE(IA32, add, "\x00\x78", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %bh, (%ecx) */
    AA_OPCODE(IA32, add, "\x00\x79", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %bh, (%edx) */
    AA_OPCODE(IA32, add, "\x00\x7a", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %bh, (%ebx) */
    AA_OPCODE(IA32, add, "\x00\x7b", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %bh, (%esp) */
    AA_OPCODE(IA32, add, "\x00\x7c\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %bh, (%ebp) */
    AA_OPCODE(IA32, add, "\x00\x7d", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %bh, (%esi) */
    AA_OPCODE(IA32, add, "\x00\x7e", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %bh, (%edi) */
    AA_OPCODE(IA32, add, "\x00\x7f", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addl %reg32, (%reg32) */

    /* addl %eax, (%eax) */
    AA_OPCODE(IA32, add, "\x01\x00", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addl %eax, (%ecx) */
    AA_OPCODE(IA32, add, "\x01\x01", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addl %eax, (%edx) */
    AA_OPCODE(IA32, add, "\x01\x02", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addl %eax, (%ebx) */
    AA_OPCODE(IA32, add, "\x01\x03", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addl %eax, (%esp) */
    AA_OPCODE(IA32, add, "\x01\x04\x24", 3, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addl %eax, (%ebp) */
    AA_OPCODE(IA32, add, "\x01\x05", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addl %eax, (%esi) */
    AA_OPCODE(IA32, add, "\x01\x06", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addl %eax, (%edi) */
    AA_OPCODE(IA32, add, "\x01\x07", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addl %ecx, (%eax) */
    AA_OPCODE(IA32, add, "\x01\x08", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addl %ecx, (%ecx) */
    AA_OPCODE(IA32, add, "\x01\x09", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addl %ecx, (%edx) */
    AA_OPCODE(IA32, add, "\x01\x0a", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addl %ecx, (%ebx) */
    AA_OPCODE(IA32, add, "\x01\x0b", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addl %ecx, (%esp) */
    AA_OPCODE(IA32, add, "\x01\x0c\x24", 3, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addl %ecx, (%ebp) */
    AA_OPCODE(IA32, add, "\x01\x0d", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addl %ecx, (%esi) */
    AA_OPCODE(IA32, add, "\x01\x0e", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addl %ecx, (%edi) */
    AA_OPCODE(IA32, add, "\x01\x0f", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addl %edx, (%eax) */
    AA_OPCODE(IA32, add, "\x01\x10", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addl %edx, (%ecx) */
    AA_OPCODE(IA32, add, "\x01\x11", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addl %edx, (%edx) */
    AA_OPCODE(IA32, add, "\x01\x12", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addl %edx, (%ebx) */
    AA_OPCODE(IA32, add, "\x01\x13", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addl %edx, (%esp) */
    AA_OPCODE(IA32, add, "\x01\x14\x24", 3, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addl %edx, (%ebp) */
    AA_OPCODE(IA32, add, "\x01\x15", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addl %edx, (%esi) */
    AA_OPCODE(IA32, add, "\x01\x16", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addl %edx, (%edi) */
    AA_OPCODE(IA32, add, "\x01\x17", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addl %ebx, (%eax) */
    AA_OPCODE(IA32, add, "\x01\x18", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addl %ebx, (%ecx) */
    AA_OPCODE(IA32, add, "\x01\x19", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addl %ebx, (%edx) */
    AA_OPCODE(IA32, add, "\x01\x1a", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addl %ebx, (%ebx) */
    AA_OPCODE(IA32, add, "\x01\x1b", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addl %ebx, (%esp) */
    AA_OPCODE(IA32, add, "\x01\x1c\x24", 3, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addl %ebx, (%ebp) */
    AA_OPCODE(IA32, add, "\x01\x1d", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addl %ebx, (%esi) */
    AA_OPCODE(IA32, add, "\x01\x1e", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addl %ebx, (%edi) */
    AA_OPCODE(IA32, add, "\x01\x1f", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addl %esp, (%eax) */
    AA_OPCODE(IA32, add, "\x01\x20", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addl %esp, (%ecx) */
    AA_OPCODE(IA32, add, "\x01\x21", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addl %esp, (%edx) */
    AA_OPCODE(IA32, add, "\x01\x22", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addl %esp, (%ebx) */
    AA_OPCODE(IA32, add, "\x01\x23", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addl %esp, (%esp) */
    AA_OPCODE(IA32, add, "\x01\x24\x24", 3, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addl %esp, (%ebp) */
    AA_OPCODE(IA32, add, "\x01\x25", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addl %esp, (%esi) */
    AA_OPCODE(IA32, add, "\x01\x26", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addl %esp, (%edi) */
    AA_OPCODE(IA32, add, "\x01\x27", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addl %ebp, (%eax) */
    AA_OPCODE(IA32, add, "\x01\x28", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addl %ebp, (%ecx) */
    AA_OPCODE(IA32, add, "\x01\x29", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addl %ebp, (%edx) */
    AA_OPCODE(IA32, add, "\x01\x2a", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addl %ebp, (%ebx) */
    AA_OPCODE(IA32, add, "\x01\x2b", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addl %ebp, (%esp) */
    AA_OPCODE(IA32, add, "\x01\x2c\x24", 3, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addl %ebp, (%ebp) */
    AA_OPCODE(IA32, add, "\x01\x2d", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addl %ebp, (%esi) */
    AA_OPCODE(IA32, add, "\x01\x2e", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addl %ebp, (%edi) */
    AA_OPCODE(IA32, add, "\x01\x2f", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addl %esi, (%eax) */
    AA_OPCODE(IA32, add, "\x01\x30", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addl %esi, (%ecx) */
    AA_OPCODE(IA32, add, "\x01\x31", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addl %esi, (%edx) */
    AA_OPCODE(IA32, add, "\x01\x32", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addl %esi, (%ebx) */
    AA_OPCODE(IA32, add, "\x01\x33", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addl %esi, (%esp) */
    AA_OPCODE(IA32, add, "\x01\x34\x24", 3, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addl %esi, (%ebp) */
    AA_OPCODE(IA32, add, "\x01\x35", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addl %esi, (%esi) */
    AA_OPCODE(IA32, add, "\x01\x36", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addl %esi, (%edi) */
    AA_OPCODE(IA32, add, "\x01\x37", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addl %edi, (%eax) */
    AA_OPCODE(IA32, add, "\x01\x38", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addl %edi, (%ecx) */
    AA_OPCODE(IA32, add, "\x01\x39", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addl %edi, (%edx) */
    AA_OPCODE(IA32, add, "\x01\x3a", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addl %edi, (%ebx) */
    AA_OPCODE(IA32, add, "\x01\x3b", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addl %edi, (%esp) */
    AA_OPCODE(IA32, add, "\x01\x3c\x24", 3, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addl %edi, (%ebp) */
    AA_OPCODE(IA32, add, "\x01\x3d", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addl %edi, (%esi) */
    AA_OPCODE(IA32, add, "\x01\x3e", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addl %edi, (%edi) */
    AA_OPCODE(IA32, add, "\x01\x3f", 2, 0,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addl %reg32, n(%reg32) */

    /* addb %eax, n(%eax) */
    AA_OPCODE(IA32, add, "\x01\x40", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %eax, n(%ecx) */
    AA_OPCODE(IA32, add, "\x01\x41", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %eax, n(%edx) */
    AA_OPCODE(IA32, add, "\x01\x42", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %eax, n(%ebx) */
    AA_OPCODE(IA32, add, "\x01\x43", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %eax, n(%esp) */
    AA_OPCODE(IA32, add, "\x01\x44\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %eax, n(%ebp) */
    AA_OPCODE(IA32, add, "\x01\x45", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %eax, n(%esi) */
    AA_OPCODE(IA32, add, "\x01\x46", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %eax, n(%edi) */
    AA_OPCODE(IA32, add, "\x01\x47", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %ecx, n(%eax) */
    AA_OPCODE(IA32, add, "\x01\x48", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %ecx, n(%ecx) */
    AA_OPCODE(IA32, add, "\x01\x49", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %ecx, n(%edx) */
    AA_OPCODE(IA32, add, "\x01\x4a", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %ecx, n(%ebx) */
    AA_OPCODE(IA32, add, "\x01\x4b", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %ecx, n(%esp) */
    AA_OPCODE(IA32, add, "\x01\x4c\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %ecx, n(%ebp) */
    AA_OPCODE(IA32, add, "\x01\x4d", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %ecx, n(%esi) */
    AA_OPCODE(IA32, add, "\x01\x4e", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %ecx, n(%edi) */
    AA_OPCODE(IA32, add, "\x01\x4f", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %edx, n(%eax) */
    AA_OPCODE(IA32, add, "\x01\x50", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %edx, n(%ecx) */
    AA_OPCODE(IA32, add, "\x01\x51", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %edx, n(%edx) */
    AA_OPCODE(IA32, add, "\x01\x52", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %edx, n(%ebx) */
    AA_OPCODE(IA32, add, "\x01\x53", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %edx, n(%esp) */
    AA_OPCODE(IA32, add, "\x01\x54\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %edx, n(%ebp) */
    AA_OPCODE(IA32, add, "\x01\x55", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %edx, n(%esi) */
    AA_OPCODE(IA32, add, "\x01\x56", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %edx, n(%edi) */
    AA_OPCODE(IA32, add, "\x01\x57", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %ebx, n(%eax) */
    AA_OPCODE(IA32, add, "\x01\x58", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %ebx, n(%ecx) */
    AA_OPCODE(IA32, add, "\x01\x59", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %ebx, n(%edx) */
    AA_OPCODE(IA32, add, "\x01\x5a", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %ebx, n(%ebx) */
    AA_OPCODE(IA32, add, "\x01\x5b", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %ebx, n(%esp) */
    AA_OPCODE(IA32, add, "\x01\x5c\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %ebx, n(%ebp) */
    AA_OPCODE(IA32, add, "\x01\x5d", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %ebx, n(%esi) */
    AA_OPCODE(IA32, add, "\x01\x5e", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %ebx, n(%edi) */
    AA_OPCODE(IA32, add, "\x01\x5f", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %esp, n(%eax) */
    AA_OPCODE(IA32, add, "\x01\x60", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %esp, n(%ecx) */
    AA_OPCODE(IA32, add, "\x01\x61", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %esp, n(%edx) */
    AA_OPCODE(IA32, add, "\x01\x62", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %esp, n(%ebx) */
    AA_OPCODE(IA32, add, "\x01\x63", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %esp, n(%esp) */
    AA_OPCODE(IA32, add, "\x01\x64\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %esp, n(%ebp) */
    AA_OPCODE(IA32, add, "\x01\x65", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %esp, n(%esi) */
    AA_OPCODE(IA32, add, "\x01\x66", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %esp, n(%edi) */
    AA_OPCODE(IA32, add, "\x01\x67", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %ebp, n(%eax) */
    AA_OPCODE(IA32, add, "\x01\x68", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %ebp, n(%ecx) */
    AA_OPCODE(IA32, add, "\x01\x69", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %ebp, n(%edx) */
    AA_OPCODE(IA32, add, "\x01\x6a", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %ebp, n(%ebx) */
    AA_OPCODE(IA32, add, "\x01\x6b", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %ebp, n(%esp) */
    AA_OPCODE(IA32, add, "\x01\x6c\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %ebp, n(%ebp) */
    AA_OPCODE(IA32, add, "\x01\x6d", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %ebp, n(%esi) */
    AA_OPCODE(IA32, add, "\x01\x6e", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %ebp, n(%edi) */
    AA_OPCODE(IA32, add, "\x01\x6f", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %esi, n(%eax) */
    AA_OPCODE(IA32, add, "\x01\x70", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %esi, n(%ecx) */
    AA_OPCODE(IA32, add, "\x01\x71", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %esi, n(%edx) */
    AA_OPCODE(IA32, add, "\x01\x72", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %esi, n(%ebx) */
    AA_OPCODE(IA32, add, "\x01\x73", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %esi, n(%esp) */
    AA_OPCODE(IA32, add, "\x01\x74\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %esi, n(%ebp) */
    AA_OPCODE(IA32, add, "\x01\x75", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %esi, n(%esi) */
    AA_OPCODE(IA32, add, "\x01\x76", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %esi, n(%edi) */
    AA_OPCODE(IA32, add, "\x01\x77", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %edi, n(%eax) */
    AA_OPCODE(IA32, add, "\x01\x78", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %edi, n(%ecx) */
    AA_OPCODE(IA32, add, "\x01\x79", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %edi, n(%edx) */
    AA_OPCODE(IA32, add, "\x01\x7a", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %edi, n(%ebx) */
    AA_OPCODE(IA32, add, "\x01\x7b", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %edi, n(%esp) */
    AA_OPCODE(IA32, add, "\x01\x7c\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %edi, n(%ebp) */
    AA_OPCODE(IA32, add, "\x01\x7d", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %edi, n(%esi) */
    AA_OPCODE(IA32, add, "\x01\x7e", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %edi, n(%edi) */
    AA_OPCODE(IA32, add, "\x01\x7f", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addl %reg32, %reg32 */

    /* addb %eax, %eax */
    AA_OPCODE(IA32, add, "\x01\xc0", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %eax, %ecx */
    AA_OPCODE(IA32, add, "\x01\xc1", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %eax, %edx */
    AA_OPCODE(IA32, add, "\x01\xc2", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %eax, %ebx */
    AA_OPCODE(IA32, add, "\x01\xc3", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %eax, %esp */
    AA_OPCODE(IA32, add, "\x01\xc4\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %eax, %ebp */
    AA_OPCODE(IA32, add, "\x01\xc5", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %eax, %esi */
    AA_OPCODE(IA32, add, "\x01\xc6", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %eax, %edi */
    AA_OPCODE(IA32, add, "\x01\xc7", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %ecx, %eax */
    AA_OPCODE(IA32, add, "\x01\xc8", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %ecx, %ecx */
    AA_OPCODE(IA32, add, "\x01\xc9", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %ecx, %edx */
    AA_OPCODE(IA32, add, "\x01\xca", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %ecx, %ebx */
    AA_OPCODE(IA32, add, "\x01\xcb", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %ecx, %esp */
    AA_OPCODE(IA32, add, "\x01\xcc\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %ecx, %ebp */
    AA_OPCODE(IA32, add, "\x01\xcd", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %ecx, %esi */
    AA_OPCODE(IA32, add, "\x01\xce", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %ecx, %edi */
    AA_OPCODE(IA32, add, "\x01\xcf", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %edx, %eax */
    AA_OPCODE(IA32, add, "\x01\xd0", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %edx, %ecx */
    AA_OPCODE(IA32, add, "\x01\xd1", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %edx, %edx */
    AA_OPCODE(IA32, add, "\x01\xd2", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %edx, %ebx */
    AA_OPCODE(IA32, add, "\x01\xd3", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %edx, %esp */
    AA_OPCODE(IA32, add, "\x01\xd4\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %edx, %ebp */
    AA_OPCODE(IA32, add, "\x01\xd5", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %edx, %esi */
    AA_OPCODE(IA32, add, "\x01\xd6", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %edx, %edi */
    AA_OPCODE(IA32, add, "\x01\xd7", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %ebx, %eax */
    AA_OPCODE(IA32, add, "\x01\xd8", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %ebx, %ecx */
    AA_OPCODE(IA32, add, "\x01\xd9", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %ebx, %edx */
    AA_OPCODE(IA32, add, "\x01\xda", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %ebx, %ebx */
    AA_OPCODE(IA32, add, "\x01\xdb", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %ebx, %esp */
    AA_OPCODE(IA32, add, "\x01\xdc\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %ebx, %ebp */
    AA_OPCODE(IA32, add, "\x01\xdd", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %ebx, %esi */
    AA_OPCODE(IA32, add, "\x01\xde", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %ebx, %edi */
    AA_OPCODE(IA32, add, "\x01\xdf", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %esp, %eax */
    AA_OPCODE(IA32, add, "\x01\xe0", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %esp, %ecx */
    AA_OPCODE(IA32, add, "\x01\xe1", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %esp, %edx */
    AA_OPCODE(IA32, add, "\x01\xe2", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %esp, %ebx */
    AA_OPCODE(IA32, add, "\x01\xe3", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %esp, %esp */
    AA_OPCODE(IA32, add, "\x01\xe4\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %esp, %ebp */
    AA_OPCODE(IA32, add, "\x01\xe5", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %esp, %esi */
    AA_OPCODE(IA32, add, "\x01\xe6", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %esp, %edi */
    AA_OPCODE(IA32, add, "\x01\xe7", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %ebp, %eax */
    AA_OPCODE(IA32, add, "\x01\xe8", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %ebp, %ecx */
    AA_OPCODE(IA32, add, "\x01\xe9", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %ebp, %edx */
    AA_OPCODE(IA32, add, "\x01\xea", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %ebp, %ebx */
    AA_OPCODE(IA32, add, "\x01\xeb", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %ebp, %esp */
    AA_OPCODE(IA32, add, "\x01\xec\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %ebp, %ebp */
    AA_OPCODE(IA32, add, "\x01\xed", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %ebp, %esi */
    AA_OPCODE(IA32, add, "\x01\xee", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %ebp, %edi */
    AA_OPCODE(IA32, add, "\x01\xef", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %esi, %eax */
    AA_OPCODE(IA32, add, "\x01\xf0", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %esi, %ecx */
    AA_OPCODE(IA32, add, "\x01\xf1", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %esi, %edx */
    AA_OPCODE(IA32, add, "\x01\xf2", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %esi, %ebx */
    AA_OPCODE(IA32, add, "\x01\xf3", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %esi, %esp */
    AA_OPCODE(IA32, add, "\x01\xf4\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %esi, %ebp */
    AA_OPCODE(IA32, add, "\x01\xf5", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %esi, %esi */
    AA_OPCODE(IA32, add, "\x01\xf6", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %esi, %edi */
    AA_OPCODE(IA32, add, "\x01\xf7", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb %edi, %eax */
    AA_OPCODE(IA32, add, "\x01\xf8", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    /* addb %edi, %ecx */
    AA_OPCODE(IA32, add, "\x01\xf9", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ECX))),

    /* addb %edi, %edx */
    AA_OPCODE(IA32, add, "\x01\xfa", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDX))),

    /* addb %edi, %ebx */
    AA_OPCODE(IA32, add, "\x01\xfb", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBX))),

    /* addb %edi, %esp */
    AA_OPCODE(IA32, add, "\x01\xfc\x24", 3, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESP))),

    /* addb %edi, %ebp */
    AA_OPCODE(IA32, add, "\x01\xfd", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EBP))),

    /* addb %edi, %esi */
    AA_OPCODE(IA32, add, "\x01\xfe", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, ESI))),

    /* addb %edi, %edi */
    AA_OPCODE(IA32, add, "\x01\xff", 2, 1,
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EDI))),

    /* addb (%eax), %al */
    AA_OPCODE(IA32, add, "\x02\x00", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL))),

    /* addb (%eax), %cl */
    AA_OPCODE(IA32, add, "\x02\x01", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL))),

    /* addb (%eax), %dl */
    AA_OPCODE(IA32, add, "\x02\x02", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL))),

    /* addb (%eax), %bl */
    AA_OPCODE(IA32, add, "\x02\x03", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL))),

    /* addb (%eax), %ah */
    AA_OPCODE(IA32, add, "\x02\x04", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH))),

    /* addb (%eax), %ch */
    AA_OPCODE(IA32, add, "\x02\x05", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH))),

    /* addb (%eax), %dh */
    AA_OPCODE(IA32, add, "\x02\x06", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH))),

    /* addb (%eax), %bh */
    AA_OPCODE(IA32, add, "\x02\x07", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH))),

    /* addb (%ecx), %al */
    AA_OPCODE(IA32, add, "\x02\x08", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL))),

    /* addb (%ecx), %cl */
    AA_OPCODE(IA32, add, "\x02\x09", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL))),

    /* addb (%ecx), %dl */
    AA_OPCODE(IA32, add, "\x02\x0a", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL))),

    /* addb (%ecx), %bl */
    AA_OPCODE(IA32, add, "\x02\x0b", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL))),

    /* addb (%ecx), %ah */
    AA_OPCODE(IA32, add, "\x02\x0c", 3, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH))),

    /* addb (%ecx), %ch */
    AA_OPCODE(IA32, add, "\x02\x0d", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH))),

    /* addb (%ecx), %dh */
    AA_OPCODE(IA32, add, "\x02\x0e", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH))),

    /* addb (%ecx), %bh */
    AA_OPCODE(IA32, add, "\x02\x0f", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH))),

    /* addb (%edx), %al */
    AA_OPCODE(IA32, add, "\x02\x10", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL))),

    /* addb (%edx), %cl */
    AA_OPCODE(IA32, add, "\x02\x11", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL))),

    /* addb (%edx), %dl */
    AA_OPCODE(IA32, add, "\x02\x12", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL))),

    /* addb (%edx), %bl */
    AA_OPCODE(IA32, add, "\x02\x13", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL))),

    /* addb (%edx), %ah */
    AA_OPCODE(IA32, add, "\x02\x14", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH))),

    /* addb (%edx), %ch */
    AA_OPCODE(IA32, add, "\x02\x15", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH))),

    /* addb (%edx), %dh */
    AA_OPCODE(IA32, add, "\x02\x16", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH))),

    /* addb (%edx), %bh */
    AA_OPCODE(IA32, add, "\x02\x17", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH))),

    /* addb (%ebx), %al */
    AA_OPCODE(IA32, add, "\x02\x18", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL))),

    /* addb (%ebx), %cl */
    AA_OPCODE(IA32, add, "\x02\x19", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL))),

    /* addb (%ebx), %dl */
    AA_OPCODE(IA32, add, "\x02\x1a", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL))),

    /* addb (%ebx), %bl */
    AA_OPCODE(IA32, add, "\x02\x1b", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL))),

    /* addb (%ebx), %ah */
    AA_OPCODE(IA32, add, "\x02\x1c", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH))),

    /* addb (%ebx), %ch */
    AA_OPCODE(IA32, add, "\x02\x1d", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH))),

    /* addb (%ebx), %dh */
    AA_OPCODE(IA32, add, "\x02\x1e", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH))),

    /* addb (%ebx), %bh */
    AA_OPCODE(IA32, add, "\x02\x1f", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH))),

    /* addb (%esp), %al */
    AA_OPCODE(IA32, add, "\x02\x20\x24", 3, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL))),

    /* addb (%esp), %cl */
    AA_OPCODE(IA32, add, "\x02\x21\x24", 3, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL))),

    /* addb (%esp), %dl */
    AA_OPCODE(IA32, add, "\x02\x22\x24", 3, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL))),

    /* addb (%esp), %bl */
    AA_OPCODE(IA32, add, "\x02\x23\x24", 3, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL))),

    /* addb (%esp), %ah */
    AA_OPCODE(IA32, add, "\x02\x24\x24", 3, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH))),

    /* addb (%esp), %ch */
    AA_OPCODE(IA32, add, "\x02\x25\x24", 3, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH))),

    /* addb (%esp), %dh */
    AA_OPCODE(IA32, add, "\x02\x26\x24", 3, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH))),

    /* addb (%esp), %bh */
    AA_OPCODE(IA32, add, "\x02\x27\x24", 3, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH))),

    /* addb (%ebp), %al */
    AA_OPCODE(IA32, add, "\x02\x28", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL))),

    /* addb (%ebp), %cl */
    AA_OPCODE(IA32, add, "\x02\x29", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL))),

    /* addb (%ebp), %dl */
    AA_OPCODE(IA32, add, "\x02\x2a", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL))),

    /* addb (%ebp), %bl */
    AA_OPCODE(IA32, add, "\x02\x2b", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL))),

    /* addb (%ebp), %ah */
    AA_OPCODE(IA32, add, "\x02\x2c", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH))),

    /* addb (%ebp), %ch */
    AA_OPCODE(IA32, add, "\x02\x2d", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH))),

    /* addb (%ebp), %dh */
    AA_OPCODE(IA32, add, "\x02\x2e", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH))),

    /* addb (%ebp), %bh */
    AA_OPCODE(IA32, add, "\x02\x2f", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH))),

    /* addb (%esi), %al */
    AA_OPCODE(IA32, add, "\x02\x30", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL))),

    /* addb (%esi), %cl */
    AA_OPCODE(IA32, add, "\x02\x31", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL))),

    /* addb (%esi), %dl */
    AA_OPCODE(IA32, add, "\x02\x32", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL))),

    /* addb (%esi), %bl */
    AA_OPCODE(IA32, add, "\x02\x33", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL))),

    /* addb (%esi), %ah */
    AA_OPCODE(IA32, add, "\x02\x34", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH))),

    /* addb (%esi), %ch */
    AA_OPCODE(IA32, add, "\x02\x35", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH))),

    /* addb (%esi), %dh */
    AA_OPCODE(IA32, add, "\x02\x36", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH))),

    /* addb (%esi), %bh */
    AA_OPCODE(IA32, add, "\x02\x37", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH))),

    /* addb (%edi), %al */
    AA_OPCODE(IA32, add, "\x02\x38", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL))),

    /* addb (%edi), %cl */
    AA_OPCODE(IA32, add, "\x02\x39", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL))),

    /* addb (%edi), %dl */
    AA_OPCODE(IA32, add, "\x02\x3a", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL))),

    /* addb (%edi), %bl */
    AA_OPCODE(IA32, add, "\x02\x3b", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL))),

    /* addb (%edi), %ah */
    AA_OPCODE(IA32, add, "\x02\x3c", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH))),

    /* addb (%edi), %ch */
    AA_OPCODE(IA32, add, "\x02\x3d", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH))),

    /* addb (%edi), %dh */
    AA_OPCODE(IA32, add, "\x02\x3e", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH))),

    /* addb (%edi), %bh */
    AA_OPCODE(IA32, add, "\x02\x3f", 2, 0,
        AA_OPCODE_OPERAND(AAMemoryFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH))),

    /* addb n(%eax), %al */
    AA_OPCODE(IA32, add, "\x02\x40", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, AL))),

    /* addb n(%eax), %cl */
    AA_OPCODE(IA32, add, "\x02\x41", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, CL))),

    /* addb n(%eax), %dl */
    AA_OPCODE(IA32, add, "\x02\x42", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, DL))),

    /* addb n(%eax), %bl */
    AA_OPCODE(IA32, add, "\x02\x43", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, BL))),

    /* addb n(%eax), %ah */
    AA_OPCODE(IA32, add, "\x02\x44", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, AH))),

    /* addb n(%eax), %ch */
    AA_OPCODE(IA32, add, "\x02\x45", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, CH))),

    /* addb n(%eax), %dh */
    AA_OPCODE(IA32, add, "\x02\x46", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, DH))),

    /* addb n(%eax), %bh */
    AA_OPCODE(IA32, add, "\x02\x47", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, EAX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, BH))),

    /* addb n(%ecx), %al */
    AA_OPCODE(IA32, add, "\x02\x48", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, AL))),

    /* addb n(%ecx), %cl */
    AA_OPCODE(IA32, add, "\x02\x49", 2, 1,
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, CL))),

    /* addb n(%ecx), %dl */
    AA_OPCODE(IA32, add, "\x02\x4a", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL))),

    /* addb n(%ecx), %bl */
    AA_OPCODE(IA32, add, "\x02\x4b", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL))),

    /* addb n(%ecx), %ah */
    AA_OPCODE(IA32, add, "\x02\x4c", 3, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH))),

    /* addb n(%ecx), %ch */
    AA_OPCODE(IA32, add, "\x02\x4d", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH))),

    /* addb n(%ecx), %dh */
    AA_OPCODE(IA32, add, "\x02\x4e", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH))),

    /* addb n(%ecx), %bh */
    AA_OPCODE(IA32, add, "\x02\x4f", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ECX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH))),

    /* addb n(%edx), %al */
    AA_OPCODE(IA32, add, "\x02\x50", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL))),

    /* addb n(%edx), %cl */
    AA_OPCODE(IA32, add, "\x02\x51", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL))),

    /* addb n(%edx), %dl */
    AA_OPCODE(IA32, add, "\x02\x52", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL))),

    /* addb n(%edx), %bl */
    AA_OPCODE(IA32, add, "\x02\x53", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL))),

    /* addb n(%edx), %ah */
    AA_OPCODE(IA32, add, "\x02\x54", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH))),

    /* addb n(%edx), %ch */
    AA_OPCODE(IA32, add, "\x02\x55", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH))),

    /* addb n(%edx), %dh */
    AA_OPCODE(IA32, add, "\x02\x56", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH))),

    /* addb n(%edx), %bh */
    AA_OPCODE(IA32, add, "\x02\x57", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH))),

    /* addb n(%ebx), %al */
    AA_OPCODE(IA32, add, "\x02\x58", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL))),

    /* addb n(%ebx), %cl */
    AA_OPCODE(IA32, add, "\x02\x59", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL))),

    /* addb n(%ebx), %dl */
    AA_OPCODE(IA32, add, "\x02\x5a", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL))),

    /* addb n(%ebx), %bl */
    AA_OPCODE(IA32, add, "\x02\x5b", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL))),

    /* addb n(%ebx), %ah */
    AA_OPCODE(IA32, add, "\x02\x5c", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH))),

    /* addb n(%ebx), %ch */
    AA_OPCODE(IA32, add, "\x02\x5d", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH))),

    /* addb n(%ebx), %dh */
    AA_OPCODE(IA32, add, "\x02\x5e", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH))),

    /* addb n(%ebx), %bh */
    AA_OPCODE(IA32, add, "\x02\x5f", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBX)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH))),

    /* addb n(%esp), %al */
    AA_OPCODE(IA32, add, "\x02\x60\x24", 3, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL))),

    /* addb n(%esp), %cl */
    AA_OPCODE(IA32, add, "\x02\x61\x24", 3, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL))),

    /* addb n(%esp), %dl */
    AA_OPCODE(IA32, add, "\x02\x62\x24", 3, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL))),

    /* addb n(%esp), %bl */
    AA_OPCODE(IA32, add, "\x02\x63\x24", 3, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL))),

    /* addb n(%esp), %ah */
    AA_OPCODE(IA32, add, "\x02\x64\x24", 3, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH))),

    /* addb n(%esp), %ch */
    AA_OPCODE(IA32, add, "\x02\x65\x24", 3, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH))),

    /* addb n(%esp), %dh */
    AA_OPCODE(IA32, add, "\x02\x66\x24", 3, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH))),

    /* addb n(%esp), %bh */
    AA_OPCODE(IA32, add, "\x02\x67\x24", 3, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH))),

    /* addb n(%ebp), %al */
    AA_OPCODE(IA32, add, "\x02\x68", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL))),

    /* addb n(%ebp), %cl */
    AA_OPCODE(IA32, add, "\x02\x69", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL))),

    /* addb n(%ebp), %dl */
    AA_OPCODE(IA32, add, "\x02\x6a", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL))),

    /* addb n(%ebp), %bl */
    AA_OPCODE(IA32, add, "\x02\x6b", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL))),

    /* addb n(%ebp), %ah */
    AA_OPCODE(IA32, add, "\x02\x6c", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH))),

    /* addb n(%ebp), %ch */
    AA_OPCODE(IA32, add, "\x02\x6d", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH))),

    /* addb n(%ebp), %dh */
    AA_OPCODE(IA32, add, "\x02\x6e", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH))),

    /* addb n(%ebp), %bh */
    AA_OPCODE(IA32, add, "\x02\x6f", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EBP)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH))),

    /* addb n(%esi), %al */
    AA_OPCODE(IA32, add, "\x02\x70", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL))),

    /* addb n(%esi), %cl */
    AA_OPCODE(IA32, add, "\x02\x71", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL))),

    /* addb n(%esi), %dl */
    AA_OPCODE(IA32, add, "\x02\x72", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL))),

    /* addb n(%esi), %bl */
    AA_OPCODE(IA32, add, "\x02\x73", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL))),

    /* addb n(%esi), %ah */
    AA_OPCODE(IA32, add, "\x02\x74", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH))),

    /* addb n(%esi), %ch */
    AA_OPCODE(IA32, add, "\x02\x75", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH))),

    /* addb n(%esi), %dh */
    AA_OPCODE(IA32, add, "\x02\x76", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH))),

    /* addb n(%esi), %bh */
    AA_OPCODE(IA32, add, "\x02\x77", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, ESI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH))),

    /* addb n(%edi), %al */
    AA_OPCODE(IA32, add, "\x02\x78", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL))),

    /* addb n(%edi), %cl */
    AA_OPCODE(IA32, add, "\x02\x79", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CL))),

    /* addb n(%edi), %dl */
    AA_OPCODE(IA32, add, "\x02\x7a", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DL))),

    /* addb n(%edi), %bl */
    AA_OPCODE(IA32, add, "\x02\x7b", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BL))),

    /* addb n(%edi), %ah */
    AA_OPCODE(IA32, add, "\x02\x7c", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AH))),

    /* addb n(%edi), %ch */
    AA_OPCODE(IA32, add, "\x02\x7d", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, CH))),

    /* addb n(%edi), %dh */
    AA_OPCODE(IA32, add, "\x02\x7e", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, DH))),

    /* addb n(%edi), %bh */
    AA_OPCODE(IA32, add, "\x02\x7f", 2, 1,
        AA_OPCODE_OPERAND(AAMemoryOffsetFromRegister32Operand, AA_OPCODE_REGISTER(IA32, EDI)),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, BH))),

    /* %*a* shortcuts */

    /* addb $n, %al */
    AA_OPCODE(IA32, add, "\x04", 1, 1,
        AA_OPCODE_OPERAND(AAScalarOperand, AANone),
        AA_OPCODE_OPERAND(AARegister8Operand, AA_OPCODE_REGISTER(IA32, AL))),

    /* addw $n, %ax */
    AA_OPCODE(IA32, add, "\x05", 1, 2,
        AA_OPCODE_OPERAND(AAScalarOperand, AANone),
        AA_OPCODE_OPERAND(AARegister16Operand, AA_OPCODE_REGISTER(IA32, AX))),

    /* addl $n, %eax */
    AA_OPCODE(IA32, add, "\x05", 1, 4,
        AA_OPCODE_OPERAND(AAScalarOperand, AANone),
        AA_OPCODE_OPERAND(AARegister32Operand, AA_OPCODE_REGISTER(IA32, EAX))),

    AA_OPCODES_END
};

const AAOpcodeList AA_IA32_Opcodes[] = {
    AA_NEW_OPCODELIST(IA32, mov),
    AA_NEW_OPCODELIST(IA32, add),

    AA_OPCODELIST_END
};

