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

#include "InstructionStream.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AAInstructionStream*
AA_NewInstructionStream (AABytecode* bytecode, const char* arch)
{
    AAInstructionStream* result;

    if (bytecode == NULL) {
        return NULL;
    }

    result               = (AAInstructionStream*) malloc(sizeof(AAInstructionStream));
    result->bytecode     = bytecode;
    result->instructions = 0;
    result->_offset      = 0;
    result->_arch        = (arch != NULL) ? strdup(arch) : AA_DEFAULT_ARCH;

    return result;
}

void
AA_DestroyInstructionStream (AAInstructionStream* stream)
{
    AA_DestroyBytecode(stream->bytecode);
    free(stream->_arch);

    free(stream);
}

AAInstruction*
AA_NextStreamInstruction (AAInstructionStream* stream)
{
    unsigned int   offset;
    AABytecode*    wrapper;
    AAInstruction* result;

    wrapper->data   = stream->bytecode->data   + stream->_offset;
    wrapper->length = stream->bytecode->length - stream->_offset;

    if (wrapper->length == 0) {
        return NULL;
    }

    result = AA_ParseInstruction (stream->_arch, wrapper, &offset);

    stream->_offset += offset;
    stream->instructions++;

    return result;
}

AABool
AA_ProcessInstructionStream (AAInstructionStream* stream, AABool (*callback)(AAInstruction*))
{
    AABool         result = AAFalse;
    AAInstruction* data;

    while ((data = AA_NextStreamInstruction(stream)) != NULL) {
        result = callback(data);

        AA_DestroyInstruction(data);

        if (!result) {
            break;
        }
    }

    return result;
}

