/**
 * The files in this directory and elsewhere which refer to this LICENCE
 * file are part of ElfShark, the library for disassembling/assembling
 * binary code.
 *
 * Copyright (C) 2009 meh. and BlackLight [http://meh.doesntexist.org]
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

#include <stdio.h>
#include <string.h>
#include "elfshark.h"
#include "elfshark_private.h"

int
es_op_scal8 (char* op, u8 code[], u8 len, char* buf, u8 buflen, u8 opts)
{
    char reg[8];

    if (len < 2) {
        return -1;
    }

    if (code[0] == 0x04) {
        if (ES_IS_INTEL(opts)) {
            snprintf(buf+strlen(buf), buflen-strlen(buf), "%s\tal, 0x%x\n", op, code[1]);
        }
        else {
            snprintf(buf+strlen(buf), buflen-strlen(buf), "%s\t$0x%x, al\n", op, code[1]);
        }

        return 0;
    }

    switch ((code[0] & 0xf8) >> 3) {
        case 0x16:
            es_get_dstreg8(code[0], reg, sizeof(reg), opts);
            
            if (ES_IS_INTEL(opts)) {
                snprintf(buf+strlen(buf), buflen-strlen(buf), "%s\t%s,0x%x\n", op, reg, code[1]);
            }
            else {
                snprintf(buf+strlen(buf), buflen-strlen(buf), "%s\t$0x%x,%s\n", op, code[1], reg);
            }
        break;
    }

    return 0;
}

int op_reg8 (char *op, u8 code[], u8 len, char buf[], u8 buflen, u8 opts)  {
    char srcreg[8], dstreg[8];

    if (len < 2) return -1;

    get_srcreg8 (code[1], srcreg, sizeof(srcreg), opts);

    if ((code[0] & 0x3) == 0x0)  {
        get_dstreg8 (code[1], dstreg, sizeof(dstreg), opts);

        if ((opts & 0x1) == INTEL_FLAVOR)
            snprintf (buf+strlen(buf), buflen-strlen(buf), "%s\t%s,%s\n", op, dstreg, srcreg);
        else
            snprintf (buf+strlen(buf), buflen-strlen(buf), "%s\t%s,%s\n", op, srcreg, dstreg);
    } else if ((code[0] & 0x3) == 0x2)  {
        get_dstreg (code[1], dstreg, sizeof(dstreg), opts);

        if ((opts & 0x1) == INTEL_FLAVOR)
            snprintf (buf+strlen(buf), buflen-strlen(buf), "%s\t%s,[%s]\n", op, srcreg, dstreg);
        else
            snprintf (buf+strlen(buf), buflen-strlen(buf), "%s\t(%s),%s\n", op, dstreg, srcreg);
    }

    return 0;
}

