#include"reg52.h"
#include <intrins.h>

#define uint unsigned int
#define uchar unsigned char
   
uchar temp,aa,bb,temp,temp1,i;

uchar code table0[]={0xfe,0xfc,0xf8,0xf0,0xe0,0xc0,0x80,0x00};//P0-P7依次点亮
uchar code table1[]={0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff};//P0-P7依次熄灭
uchar code table2[]={0x7f,0x3f,0x1f,0x0f,0x07,0x03,0x01,0x00};//P7-P0依次点亮
uchar code table3[]={0x80,0xc0,0xe0,0xf0,0xf8,0xfc,0xfe,0xff};//P7-P0依次熄灭

void h();
void hh();
void hhh();
void hhhh();

void delay(uint z)//延时函数
{
 uint x,y;
 for(x=z;x>0;x--)
  for(y=110;y>0;y--);
}

void main()
{	 
    while(1)
    {
        hh();   
        h();
        hhh();
        hhhh();
    }
}

void h()
{
    for(aa=0;aa<3;aa++)
    {
        for(bb=0;bb<8;bb++)
        {
            P0=table0[bb];
            delay(50);
        }
        for(bb=0;bb<8;bb++)
        {
            P1=table0[bb];
            delay(50);
        }
        for(bb=0;bb<8;bb++)
        {
            P3=table0[bb];
            delay(50);
        }
        for(bb=0;bb<8;bb++)
        {
            P2=table0[bb];
            delay(50);
        }
        delay(50);
        for(bb=0;bb<8;bb++)
        {
            P0=table1[bb];
            delay(50);
        }
        for(bb=0;bb<8;bb++)
        {
            P1=table1[bb];
            delay(50);
        }
        for(bb=0;bb<8;bb++)
        {
            P3=table1[bb];
            delay(50);
        }
        for(bb=0;bb<8;bb++)
        {
            P2=table1[bb];
            delay(50);
        }
    }
    for(aa=0;aa<3;aa++)
    {
        for(bb=0;bb<8;bb++)
        {
            P2=table2[bb];
            delay(50);
        }
        for(bb=0;bb<8;bb++)
        {
            P3=table2[bb];
            delay(50);
        }
        for(bb=0;bb<8;bb++)
        {
            P1=table2[bb];
            delay(50);
        }
        for(bb=0;bb<8;bb++)
        {
            P0=table2[bb];
            delay(50);
        }
        
        delay(50);

        for(bb=0;bb<8;bb++)
        {
            P2=table3[bb];
            delay(50);
        }
        for(bb=0;bb<8;bb++)
        {
            P3=table3[bb];
            delay(50);
        }
        for(bb=0;bb<8;bb++)
        {
            P1=table3[bb];
            delay(50);
        }
        for(bb=0;bb<8;bb++)
        {
            P0=table3[bb];
            delay(50);
        }
    }
}

void hh()
{
    for(bb=0;bb<3;bb++)
    {
        for(aa=0;aa<8;aa++)
        {
            P0=table0[aa];
            P2=table2[aa];
            delay(100);
        }
        
        for(aa=0;aa<8;aa++)
        {
            P3=table2[aa];
            P1=table0[aa];
            delay(100);
        }
        
        for(aa=0;aa<8;aa++)
        {
            P2=table3[aa];
            P0=table1[aa];
            delay(100);
        }
        
        for(aa=0;aa<8;aa++)
        {
            P1=table1[aa];
            P3=table3[aa];
            delay(100);
        }
    } 
}

void hhh()
{
    for(bb=0;bb<10;bb++)
    {
        for(aa=0;aa<8;aa++)
        {
            P0=temp;
            temp=_crol_(temp,1);
            delay(40);
        }
        
        P0=0xff;
        
        for(aa=0;aa<8;aa++)
        {
            P1=temp;
            temp=_crol_(temp,1);
            delay(40);
        }
        
        P1=0xff;
        
        for(aa=0;aa<8;aa++)
        {
            P3=temp;
            temp=_crol_(temp,1);
            delay(40);
        }
            
        P3=0xff;
        
        for(aa=0;aa<8;aa++)
        {
            P2=temp;
            temp=_crol_(temp,1);
            delay(40);
        }
        
        P2=0xff;
    }  
}

void hhhh()
{
    for(aa=0;aa<30;aa++)
    {
        P0=P1=0x00;
        delay(100);
        P1=P0=0xff;
        P2=P3=0x00;
        delay(100);
        P2=P3=0xff;
    }
} 