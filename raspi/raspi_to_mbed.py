import serial
import time

def strcmp(ref,command):
	back_char = 1 if len(ref) > 1 else 0
	if ref[:len(command) - back_char] == command:
		return True
	else:
		return False

if __name__=="__main__":
	ser=serial.Serial("/dev/ttyACM0",9600)
	ser2 = serial.Serial("/dev/rfcomm0",timeout=0.1)
	try:
		while True:
			line=ser2.read(10)
			if len(line)>0:
				if strcmp(line,"1"):
					ser.write("test1\n")
				elif strcmp(line,"2"):
					ser.write("test2\n")
				elif strcmp(line,"3"):
					ser.write("test3\n")
				elif strcmp(line,"4"):
					ser.write("test4\n")
				else:
					ser.write("test5\n")
	except KeyboardInterrupt:
		print "keyboard interrupt"
		ser.close()
