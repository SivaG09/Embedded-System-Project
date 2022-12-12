#include<reg51.h>
sbit r1=P2^0;
sbit r2=P2^1;
sbit r3=P2^2;
sbit r4=P2^3;
sbit c1=P2^4;
sbit c2=P2^5;
sbit c3=P2^6;
unsigned char keypad();
void delay(unsigned int ms);
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