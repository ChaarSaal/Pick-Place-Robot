//MECANUM WHEELS ROBOT
//ROBOT LK

#define IN_10  10        // L298N #1 in 4 motor Front Right
#define IN_11  11       // L298N #1 in 3 motor Front Right
#define IN_12  12       // L298N #1 in 2 motor Front Left
#define IN_13  13       // L298N #1 in 1 motor Front Left


//ROBOT LK


int command;             //Int to store app command state.
boolean state = 1;


void stopRobot() {
  digitalWrite(IN_10, LOW);
  digitalWrite(IN_11, LOW);

  digitalWrite(IN_12, LOW);
  digitalWrite(IN_13, LOW);
  
}
void back() {
  digitalWrite(IN_10, HIGH);
  digitalWrite(IN_11, LOW);

  digitalWrite(IN_12, HIGH);
  digitalWrite(IN_13, LOW);
 
}
void forward () {
  digitalWrite(IN_10, LOW);
  digitalWrite(IN_11, HIGH);

  digitalWrite(IN_12, LOW);
  digitalWrite(IN_13, HIGH);
 
}
void left() {
  digitalWrite(IN_10, HIGH);
  digitalWrite(IN_11, LOW);
  
  digitalWrite(IN_12, LOW);
  digitalWrite(IN_13, HIGH);
  
}
void right() {
  digitalWrite(IN_10, LOW);
  digitalWrite(IN_11, HIGH);
  
  digitalWrite(IN_12, HIGH);
  digitalWrite(IN_13, LOW);

}
void superleft () {
  digitalWrite(IN_10, HIGH);
  digitalWrite(IN_11, LOW);
  
  digitalWrite(IN_12, LOW);
  digitalWrite(IN_13, HIGH);
 
}
void superright () {
  digitalWrite(IN_10, LOW);
  digitalWrite(IN_11, HIGH);
  
  digitalWrite(IN_12, HIGH);
  digitalWrite(IN_13, LOW);

}
void forwardright () {
  digitalWrite(IN_10, LOW);
  digitalWrite(IN_11, HIGH);
  
  digitalWrite(IN_12, LOW);
  digitalWrite(IN_13, LOW);
}
void forwardleft () {
  digitalWrite(IN_10, LOW);
  digitalWrite(IN_11, LOW);
  
  digitalWrite(IN_12, LOW);
  digitalWrite(IN_13, HIGH);
}
void backright () {
  digitalWrite(IN_10, LOW);
  digitalWrite(IN_11, LOW);
  
  digitalWrite(IN_12, HIGH);
  digitalWrite(IN_13, LOW);
}
void backleft () {
  digitalWrite(IN_10, HIGH);
  digitalWrite(IN_11, LOW);
  
  digitalWrite(IN_12, LOW);
  digitalWrite(IN_13, LOW);

}
void setup() {
  Serial.begin (9600);

  pinMode(IN_10, OUTPUT);
  pinMode(IN_11, OUTPUT);
  pinMode(IN_12, OUTPUT);
  pinMode(IN_13, OUTPUT);

}
//ROBOT LK

void loop() {
  if (Serial.available()) {
    command = Serial.read();
    if (command == 'X') {
      state = 1;
    } else if (command == 'x') {
      state = 0;
    }
    if (command == 'B') {
      back();
    } else if (command == 'F') {
      forward();
    } else if (command == 'R' && state == 1) {
      superright ();
    } else if (command == 'L' && state == 1) {
      superleft ();
    } else if (command == 'R' && state == 0) {
      right ();
    } else if (command == 'L' && state == 0) {
      left ();
    } else if (command == 'G') {
      forwardleft ();
    } else if (command == 'I') {
      forwardright ();
    } else if (command == 'H') {
      backright ();
    } else if (command == 'J') {
      backleft ();
    }  else {
      stopRobot();
    }
  }
}
//robot lk
