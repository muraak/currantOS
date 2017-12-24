
#include "serial.h"

#define MAX_LENGTH 4096
#define DUMMY 0

void PutByte(uint08 b)
{
	AuxMiniUartPutByte(b);
}

void PutChar(char c)
{
	if(c == '\n') {
		AuxMiniUartPutByte((uint08)'\r');
	}

	AuxMiniUartPutByte((uint08)c);

}

uint32 PutString(char * c, uint32 len)
{
	int32 i;

	for(i = 0; i < len; i++) {

		if(i > MAX_LENGTH - 1) return 1;
		if(c[i] == '\0') return 2;

		PutChar(c[i]);
	}

	return 0;
}

int08 GetChar()
{
	int08 c;

	c = AuxMiniUartGetByte();

	c = (c == '\r') ? '\n' : c;

	PutChar(c);

	return c;
}

uint32 GetString(char * buf, uint32 len)
{
	uint32 i;
	int08 c;

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
