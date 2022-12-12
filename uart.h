#include<reg51.h>
void sendUART(unsigned char UARTdata)
{
  TI=0;
	SBUF=UARTdata;
	while(TI==0);
}
unsigned char receiveUART(void)
{
	unsigned char mydata;
	while(RI==0);
	mydata = SBUF;
	RI =0;
}

void UARTinit()
{
  TMOD=0x21;
	TH1= 253;
	TL1= 253;
	SCON =0x50;
	TR1 = 1;
}
