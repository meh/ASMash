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

#include "Instruction.h"
#include "Archs/api.h"
#include "private/Instruction.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AAInstruction*
AA_NewInstruction (const char* name, unsigned int opcode, unsigned int offset, AAInstructionOperand* source, AAInstructionOperand* dest)
{
    AAInstruction* result;

    if (name == NULL || strlen(name) == 0) {
        return NULL;
    }
    
    result         = (AAInstruction*) malloc(sizeof(AAInstruction));
    result->name   = strdup(name);
    result->opcode = opcode;
    result->offset = offset;
    result->source = source;
    result->dest   = dest;

    return result;
}

void
AA_DestroyInstruction (AAInstruction* instruction)
{
    free(instruction->name);

    if (instruction->source) {
        AA_DestroyInstructionOperand(instruction->source)
    }

    if (instruction->dest) {
        AA_DestroyInstructionOperand(instruction->dest);
    }

    free(instruction);
}

AAInstruction*
AA_ParseInstruction (const char* arch, AABytecode* bytecode, unsigned int* offset)
{
    return AA_ArchDispatch(arch, bytecode, offset);
}

AAInstruction*
AA_ParseInstructionIA32 (AABytecode* bytecode, unsigned int* offset)
{
    AAInstruction*  result    = (AAInstruction*) malloc(sizeof(AAInstruction));
    unsigned int    increment = 0;

    switch (AA_GetBytecodeByte(bytecode, 0)) {
        case 0x01:
        case 0x09:
        case 0x11:
        case 0x19:
        case 0x21:
        case 0x25:
        case 0x29:
        case 0x31:
        case 0x39:
        case 0x85:
        case 0x86:
        case 0x87:
        case 0x89:
        case 0xa1:
        case 0xa3:
            increment = 1;

            if ((code[i+1] & 0x07)      == aaESP) increment++;
            if ((code[i+1] & 0xc0) >> 6 == 0x01)  increment++;

            if ((code[i+1] & 0xc0) >> 6 == 0x10) {
                result->name[0] = '\0';
            }
        break;

    }

    return result;
}

AAInstruction*
AA_ParseInstructionAMD64 (AABytecode* bytecode, unsigned int* offset)
{
    return NULL;
}

AAInstruction*
AA_ParseInstructionPPC (AABytecode* bytecode, unsigned int* offset)
{
    return NULL;
}

