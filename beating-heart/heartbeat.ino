



void heartbeat() {

  int bpm = map(analogRead(potpin), 0, 1023, 30, 100);
  int ondelay = (0.3 * ((60.0 / bpm) * 1000.0)) / 255.0;
  int offdelay = (0.7 * ((60.0 / bpm) * 1000.0)) / 255.0;

  for (brightness = 0; brightness <= 255; brightness += 1) {  //
      analogWrite(ledpin, brightness);
      delay(ondelay);
  }
  for (brightness = 255; brightness >= 0; brightness -= 1) {  //
      analogWrite(ledpin, brightness);
      delay(offdelay);
  }
}
