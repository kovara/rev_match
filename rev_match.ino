#include <PololuLedStrip.h>

#define LED_COUNT 45		// number of LEDS

// this block is to determine rpm_per_led.  You may declare rpm_per_led directly instead of using the variables
#define LED_DENSITY 6.9 	// mm per LED 
#define TACH_ARC 300		// arc of usable tach (0 rpm to max redline) in mm
#define TACH_REDLINE 8000	// redline of car
float rpm_per_led = TACH_REDLINE * LED_DENSITY / TACH_ARC

#define NUM_GEARS 6
#define GEAR_RATIO_1 5.087	// gear ratio for first gear
#define GEAR_RATIO_2 2.991	// gear ratio for second gear
#define GEAR_RATIO_3 2.035	// gear ratio for third gear
#define GEAR_RATIO_4 1.594	// gear ratio for fourth gear
#define GEAR_RATIO_5 1.286	// gear ratio for fifth gear
#define GEAR_RATIO_6 1.000	// gear ratio for sixth gear
#define GEAR_FINAL 2.866	// gear ration for final drive
#define TIRE_CIRCUM 3		// cirumference of tire in inches

#define GEAR_1_COLOR_R 1	// gear 1 color value for Red

PololuLedStrip<12> ledStrip;
rgb_color colors[LED_COUNT];
rgb_color color_blank;
rgb_color gear_colors[NUM_GEARS];
uint16_t gears_rpm[NUM_GEARS]
uint16_t gears_LED_loc[NUM_GEARS]

bool blink = false;

void initColors() {

}

uint16_t getSpeed() {
}

void getGearsRPM(uint16_t speed) {
	// engine RPM = speed (mph) * GEAR_RATIO * GEAR_FINAL / (TIRE_CIRCUM (inches) * Conversion factor (.00595)) 
	gears_rpm[0] = (speed * GEAR_RATIO_1 * GEAR_FINAL) / (TIRE_CIRUM * .00595)
	gears_rpm[1] = (speed * GEAR_RATIO_2 * GEAR_FINAL) / (TIRE_CIRUM * .00595)
	gears_rpm[2] = (speed * GEAR_RATIO_3 * GEAR_FINAL) / (TIRE_CIRUM * .00595)
	gears_rpm[3] = (speed * GEAR_RATIO_4 * GEAR_FINAL) / (TIRE_CIRUM * .00595)
	gears_rpm[4] = (speed * GEAR_RATIO_5 * GEAR_FINAL) / (TIRE_CIRUM * .00595)
	gears_rpm[5] = (speed * GEAR_RATIO_6 * GEAR_FINAL) / (TIRE_CIRUM * .00595)
}

void getRPMLoc() {
	for (uint16_t i = 0; i < NUM_GEARS; i++ 0 {
		gears_LED_loc[i] = int(gears_rpm[i] / rpm_per_led)
	}
}

void setup() {
  // init bluetooth/freematics connection

  // init colors for each gear
  initColors()
}

void loop() {
  if ( ) { //connection available
    speed = getSpeed()
    // determine rpms for all gears
    getGearsRPM(speed) //&gears_rpm)
    // determine LED number for each gear RPM
    getRPMLoc()    

    //turn off all LEDs
    for (uint16_t i = 0; i < LED_COUNT; i++) {
	colors[i] = color_blank;
    }
    // loop through each gear, set LED to correct color
    for (uint16_t i = 0; i < NUM_GEARS; i++ ) {
	// set the LED at the LED location for gear i to the color for gear i
        colors[gears_LED_loc[i]] = gear_colors[i]
    }
    // write colors to LED strip
    ledStrip.write(colors, LED_COUNT);
    
  } else {
    // if connection isn't available, flash LEDs and attempt to reconnect
    if (blink) {
      for (uint16_t i = 0; i < LED_COUNT; i++) {
        colors[i] = gear_colors[0];
    } else {
      for (uint16_t i = 0; i < LED_COUNT; i++) {
        colors[i] = color_blank;
    }
    blink = !blink
    // attempt reconnect...
}
