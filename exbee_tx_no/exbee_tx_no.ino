#include <SoftwareSerial.h>
int data = 23;
short xBeeTx = 11;
short xBeeRx = 12;
SoftwareSerial xBeeSerial(xBeeRx, xBeeTx);
void setup () {
xBeeSerial.begin(9600) ;
}
void loop () {
xBeeSerial.println ( data ) ;
delay (2000) ;
}
