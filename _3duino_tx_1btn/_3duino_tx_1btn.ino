#include <SoftwareSerial.h >
short button1 = 2;
short button2 = 3;

short xBeeTx = 11;
short xBeeRx = 12;

char LEDstate1 ; // state of the button
int LEDstate2 ; // state of the potentiometer

char LED2state1 ; // state of the button
int LED2state2 ; // state of the potentiometer

SoftwareSerial xBeeSerial ( xBeeRx , xBeeTx ) ;
void setup () {
  Serial.begin(9600);
xBeeSerial.begin (9600) ;
pinMode ( button1 , INPUT ) ;
pinMode ( button2 , INPUT ) ;
}
void loop () {
int temp = analogRead ( A0 ) ; // read in value from the potentiometer
int temp2 = analogRead ( A1 ) ; // read in value from the potentiometer
LEDstate2 = map ( temp ,0 ,1023 ,0 ,255) ; // map temp from the range (0 ,1023) to the range (0 ,255)
LED2state2 = map ( temp2 ,0 ,1023 ,0 ,255) ; // map temp from the range (0 ,1023) to the range (0 ,255)
if ( digitalRead ( button1 ) == HIGH ) {
LEDstate1 = 'H' ;
}
else { LEDstate1 = 'L' ;}

if ( digitalRead ( button2 ) == HIGH ) {
LED2state1 = 'H' ;
}
else { LED2state1 = 'L' ;}

xBeeSerial.print ( LEDstate1 ) ; // transmit the state of the button
xBeeSerial.print ( ',' ) ; // seperate two data by a comma
xBeeSerial.print ( LEDstate2 ) ; // transmit the state of the potentiometer
xBeeSerial.print ( ',' ) ; // seperate two data by a comma
xBeeSerial.print ( LED2state1 ) ; // transmit the state of the button
xBeeSerial.print ( ',' ) ; // seperate two data by a comma
xBeeSerial.print ( LED2state2 ) ; // transmit the state of the potentiometer
xBeeSerial.println () ;
}
