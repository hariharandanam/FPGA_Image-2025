const int buzzerPins[3] = {2, 3, 4};
const int ledPins[5] = {5, 6, 7, 8, 9};
const int pot1Pin = A0;
const int pot2Pin = A1;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(buzzerPins[i], OUTPUT);
  }
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int pot1Val = analogRead(pot1Pin);
  int pot2Val = analogRead(pot2Pin);
  int buzzerIndex = pot1Val / 341;
  if (buzzerIndex > 2) buzzerIndex = 2;

  for (int i = 0; i < 3; i++) {
    digitalWrite(buzzerPins[i], (i == buzzerIndex) ? HIGH : LOW);
  }

  int delayTime = map(pot2Val, 0, 1023, 50, 1000);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      digitalWrite(ledPins[j], (j == i) ? HIGH : LOW);
    }
    delay(delayTime);
  }
}

/*The link for the Tinkercad simulation is give below.
https://www.tinkercad.com/things/76DRIXiv40i-fpga1/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=xPf9U5EtbAEZBa8nQSatZ7o4QBKuugIY58qQFB7upX8*/
