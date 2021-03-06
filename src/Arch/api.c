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

#include "types.h"
#include "Arch/api.h"

#include <string.h>

#include "Arch/IA32/api.h"

#define AA_NEW_ARCH(name) { #name, &AA_## name ##_BytecodeToInstruction, &AA_## name ##_InstructionToBytecode }
#define AA_END_ARCHS { 0, 0, 0 }

#define AA_ARCH_IA32 0

const AAArch AAArchs[] = {
    AA_NEW_ARCH(IA32),

    AA_END_ARCHS
};

AAInstruction*
AA_ArchDispatchBytecodeToInstruction (const char* arch, AABytecode* bytecode, AAAddress* offset)
{
    AAArch* Archs = (AAArch*) AAArchs;
    AAArch* Arch;

    while ((Arch = Archs++) != NULL) {
        if (strcmp(Arch->name, arch)) {
            return Arch->BytecodeToInstruction(bytecode, offset);
        }
    }

    return NULL;
}

AABytecode*
AA_ArchDispatchInstructionToBytecode (const char* arch, AAInstruction* instruction, AAAddress* offset)
{
    AAArch* Archs = (AAArch*) AAArchs;
    AAArch* Arch;

    while ((Arch = Archs++) != NULL) {
        if (strcmp(Arch->name, arch)) {
            return Arch->InstructionToBytecode(instruction, offset);
        }
    }

    return NULL;
}

