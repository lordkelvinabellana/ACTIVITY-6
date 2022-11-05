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
  round_robin(); //calling the function.
}

void round_robin(){
  int time_quantum = 2000;
  int burst_time[6] = {3000, 5000, 2000, 1000, 6000, 4000};
  int pin[6] = {6, 5, 4, 3, 2, 1};
  int ready_queue[6];
  int arrival_time[6] = {0, 5000, 2000, 3000, 6000, 5000};
  int time = 0;
  
  int temp;
  for (int i=0; i<6; i++){
    for (int j=0; j<6; j++){
      if (arrival_time[i] < arrival_time[j]){
      	temp = arrival_time[i];
        arrival_time[i] = arrival_time[j];
        arrival_time[j] = temp;
        
        temp = burst_time[i];
        burst_time[i] = burst_time[j];
        burst_time[j] = temp;
        
        temp = pin[i];
        pin[i] = pin[j];
        pin[j] = temp;
      }
    }
  }
  
  for (int i=0; i<6; i++){
  	digitalWrite(pin[i], HIGH);
    delay(time_quantum);
    digitalWrite(pin[i], LOW);
    burst_time[i] = burst_time[i] - time_quantum;
  
  }
  
}
