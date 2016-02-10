#ifndef __KRS2552_H__
#define __KRS2552_H__

#include "mbed.h"

Serial pc(USBTX,USBRX);
SerialHalfDuplex master(p9,p10);

class KRS2552
{
public:
    KRS2552()
    {
        master.baud(115200);
        master.format(8,Serial::Even,1);
    
        pc.printf("init\r\n");
        wait(0.5);
    }
    
    int angle_raw(int id,int pos)
    {
        if(11500<pos)
        {
            pos=11500;
        }else if(pos<3500)
        {
            pos=3500;
        }
        int low=(pos&127);
        int high=((pos>>7)&127);
        master.putc(128|id);
        master.putc(high);
        master.putc(low);
        int a = master.getc();
        int b = master.getc();
        int c = master.getc();
        return ((b<<7)|c);
    }
    
    int angle(int id,int pos)
    {
        pos=30*pos+7500;
        if(11500<pos)
        {
            pos=11500;
        }else if(pos<3500)
        {
            pos=3500;
        }
        return angle_raw(id,pos);
    }
    
    int speed(int id, int sp)
    {
        master.putc(192|id);
        master.putc(2);
        master.putc(sp);
        int a=master.getc();
        int b=master.getc();
        int c=master.getc();
        return c;
    }
};

int readID()
{
    master.putc(0xFF);
    master.putc(0x00);
    master.putc(0x00);
    master.putc(0x00);
    int id = master.getc();
    return id & 31;
}

#endif