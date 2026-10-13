// ===============================
// SIMULATED TEMPERATURE
// ===============================
float temperature = 28.0;


// ===============================
// RGB LED 1
// ===============================
#define R1 13
#define G1 14
#define B1 27

// ===============================
// RGB LED 2
// ===============================
#define R2 26
#define G2 32
#define B2 33

// ===============================
// BUZZER
// ===============================
#define BUZZER 25


void setup() {

  Serial.begin(115200);

  pinMode(R1, OUTPUT);
  pinMode(G1, OUTPUT);
  pinMode(B1, OUTPUT);

  pinMode(R2, OUTPUT);
  pinMode(G2, OUTPUT);
  pinMode(B2, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  setColor(0, 0, 0);
  noTone(BUZZER);

  Serial.println("Temperature Alert System");
}


void loop() {

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");


  // =================================
  // TEMPERATURE BELOW 30°C
  // =================================

  if (temperature < 30.0) {

    Serial.println("STATUS: NORMAL");

    // GREEN
    setColor(0, 255, 0);

    // Buzzer OFF
    noTone(BUZZER);

    delay(1000);
  }


  // =================================
  // TEMPERATURE 30°C OR ABOVE
  // =================================

  else {

    Serial.println("STATUS: HIGH TEMPERATURE");

    // RED
    setColor(255, 0, 0);

    // Buzzer ON
    tone(BUZZER, 2000);

    delay(300);

    // Small beep gap
    noTone(BUZZER);

    delay(200);
  }
}


// =================================
// SET BOTH RGB LEDs
// =================================

void setColor(int r, int g, int b) {

  analogWrite(R1, r);
  analogWrite(G1, g);
  analogWrite(B1, b);

  analogWrite(R2, r);
  analogWrite(G2, g);
  analogWrite(B2, b);
}
