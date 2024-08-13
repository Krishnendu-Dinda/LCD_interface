#include<reg51.h>
#define DATA P2

unsigned int i,j,k,l,m;

sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;

unsigned char name[]={"Hii"};
unsigned char title[]={"LinkedIN"};
unsigned char title2[]={"Family"};

void delay(unsigned int x)
{

	for(i=0;i<x;i++)
		for(j=0;j<1275;j++);
}


void lcddata(unsigned char dat)
{

	DATA=dat;
	rs=1;
	rw=0;
	en=1;
	delay(1);
	en=0;
	
}

void lcdcmd(unsigned char comnd)
{
DATA=comnd;
	rs=0;
	rw=0;
	en=1;
	delay(1);
	en=0;
	
}


void main(){
while(1){
	lcdcmd(0x38);
	delay(150);
	lcdcmd(0x0E);
	delay(150);
	lcdcmd(0x01);
	delay(150);
	lcdcmd(0x06);
	delay(150);
	lcdcmd(0x80);
	delay(150);

	for(k=0;name[k]!=(0);k++){
	
	lcddata(name[k]);
	
	}
	delay(150);
	lcdcmd(0x01);
	delay(150);
	lcdcmd(0x80);
	delay(150);
	
	for(l=0;title[l]!=(0);l++){
	
	lcddata(title[l]);
	
	}
	delay(150);
	lcdcmd(0xC3);
	delay(150);
	
	for(m=0;title2[m]!=(0);m++){
	
	lcddata(title2[m]);
	
		}
	}
}

