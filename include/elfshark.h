/**
 * The files in this directory and elsewhere which refer to this LICENCE
 * file are part of ElfShark, the library for disassembling/assembling
 * binary code.
 *
 * Copyright (C) 2009 BlackLight and meh. [http://meh.doesntexist.org]
 *
 * ElfShark is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 3 or (at your option) any later 
 * version.
 *
 * ElfShark is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with ElfShark; if not, write to the Free Software Foundation, Inc.,
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

#ifndef	__ELFSHARK_H
#define	__ELFSHARK_H

#define	ES_INTEL_FLAVOR	    0x01
#define	ES_AT_FLAVOR		0x02

#define ES_IS_INTEL(flags) ((flags & ES_INTEL_FLAVOUR) == ES_INTEL_FLAVOUR)
#define ES_IS_AT(flags)    ((flags & ES_AT_FLAVOUR) == ES_AT_FLAVOUR)

#define	ES_DISP_BINARY	    0x04
#define	ES_BITS_16		    0x08
#define	ES_BITS_8		    0x10

#include "Code.h"

unsigned char* ES_GetExecutableElfCode (char* fileName, int* codeSize, int* addr);
char* ES_DecodeToAsm (ESCode* code, unsigned char code[], unsigned int len, unsigned int initAddr, ESFlags opts);

#endif

