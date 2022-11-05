void setup()
{
  pinMode(6, OUTPUT); //set port 6 to output
  pinMode(5, OUTPUT); //set port 5 to output
  pinMode(4, OUTPUT); //set port 4 to output
  pinMode(3, OUTPUT); //set port 3 to output
  pinMode(2, OUTPUT); //set port 2 to output
  pinMode(1, OUTPUT); //set port 1 to output
}

void loop()
{
  FIFO(); //calling the function.
}

void FIFO(){
  int time[6] = {3000, 5000, 2000, 1000, 6000, 4000};
  //above are the time delay in milliseconds to be used
  //in each of the LEDs that will be used in the implementation.
  int count = 0; 
  //used to initialize the count or the number of times the function loops
  for (int i=6; i>=1; i--){
    
    digitalWrite(i, HIGH); //this command turns the LED ON.
    delay(time[count]); 
    //the numbers stored in the time array will be used
    //according to how many times the function loops.
    //for example, if the function starts, the loop count will be zero,
    //so the time delay that the LED will use will be on time[0].
    //same as if the loop has started a second time, hence loop count will be 1
    //so the new time delay that will be used in the loop will now be time[1] 
    digitalWrite(i, LOW); //this command turns the LED OFF.
    count++; //Increment count by 1.
  }
}
