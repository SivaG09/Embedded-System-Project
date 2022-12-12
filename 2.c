#include<reg51.h>
#include"lcd.h"
unsigned char mydata[3] = "PTU";
unsigned int i;
void main()
{
	LCDinit();
	while(1)
	{
	 LCDcommand(0X81);
		for(i=0;i<3;i++)
		{
		 LCDdata(mydata[i]);
		}
	  LCDcommand(0X01);
		delays();
	}
}