#define potpin A0 //potentiometer is being read by analog pin A0
#define ledpin 3 //led is controlled by digital pin 3

int brightness = 0; //brightness variable use by the heartbeat function

void setup() { 
  pinMode(ledpin, OUTPUT); //initialize the ledpin 3 as an output
}

void loop() {

  heartbeat(); //loops through the jheartbeat function to constantly read analog pin and adjust bpm of bpm
}

