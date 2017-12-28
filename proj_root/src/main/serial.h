
#ifndef SERIAL_H
#define SERIAL_H

#include "type.h"
#include "aux.h"

void PutByte(BYTE b);
void PutChar(CHAR c);
UINT32 PutString(CHAR * c, UINT32 len);
CHAR GetChar();
UINT32 GetString(CHAR * buf, UINT32 len);

#endif
