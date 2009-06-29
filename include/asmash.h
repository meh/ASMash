/**
 * The files in this directory and elsewhere which refer to this LICENCE
 * file are part of ElfShark, the library for disassembling/assembling
 * binary code.
 *
 * Copyright (C) 2009 BlackLight and meh.
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

#ifndef	__ASMASH_H
#define	__ASMASH_H

typedef unsigned char AAOptions;

#define	AA_INTEL_FLAVOR	    0x01
#define	AA_AT_FLAVOR		0x02

#define AA_IS_INTEL(flags) ((flags & AA_INTEL_FLAVOUR) == AA_INTEL_FLAVOUR)
#define AA_IS_AT(flags)    ((flags & AA_AT_FLAVOUR) == AA_AT_FLAVOUR)

#define	AA_DISP_BINARY	    0x04

#define	AA_BITS_8		    0x08
#define	AA_BITS_16		    0x10
#define AA_BITS_32          0x20

#define AA_IS_8BIT(flags)  ((flags & AA_BITS_8) == AA_BITS_8)
#define AA_IS_16BIT(flags) ((flags & AA_BITS_16) == AA_BITS_16)
#define AA_IS_32BIT(flags) ((flags & AA_BITS_32) == AA_BITS_32)

#include "Code.h"

#endif

