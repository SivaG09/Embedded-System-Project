#include<reg51.h>
#include"lcd.h"
#include"keypad.h"
sbit LED = P3^1;
sbit IN1 = P3^2;
sbit IN2 = P3^3;
sbit EN1 = P3^4;
char pass[] = {"1234"};
unsigned char pin[3];
void check();
void main(){
	LCDinit();
	while(1)
	  { 
	    unsigned int i=0;
			LED=0;
			LCDcommand(0x81);
			LCDdis("ENTER PASSWORD:");
			delay(100);
			LCDcommand(0xC5);
			while(pass[i]!='\0')
			 {
			   pin[i] = keypad();
				 delay(50);
				 i++;
			 }
			 check();
	  }
}

void check()
 {
   if(pass[0]==pin[0] &&  pass[1]==pin[1] && pass[2]==pin[2] && pass[3]==pin[3])
	 {
	   delay(100);
		 LCDcommand(0x01);
		 LCDcommand(0x81);
		 LCDdis("VERIFIED");
		 delay(500);
		 LCDcommand(0xc1);
		 LCDdis("DOOR OPENED");
		 LED=1;
		 EN1=1;
		 IN1=1;
		 IN2=0;
		 delay(3000);
		 EN1=0;
		 LED=0;
		 LCDcommand(0x01);
	 }
	 else
	 {
	   LCDcommand(0x01);
		 LCDcommand(0X84);
		 LCDdis("PASSWORD");
	   LCDcommand(0xc3);
     LCDdis("INCORRECT");
		 delay(2000);
		 LCDcommand(0X01);
	 }
	 }

 
