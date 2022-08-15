# Automated-Pump-Station
Embedded C program that runs a fully automated pump station with an ATMega328P Microprocessor, one ultrasonic sensor, one backup mechanical float switch, two
relay modules, two pumps, and six LEDs.

The program initially sets all the input and output pins in the header as well as in the setup function.

Once the program is initialized, it conintuous monitors the water level in the pump station holding tank with an ultrasonic sensor.

If water level reaches 25% of the wet tank's capacity, the '25% Full' indication light will illuminate.

If water level reaches 50% of the wet tank's capacity, the '50% Full' indication light will illuminate and the program and will 
command Pump #1 on through the microcontroller and relay.

If water level reaches 75% of the wet tank's capacity, the '75% Full' indication light will illuminate and the program and will 
command Pump #2 on through the microcontroller and relay. This is an 'abnormal flow' condition which requires the extra capability 
of a second pump.

If water level reaches 100% of the wet tank's capacity, the '100% Full' indication light will illuminate and the 'Warning' indication
light will illuminate.

If the ultrasonic sensor fails, the wet tank will fill until the water level trips the backup mechanical sensor. In this state, the program
will command both pumps to run for 30 seconds, approximately enough time for the water level to reduce to 10% of the wet tanks capacity, depending
on flow conditions.

If the microcontroller itself fails, the relays will return to their normally closed state, both pumps will run continuously until power to them
is shut off, and a warning light will illuminate.
