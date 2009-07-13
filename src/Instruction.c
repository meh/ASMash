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

#include "Instruction.h"
#include "Arch/api.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AAInstruction*
AA_NewInstruction (const char* name, AAOpcode* opcode, AAAddress offset, AAInstructionOperand* source, AAInstructionOperand* dest)
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
    if (instruction->source) {
        AA_DestroyInstructionOperand(instruction->source);
    }

    if (instruction->dest) {
        AA_DestroyInstructionOperand(instruction->dest);
    }

    free(instruction);
}

AAInstruction*
AA_ParseInstruction (const char* arch, AABytecode* bytecode, AAAddress* offset)
{
    return AA_ArchDispatchBytecodeToInstruction(arch, bytecode, offset);
}

