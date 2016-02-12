#pragma once
#include "mbed.h"
#include <string.h>
#include "motion.h"

DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);

class BTC
{
public:
    BTC():master(USBTX, USBRX)
    {
        master.baud(9600);
        master.attach(this,&BTC::pc_tx,Serial::RxIrq);
    }
    
private:
    Serial master;
	Motion robot;
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
        if(strcmp(a,"test")==0){
        	myled1=0;
            myled2=1;
            myled3=1;
            myled4=0;
        	robot.walk();
        	ledinit();
        }
        else if(strcmp(a,"r")==0)
        {
            myled1=0;
            myled2=0;
            myled3=1;
            myled4=1;
            robot.walkLeft();
        	ledinit();
        }
        else if(strcmp(a,"y")==0)
        {
            myled1=1;
            myled2=1;
            myled3=0;
            myled4=0;
            robot.walkRight();
            ledinit();
        }
        else if(strcmp(a,"f")==0)
        {
            myled1=0;
            myled2=0;
            myled3=0;
            myled4=1;
            robot.turnL();
            ledinit();
        }
        else if(strcmp(a,"h")==0)
        {
            myled1=1;
            myled2=0;
            myled3=0;
            myled4=0;
            robot.turnR();
            ledinit();
        }
        else if(strcmp(a,"b")==0)
        {
            myled1=1;
            myled2=0;
            myled3=0;
            myled4=1;
            robot.back();
            ledinit();
        }
        else if(strcmp(a,"g")==0)
        {
            myled1=0;
            myled2=0;
            myled3=0;
            myled4=0;
            robot.init();
            ledinit();
        }
        
    }
};
