// Arduino Dual Axis Joystick Example
#define Xaxis_pin A0 // Arduino pin connected to the VRx Pin
#define Yaxis_pin A1 // Arduino pin connected to the VRy Pin
#define SW_pin A2 // Arduino pin connected to the SW Pin

bool ValueChange = true;
String X_movement = "0";
String Y_movement = "0";
String J_movement = "N";

void setup() {
  // Setting Up the Joystick Input
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  // Check for left or right joystick movement
  if (analogRead(Xaxis_pin) <= 100)
  {
    if (X_movement != "-1")
    {
      X_movement = "-1";
      ValueChange = true;
    }
  }
  else if (analogRead(Xaxis_pin) >= 900)
  {
    if (X_movement != "1")
    {
      X_movement = "1";
      ValueChange = true;
    }
  }
  else
  { 
    if (X_movement != "0")
    {
      X_movement = "0";
      ValueChange = true;
    }
  }

  // check for forward or back joystick movement
  if (analogRead(Yaxis_pin) <= 100)
  {
    if (Y_movement != "-1")
    {
      Y_movement = "-1";
      ValueChange = true;
    }
  }
  else if (analogRead(Yaxis_pin) >= 900)
  {
    if (Y_movement != "1")
    {
      Y_movement = "1";
      ValueChange = true;
    }
  }
  else
  {
    if (Y_movement != "0")
    {
      Y_movement = "0";
      ValueChange = true;
    }
  }

  // check for jumping trigger
  if (digitalRead(SW_pin) == 0)
  {
    if (J_movement != "J")
    {
      J_movement = "J";
      ValueChange = true;
    }
  }
  else
  {
    if (J_movement != "N")
    {
      J_movement = "N";
      ValueChange = true;
    }
  }
  // Send data to Unreal only if there has been a change to one of the values
  if (ValueChange)
  {
    if (X_movement == "1" && Y_movement == "-1" && J_movement == "J") { Serial.println("0"); }
    else if (X_movement == "1" && Y_movement == "-1" && J_movement == "N") { Serial.println("1"); }
    else if (X_movement == "1" && Y_movement == "0" && J_movement == "J") { Serial.println("2"); }
    else if (X_movement == "1" && Y_movement == "0" && J_movement == "N") { Serial.println("3"); }
    else if (X_movement == "1" && Y_movement == "1" && J_movement == "J") { Serial.println("4"); }
    else if (X_movement == "1" && Y_movement == "1" && J_movement == "N") { Serial.println("5"); }
    else if (X_movement == "0" && Y_movement == "-1" && J_movement == "J") { Serial.println("6"); }
    else if (X_movement == "0" && Y_movement == "-1" && J_movement == "N") { Serial.println("7"); }
    else if (X_movement == "0" && Y_movement == "0" && J_movement == "J") { Serial.println("8"); }
    else if (X_movement == "0" && Y_movement == "0" && J_movement == "N") { Serial.println("9"); }
    else if (X_movement == "0" && Y_movement == "1" && J_movement == "J") { Serial.println("10"); }
    else if (X_movement == "0" && Y_movement == "1" && J_movement == "N") { Serial.println("11"); }
    else if (X_movement == "-1" && Y_movement == "-1" && J_movement == "J") { Serial.println("12"); }
    else if (X_movement == "-1" && Y_movement == "-1" && J_movement == "N") { Serial.println("13"); }
    else if (X_movement == "-1" && Y_movement == "0" && J_movement == "J") { Serial.println("14"); }
    else if (X_movement == "-1" && Y_movement == "0" && J_movement == "N") { Serial.println("15"); }
    else if (X_movement == "-1" && Y_movement == "1" && J_movement == "J") { Serial.println("16"); }
    else if (X_movement == "-1" && Y_movement == "1" && J_movement == "N") { Serial.println("17"); }
    ValueChange = false;
    delay(100);
  }
}
