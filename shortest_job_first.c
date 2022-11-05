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
  SJ(); //calling the shortest job function.
}

void SJ(){
  int pin[6] = {6, 5, 4, 3, 2, 1};
  int time[6] = {3000, 5000, 2000, 1000, 6000, 4000};
  //an array of time in milliseconds to be used in delay function.
  //index 0 or the LED1 has a time of 3 seconds.
  //index 1 or the LED2 has a time of 5 seconds.
  //index 2 or the LED3 has a time of 2 seconds.
  //index 3 or the LED4 has a time of 1 second.
  //index 4 or the LED5 has a time of 6 seconds.
  //index 5 or the LED6 has a time of 4 seconds.
  
  //with the given burst time, the first to be executed is the LED4 
  //followed by LED3, LED1, LED6, LED2 and lastly LED5.
  
  int temp; //temporary value used in swapping.
  
  for (int i=0; i<6; i++){
    for (int j=0; j<6; j++){
      if (time[i] < time[j]){
      	temp = time[i];
        time[i] = time[j];
        time[j] = temp;
        
        temp = pin[i];
        pin[i] = pin[j];
        pin[j] = temp;
      }
    }
  }
  //this loop will sort out the elements in the array.
  //the loop will check if the element after the the "i" pointer is lessthan the current element.
  //if it is, then a swapping of elements will now begin.
  //using the temp variable, the swaping process will be much easier.
  
  //after executing this loop, the time array as well as pin array will be sorted in ascending.
  //INCREASING ORDER
  int count = 0; //used to identifies the element of time array.
  while (count != 6){
  	digitalWrite(pin[count], HIGH);
    delay(time[count]);
    digitalWrite(pin[count], LOW);
    count++;
  } //executes shortest job scheduling.
}
