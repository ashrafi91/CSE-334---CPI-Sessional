int motor_left[] = {7, 6};
int motor_right[] = {5, 4};

void setup() {
	int i;
	for(i = 0; i < 2; i++){
		pinMode(motor_left[i], OUTPUT);
		pinMode(motor_right[i], OUTPUT);
	}
}
void loop() {
	drive_forward();
	delay(1000);
	motor_stop();
	drive_backward();
	delay(1000);
	motor_stop();
	turn_left();
	delay(1000);
	motor_stop();
	turn_right();
	delay(1000);
	motor_stop();
	motor_stop();
	delay(1000);
	motor_stop();
}
void motor_stop(){
	digitalWrite(motor_left[0], LOW);
	digitalWrite(motor_left[1], LOW);
	digitalWrite(motor_right[0], LOW);
	digitalWrite(motor_right[1], LOW);
	delay(25);
}
void drive_forward(){
	digitalWrite(motor_left[0], HIGH);
	digitalWrite(motor_left[1], LOW);
	digitalWrite(motor_right[0], HIGH);
	digitalWrite(motor_right[1], LOW);
}
void drive_backward(){
	digitalWrite(motor_left[0], LOW);
	digitalWrite(motor_left[1], HIGH);
	digitalWrite(motor_right[0], LOW);
	digitalWrite(motor_right[1], HIGH);
}
void turn_left(){
	digitalWrite(motor_left[0], LOW);
	digitalWrite(motor_left[1], HIGH);
	digitalWrite(motor_right[0], HIGH);
	digitalWrite(motor_right[1], LOW);
}
void turn_right(){
	digitalWrite(motor_left[0], HIGH);
	digitalWrite(motor_left[1], LOW);
	digitalWrite(motor_right[0], LOW);
	digitalWrite(motor_right[1], HIGH);
}