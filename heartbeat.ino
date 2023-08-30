



void heartbeat() {

  float bpm = map(analogRead(potpin), 0, 1023, 30, 100);
  float ondelay = (0.3 * ((60.0 / bpm) * 1000.0)) / 255.0;
  float offdelay = (0.7 * ((60.0 / bpm) * 1000.0)) / 255.0;
  
  Serial.println(ondelay);
  Serial.println(bpm);

  for (brightness = 0; brightness <= 255; brightness += 1) {  //
      analogWrite(ledpin, brightness);
      delay(ondelay);
  }
  for (brightness = 255; brightness >= 0; brightness -= 1) {  //
      analogWrite(ledpin, brightness);
      delay(offdelay);
  }
}
