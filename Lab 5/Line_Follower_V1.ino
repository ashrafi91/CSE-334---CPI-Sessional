#define NUM_SENSORS   5    // number of sensors used
#define enableA 11 
#define enableB 10
#define direction1motorA 2
#define direction2motorA 3
#define direction1motorB 7
#define direction2motorB 8

unsigned int sensorValues[NUM_SENSORS];

int SumLeft = 0;
int SumRight = 0;
int SumDifference = 0;
int Last = 0;

void setup()
{
   delay(500);
   pinMode(enableA, OUTPUT);
   pinMode(enableB, OUTPUT);
   pinMode(direction1motorA, OUTPUT);
   pinMode(direction2motorA, OUTPUT);
   pinMode(direction1motorB, OUTPUT);
   pinMode(direction2motorB, OUTPUT); 
}
void loop()
{
  sensorValues[0] = analogRead(0);
  sensorValues[1] = analogRead(1);
  sensorValues[2] = analogRead(2);
  sensorValues[3] = analogRead(3);
  sensorValues[4] = analogRead(4);
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  SumLeft =(sensorValues[0] + sensorValues[1] + sensorValues[2]);
  SumRight = (sensorValues[2] + sensorValues[3] + sensorValues[4]);
  SumDifference = (SumLeft - SumRight);
  if(abs(SumDifference) < 700){
    Forward();
    delay(1);
  }
  if((SumDifference > 700) && (SumDifference < 1000)){
    SlightRight();
    Last = 1;
    delay(1);
  }
  if(SumDifference >= 1000){
    HardRight();
    Last = 1;
    delay(1);
  }
  
  if((SumDifference < -700) && (SumDifference > -1000)){
    SlightLeft();
    Last = 2;
    delay(1);
  }
  if((SumDifference) <= -1000){
    HardLeft();
    Last = 2;
    delay(1);
  }
  if ((SumLeft < 100) && (SumRight < 100)){
    if (Last == 1){
      HardRight();
      delay(1);
    }
    if (Last == 2){
      HardLeft();
      delay(1);
    }
  }
}

void Forward(){
    digitalWrite(direction1motorA, HIGH);
    digitalWrite(direction2motorA, LOW);
    digitalWrite(direction1motorB, HIGH);
    digitalWrite(direction2motorB, LOW);
    analogWrite(enableA,175);
    analogWrite(enableB,175);
}

void SlightRight(){
    digitalWrite(direction1motorA, HIGH);
    digitalWrite(direction2motorA, LOW);
    digitalWrite(direction1motorB, LOW);
    digitalWrite(direction2motorB, HIGH);
    analogWrite(enableA,125);
    analogWrite(enableB,175);
}

 void HardRight(){
    digitalWrite(direction1motorA, HIGH);
    digitalWrite(direction2motorA, LOW);
    digitalWrite(direction1motorB, LOW);
    digitalWrite(direction2motorB, HIGH);
    analogWrite(enableA,0);
    analogWrite(enableB,175);
 }

void SlightLeft(){
    digitalWrite(direction1motorA, LOW);
    digitalWrite(direction2motorA, HIGH);
    digitalWrite(direction1motorB, HIGH);
    digitalWrite(direction2motorB, LOW);
    analogWrite(enableA,175);
    analogWrite(enableB,125);
}
void HardLeft(){
    digitalWrite(direction1motorA, LOW);
    digitalWrite(direction2motorA, HIGH);
    digitalWrite(direction1motorB, HIGH);
    digitalWrite(direction2motorB, LOW);
    analogWrite(enableA,175);
    analogWrite(enableB,0);
}
void Stop(){
    digitalWrite(direction1motorA, LOW);
    digitalWrite(direction2motorA, LOW);
    digitalWrite(direction1motorB, LOW);
    digitalWrite(direction2motorB, LOW);
    analogWrite(enableA,0);
    analogWrite(enableB,0);
}
