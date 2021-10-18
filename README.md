# Group_222 ENCE260 Project - Maze Runner

A speed running maze game run on a UCFK4 microcontroller.

## Set up

Mount the UCFK4 to a usb port on the computer.

First, navigate to the group_222 folder in the terminal.

```bash
$ cd ../ence260-ucfk4/assignment/group_222/
```

Then compile the program using the Makefile.

```bash
$ make
```

Run the game using the make program command.

```bash
$ make program
```

External LEDs are needed to be connected to the UCFK4 to display remaining collectables, but the game is playable without.

Each LED is connected in order, to the bottom five pins on the header through a 330ohm resistor to the LEDs anode(long leg).
The cathode of each LED is connected to ground(Top pin on header).

## Playing the game

Use the navswitch to run around the (16x20) maze and grab all the collectables (flashing dots) in the maze as fast as you can. There are three levels, and five collectables in each level. Try and get the fastest time (NOTE: time is in deciseconds (seconds*10)). To replay the game, press the navswitch. You can reset the game using the 'reset' button (S2), and then start it again by holding the button (S3) and pressing the 'reset' (S2) button.

## Authors

Artemis Hingston - 83986198 - irh20@uclive.ac.nz

Robert Beck - 27223174 - rbe78@uclive.ac.nz
