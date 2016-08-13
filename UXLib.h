#pragma config(Sensor, in8,    actuatPoten,    sensorPotentiometer)
#pragma config(Sensor, dgtl1,  rightLimit,     sensorTouch)
#pragma config(Sensor, dgtl2,  rightLower,     sensorTouch)
#pragma config(Sensor, dgtl11, leftLower,      sensorTouch)
#pragma config(Sensor, dgtl12, leftLimit,      sensorTouch)
#pragma config(Motor,  port1,           rightBack,     tmotorVex393, openLoop)
#pragma config(Motor,  port2,           rightFront,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           rightLift,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,           claw,          tmotorVex269, openLoop)
#pragma config(Motor,  port5,           actuator,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           leftLift,      tmotorVex393, openLoop)
#pragma config(Motor,  port9,           leftFront,     tmotorVex393, openLoop)
#pragma config(Motor,  port10,          leftBack,      tmotorVex393, openLoop)
/*
 ___  ___      ___    ___                 ___           ___      ________
|\  \|\  \    |\  \  /  /|               |\  \         |\  \    |\   __  \
\ \  \\\  \   \ \  \/  / / ____________  \ \  \        \ \  \   \ \  \|\ /_
 \ \  \\\  \   \ \    / / |\____________\ \ \  \        \ \  \   \ \   __  \
  \ \  \\\  \   /     \/  \|____________|  \ \  \____    \ \  \   \ \  \|\  \
   \ \_______\ /  /\   \                    \ \_______\   \ \__\   \ \_______\
    \|_______|/__/ /\ __\                    \|_______|    \|__|    \|_______|
              |__|/ \|__|

              Functions to add cool details to the robot
*/

//Displays Team Splash Screen and plays startup sound
void displaySplash(){

}

//Runs basic battery and sensor diagnostics
void runDiagnostics(){

}

//Plays Horn tone
void playHorn(){
	playTone(100, 1);
}
