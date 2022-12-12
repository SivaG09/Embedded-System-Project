#include<reg51.h>
sbit RS= P3^5;
sbit RW= P3^6;
sbit EN= P3^7;
void delays();
void LCDcommand(unsigned char mydata);
void LCDdis(unsigned char *s);
void LCDdata(unsigned char mydata);
void LCDinit();
void LCDinit()
{
	 LCDcommand(0x38);
	 LCDcommand(0x01);
	 LCDcommand(0x06);
   LCDcommand(0x0E);
	 LCDcommand(0x80);
}


void LCDcommand(unsigned char mydata)
  {
     RS =0;
     RW= 0;
     P1= mydata;
     EN=1;
     delays();
	   EN=0;
}
	
void LCDdata(unsigned char lcddata)
  {
	    RS =1;
      RW= 0;
      P1 = lcddata;
      EN=1;
      delays();
	    EN=0;
	}

void LCDdis(unsigned char *s)
{    while(*s)
	{
     LCDdata(*s++);
  } 
}

void delays()
{
 unsigned int q;
	for(q=0;q<1000;q++);
}

