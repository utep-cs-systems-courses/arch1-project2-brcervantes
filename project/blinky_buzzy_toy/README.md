## Description
This directory contains the programs that run the blinky_buzzy_toy.


## How to Use

The Makefile in this direcory contains rules to run the Makefile in the toy directory. Use **make** in this directory to the toy program and the timer library. Once the program is built, you can load the program onto the MSP430 by changing into the corresponding toy directory and using **make load**.

You may use **mspdebug rf2500 "erase"** to clear a program from the MSP430.
