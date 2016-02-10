#pragma once
#include "mbed.h"
#include <string.h>
#include "KRS2552.h"

DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);

class BTC
{
public:
    BTC():master(p28,p27)
    {
        pc.baud(9600);
        master.baud(9600);
        master.attach(this,&BTC::pc_tx,Serial::RxIrq);
        myled1=0;
    }
    
    
    bool get_command(char *command)
    {
        if(strcmp(a,command)==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
private:
    Serial master;
    KRS2552 servo;
    char a[10];
    
    void pc_tx()
    {
        memset(a,'\0',sizeof(a));
        master.scanf("%9s",a);
        /*
        if(strcmp(a,"1")==0)
        {
            pc.printf("1\r\n");
            myled1=1;
            myled2=0;
            myled3=0;
            myled4=0;
        }
        else if(strcmp(a,"2")==0)
        {
            pc.printf("2\r\n");
            myled1=0;
            myled2=1;
            myled3=0;
            myled4=0;
        }
        else if(strcmp(a,"3")==0)
        {
            pc.printf("3\r\n");
            myled1=0;
            myled2=0;
            myled3=1;
            myled4=0;
        }
        else if(strcmp(a,"4")==0)
        {
            pc.printf("4\r\n");
            myled1=0;
            myled2=0;
            myled3=0;
            myled4=1;
        }
        else if(strcmp(a,"5")==0)
        {
            servo.angle(5,-50);
        }
        else if(strcmp(a,"6")==0)
        {
            servo.angle(5,50);
        }
        */
    }
};