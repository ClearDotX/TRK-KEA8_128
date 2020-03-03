#ifndef _SCI_V5_H
#define _SCI_V5_H


#include "lin.h"
#include "lin_cfg.h"
#include "lin_lld_sci.h"

void SCI_init(l_u16 baudrate);
void __SCI_init(l_u16 baudrate);

#endif