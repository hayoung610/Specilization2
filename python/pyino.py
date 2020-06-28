import serial
import time
ser = serial.Serial ( 'COM9' , 9600)
receivestring = ser.readline () # ignore the first read in
while True :
		receivestring = ser.readline ().decode ( "utf-8" ) . strip () # read one line and convert bytes to a string
		receivelists = receivestring.split ( ',' )
		print(receivelists)
		time.sleep(1)