
#ifndef SERIAL_H
#define SERIAL_H

#include "type.h"
#include "aux.h"

void PutByte(uint08 b);
void PutChar(char c);
uint32 PutString(char * c, uint32 len);
int08 GetChar();
uint32 GetString(char * buf, uint32 len);

#endif
