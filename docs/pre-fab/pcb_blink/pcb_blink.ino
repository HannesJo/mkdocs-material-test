//Defining which pin to use for LED and button
#define LED 4
#define BUTTON 0

//Variable to count number of button press
int cnt = 0;
//Timer before executing the blink
int cntpause = 0;

void setup() { 
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() { 
  //Check if Button is pressed -> counter +1
  if(digitalRead(BUTTON) == LOW){
    cnt++;  
    cntpause=0;
    while(digitalRead(BUTTON) == LOW){
      //wait
    }
    digitalWrite(LED, HIGH);
    delay(50);
    digitalWrite(LED, LOW);
    delay(50);      
  //Check if button has been pressed at least once and if timer has reached 200 -> then start blink
  }else if(cnt > 0 && cntpause > 200){
    for(int i = 0; cnt > i; i++){
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);     
    }
    //reset counter and timer
    cntpause=0;
    cnt=0;
  //Check if button has been pressed at least once and increase timer counter by 10ms
  }else if(cnt > 0){
    cntpause++;
    delay(10);
  }

}
