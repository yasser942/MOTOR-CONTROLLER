int MOTOR_STEPS = 10;
int dir = 0;
int current_step = 0;
int enA = 11;
int lButton = 3;
int rButton = 2;
int lButtonState = 0;
int rButtonState = 0;

const int A = 7;
const int B = 6;
const int G = 9;
const int D = 4;
const int E = 5;
const int F = 8;
const int C = 13;
const int H = 12;
void (*functions[16])();

void setup() {
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(lButton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(lButton), lbtn, RISING);
  pinMode(rButton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(rButton), rbtn, RISING);
  Serial.begin(9600);

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);

  count(0);
}

void lbtn() {
  lButtonState = 1;
}
void rbtn() {
  rButtonState = 1;
}

void direction() {
  if (current_step > 0)
    dir = 1;
  else if (current_step == 0)
    dir = 0;
  else dir = -1;
}

void motor_dir() {
  if (dir == 1) {
    digitalWrite(A0, HIGH);
    digitalWrite(A1, LOW);
    digitalWrite(A3, HIGH);
    digitalWrite(A2, LOW);
  } else if (dir == -1) {
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);
  } else {
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
  }
}



void loop() {
  if (lButtonState == 1) {
    if (current_step != -MOTOR_STEPS) {
      current_step--;
      count(abs(current_step));
    }
    direction();
    motor_dir();
    for (int i = 0; i < abs(current_step) * 255 / MOTOR_STEPS; i++) {
      analogWrite(enA, i);
    }
    Serial.print("Current Step: ");
    Serial.println(current_step);
    Serial.print("Motor RPM: ");
    Serial.println(abs(current_step) * 255 / MOTOR_STEPS);
    lButtonState = 0;
  }
  if (rButtonState == 1) {
    if (current_step != MOTOR_STEPS) {
      current_step++;
      count(abs(current_step));
    }
    direction();
    motor_dir();
    for (int i = 0; i < abs(current_step) * 255 / MOTOR_STEPS; i++) {
      analogWrite(enA, i);
    }
    rButtonState = 0;
    Serial.print("Current Step: ");
    Serial.println(current_step);
    Serial.print("Motor RPM: ");
    Serial.println(abs(current_step) * 255 / MOTOR_STEPS);
  }
}

void count(int counter) {
  functions[0] = zero;
  functions[1] = one;
  functions[2] = two;
  functions[3] = three;
  functions[4] = four;
  functions[5] = five;
  functions[6] = six;
  functions[7] = seven;
  functions[8] = eight;
  functions[9] = nine;
  functions[10] = ten;

  (*functions[counter])();
}
void zero() {
  for (int i = 4; i < 14; i++) {
    if (i == 11) continue;
    if (i == 9 || i == 12)
      digitalWrite(i, HIGH);
    else
      digitalWrite(i, LOW);
  }
}

void one() {
  for (int i = 4; i < 14; i++) {
    if (i == 11) continue;
    if (i == 6 || i == 13)
      digitalWrite(i, LOW);
    else
      digitalWrite(i, HIGH);
  }
}

void two() {
  for (int i = 4; i < 14; i++) {
    if (i == 11) continue;
    if (i == 8 || i == 13 || i == 12)
      digitalWrite(i, HIGH);
    else
      digitalWrite(i, LOW);
  }
}

void three() {
  for (int i = 4; i < 14; i++) {
    if (i == 11) continue;
    if (i == 8 || i == 5 || i == 12)
      digitalWrite(i, HIGH);
    else
      digitalWrite(i, LOW);
  }
}

void four() {
  for (int i = 4; i < 14; i++) {
    if (i == 11) continue;
    if (i == 7 || i == 5 || i == 4 || i == 12)
      digitalWrite(i, HIGH);
    else
      digitalWrite(i, LOW);
  }
}

void five() {
  for (int i = 4; i < 14; i++) {
    if (i == 11) continue;
    if (i == 6 || i == 5 || i == 12)
      digitalWrite(i, HIGH);
    else
      digitalWrite(i, LOW);
  }
}

void six() {
  for (int i = 4; i < 14; i++) {
    if (i == 11) continue;
    if (i == 6 || i == 12)
      digitalWrite(i, HIGH);
    else
      digitalWrite(i, LOW);
  }
}

void seven() {
  for (int i = 4; i < 14; i++) {
    if (i == 11) continue;
    if (i == 7 || i == 13 || i == 6)
      digitalWrite(i, LOW);
    else
      digitalWrite(i, HIGH);
  }
}

void eight() {
  for (int i = 4; i < 14; i++) {
    if (i == 11) continue;
    if (i == 12)
      digitalWrite(i, HIGH);
    else
      digitalWrite(i, LOW);
  }
}

void nine() {
  for (int i = 4; i < 14; i++) {
    if (i == 11) continue;
    if (i == 5 || i == 12)
      digitalWrite(i, HIGH);
    else
      digitalWrite(i, LOW);
  }
}
void ten() {
  for (int i = 4; i < 14; i++) {
    if (i == 11) continue;
    if (i == 4 || i == 12)
      digitalWrite(i, HIGH);
    else
      digitalWrite(i, LOW);
  }
}