const int motorA2 = 5;
const int motorB1 = 6;
const int motorA1 = 7;
const int motorB2 = 8;

int sure ;
int mesafe ;
int onfar=9;
int arkafar=10;
int korna=11;
int i=0;
int j=0;
int state;
int vSpeed=255;

void setup() {
pinMode(motorA1, OUTPUT);
pinMode(motorA2, OUTPUT);
pinMode(motorB1, OUTPUT);
pinMode(motorB2, OUTPUT);
pinMode(onfar,OUTPUT);
pinMode(arkafar,OUTPUT);
pinMode(korna,OUTPUT);
pinMode(3 , OUTPUT);
pinMode(4 , INPUT);
Serial.begin(9600);
}

void loop() {
if(Serial.available() > 0){
state = Serial.read();
}

if (state == '0'){
vSpeed=0;}
else if (state == '1'){
vSpeed=100;}
else if (state == '2'){
vSpeed=180;}
else if (state == '3'){
vSpeed=200;}
else if (state == '4'){
vSpeed=255;}

if (state == 'F') {
analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0);
analogWrite(motorB1, vSpeed); analogWrite(motorB2, 0);
}
else if (state == 'G') {
analogWrite(motorA1,vSpeed ); analogWrite(motorA2, 0);
analogWrite(motorB1, vSpeed/2); analogWrite(motorB2, 0);
}
else if (state == 'I') {
analogWrite(motorA1, vSpeed/2); analogWrite(motorA2, 0);
analogWrite(motorB1, vSpeed); analogWrite(motorB2, 0);
}
else if (state == 'B') {
analogWrite(motorA1, 0); analogWrite(motorA2, vSpeed);
analogWrite(motorB1, 0); analogWrite(motorB2, vSpeed);
}
else if (state == 'H') {
analogWrite(motorA1, 0); analogWrite(motorA2, vSpeed/2);
analogWrite(motorB1, 0); analogWrite(motorB2, vSpeed);
}
else if (state == 'J') {
analogWrite(motorA1, 0); analogWrite(motorA2, vSpeed);
analogWrite(motorB1, 0); analogWrite(motorB2, vSpeed/2);
}
else if (state == 'L') {
analogWrite(motorA1, vSpeed); analogWrite(motorA2, vSpeed);
analogWrite(motorB1, 0); analogWrite(motorB2, 0);
}
else if (state == 'R') {
analogWrite(motorA1, 0); analogWrite(motorA2, 0);
analogWrite(motorB1, vSpeed); analogWrite(motorB2, vSpeed);
}
else if (state == 'S'){
analogWrite(motorA1, 0); analogWrite(motorA2, 0);
analogWrite(motorB1, 0); analogWrite(motorB2, 0);
}
else if(state=='W') digitalWrite(onfar,HIGH);
else if(state=='w') digitalWrite(onfar,LOW);
else if(state=='U') digitalWrite(arkafar,HIGH);
else if(state=='u') digitalWrite(arkafar,LOW);
else if(state=='V') digitalWrite(korna,HIGH);
else if(state=='v') digitalWrite(korna,LOW);
}