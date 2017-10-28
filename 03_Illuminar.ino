
int irOutLed = 8;                 // IR Led
int irSensor = 0; // IR phototransistor
float irSensorVal=0;

int irDelta=100;
int irBase=20;
int irMax=230;

int t1=0;
int t2=0;

int state= 0; // 0= off, 1 = on


int pwmOut=9;




void switchState(){
  if(state == 0){
    state = 1;
  }else{
    state = 0;
  }
  
}


void readIR(){
    irSensorVal = analogRead(irSensor);
    irSensorVal += analogRead(irSensor);
    irSensorVal += analogRead(irSensor);
    irSensorVal = irSensorVal/3;

    irSensorVal = sqrt(irSensorVal);
    irSensorVal = irSensorVal*10;

    irSensorVal = map(irSensorVal, irBase, irMax, 0, 1000);
    
}




void setup()
{
  pinMode(irOutLed, OUTPUT);      
  pinMode(pwmOut, OUTPUT);     
  digitalWrite(irOutLed, HIGH);  

  Serial.begin(9600);
  
}




void loop() { 

  
  readIR();


  if( irSensorVal > (t1 + irDelta) ){
    switchState();
  }
  
  if(state == 1){
    analogWrite(pwmOut,200);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255  
  }else if(state == 0){
    analogWrite(pwmOut,0);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255  

  }


   Serial.print("STATE: ");
   Serial.print(state);



  Serial.print("   IR Val:"); 

  Serial.print(irSensorVal);


    
  Serial.println("");
  delay(20);    
}


