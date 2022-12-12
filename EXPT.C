#include<reg51.h>
sbit LED = P3^1;
sbit IN1 = P3^2;
sbit IN2 = P3^3;
sbit EN1 = P3^4;
sbit r1=P2^0;
sbit r2=P2^1;
sbit r3=P2^2;
sbit r4=P2^3;
sbit c1=P2^4;
sbit c2=P2^5;
sbit c3=P2^6;
sbit RS= P3^5;
sbit RW= P3^6;
sbit EN= P3^7;
char pass[] = {"5555"};
unsigned char key[3];
unsigned char keypad();
void delay(unsigned int ms);
void LCDcommand(unsigned char mydata);
void LCDdis(unsigned char *s);
void LCDdata(unsigned char mydata);
void LCDinit();
void check();
void main(){
	LCDinit();
	while(1)
	  { 
	    unsigned int i=0;
			LCDcommand(0x81);
			LED=0;
			LCDdis("Enter Password:");
			delay(500);
			LCDcommand(0xC5);
			while(pass[i]!='\0')
			 {
			   key[i] = keypad();
				 delay(500);
				 i++;
			 }
			 check();
	  }
}

void check()
 {
   if(pass[0]==key[0] &&  pass[1]==key[1] && pass[2]==key[2] && pass[3]==key[3])
	 {
	   delay(500);
		 LCDcommand(0x01);
		 LCDcommand(0x81);
		 LCDdis("CORRECT");
		 delay(700);
		 LCDcommand(0xc1);
		 LCDdis("LOCK OPENED");
		 LED =1;
		 EN1=1;
		 IN1=1;
		 IN2=0;
		 delay(1000);
		 EN1=0;
		 LED=0;
		 LCDcommand(0x01);
	 }
	 else
	 {
	   LCDcommand(0x01);
		 LCDcommand(0X84);
		 LCDdis("INCORRECT");
		 delay(500);
		 LCDcommand(0X01);
	 }
	 }
 
unsigned char keypad()
		{
		 int x=0;
		 while(x==0)
		 {
		 r1=0;r2=1;r3=1;r4=1;
     if(c1==0)
        {
          LCDdata('*');
          delay(500);
					x=1;
					return '1';
        } 
          if(c2==0)
        {
          LCDdata('*');
          delay(500);
					x=1;
					return '2';
        } 
				     if(c3==0)
        {
          LCDdata('*');
          delay(500);
					x=1;
					return '3';
        } 
				r1=1;r2=0;r3=1;r4=1;
				     if(c1==0)
        {
          LCDdata('*');
          delay(500);
					x=1;
					return '4';
        } 
				     if(c2==0)
        {
          LCDdata('*');
          delay(500);
					x=1;
					return '5';
        } 
				     if(c3==0)
        {
          LCDdata('*');
          delay(500);
					x=1;
					return '6';
        } 
				
				r1=1;r2=1;r3=0;r4=1;
				     if(c1==0)
        {
          LCDdata('*');
          delay(500);
					x=1;
					return '7';
        } 
				     if(c2==0)
        {
          LCDdata('*');
          delay(500);
					x=1;
					return '8';
        } 
				     if(c3==0)
        {
          LCDdata('*');
          delay(500);
					x=1;
					return '9';
        } 
				
				r1=1;r2=1;r3=1;r4=0;
				     if(c1==0)
        {
          LCDdata('*');
					delay(500);
					x=1;
					return '*';
        } 
				     if(c2==0)
        {
          LCDdata('*');
					delay(500);
					x=1;
					return '0';
        } 
				     if(c3==0)
        {
          LCDdata('*');
          delay(500);
					x=1;
					return '#';
        }
			}
		return x;
		}
	

void delay(unsigned int ms)
{ int i;
	for(i=0;i<ms;i++)
	 {
		 TMOD=0X01;
		 TL0=0X66;
		 TH0=0XFC;
		 TF0=0;
		 TR0=1;
		 while(TF0==0);
	}
}

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
     delay(50);
	   EN=0;
}
	
void LCDdata(unsigned char lcddata)
  {
	    RS =1;
      RW= 0;
      P1 = lcddata;
      EN=1;
      delay(50);
	    EN=0;
	}

void LCDdis(unsigned char *s)
{    while(*s)
	{
     LCDdata(*s++);
  } 
}

