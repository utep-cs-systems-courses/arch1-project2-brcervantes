## Description
This program uses interrupts and timers to switch between the functionallity of the top 4 buttons on the MSP430 board. Each button has a different function (from left to right on the MSP430 board);

The 1st button when pressed will count to 3 in binary using the LEDS, upon each click of the button the count will be increased by 1 using the state_machine.c.

The 2nd button when pressed will play the melody Windmill/Song of Storms from the Legend of Zelda. The song will repeat until the 4th button is pressed. When a note is being played the green LED is displayed, when there is no note playing the red LED is displayed.

The 3rd button will alternate between fading the green LED and the red LED with each press.

The 4th and final button will reset the state of the first 3 buttons. It resets the LEDs and the buzzer.

## How To Run
To run the Blinky Buzzy Toy you must be in this directory to run the command **make load** 
