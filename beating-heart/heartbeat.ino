

void heartbeat() {

  int bpm = map(analogRead(potpin), 0, 1023, 30, 100); //use map function to translate the position of the potentiometer to a value of 30:100
  int ondelay = (0.3 * ((60.0 / bpm) * 1000.0)) / 255.0; //use the bpm to create a delay that will serve to fade in and fadein the led
  int offdelay = (0.7 * ((60.0 / bpm) * 1000.0)) / 255.0; //use the bpm to create a delay that will serve to fade in and fadeout the led

  for (brightness = 0; brightness <= 255; brightness += 1) {  //for loop adds to the brightness variable up to 255 
      analogWrite(ledpin, brightness);                        //uses pwm or ledpin pin to analogwrite to ledpin the brightness value
      delay(ondelay);                                         //delays the on delay value
  }
  for (brightness = 255; brightness >= 0; brightness -= 1) {  //for loop subtracts the current brightness variable back down to zero
      analogWrite(ledpin, brightness);                        //uses pwm or ledpin pin to analogwrite to ledpin the brightness value
      delay(offdelay);                                        //delays the off dalay value
  }
}
