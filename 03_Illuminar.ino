
int irOutLed = 8;                 // IR Led
int irSensor = 0; // IR phototransistor
float irSensorVal=0;

int irDelta=100;
int irBase=25;
int irMax=200;


int t1=0;
int t2=0;

int state=0; // 0= off, 1 = on
int handposition=0; // 0 = off, 1 = on

int dimMode=0;
int minDim=5;
int maxDim=255;
int dimVal=200;
int readyForChange=1;


int pwmOut=9;

unsigned long lastTime;
int timeDelta=500;


void switchState(){
  if(readyForChange==1){
    if(state == 0 ){
      state = 1;
    }else{
      state = 0;
    }
    readyForChange=0;
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

    if(irSensorVal > 1000){
      irSensorVal = 1000;
    }
    
}




void setup()
{
  pinMode(irOutLed, OUTPUT);      
  pinMode(pwmOut, OUTPUT);     
  digitalWrite(irOutLed, HIGH);  

  Serial.begin(9600);
  
}




void loop() { 


  unsigned long thisTime= millis();
  
  //if( thisTime >= lastTime + timeDelta){
   // Serial.print(thisTime);
   // Serial.println("BINGO");   
   // lastTime=thisTime;
  //}
  
  readIR();


  if( irSensorVal >= (t1 + irDelta) ){
    //switchState();
    if(handposition == 0){
      lastTime=thisTime;
      handposition=1;
    }else if(handposition == 1){
      if(thisTime >= lastTime + timeDelta){
        if(dimMode == 0){
          dimMode=1;
        }
      }     
    } 
  }else if(irSensorVal <  (t1 + irDelta) ){
    if(thisTime < lastTime + timeDelta){
      if(handposition == 1){
        if(state == 0 ){
          state = 1;
        }else{
          state = 0;
        }
      }
    }
      handposition=0;
      dimMode=0;
  }



if(dimMode==1){
  dimVal= map(irSensorVal, 0, 1000, 0, 255);
  if(dimVal < minDim){
    dimVal = minDim;
  }
  
  if(dimVal > maxDim){
    dimVal = maxDim;
  }
  
}

  
  if(state == 1){
    analogWrite(pwmOut,dimVal);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255  
  }else if(state == 0){
    analogWrite(pwmOut,0);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255  

  }


   Serial.print("STATE: ");
   Serial.print(state);
   
   Serial.print("   HAND: ");
   Serial.print(handposition);


  Serial.print("   IR Val:"); 

  Serial.print(irSensorVal);


    
  Serial.println("");

}


