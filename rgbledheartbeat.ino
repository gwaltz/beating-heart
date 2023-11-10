
#define potpin A0 //potentiometer is being read by analog pin A0
const int redpin=6, greenpin=5, bluepin=3;//led is controlled by digital pin 3

float red = 0, green=0, blue=0;
float redinc, greeninc, blueinc;
float currentred, currentgreen, currentblue;
int redbrightness, greenbrightness, bluebrightness;
int bpm, previousbpm;


void setup() {
  // put your setup code here, to run once:
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  bpm = map(analogRead(potpin), 0, 1023, 30, 130);
  mapcolors();
  beatheart();
  Serial.println(bpm);
  Serial.println(String("Red: ") + red + ", " + String("Green: ") + green + ", " + String("Blue: ") + blue);
  Serial.println(String("Redinc: ") + redinc + ", " + String("Greeninc: ") + greeninc + ", " + String("Blueinc: ") + blueinc);


}

 //use map function to translate the position of the potentiometer to a value of 30:100

void mapcolors() {

  if (bpm < 60) {
    blue = map(bpm, 30, 60, 255, 50);
    red = 0;
    green = 0;
  }
  else if (bpm >= 60 && bpm < 80) {
    blue = 0;
    green = map(bpm, 60, 80, 50, 255);
    red = 0;
  }
  else if (bpm >= 80 && bpm <= 100) {
    blue = 0;
    green = map(bpm, 80, 100, 255, 50);
    red = 0;
  }
  else if (bpm > 100) {
    blue = 0;
    green = 0;
    red = map(bpm, 100, 130, 50, 255);
  }
}


void beatheart() {
  int ondelay = (0.3 * ((60.0 / bpm) * 1000.0)) / 255;   //use the bpm to create a delay that will serve to fade in and fadein the led
  int offdelay = (0.7 * ((60.0 / bpm) * 1000.0)) / 255;  //use the bpm to create a delay that will serve to fade in and fadeout the led
  redinc = red/255; greeninc = green/255; blueinc = blue/255;
  int brightness;

  for (brightness = 0; brightness <= 255; brightness += 1) {  //for loop adds to the brightness variable up to 255
    analogWrite(redpin, currentred);
    analogWrite(greenpin, currentgreen);
    analogWrite(bluepin, currentblue);  //uses pwm or ledpin pin to analogwrite to ledpin the brightness value
    currentred += redinc; currentgreen += greeninc; currentblue += blueinc;
    delay(ondelay);              //delays the on delay value
  }
  for (brightness = 255; brightness >= 0; brightness -= 1) {  //for loop subtracts the current brightness variable back down to zero
    analogWrite(redpin, currentred);
    analogWrite(greenpin, currentgreen);
    analogWrite(bluepin, currentblue);  //uses pwm or ledpin pin to analogwrite to ledpin the brightness value
    currentred -= redinc; currentgreen -= greeninc; currentblue -= blueinc;
    delay(offdelay);             //delays the off dalay value
  }
}
