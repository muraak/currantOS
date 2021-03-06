#include "console.h"
#include "serial.h"
#include "interrupts.h"

#define COMMAND_READY() ConsoleWrite("currantOS> ", 11)

void ConsoleInit()
{
	SerialInit();
	COMMAND_READY();
}

INT32 ConsoleWrite(CHAR * string, UINT32 len)
{
	return PutString(string, len);
}

INT32 ConsoleWriteLine(CHAR * string, UINT32 len)
{
	INT32 result;

	if((result = PutString(string, len)) != 0){ return result; }
	
	PutChar('\n');

	return 0;
}

INT32 ConsoleRead(CHAR * string, UINT32 len)
{
	return GetString(string, len);
}

void ConsoleOnReceived(CHAR * line)
{
	ConsoleWriteLine("unknown.", 8);
	COMMAND_READY();	
}
