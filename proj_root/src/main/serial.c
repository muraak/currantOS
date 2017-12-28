
#include "serial.h"

#define MAX_LENGTH 4096
#define DUMMY 0

void SerialInit()
{
	AuxMiniUartInit(115200, 8);
}

void PutByte(BYTE b)
{
	AuxMiniUartPutByte(b);
}

void PutChar(CHAR c)
{
	if(c == '\n') {
		AuxMiniUartPutByte((BYTE)'\r');
	}

	AuxMiniUartPutByte((BYTE)c);

}

UINT32 PutString(CHAR * c, UINT32 len)
{
	UINT32 i;

	for(i = 0; i < len; i++) {

		if(i > MAX_LENGTH - 1) return 1;
		if(c[i] == '\0') return 2;

		PutChar(c[i]);
	}

	return 0;
}

CHAR GetChar()
{
	CHAR c;

	c = AuxMiniUartGetByte();

	c = (c == '\r') ? '\n' : c;

	PutChar(c);

	return c;
}

UINT32 GetString(CHAR * buf, UINT32 len)
{
	UINT32 i;
	CHAR c;

	for(i = 0; i < len; i++) {
		
		if(i > MAX_LENGTH - 1) return 1;

		c = GetChar();

		if(c == '\n') {
			buf[i] = '\0';
			return 0;
		}

		buf[i] = c;
	}

	return 0;

}
