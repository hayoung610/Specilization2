#include <SoftwareSerial.h>

String receive;

short xBeeTx = 11;
short xBeeRx = 12;

SoftwareSerial xBeeSerial ( xBeeRx , xBeeTx ) ;
void setup () {
Serial.begin (9600) ;
xBeeSerial.begin (9600) ;
}
void loop () {
if ( xBeeSerial.available () > 0) {
receive = xBeeSerial.readStringUntil('\n');
int receiveInt = receive.toInt();
Serial.println ( receiveInt ) ; // print out the received integer in the serial monitor
}
}
