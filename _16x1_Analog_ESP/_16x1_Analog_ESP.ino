/***********************************************************************************************

 This is the code for reading 16 sensors using ESP8266 12e module & 16 channel analog multiplexer.
 
 Written by Sachin Soni for techiesms YouTube channel & community.
 
  
***********************************************************************************************/

#define S0 D0
#define S1 D1
#define S2 D2
#define S3 D3
#define analogpin A0

void setup() {

  pinMode(analogpin, INPUT);
  pinMode(S0,OUTPUT);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);  
  Serial.begin(115200);

  // put your setup code here, to run once:
}

void loop() {

  digitalWrite(S0,LOW);
  digitalWrite(S1,LOW);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  Serial.print("Sensor 1 ");Serial.println(analogRead(analogpin));
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  Serial.print("Sensor 2 ");Serial.println(analogRead(analogpin));
  
  digitalWrite(S0,LOW);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  Serial.print("Sensor 3 ");Serial.println(analogRead(analogpin));
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  Serial.print("Sensor 4 ");Serial.println(analogRead(analogpin));
  
  digitalWrite(S0,LOW);
  digitalWrite(S1,LOW);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,LOW);
  Serial.print("Sensor 5 ");Serial.println(analogRead(analogpin));
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,LOW);
  Serial.print("Sensor 6 ");Serial.println(analogRead(analogpin));
  
  digitalWrite(S0,LOW);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,LOW);
  Serial.print("Sensor 7 ");Serial.println(analogRead(analogpin));
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,LOW);
  Serial.print("Sensor 8 ");Serial.println(analogRead(analogpin));
  
  digitalWrite(S0,LOW);
  digitalWrite(S1,LOW);
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  Serial.print("Sensor 9 ");Serial.println(analogRead(analogpin));
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  Serial.print("Sensor 10 ");Serial.println(analogRead(analogpin));

  digitalWrite(S0,LOW);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  Serial.print("Sensor 11 ");Serial.println(analogRead(analogpin));

  digitalWrite(S0,HIGH);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  Serial.print("Sensor 12 ");Serial.println(analogRead(analogpin));

  digitalWrite(S0,LOW);
  digitalWrite(S1,LOW);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  Serial.print("Sensor 13 ");Serial.println(analogRead(analogpin));

  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  Serial.print("Sensor 14 ");Serial.println(analogRead(analogpin));

  digitalWrite(S0,LOW);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  Serial.print("Sensor 15 ");Serial.println(analogRead(analogpin));

  digitalWrite(S0,HIGH);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  Serial.print("Sensor 16 ");Serial.println(analogRead(analogpin));

  delay(5000);
  // put your main code here, to run repeatedly:

}
