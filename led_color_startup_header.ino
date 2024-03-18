//the autostart code written by Caleb Dasher

/* Connect SCL    to 20 (SDA)
   Connect SDA    to 21 (SCL)
   Connect VDD    to 3.3V DC
   Connect GROUND to common ground */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

// returns percent change from one iteration to the next
float percent_change(int prev, int next)
{
   float val = (float(next-prev)/float(prev))*100;
   Serial.print("Percent change\n");
   Serial.println(val);
  return (float(next-prev)/float(prev))*100;
}
// returns true of enabled has changed more than the percent change specified
// currently configured to run with green led input
bool start_light_enabled(float percent_0_to_1)
{
  // flag to set up the function on first call
  static bool first_run = 1;
  // store values from tcs.getRGB
  float red, green, blue;
  tcs.getRGB(&red, &green, &blue);
  // store the colors as ints
  //int red_val = int(red);
  int green_val = int(green);
  //int blue_val = int(blue);
  // create persistent ints that store result of previous tcs function
  //static int old_red;
  static int old_green;
  //static int old_blue;
  // set the old colors to current colors if first function call is invoked
  if (first_run == 1) {
    //old_red = red_val;
    old_green = green_val;
     Serial.print("Initial value\n");
     Serial.println(old_green);
    //old_blue = blue_val;
    first_run = 0;
  }
  if (percent_change(old_green, green_val) >= percent_0_to_1)
  {
     Serial.print("Final value\n");
     Serial.println(green_val);
    return 1;
  }
  else {
    return 0;
  }
}
// sets up and runs the sensor module 
// input time delay in ms in increments of 50 ms after which the function will return regardless of sensor input
// input sensor percent change needed to detect light, about 0.1 is good
void start_up(float max_time_delay_ms, float percent_0_to_1) {
  static bool start = 0;
  float time_delay = 0;
  float red, green, blue;
  tcs.getRGB(&red, &green, &blue);
  //Serial.print("R: "); Serial.print(int(red));
  Serial.print("\tG: "); Serial.print(int(green));
  //Serial.print("\tB: "); Serial.print(int(blue));
  // runs until the sensor change is greater percent_0_to_1 or until max time delay has elapsed
  while (start_light_enabled(percent_0_to_1) != 1) {
    time_delay += 50;
    if (time_delay > max_time_delay_ms){
      break;
    }
   Serial.print("Starting\n");
  }
}
