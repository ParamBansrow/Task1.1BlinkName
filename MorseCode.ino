int dotDuration = 200;   // Duration of a dot
int dashDuration = 600;  // Duration of a dash
int letterGap = 600;     // Gap between letters

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  blinkLetter("P");
  delay(letterGap);
  blinkLetter("A");
  delay(letterGap);
  blinkLetter("R");
  delay(letterGap);
  blinkLetter("A");
  delay(letterGap);
  blinkLetter("M");
  delay(2000); // Delay before repeating
}

// Morse patterns: '.' = short, '-' = long
void blinkLetter(String letter) {
  if (letter == "P") blinkPattern(".--.");
  else if (letter == "A") blinkPattern(".-");
  else if (letter == "R") blinkPattern(".-.");
  else if (letter == "M") blinkPattern("--");
}

void blinkPattern(String pattern) {
  for (int i = 0; i < pattern.length(); i++) {
    if (pattern.charAt(i) == '.') {
      blinkDot();
    } else if (pattern.charAt(i) == '-') {
      blinkDash();
    }
    delay(200); // Gap between parts of the same letter
  }
}

void blinkDot() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(dotDuration);
  digitalWrite(LED_BUILTIN, LOW);
  delay(dotDuration);
}

void blinkDash() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(dashDuration);
  digitalWrite(LED_BUILTIN, LOW);
  delay(dotDuration);
}
