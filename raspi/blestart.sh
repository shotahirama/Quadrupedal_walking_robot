#! /bin/sh

sdptool add --channel=22 SP
#sudo sh -c `rfcomm listen /dev/rfcomm0 22 &`
rfcomm listen /dev/rfcomm0 22 &
