void setup() {
  int led_pin = 7;
  pinMode(led_pin, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led_pin, LOW);   // Turn the LED on (Note that LOW is the 						  voltage level
  delay(1000);                  // Wait for a second
  digitalWrite(led_pin, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(1000);                  // Wait for one second (to demonstrate the 					         active low LED)
}