#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8,9}; //connect to the column pinouts of the keypad

char correctPass[4];
char pass[4];
int currentIndex;

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  Serial.println("Program started");

  pass[0]=' ';
  pass[1]=' ';
  pass[2]=' ';
  pass[3]=' ';
  correctPass[0]='1';
  correctPass[1]='2';
  correctPass[2]='3';
  correctPass[3]='4';
  currentIndex=-1;
}
  
void loop(){
  
  
  char key = keypad.getKey();
    // just print the pressed key
   if (key){
    Serial.println("Key pressed:");
    Serial.println(key);
    
    if(currentIndex<3){
      currentIndex++;
      pass[currentIndex]=key;
      Serial.println("Current Password");
      int numchars=currentIndex+2;
      Serial.println(pass);
      Serial.println("_____________________");
    }

    if(currentIndex==3){

      if(checkPass()){
        Serial.println("Correct Password");
        }
      else{
        Serial.println("Incorrect Password");
        }

        
      
      pass[0]='a';
      pass[1]='a';
      pass[2]='a';
      pass[3]='a';
      currentIndex=-1;
      pass[currentIndex]=key;
    }

    
    
    } 
}

boolean checkPass(){
  for(int i=0;i<4;i++)
  {
    if(correctPass[i]!=pass[i]){
      return false;
      }
  }
    return true;
  }
