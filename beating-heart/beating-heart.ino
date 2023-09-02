#define potpin A0
#define ledpin 3

int brightness = 0;

void setup() {
  pinMode(ledpin, OUTPUT);
}

void loop() {
  // Read the value from the potentiometer
  heartbeat();
  // Map the potentiometer value to LED brightness (0-255)
}

