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

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
#include "Functions.h" //Matt and Banj External Functions file
#include "UXLib.h" //Our little cosmetic function pack
/*
         ,----,
       .'   .`|                                           ,--.
    .'   .'   ;   ,----,     ,----..        ,---,       ,--.'|
  ,---, '    .' .'   .' \   /   /   \    ,`--.' |   ,--,:  : |
  |   :     ./,----,'    | /   .     :  /    /  :,`--.'`|  ' :
  ;   | .'  / |    :  .  ;.   /   ;.  \:    |.' '|   :  :  | |
  `---' /  ;  ;    |.'  /.   ;   /  ` ;`----':  |:   |   \ | :
    /  ;  /   `----'/  ; ;   |  ; \ ; |   '   ' ;|   : '  '; |
   ;  /  /      /  ;  /  |   :  | ; | '   |   | |'   ' ;.    ;
  /  /  /      ;  /  /-, .   |  ' ' ' :   '   : ;|   | | \   |
./__;  /      /  /  /.`| '   ;  \; /  |   |   | ''   : |  ; .'
|   : /     ./__;      :  \   \  ',  /    '   : ||   | '`--'
;   |/      |   :    .'    ;   :    /     ;   |.''   : |
`---'       ;   | .'        \   \ .'      '---'  ;   |.'
            `---'            `---`               '---'

										Official Code By

  __  __       _   _     _    _       _     _      _
 |  \/  |     | | | |   | |  | |     (_)   | |    | |
 | \  / | __ _| |_| |_  | |__| | __ _ _  __| | ___| |_
 | |\/| |/ _` | __| __| |  __  |/ _` | |/ _` |/ _ \ __|
 | |  | | (_| | |_| |_  | |  | | (_| | | (_| |  __/ |_
 |_|  |_|\__,_|\__|\__| |_|  |_|\__,_|_|\__,_|\___|\__|

                        and
  _   _ _      _       ____             _                 _ _
 | \ | (_)    | |     / __ \           | |               (_|_)
 |  \| |_  ___| | __ | |  | |_   _  ___| |__   __ _ _ __  _ _
 | . ` | |/ __| |/ / | |  | | | | |/ _ \ '_ \ / _` | '_ \| | |
 | |\  | | (__|   <  | |__| | |_| |  __/ |_) | (_| | | | | | |
 |_| \_|_|\___|_|\_\  \____/ \__, |\___|_.__/ \__,_|_| |_| |_|
                              __/ |                     _/ |
                             |___/                     |__/
*/




/*
           __          __        ___  __
\  /  /\  |__) |  /\  |__) |    |__  /__`
 \/  /~~\ |  \ | /~~\ |__) |___ |___ .__/

*/
#define RIGHT 0;
#define LEFT 1;


//potentiometer direction tracking
int deltaPot = 0;

/*
 ___            __  ___    __        __
|__  |  | |\ | /  `  |  | /  \ |\ | /__`
|    \__/ | \| \__,  |  | \__/ | \| .__/

*/
task updateSensors(){
	while(true){
		int potVal = SensorValue(actuatPoten);
		wait1Msec(100);
		deltaPot = potVal-SensorValue(actuatPoten);
	}
}

task openClaw(){
	motor[claw] = 50;
	wait10Msec(20);
	motor[claw] = 0;
	stopTask(openClaw);
}

task closeClaw(){
	motor[claw] = -50;
	wait10Msec(20);
	while(vexRT(Btn8R)){
		motor[claw] = -25;
	}
	motor[claw] = 0;
	stopTask(closeClaw);
}


/*
    .          .
   / \        _|_
  /___\  .  .  |   .-. .--.  .-. .--.--.  .-. .  . .--.
 /     \ |  |  |  (   )|  | (   )|  |  | (   )|  | `--.
'       ``--`- `-' `-' '  `- `-' '  '  `- `-' `--`-`--'
*/
void pre_auton()
{
	bStopTasksBetweenModes = true;
}

task autonomous()
{
	//Robot Should be facing their respective star farthest on their side at start
int side = 0;
switch(side){
	case LEFT
	//Forward
	//Scoop
	//Turn 90
	//Forward
	//Turn 180
	//Release Chamber
	//Load Chamber
	//Release Chamber

	break;

	case RIGHT

	break;
}

}


/*
.--.                                .--.           .           .
|   :      o                       :              _|_          |
|   |.--.  .  .    ._ .-. .--.     |     .-. .--.  |  .--. .-. |
|   ;|     |   \  /  (.-' |        :    (   )|  |  |  |   (   )|
'--' '   -' `-  `'    `--''         `--' `-' '  `- `-''    `-' `-
*/
task usercontrol()
{
	startTask (updateSensors);
	while (true)
	{
		//Driving
		motor[leftBack] = vexRT(Ch3) - vexRT(Ch4);
		motor[leftFront] = vexRT(Ch3)+ vexRT(Ch4);
		motor[rightFront] = vexRT(Ch2) - vexRT(Ch1);
		motor[rightBack] = vexRT(Ch2) + vexRT(Ch1);

		//Lifter
		motor[leftLift] = (!SensorValue(leftLimit))*vexRT(Btn6U)*100 - vexRT(Btn6D)*100;
		motor[rightLift] = (!SensorValue(rightLimit))*vexRT(Btn6U)*100 - vexRT(Btn6D)*100;

		//Actuator
		motor[actuator] = vexRT(Btn8U)*100 - vexRT(Btn8D)*100;

		//Claw
		if(vexRT(Btn8L)) startTask(openClaw);
		if(vexRT(Btn8R)) startTask(closeClaw);

		//Auto-open the claw
		if(SensorValue(actuatPoten)<=300 && deltaPot<-10) startTask(openClaw);
	}
}

/*
                                               ,w.
                                             ,YWMMw  ,M  ,
                        _.---.._   __..---._.'MMMMMw,wMWmW,
                   _.-""        """           YP"WMMMMMMMMMb,
                .-' __.'                   .'     MMMMW^WMMMM;
    _,        .'.-'"; `,       /`     .--""      :MMM[==MWMW^;
 ,mM^"     ,-'.'   /   ;      ;      /   ,       MMMMb_wMW"  @\
,MM:.    .'.-'   .'     ;     `\    ;     `,     MMMMMMMW `"=./`-,
WMMm__,-'.'     /      _.\      F"""-+,,   ;_,_.dMMMMMMMM[,_ / `=_}
"^MP__.-'    ,-' _.--""   `-,   ;       \  ; ;MMMMMMMMMMW^``; __|
           /   .'            ; ;         )  )`{  \ `"^W^`,   \  :
          /  .'             /  (       .'  /     Ww._     `.  `"
         /  Y,              `,  `-,=,_{   ;      MMMP`""-,  `-._.-,
fsc     (--, )                `,_ / `) \/"")      ^"      `-, -;"\:
         `"""                    `"""   `"'                  `---"
*/
