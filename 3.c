#include<reg51.h>
sbit IN1=P3^2;
sbit IN2=P3^3;
sbit EN1=P3^4;
void delay();
void main()
{
	while(1)
	{
	 EN1=1;
	 IN1=1;
		IN2=0;
		delay();
			 EN1=1;
	 IN1=0;
		IN2=1;
		delay();
	}
}
void delay()
{
	unsigned int i;
  for (i=0;i<50000;i++);
}