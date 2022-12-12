#include<reg51.h>
sbit r1=P1^0;
sbit r2=P1^1;
sbit r3=P1^2;
sbit r4=P1^3;
sbit c1=P1^4;
sbit c2=P1^5;
sbit c3=P1^6;
sbit RS= P3^0;
sbit EN= P3^1;
sbit IN1 = P3^2;
sbit IN2 = P3^3;
sbit EN1 = P3^4;

unsigned char keypad();
void LCDcommand(unsigned char mydata);
void LCDdis(unsigned char *s);
void LCDdata(unsigned char lcddata);
void check();
void delay(unsigned int j);

unsigned char pass[] = {"2222"};
unsigned char pin[3];

void main()
{
   LCDcommand(0X0F);
	 LCDcommand(0X38);
	 LCDcommand(0X01);
	 LCDcommand(0X80);
	
	 while(1)
	  { LED=0;
	    unsigned int i=0;
			LCDcommand(0X80);
			LCDdis("ENTER PASSWORD:");
			delay(10000);
			LCDcommand(0XC0);
			while(pass[i]!='\0')
			 {
			   pin[i] = keypad();
				 delay(1000);
				 i++;
			 }
			 check();
	  }
}

void check()
 {
   if(pass[0]==pin[0] &&  pass[1]==pin[1] && pass[2]==pin[2] && pass[3]==pin[3])
	 {
	   delay(10000);
		 LCDcommand(0X01);
		 LCDcommand(0X81);
		 LCDdis("Password Verified");
		 delay(10000);
		 EN1=1;
		 IN1=1;
		 IN2=0;
		 LCDcommand(0Xc1);
		 LCDdis("LOCK OPENED");
		 delay(100000000);
		 EN1=0;
		 LCDcommand(0X01);
	 }
	 else
	 {
	   LCDcommand(0X01);
	   LCDcommand(0X83);
     LCDdis("INCORRECT PASSWORD");
     delay(100000);
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
          delay(1000);
          x=1;
					return '1';
        } 
          if(c2==0)
        {
          LCDdata('*');
          delay(1000);
          x=1;
					return '2';
        } 
				     if(c3==0)
        {
          LCDdata('1');
          delay(1000);
          x=1;
					return '3';
        } 
				r1=1;r2=0;r3=1;r4=1;
				     if(c1==0)
        {
          LCDdata('*');
          delay(1000);
          x=1;
					return '4';
        } 
				     if(c2==0)
        {
          LCDdata('*');
          delay(1000);
          x=1;
					return '5';
        } 
				     if(c3==0)
        {
          LCDdata('*');
          delay(1000);
          x=1;
					return '6';
        } 
				
				r1=1;r2=1;r3=0;r4=1;
				     if(c1==0)
        {
          LCDdata('*');
          delay(1000);
          x=1;
					return '7';
        } 
				     if(c2==0)
        {
          LCDdata('*');
          delay(1000);
          x=1;
					return '8';
        } 
				     if(c3==0)
        {
          LCDdata('*');
          delay(1000);
          x=1;
					return '9';
        } 
				
				r1=1;r2=1;r3=1;r4=0;
				     if(c1==0)
        {
          LCDdata('*');
          delay(1000);
          x=1;
					return '*';
        } 
				     if(c2==0)
        {
          LCDdata('*');
          delay(1000);
          x=1;
					return '0';
        } 
				     if(c3==0)
        {
          LCDdata('*');
          delay(1000);
          x=1;
					return '#';
        } 
			}
		}
	
		
		void LCDcommand(unsigned char mydata)
  {
     RS =0;
     RW= 0;
     P2= mydata;
     EN=1;
     delay(1000);
	   EN=0;
}
	
void LCDdata(unsigned char mydata)
  {
	    RS =1;
      RW= 0;
      P2 = mydata;
      EN=1;
      delay(1000);
	    EN=0;
	}

void LCDdis(unsigned char *s)
{    int k;
	   for(k=0;s[k]!='\0';k++)
	   {
        LCDdata(s[k]);
    }
		delay(1000); 
}

void delay(unsigned int j)
{ unsigned int a,b;
   for(a=0;a<j;a++)
   {
	  for(b-0;b<10;b++);  
	 }	 
 }