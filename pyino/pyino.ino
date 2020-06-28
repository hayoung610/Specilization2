short LED = 9;
void setup () {
// put your setup code here , to run once :
Serial.begin (9600) ;
pinMode ( LED , OUTPUT ) ;
}
void loop () {
char state ;
// put your main code here , to run repeatedly :
if ( Serial.available () ) {
state = Serial.read () ;
if ( state == '1' ) {
digitalWrite ( LED , HIGH ) ;
delay (1000) ;
}
else {
digitalWrite ( LED , LOW ) ;
delay (1000) ;
}
}
Serial.println ( state ) ;
}
