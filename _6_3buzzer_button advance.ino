// C++ code
//
//#define A2 110
//#define B2 123

#define P  0
#define C3 131
#define C3s 139
#define D3 147
#define D3s 156
#define E3 165
#define F3 175
#define F3s 185
#define G3 196
#define G3s 208
#define A3 220
#define A3s 233
#define B3 247
#define C4 262


#define aa5 A5
#define aa4 A4
#define aa1 A1
#define aa0 A0



int  m[100]={0};
int mi=0;

  
int t[]={
  4,4,4,4,4,4,4,4,4,4,
  4,4,4,4,4,4,4,4,4,4,
  4,4,4,4,4,4,4,4,4,4,
  4,4,4,4,4,4,4,4,4,4,
  4,4,4,4,4,4,4,4,4,4,
  4,4,4,4,4,4,4,4,1,4,
  3,
};

int ledp[14]={
	2,3,4,5,6,7,8,9,10,11,12,aa5,aa4,aa1
};
byte pb1=0, bs1=0; 
byte pb2=0, bs2=0; 
byte pb3=0, bs3=0; 
byte pb4=0, bs4=0; 
byte pb5=0, bs5=0; 
byte pb6=0, bs6=0; 
byte pb7=0, bs7=0; 
byte pb8=0, bs8=0; 
byte pb9=0, bs9=0; 
byte pb10=0, bs10=0; 
byte pb11=0, bs11=0; 
byte pb12=0, bs12=0; 
byte pb13=0, bs13=0; 
byte pmb=0, mbs=0;
byte mode=0;//0:play 1:record

void record(){
   
     
  
      bs1 = digitalRead(2);
      bs2 = digitalRead(3);
      bs3 = digitalRead(4);
      bs4 = digitalRead(5);
      bs5 = digitalRead(6);
      bs6 = digitalRead(7);
      bs7 = digitalRead(8);
      bs8 = digitalRead(9);
      bs9 = digitalRead(10);
      bs10 = digitalRead(11);
      bs11 = digitalRead(12);
      bs12 = digitalRead(A5);
      bs13 = digitalRead(A4);
 
 
     if(bs1==0){
       // pb1=0;
      tone(13,C3,200); delay(201);
      m[mi]=C3;
       mi++;
      }
    else  if(bs2==0){
       // pb2=0;
      tone(13,C3s,200); delay(201);
       m[mi]=C3s;
       mi++;
      } 
    else  if(bs3==0){
       // pb3=0;
     tone(13,D3,200); delay(201);
       m[mi]=D3;
       mi++;
      }
       
      else if(bs4==0){
        // pb4=0;
     tone(13,D3s,200); delay(201);
       m[mi]=D3s;
       mi++;
      } 
      else if(bs5==0){
       //  pb5=0;
     tone(13,E3,200); delay(201);
       m[mi]=E3;
       mi++;
      }  
      else  if(bs6==0){
       //  pb6=0;
     tone(13,F3,200); delay(201);
       m[mi]=F3;
       mi++;
      } 
      else  if(bs7==0){
         pb7=0;
     tone(13,F3s,200); delay(201);
       m[mi]=F3s;
       mi++;
      }  
      else  if(bs8==0){
         pb8=0;
     tone(13,G3,200); delay(201);
       m[mi]=G3;
       mi++;
      } 
      else  if(bs9==0){
        // pb9=0;
     tone(13,G3s,200); delay(201);
       m[mi]=G3s;
       mi++;
      }  
      else  if(bs10==0){
       //  pb10=0;
     tone(13,A3,200); delay(201);
       m[mi]=A3;
       mi++;
      }  
       else if(bs11==0){
       //  pb11=0;
     tone(13,A3s,200); delay(201);
       m[mi]=A3s;
       mi++;
      }  
      else if(bs12==0){
        // pb12=0;
     tone(13,B3,200); delay(201);
       m[mi]=B3;
       mi++;
      }  
     else if(bs13==0){
       //  pb13=0;
     tone(13,C4,200); delay(201);
       m[mi]=C4;
       mi++;
      }  
   	else {
 	 tone(13,P,200); delay(201);
       m[mi]=P;
       mi++;
 	 }
   if(mi==99){mode=!mode;mi=0;}
 mbs = digitalRead(A1);
  if(mbs==0&&pmb==1){
    pmb=0;
    mode=!mode;
   mi=0;
  }
  if(mbs==1&&pmb==0){
  pmb=1;
  }
	if(mode==1){
 	  digitalWrite(aa0,HIGH);
  	}
	  else digitalWrite(aa0,LOW);

}

void play(){

 
  
  tone(13,m[mi],200);delay(201);
		mi++;
  if(mi==99)mi=0;
  mbs = digitalRead(A1);
 	 if(mbs==0&&pmb==1){
 	   pmb=0;
  	  mode=!mode;
       mi=0;
  	}
 	 if(mbs==1&&pmb==0){
 	 pmb=1;
  }
  if(mode==1){
   digitalWrite(aa0,HIGH);
  }
  else digitalWrite(aa0,LOW);
}
void setup()
{
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
    pinMode(6, INPUT_PULLUP);
    pinMode(7, INPUT_PULLUP);
    pinMode(8, INPUT_PULLUP);
    pinMode(9, INPUT_PULLUP);
    pinMode(10, INPUT_PULLUP);
    pinMode(11, INPUT_PULLUP);
    pinMode(12, INPUT_PULLUP);
   // pinMode(13, OUTPUT);
    pinMode(aa5, INPUT_PULLUP);
    pinMode(aa4,INPUT_PULLUP);
   pinMode(aa1,INPUT_PULLUP);
   pinMode(aa0,OUTPUT);
    // pinMode(aa1, OUTPUT);
   Serial.begin(9600);
}

void loop()
{
  mbs = digitalRead(A1);
  if(mbs==0&&pmb==1){
    pmb=0;
    mode=!mode;
    mi=0;
  
  }
  if(mbs==1&&pmb==0){
  pmb=1;
  
  } 
  if(mode==1){
   digitalWrite(aa0,HIGH);
  }
  else digitalWrite(aa0,LOW);
  
  
  while(mode==1){
 
    record();
    Serial.println("RECORD MODE ");
        Serial.println(mi);
    
  }
  while(mode==0){ 
   	  Serial.println("PLAY MODE ");     
       Serial.println(mi);
      play();
       
         }
 

}
  