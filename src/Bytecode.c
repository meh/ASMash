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

#include "asmash.h"
#include "Bytecode.h"
#include "private/Bytecode.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

AABytecode*
AA_NewBytecode (const char* code, unsigned int length)
{
    AABytecode* result = (AABytecode*) malloc(sizeof(AABytecode));
    result->data       = code;
    result->length     = length;

    return result;
}

AABytecode*
AA_NewBytecodeFromFile (const char* path)
{
    return NULL;
}

char*
AA_BytecodeToASM (AABytecode* code, unsigned int initAddr, AAOptions flags)
{
    unsigned int i;
    unsigned int increment    = 0
    unsigned int bufferLength = 0;
    char*        buffer       = NULL;
    char         line[AA_DECODE_LINESIZE];

    if (initAddr == 0) {
        initAddr = 0x08048000;
    }

    for (i = 0; i < AA_GetBytecodeLength(code); i++) {
        increment = 0;
        memset(line, 0, AA_DECODE_LINESIZE);

        switch (AA_GetBytecodeByte(code, i)) {
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

                if ((code[i+1] & 0x07)      == AA_ESP) increment++;
                if ((code[i+1] & 0xc0) >> 6 == 0x01)   increment++;
                
                if ((code[i+1] & 0xc0) >> 6 == 0x10) {
                    aa_Bytecode_Unknown(&(code[i]), 1, line, AA_DECODE_LINESIZE, flags);
                    bufferLength += strlen(line);
                    buffer        = (char*) realloc(buffer, bufferLenght);
                    sprintf(buffer, "%s%s", buffer, line);
                    continue;
                }

                switch (code[i])  {
                    case 0x01:
                        op_reg32 ("add", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0x09:
                        op_reg32 ("or",  code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0x11:
                        op_reg32 ("adc", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0x19:
                        op_reg32 ("sbb", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0x21:
                    case 0x25:
                        op_reg32 ("and", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0x29:
                        op_reg32 ("sub", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0x31:
                        op_reg32 ("xor", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0x39:
                        op_reg32 ("cmp", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0x85:
                        op_reg32 ("test", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0x86:
                        op_reg32 ("xchg", code+i, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_8); break;
                    case 0x87:
                        op_reg32 ("xchg", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0x89:
                        if ((code[i+1] & 0x7) == 0x5) increment = 5;
                        op_reg32 ("mov", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0xa1:
                    case 0xa3:
                        increment = 4;
                        op_reg32 ("mov", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                }
        
                break;

            case 0x03:
            case 0x0b:
            case 0x13:
            case 0x1b:
            case 0x23:
            case 0x2b:
            case 0x33:
            case 0x3b:
            case 0x8b:
                increment = 1;

                if ((code[i+1] & 0x07) == ES_ESP) increment++;
                if ((code[i+1] & 0xc0) >> 6 == 0x1) increment++;
                
                if ((code[i+1] & 0xc0) >> 6 == 0x10)  {
                    unknown (&(code[i]), 1, line, AA_DECODE_LINESIZE, flags);
                    buflen += strlen(line);
                    buf = (char*) realloc(buf, buflen);
                    sprintf (buf, "%s%s", buf, line);
                    continue;
                }

                switch (code[i])  {
                    case 0x03:
                        op_reg32_inv ("add", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0x0b:
                        op_reg32_inv ("or",  code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0x13:
                        op_reg32_inv ("adc", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0x1b:
                        op_reg32_inv ("sbb", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0x23:
                        op_reg32_inv ("and", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0x2b:
                        op_reg32_inv ("sub", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0x33:
                        op_reg32_inv ("xor", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0x3b:
                        op_reg32_inv ("cmp", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0x8b:
                        if ((code[i+1] & 0x7) == 0x5) increment = 5;
                        op_reg32_inv ("mov", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                }
        
                break;

            case 0xb8:
            case 0xb9:
            case 0xba:
            case 0xbb:
            case 0xbc:
            case 0xbd:
            case 0xbe:
            case 0xbf:
                increment = 4;
                op_scal32 ("mov", code+i, increment+1, line, AA_DECODE_LINESIZE, flags);
                break;

            case 0x81:
                increment = 5;
                op_scal81 (code+i, increment+1, line, AA_DECODE_LINESIZE, flags);
                break;

            case 0x83:
                increment = 2;
                op_scal83 (code+i, increment+1, line, AA_DECODE_LINESIZE, flags);
                break;

            case 0x27:
            case 0x2f:
            case 0x37:
            case 0x60:
            case 0x61:
            case 0x90:
            case 0x91:
            case 0x92:
            case 0x93:
            case 0x94:
            case 0x95:
            case 0x96:
            case 0x97:
            case 0x98:
            case 0x99:
            case 0x9b:
            case 0x9c:
            case 0x9d:
            case 0x9e:
            case 0x9f:
            case 0xc3:
            case 0xc9:
            case 0xcb:
            case 0xce:
            case 0xcf:
            case 0xf4:
            case 0xf5:
            case 0xf8:
            case 0xf9:
            case 0xfa:
            case 0xfb:
            case 0xfc:
            case 0xfd:
                single_op (code[i], line, AA_DECODE_LINESIZE, flags);
                break;

            case 0xcd:
                interrupt (code+i, 2, line, AA_DECODE_LINESIZE, flags);
                increment = 1;
                break;

            case 0x66:
                if ((code[i+1] & 0xf0) == 0x50)  {
                    increment = 1;

                    ( ((code[i+1] & 0x4) >> 3) == 0x0 )
                        ? op_pushpop ("push", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16)
                        : op_pushpop ("pop" , code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16);

                    break;
                }

                increment = 2;

                if ((code[i+2] & 0x07) == ES_ESP) increment++;
                if ((code[i+2] & 0xc0) >> 6 == 0x1) increment++;
                
                if ((code[i+2] & 0xc0) >> 6 == 0x10)  {
                    unknown (&(code[i]), 1, line, AA_DECODE_LINESIZE, flags);
                    buflen += strlen(line);
                    buf = (char*) realloc(buf, buflen);
                    sprintf (buf, "%s%s", buf, line);
                    continue;
                }

                switch (code[i+1])  {
                    case 0x01:
                        op_reg32 ("add", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    case 0x09:
                        op_reg32 ("or",  code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    case 0x11:
                        op_reg32 ("adc", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    case 0x19:
                        op_reg32 ("sbb", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    case 0x21:
                        op_reg32 ("and", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    case 0x29:
                        op_reg32 ("sub", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    case 0x31:
                        op_reg32 ("xor", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    case 0x39:
                        op_reg32 ("cmp", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;

                    case 0x40:
                    case 0x41:
                    case 0x42:
                    case 0x43:
                    case 0x44:
                    case 0x45:
                    case 0x46:
                    case 0x47:
                    case 0x48:
                    case 0x49:
                    case 0x4a:
                    case 0x4b:
                    case 0x4c:
                    case 0x4d:
                    case 0x4e:
                    case 0x4f:
                        increment = 1;
                        op_incdec (code+i, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16);
                        break;

                    case 0x85:
                        op_reg32 ("test", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    case 0x87:
                        op_reg32 ("xchg", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    case 0x89:
                        op_reg32 ("mov", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    
                    case 0x03:
                        op_reg32_inv ("add", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    case 0x0b:
                        op_reg32_inv ("or",  code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    case 0x13:
                        op_reg32_inv ("adc", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    case 0x1b:
                        op_reg32_inv ("sbb", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    case 0x23:
                        op_reg32_inv ("and", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    case 0x2b:
                        op_reg32_inv ("sub", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    case 0x33:
                        op_reg32_inv ("xor", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    case 0x3b:
                        op_reg32_inv ("cmp", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    case 0x8b:
                        op_reg32_inv ("mov", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                    case 0x8d:
                    case 0xc4:
                    case 0xc5:
                        if ((code[i+2] & 0xc0) == 0x00)
                            increment = 2;
                        else if ((code[i+2] & 0xc0) == 0x40)
                            increment = 3;

                        if ((code[i+2] & 0x07) == 0x04)
                            increment++;

                        switch (code[i+1])  {
                            case 0x8d:
                                op_lea32 ("lea", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                            case 0xc4:
                                op_lea32 ("les", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                            case 0xc5:
                                op_lea32 ("lds", code+i+1, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16); break;
                        }

                        break;

                    case 0xe4:
                    case 0xe5:
                    case 0xe6:
                    case 0xe7:
                    case 0xec:
                    case 0xed:
                    case 0xee:
                    case 0xef:
                        if ((code[i+1] >= 0xe4) && (code[i+1] <= 0xe7))
                            increment = 2;
                        else
                            increment = 1;

                        op_inout (code+i, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16);
                        break;

                    case 0xf6:
                    case 0xf7:
                        increment = 2;

                        if (code[i+2] >= 0xd0 && code[i+2] <= 0xd7)
                            op_notneg ("not", code+i, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16);
                        else if (code[i+2] >= 0xd8 && code[i+2] <= 0xdf)
                            op_notneg ("neg", code+i, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16);
                        else if (code[i+2] >= 0xe0 && code[i+2] <= 0xe7)
                            op_muldiv ("mul", code+i, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16);
                        else if (code[i+2] >= 0xe8 && code[i+2] <= 0xef)
                            op_muldiv ("imul", code+i, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16);
                        else if (code[i+2] >= 0xf0 && code[i+2] <= 0xf7)
                            op_muldiv ("div", code+i, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16);
                        else if (code[i+2] >= 0xf8)
                            op_muldiv ("idiv", code+i, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_16);
                        break;
                }
        
                break;

            case 0x70:
            case 0x71:
            case 0x72:
            case 0x73:
            case 0x74:
            case 0x75:
            case 0x76:
            case 0x77:
            case 0x78:
            case 0x79:
            case 0x7a:
            case 0x7b:
            case 0x7c:
            case 0x7d:
            case 0x7e:
            case 0x7f:
            case 0xe0:
            case 0xe1:
            case 0xe2:
            case 0xe8:
            case 0xe9:
            case 0xeb:
                switch (code[i])  {
                    case 0xe0:
                        increment = 1;
                        op_jmp ("loopne", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags);
                        break;

                    case 0xe1:
                        increment = 1;
                        op_jmp ("loope", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags);
                        break;

                    case 0xe2:
                        increment = 1;
                        op_jmp ("loop", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags);
                        break;

                    case 0xe9:
                    case 0xeb:
                        increment = (code[i] == 0xeb) ? 1 : 4;
                        op_jmp ("jmp", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags);
                        break;

                    case 0xe8:
                        increment = 4;
                        op_jmp ("call", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags);
                        break;

                    case 0x70:
                        increment = 1;
                        op_jmp ("jo", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags); break;

                    case 0x71:
                        increment = 1;
                        op_jmp ("jno", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags); break;

                    case 0x72:
                        increment = 1;
                        op_jmp ("jb", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags); break;

                    case 0x73:
                        increment = 1;
                        op_jmp ("jae", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags); break;

                    case 0x74:
                        increment = 1;
                        op_jmp ("je", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags); break;

                    case 0x75:
                        increment = 1;
                        op_jmp ("jne", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags); break;

                    case 0x76:
                        increment = 1;
                        op_jmp ("jbe", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags); break;

                    case 0x77:
                        increment = 1;
                        op_jmp ("ja", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags); break;

                    case 0x78:
                        increment = 1;
                        op_jmp ("js", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags); break;

                    case 0x79:
                        increment = 1;
                        op_jmp ("jns", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags); break;

                    case 0x7a:
                        increment = 1;
                        op_jmp ("jp", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags); break;

                    case 0x7b:
                        increment = 1;
                        op_jmp ("jnp", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags); break;

                    case 0x7c:
                        increment = 1;
                        op_jmp ("jl", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags); break;

                    case 0x7d:
                        increment = 1;
                        op_jmp ("jge", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags); break;

                    case 0x7e:
                        increment = 1;
                        op_jmp ("jle", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags); break;

                    case 0x7f:
                        increment = 1;
                        op_jmp ("jg", code+i, increment+1, line, AA_DECODE_LINESIZE, initAddr + i + increment + 1, flags); break;
                }

                break;

            case 0x50:
            case 0x51:
            case 0x52:
            case 0x53:
            case 0x54:
            case 0x55:
            case 0x56:
            case 0x57:
            case 0x58:
            case 0x59:
            case 0x5a:
            case 0x5b:
            case 0x5c:
            case 0x5d:
            case 0x5e:
            case 0x5f:
                ( ((code[i] & 0x4) >> 3) == 0x0 )
                    ? op_pushpop ("push", code+i, increment+1, line, AA_DECODE_LINESIZE, flags)
                    : op_pushpop ("pop" , code+i, increment+1, line, AA_DECODE_LINESIZE, flags);

                break;

            case 0x68:
                increment = 4;
                op_pushpop ("push", code+i, increment+1, line, AA_DECODE_LINESIZE, flags);
                break;

            case 0xff:
                switch ((code[i+1] & 0xc0) >> 6)  {
                    case 0x1:
                        increment = ((code[i+1] & 0x7) == 0x4) ? 3 : 2;
                        break;

                    default:
                        increment = ((code[i+1] & 0x7) == 0x4) ? 2 : 1;
                        break;
                }

                switch ((code[i+1] & 0x30) >> 4)  {
                    case 0x01:
                        op_jmp_ff ("call", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;

                    case 0x02:
                        op_jmp_ff ("jmp" , code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                }

                break;

            case 0x04:
            case 0xb0:
            case 0xb1:
            case 0xb2:
            case 0xb3:
            case 0xb4:
            case 0xb5:
            case 0xb6:
            case 0xb7:
                increment = 1;

                if (code[i] == 0x04)  {
                    op_scal8 ("add", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                }

                op_scal8 ("mov", code+i, increment+1, line, AA_DECODE_LINESIZE, flags);
                break;

            case 0x00:
            case 0x02:
            case 0x08:
            case 0x0a:
            case 0x10:
            case 0x12:
            case 0x18:
            case 0x1a:
            case 0x20:
            case 0x22:
            case 0x28:
            case 0x2a:
            case 0x30:
            case 0x32:
            case 0x38:
            case 0x3a:
            case 0x84:
            case 0x88:
            case 0x8a:
                increment = 1;

                switch (code[i])  {
                    case 0x00:
                    case 0x02:
                    case 0x04:
                        op_reg8 ("add", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;

                    case 0x08:
                    case 0x0a:
                        op_reg8 ("or", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;

                    case 0x10:
                    case 0x12:
                        op_reg8 ("adc", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;

                    case 0x18:
                    case 0x1a:
                        op_reg8 ("sbb", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;

                    case 0x20:
                    case 0x22:
                        op_reg8 ("sbb", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;

                    case 0x28:
                    case 0x2a:
                        op_reg8 ("sub", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;

                    case 0x30:
                    case 0x32:
                        op_reg8 ("xor", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;

                    case 0x38:
                    case 0x3a:
                        op_reg8 ("cmp", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;

                    case 0x84:
                        op_reg8 ("test", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;

                    case 0x88:
                    case 0x8a:
                        op_reg8 ("mov", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                }

                break;

            case 0x40:
            case 0x41:
            case 0x42:
            case 0x43:
            case 0x44:
            case 0x45:
            case 0x46:
            case 0x47:
            case 0x48:
            case 0x49:
            case 0x4a:
            case 0x4b:
            case 0x4c:
            case 0x4d:
            case 0x4e:
            case 0x4f:
                op_incdec (&(code[i]), 1, line, AA_DECODE_LINESIZE, flags);
                break;

            case 0xfe:
                increment = 1;

                if ((code[i+1] & 0xc0) == 0xc0)
                    op_incdec (code+i, increment+1, line, AA_DECODE_LINESIZE, flags|ES_BITS_8);
                break;

            case 0x8d:
            case 0xc4:
            case 0xc5:
                if ((code[i+1] & 0xc0) == 0x00)
                    increment = 1;
                else if ((code[i+1] & 0xc0) == 0x40)
                    increment = 2;

                if ((code[i+1] & 0x07) == 0x04)
                    increment++;

                switch (code[i])  {
                    case 0x8d:
                        op_lea32 ("lea", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0xc4:
                        op_lea32 ("les", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                    case 0xc5:
                        op_lea32 ("lds", code+i, increment+1, line, AA_DECODE_LINESIZE, flags); break;
                }

                break;

            case 0xe4:
            case 0xe5:
            case 0xe6:
            case 0xe7:
            case 0xec:
            case 0xed:
            case 0xee:
            case 0xef:
                if ((code[i] >= 0xe4) && (code[i] <= 0xe7))
                    increment = 1;
                else
                    increment = 0;

                op_inout (code+i, increment+1, line, AA_DECODE_LINESIZE, flags);
                break;

            case 0x0f:
                if (code[i+1] == 0xa2)  {
                    increment = 1;
                    snprintf (line, AA_DECODE_LINESIZE, "cpuid\n");
                }

                break;

            case 0xf6:
            case 0xf7:
                increment = 1;

                if (code[i+1] >= 0xd0 && code[i+1] <= 0xd7)
                    op_notneg("not", code+i, increment+1, line, AA_DECODE_LINESIZE, (code[i] == 0xf6) ? flags | ES_BITS_8 : flags);
                else if (code[i+1] >= 0xd8 && code[i+1] <= 0xdf)
                    op_notneg("neg", code+i, increment+1, line, AA_DECODE_LINESIZE, (code[i] == 0xf6) ? flags | ES_BITS_8 : flags);
                else if (code[i+1] >= 0xe0 && code[i+1] <= 0xe7)
                    op_muldiv("mul", code+i, increment+1, line, AA_DECODE_LINESIZE, flags | ES_BITS_16);
                else if (code[i+1] >= 0xe8 && code[i+1] <= 0xef)
                    op_muldiv("imul", code+i, increment+1, line, AA_DECODE_LINESIZE, flags | ES_BITS_16);
                else if (code[i+1] >= 0xf0 && code[i+1] <= 0xf7)
                    op_muldiv("div", code+i, increment+1, line, AA_DECODE_LINESIZE, flags | ES_BITS_16);
                else if (code[i+1] >= 0xf8)
                    op_muldiv("idiv", code+i, increment+1, line, AA_DECODE_LINESIZE, flags | ES_BITS_16);
                break;

            case 0xc1:
            case 0xd1:
                increment = (code[i] == 0xc1) ? 2 : 1;

                if (code[i+1] >= 0xc0 && code[i+1] <= 0xc7)
                    op_rotsh ("rol", code+i, increment+1, line, AA_DECODE_LINESIZE, flags);
                else if (code[i+1] >= 0xc8 && code[i+1] <= 0xcf)
                    op_rotsh ("ror", code+i, increment+1, line, AA_DECODE_LINESIZE, flags);
                else if (code[i+1] >= 0xd0 && code[i+1] <= 0xd7)
                    op_rotsh ("rcl", code+i, increment+1, line, AA_DECODE_LINESIZE, flags);
                else if (code[i+1] >= 0xd8 && code[i+1] <= 0xdf)
                    op_rotsh ("rcr", code+i, increment+1, line, AA_DECODE_LINESIZE, flags);
                else if (code[i+1] >= 0xe0 && code[i+1] <= 0xe7)
                    op_rotsh ("shl", code+i, increment+1, line, AA_DECODE_LINESIZE, flags);
                else if (code[i+1] >= 0xe8 && code[i+1] <= 0xef)
                    op_rotsh ("shr", code+i, increment+1, line, AA_DECODE_LINESIZE, flags);
                else if (code[i+1] >= 0xf0 && code[i+1] <= 0xf7)
                    op_rotsh ("sal", code+i, increment+1, line, AA_DECODE_LINESIZE, flags);
                else if (code[i+1] >= 0xf8)
                    op_rotsh ("sar", code+i, increment+1, line, AA_DECODE_LINESIZE, flags);
                break;

            default:
                unknown (&(code[i]), 1, line, AA_DECODE_LINESIZE, flags);
                break;
        }
        
        buflen += strlen(line);
        buf = (char*) realloc(buf, buflen);
        sprintf (buf, "%s%s", buf, line);
        i += increment;
    }

    return buf;
}

void
aa_Bytecode_GetSourceRegister (unsigned char code, char* sourceRegister, unsigned int length, AAOptions flags)
{
    if (AA_IS_8BITS(bits)) {
        switch ((code & 0x38) >> 3)  {
            case EAX:
                if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "eax");
                else snprintf (srcreg, len, "%%eax");
            break;

        case ECX:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "ecx");
            else snprintf (srcreg, len, "%%ecx");
            break;

        case EDX:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "edx");
            else snprintf (srcreg, len, "%%edx");
            break;

        case EBX:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "ebx");
            else snprintf (srcreg, len, "%%ebx");
            break;

        case ESP:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "esp");
            else snprintf (srcreg, len, "%%esp");
            break;

        case EBP:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "ebp");
            else snprintf (srcreg, len, "%%ebp");
            break;

        case ESI:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "esi");
            else snprintf (srcreg, len, "%%esi");
            break;

        case EDI:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "edi");
            else snprintf (srcreg, len, "%%edi");
            break;
    }
}

void get_dstreg (u8 code, char dstreg[], u8 len, u8 opts)  {
    switch (code & 0x07)  {
        case EAX:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "eax");
            else snprintf (dstreg, len, "%%eax");
            break;

        case ECX:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "ecx");
            else snprintf (dstreg, len, "%%ecx");
            break;

        case EDX:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "edx");
            else snprintf (dstreg, len, "%%edx");
            break;

        case EBX:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "ebx");
            else snprintf (dstreg, len, "%%ebx");
            break;

        case ESP:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "esp");
            else snprintf (dstreg, len, "%%esp");
            break;

        case EBP:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "ebp");
            else snprintf (dstreg, len, "%%ebp");
            break;

        case ESI:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "esi");
            else snprintf (dstreg, len, "%%esi");
            break;

        case EDI:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "edi");
            else snprintf (dstreg, len, "%%edi");
            break;
    }
}

void get_srcreg16 (u8 code, char srcreg[], u8 len, u8 opts)  {
    switch ((code & 0x38) >> 3)  {
        case AX:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "ax");
            else snprintf (srcreg, len, "%%ax");
            break;

        case CX:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "cx");
            else snprintf (srcreg, len, "%%cx");
            break;

        case DX:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "dx");
            else snprintf (srcreg, len, "%%dx");
            break;

        case BX:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "bx");
            else snprintf (srcreg, len, "%%bx");
            break;

        case SP:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "sp");
            else snprintf (srcreg, len, "%%sp");
            break;

        case BP:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "bp");
            else snprintf (srcreg, len, "%%bp");
            break;

        case SI:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "si");
            else snprintf (srcreg, len, "%%si");
            break;

        case DI:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "di");
            else snprintf (srcreg, len, "%%di");
            break;
    }
}

void get_dstreg8 (u8 code, char dstreg[], u8 len, u8 opts)  {
    switch (code & 0x07)  {
        case AL:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "al");
            else snprintf (dstreg, len, "%%al");
            break;

        case CL:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "cl");
            else snprintf (dstreg, len, "%%cl");
            break;

        case DL:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "dl");
            else snprintf (dstreg, len, "%%dl");
            break;

        case BL:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "bl");
            else snprintf (dstreg, len, "%%bl");
            break;

        case AH:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "ah");
            else snprintf (dstreg, len, "%%ah");
            break;

        case CH:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "ch");
            else snprintf (dstreg, len, "%%ch");
            break;

        case DH:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "dh");
            else snprintf (dstreg, len, "%%dh");
            break;

        case BH:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "bh");
            else snprintf (dstreg, len, "%%bh");
            break;
    }
}


void get_dstreg16 (u8 code, char dstreg[], u8 len, u8 opts)  {
    switch (code & 0x07)  {
        case AX:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "ax");
            else snprintf (dstreg, len, "%%ax");
            break;

        case CX:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "cx");
            else snprintf (dstreg, len, "%%cx");
            break;

        case DX:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "dx");
            else snprintf (dstreg, len, "%%dx");
            break;

        case BX:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "bx");
            else snprintf (dstreg, len, "%%bx");
            break;

        case SP:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "sp");
            else snprintf (dstreg, len, "%%sp");
            break;

        case BP:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "bp");
            else snprintf (dstreg, len, "%%bp");
            break;

        case SI:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "si");
            else snprintf (dstreg, len, "%%si");
            break;

        case DI:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (dstreg, sizeof(dstreg), "di");
            else snprintf (dstreg, len, "%%di");
            break;
    }
}

void get_srcreg8 (u8 code, char srcreg[], u8 len, u8 opts)  {
    switch ((code & 0x38) >> 3)  {
        case AL:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "al");
            else snprintf (srcreg, len, "%%al");
            break;

        case CL:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "cl");
            else snprintf (srcreg, len, "%%cl");
            break;

        case DL:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "dl");
            else snprintf (srcreg, len, "%%dl");
            break;

        case BL:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "bl");
            else snprintf (srcreg, len, "%%bl");
            break;

        case AH:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "ah");
            else snprintf (srcreg, len, "%%ah");
            break;

        case CH:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "ch");
            else snprintf (srcreg, len, "%%ch");
            break;

        case DH:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "dh");
            else snprintf (srcreg, len, "%%dh");
            break;

        case BH:
            if ((opts & 0x1) == INTEL_FLAVOR) snprintf (srcreg, sizeof(srcreg), "bh");
            else snprintf (srcreg, len, "%%bh");
            break;
    }
}


int interrupt (u8 code[], u8 len, char buf[], u8 buflen, u8 opts)  {
    if (len < 2) return -1;

    if ((opts & 0x1) == INTEL_FLAVOR) snprintf (buf, buflen, "int\t%xh\n", code[1]);
    else snprintf (buf, buflen, "int\t$0x%x\n", code[1]);
    return 0;
}

int op_inout (u8 code[], u8 len, char buf[], u8 buflen, u8 opts)  {
    u8 op, off_index;

    if (opts & BITS_16)  {
        if (code[0] != 0x66 && len < 2) return -1;
        op = code[1];
        off_index = 2;
    } else {
        if (len < 1) return -1;
        op = code[0];
        off_index = 1;
    }

    switch (op)  {
        case 0xe4:
            if ((opts & 0x1) == INTEL_FLAVOR)
                snprintf (buf, buflen, "in\tal,0x%x\n", code[off_index]);
            else
                snprintf (buf, buflen, "in\t$0x%x,%%al\n", code[off_index]);
            break;

        case 0xe5:
            if ((opts & 0x1) == INTEL_FLAVOR)
                snprintf (buf, buflen, "in\t%s,0x%x\n",
                        (opts & BITS_16) ? "ax" : "eax", code[off_index]);
            else
                snprintf (buf, buflen, "in\t$0x%x,%s\n",
                        code[off_index], (opts & BITS_16) ? "%%ax" : "%%eax");
            break;

        case 0xe6:
            if ((opts & 0x1) == INTEL_FLAVOR)
                snprintf (buf, buflen, "out\t0x%x,al\n", code[off_index]);
            else
                snprintf (buf, buflen, "out\t%%al,$0x%x\n", code[off_index]);
            break;

        case 0xe7:
            if ((opts & 0x1) == INTEL_FLAVOR)
                snprintf (buf, buflen, "out\t0x%x,%s\n",
                        code[off_index], (opts & BITS_16) ? "ax" : "eax");
            else
                snprintf (buf, buflen, "out\t%s,$0x%x\n",
                        (opts & BITS_16) ? "%%ax" : "%%eax", code[off_index]);
            break;

        case 0xec:
            if ((opts & 0x1) == INTEL_FLAVOR)
                snprintf (buf, buflen, "in\tal,dx\n");
            else
                snprintf (buf, buflen, "in\t(%%dx),%%al\n");
            break;

        case 0xed:
            if ((opts & 0x1) == INTEL_FLAVOR)
                snprintf (buf, buflen, "in\t%s,dx\n",
                        (opts & BITS_16) ? "ax" : "eax");
            else
                snprintf (buf, buflen, "in\t(%%dx),%s\n",
                        (opts & BITS_16) ? "%%ax" : "%%eax");
            break;

        case 0xee:
            if ((opts & 0x1) == INTEL_FLAVOR)
                snprintf (buf, buflen, "out\tdx,al\n");
            else
                snprintf (buf, buflen, "out\t(%%al),%%dx\n");
            break;

        case 0xef:
            if ((opts & 0x1) == INTEL_FLAVOR)
                snprintf (buf, buflen, "out\tdx,%s\n",
                        (opts & BITS_16) ? "ax" : "eax");
            else
                snprintf (buf, buflen, "out\t(%s),%%dx\n",
                        (opts & BITS_16) ? "%%ax" : "%%eax");
            break;
    }

    return 0;
}

void aa_Bytecode_Unknown (u8 code[], u8 len, char buf[], u8 buflen, u8 opts)  {
    int i;
    memset(buf, 0, buflen);

    for (i = 0; i < length; i++) {
        sprintf(buf, "%s.byte\t%.2x\n", buf, code[i]);
    }
}


