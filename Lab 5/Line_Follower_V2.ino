#define NUM_SENSORS   5    // number of sensors used
#define direction1motorA 5
#define direction2motorA 6
#define direction1motorB 9
#define direction2motorB 10

int sensorValues[NUM_SENSORS];


void setup()
{
   Serial.begin(9600);
   pinMode(enableA, OUTPUT);
   pinMode(enableB, OUTPUT);
   pinMode(direction1motorA, OUTPUT);
   pinMode(direction2motorA, OUTPUT);
   pinMode(direction1motorB, OUTPUT);
   pinMode(direction2motorB, OUTPUT); 
}


void loop()
{
  sensorValues[0]=analogRead(0);
  sensorValues[1]=analogRead(1);
  sensorValues[2]=analogRead(2);
  sensorValues[3]=analogRead(3);
  sensorValues[4]=analogRead(4);

  for(int i=0;i<5;i++){
    Serial.print(sensorValues[i]);
    Serial.print("\t");
      
  }
  Serial.println();
 
  if(sensorValues[2] > 920){
    Forward();
    delay(1);
  }
  if(sensorValues[3]>920){
    SlightRight();    
    delay(1);
  }
  if(sensorValues[4]>920){
    HardRight();
    delay(1);
  }
  
  if(sensorValues[1]>880){
    SlightLeft();
    delay(1);
  }
  if(sensorValues[0]>880){
    HardLeft();
    delay(1);
  }
}

void Forward(){
    analogWrite(direction1motorA, 120);
    analogWrite(direction2motorA, 0);
    analogWrite(direction1motorB, 120);
    analogWrite(direction2motorB, 0);
}

void SlightRight(){
    analogWrite(direction1motorA, 120);
    analogWrite(direction2motorA, 0);
    analogWrite(direction1motorB, 0);
    analogWrite(direction2motorB, 120);
}

 void HardRight(){
    analogWrite(direction1motorA, 255);
    analogWrite(direction2motorA, 0);
    analogWrite(direction1motorB, 0);
    analogWrite(direction2motorB, 255);
 }

void SlightLeft(){
    analogWrite(direction1motorA, 0);
    analogWrite(direction2motorA, 120);
    analogWrite(direction1motorB, 120);
    analogWrite(direction2motorB, 0);
}
void HardLeft(){
    analogWrite(direction1motorA, 0);
    analogWrite(direction2motorA, 255);
    analogWrite(direction1motorB, 255);
    analogWrite(direction2motorB, 0);
}
void Stop(){
    analogWrite(direction1motorA, 0);
    analogWrite(direction2motorA, 0);
    analogWrite(direction1motorB, 0);
    analogWrite(direction2motorB, 0);
}
