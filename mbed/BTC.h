#pragma once
#include "mbed.h"
#include <string.h>
#include "KRS2552.h"
#include "motion.h"
Motion robot;

DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);

class BTC
{
public:
    BTC():master(USBTX, USBRX/*p28,p27*/)
    {
        //pc.baud(9600);
        master.baud(9600);
        master.attach(this,&BTC::pc_tx,Serial::RxIrq);
        myled1=1;
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
    
    void ledinit(){
        myled1=0;
        myled2=0;
        myled3=0;
        myled4=0;
    }
    
    void pc_tx()
    {
        memset(a,'\0',sizeof(a));
        master.scanf("%9s",a);
        char c = 0;//master.getc();
        if(strcmp(a,"test")==0){
            myled1=0;
            myled2=1;
            myled3=1;
            myled4=0;
        }
        else if(c=='t')
        {
            //pc.printf("walk\r\n");
            myled1=0;
            myled2=1;
            myled3=1;
            myled4=0;
            robot.walk();
            ledinit();
        }
        //else if(strcmp(a,"r")==0)
        else if(c == 'r')
        {
            //pc.printf("walk left\r\n");
            myled1=0;
            myled2=0;
            myled3=1;
            myled4=1;
            robot.walkLeft();
            ledinit();
            
        }
        //else if(strcmp(a,"y")==0)
        else if(c == 'y')
        {
            //pc.printf("walk right\r\n");
            myled1=1;
            myled2=1;
            myled3=0;
            myled4=0;
            robot.walkRight();
            ledinit();
        }
        //else if(strcmp(a,"f")==0)
        else if(c == 'f')
        {
            //pc.printf("turn left\r\n");
            myled1=0;
            myled2=0;
            myled3=0;
            myled4=1;
            robot.turnL();
            ledinit();
        }
        //else if(strcmp(a,"h")==0)
        else if(c == 'h')
        {
            //pc.printf("turn right\r\n");
            myled1=1;
            myled2=0;
            myled3=0;
            myled4=0;
            robot.turnR();
            ledinit();
        }
        //else if(strcmp(a,"b")==0)
        else if(c == 'b')
        {
            //pc.printf("back\r\n");
            myled1=1;
            myled2=0;
            myled3=0;
            myled4=1;
            robot.back();
            ledinit();
        }
        //else if(strcmp(a,"g")==0)
        else if(c == 'g')
        {
            //pc.printf("init\r\n");
            myled1=0;
            myled2=0;
            myled3=0;
            myled4=0;
            robot.init();
            ledinit();
        }
        
    }
};
