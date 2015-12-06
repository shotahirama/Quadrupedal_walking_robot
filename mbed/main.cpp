#include "motion.h"

Motion robot;

int main()
{
    while(1) {
        for(int i = 0; i < 4; i++) {
            robot.walk();
        }
        for(int i = 0; i < 12; i++) {
            robot.turn();
        }

    }
    return 0;
}