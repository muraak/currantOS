
#ifndef CONSOLE_H
#define CONSOLE_H

#include "type.h"

void  ConsoleInit(void);
INT32 ConsoleWrite(CHAR * string, UINT32 len);
INT32 ConsoleWriteLine(CHAR * string, UINT32 len);
INT32 ConsoleRead(CHAR * string, UINT32 len);

#endif
