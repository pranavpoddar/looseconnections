
//GPS sensor not working.Hence,GPS coordinates coded in program

int PulseSensorPurplePin = 0;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int LED13 = 13;   //  The on-board Arduion LED


int Signal;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 795;  
float lat1=26.860664;
float lat2=26.89035;
float lon1=75.811802;
float lon2=75.842314;
float clat;
float clon;
int c=0;// Determine which Signal to "count as a beat", and which to ingore.


// The SetUp Function:
void setup() {
  pinMode(LED13,OUTPUT);         // pin that will blink to your heartbeat!
   Serial.begin(9600);         // Set's up Serial Communication at certain speed.

}

// The Main Loop Function
void loop() {

  Signal = analogRead(PulseSensorPurplePin); 
                                                    
if(digitalRead(6)==HIGH){
  clon=26.87523;
  clat=75.82365;
}
if(digitalRead(7)==HIGH){
    clon=27.87523;
  clat=76.82365;
  
}

  if(digitalRead(9)==HIGH)               //child mode
  {
       if(clat>lat1&&clat<lat2&&clon>lon1&&clon<lon2)
       {
        digitalWrite(LED13,HIGH);
         delay(10);
       digitalWrite(LED13,LOW); 
   } else {
     digitalWrite(LED13,LOW);               
   }

     if(Signal > Threshold){ 
       c++;
       if(c>20)
    {
       digitalWrite(LED13,HIGH);
       delay(10);
       digitalWrite(LED13,LOW); 
   } else {
    c=0;
    digitalWrite(LED13,LOW);               
   }
  }
  }
                                             

   Serial.println(Signal);                    

 if(digitalRead(10)==HIGH)                    //women security
 {
     if(Signal>Threshold)
     { 
    c++;

    if(clat>lat1&&clat<lat2&&clon>lon1&&clon<lon2)
    {
     if(c>20)
    {
       digitalWrite(LED13,HIGH);
       delay(10);
       digitalWrite(LED13,LOW); 
       
   } else {
    c=0;
   digitalWrite(LED13,LOW);               
   }
    }
else
{
  if(c>30)
    {
       digitalWrite(LED13,HIGH);
       delay(10);
       digitalWrite(LED13,LOW); 
       
   } else {
    c=0;
   digitalWrite(LED13,LOW);               
   }
}
delay(100);
 }
 }
  if(digitalRead(11)==HIGH)          //Heartpatient safety
 {
   if(Signal > Threshold){ 
    c++;
    if(c>20)
    {
       digitalWrite(LED13,HIGH);
       delay(10);
       digitalWrite(LED13,LOW); 
       
   } else {
    c=0;
   digitalWrite(LED13,LOW);               
   }}
 } } 


