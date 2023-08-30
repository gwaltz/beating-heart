#define potpin A0
#define ledpin 3

unsigned long testmillis, currentmillis;
unsigned long h = 1000;
int brightness = 0, faderateon, faderateoff;

unsigned long prevmillis, interval;


void setup() {
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(test, OUTPUT);
  millis();
}

void loop() {
  // Read the value from the potentiometer
  currentmillis = millis();
  heartbeat();
  // Map the potentiometer value to LED brightness (0-255)
}

