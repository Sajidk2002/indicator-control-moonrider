#define LEFT_BUTTON_PIN 2
#define RIGHT_BUTTON_PIN 3
#define LEFT_LED_PIN 9
#define RIGHT_LED_PIN 10

enum Mode {
  OFF,
  LEFT,
  RIGHT,
  HAZARD
};

Mode currentMode = OFF;

unsigned long lastToggleTime = 0;
unsigned long toggleInterval = 300;
bool ledState = false;

unsigned long leftPressStart = 0;
unsigned long rightPressStart = 0;

void setup() {
  pinMode(LEFT_BUTTON_PIN, INPUT);
  pinMode(RIGHT_BUTTON_PIN, INPUT);
  pinMode(LEFT_LED_PIN, OUTPUT);
  pinMode(RIGHT_LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("[INIT] System Initialized");
}

void loop() {
  unsigned long currentTime = millis();

  // Read buttons
  bool leftPressed = digitalRead(LEFT_BUTTON_PIN);
  bool rightPressed = digitalRead(RIGHT_BUTTON_PIN);

  // Detect long press
  if (leftPressed) {
    if (leftPressStart == 0) leftPressStart = currentTime;
    if (currentTime - leftPressStart >= 1000) {
      handleLeftPress();
      leftPressStart = 0;
    }
  } else {
    leftPressStart = 0;
  }

  if (rightPressed) {
    if (rightPressStart == 0) rightPressStart = currentTime;
    if (currentTime - rightPressStart >= 1000) {
      handleRightPress();
      rightPressStart = 0;
    }
  } else {
    rightPressStart = 0;
  }

  // Detect both buttons pressed for hazard
  if (leftPressed && rightPressed) {
    if ((leftPressStart != 0) && (rightPressStart != 0)) {
      if ((currentTime - leftPressStart >= 1000) && (currentTime - rightPressStart >= 1000)) {
        setMode(HAZARD);
        leftPressStart = rightPressStart = 0;
      }
    }
  }

  // LED toggle logic
  if (currentTime - lastToggleTime >= toggleInterval) {
    lastToggleTime = currentTime;
    ledState = !ledState;
    updateLEDs();
  }

  delay(100); // 100ms scheduler
}

void setMode(Mode newMode) {
  if (currentMode == newMode) {
    currentMode = OFF;
    Serial.print("[MODE] ");
    Serial.print(modeToString(newMode));
    Serial.println(" OFF");
  } else {
    currentMode = newMode;
    Serial.print("[MODE] ");
    Serial.print(modeToString(newMode));
    Serial.println(" ON");
  }
}

void updateLEDs() {
  switch (currentMode) {
    case LEFT:
      digitalWrite(LEFT_LED_PIN, ledState);
      digitalWrite(RIGHT_LED_PIN, LOW);
      break;
    case RIGHT:
      digitalWrite(RIGHT_LED_PIN, ledState);
      digitalWrite(LEFT_LED_PIN, LOW);
      break;
    case HAZARD:
      digitalWrite(LEFT_LED_PIN, ledState);
      digitalWrite(RIGHT_LED_PIN, ledState);
      break;
    default:
      digitalWrite(LEFT_LED_PIN, LOW);
      digitalWrite(RIGHT_LED_PIN, LOW);
      break;
  }
}

void handleLeftPress() {
  if (currentMode == RIGHT || currentMode == HAZARD) {
    setMode(LEFT);
  } else if (currentMode == LEFT) {
    setMode(LEFT);
  } else {
    setMode(LEFT);
  }
}

void handleRightPress() {
  if (currentMode == LEFT || currentMode == HAZARD) {
    setMode(RIGHT);
  } else if (currentMode == RIGHT) {
    setMode(RIGHT);
  } else {
    setMode(RIGHT);
  }
}

const char* modeToString(Mode m) {
  switch (m) {
    case LEFT: return "LEFT";
    case RIGHT: return "RIGHT";
    case HAZARD: return "HAZARD";
    default: return "UNKNOWN";
  }
}
