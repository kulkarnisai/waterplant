

/* # the sensor value description

# 0  ~300     dry soil

# 300~700     humid soil

# 700~950     in water*/


byte seven_seg_digits[10][7] = { { 1,1,1,1,1,1,0 },  // = 0
                                                           { 0,1,1,0,0,0,0 },  // = 1
                                                           { 1,1,0,1,1,0,1 },  // = 2
                                                           { 1,1,1,1,0,0,1 },  // = 3
                                                           { 0,1,1,0,0,1,1 },  // = 4
                                                           { 1,0,1,1,0,1,1 },  // = 5
                                                           { 1,0,1,1,1,1,1 },  // = 6
                                                           { 1,1,1,0,0,0,0 },  // = 7
                                                           { 1,1,1,1,1,1,1 },  // = 8
                                                           { 1,1,1,0,0,1,1 }   // = 9
                                                           };


void setup(){
/*  pinMode(2, OUTPUT);   
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  */
  writeDot(0);  // start with the "dot" off
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH); 
  Serial.begin(9600); 
  

}
void writeDot(byte dot) {
  digitalWrite(9, dot);
}
    
/*void sevenSegWrite(byte digit) {
  byte pin = 2;
  for (byte segCount = 0; segCount < 7; ++segCount) {
    digitalWrite(pin, seven_seg_digits[digit][segCount]);
    ++pin;
  }
}
*/

void loop(){
  int soil_moisture=analogRead(A0);  // read from analog pin A0
//  byte digval;

//  digval = soil_moisture/100;
  
  Serial.println(soil_moisture);
  if (soil_moisture > 800){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
  } else if (soil_moisture < 450){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    
  }
//  Serial.println(digval);
//  sevenSegWrite(digval);
  delay(2000);
}


