#include <iostream>
#include <stdlib.h>
#include <Aria.h>
#include <ArActionDriveDistance.h>

#include "forward.h"
// Implementation

// Constructor
forward::forward() : ArAction("Go forward")
{
	speed = 0; // Set the robots speed to 50 mm/s. 200 is top speed
}

// Body of action
ArActionDesired * forward::fire(ArActionDesired d)
{
	desiredState.reset(); // reset the desired state (must be done)



	deltaheading = 0; // Straight line initial

	
		

	int sonarZero = myRobot->getSonarRange(0);
	int sonarOne = myRobot->getSonarRange(1);
	int sonarTwo = myRobot->getSonarRange(2);
	int sonarThree = myRobot->getSonarRange(3);
	int sonarFour = myRobot->getSonarRange(4);
	int sonarFive = myRobot->getSonarRange(5);
	int sonarSix = myRobot->getSonarRange(6);
	int sonarSeven = myRobot->getSonarRange(7);


	//speed will climb to 200 by default.
	if (speed < 200) speed++;


	int ifChangeRand1 = rand() % 2 + 0; //Whether to change direction
	int dirTurn2 = rand() % 2 + 0; //direction of turn


	// wander behaviour
		if (ifChangeRand1 == 1)
		{
			if (dirTurn2 == 0) //left turn
			{
				printf("Wandering mode: left turn\n");
				deltaheading = dirTurn2 + 30;
			}
			if (dirTurn2 == 1)
			{
				printf("Wandering mode: right turn\n");
				deltaheading = dirTurn2 - 30;
			}
	
			
		}
	

	//avoidance
		if (sonarZero < 500 || sonarOne < 500 || sonarTwo < 500)
		{
			deltaheading = -45;
			printf("Left sonar detects an object\n");
		}
		if (sonarThree < 500 || sonarFour < 500)
		{
			deltaheading = 65;
			printf("Middle sonars detect an object\n");
		}	
		if (sonarFive < 500 || sonarSix < 500)
		{
			deltaheading = 45;
			printf("Right sonars detect an object\n");
		}






		// 1 = yes
		// 2 = no

	

		/*
	
	
	printf("ifChangeRand %d\n", ifChangeRand1);
	printf("dirTurn %d\n", dirTurn2);
	printf("dirConfirm %d\n", dirConfirm3);


	*/
	
	
	
	/*
	if (sonarZero < 600 || sonarOne < 500)
	{
		deltaheading = rand() % -25 -90;
	}

	if (sonarTwo < 600)
	{
		deltaheading = rand() % 25  -25;
	}
	if (sonarThree < 800 || sonarFour < 800)
	{
		deltaheading = rand() % 100 -100;
	}

	if (sonarFive < 600)
	{
		deltaheading = rand() % 25 + 0;
	}

	if (sonarSix < 600 || sonarSeven < 600)
	{
		deltaheading = rand() % 25 + 0;
	}


	*/


	//if (sonarZero < 1500)
	//{
		//deltaheading = -50;
	//}
	/*if (sonarOne < 1500)
		robot.move(0.5);

	if (sonarThree < 2000)
		robot.move(0.5);

	if (sonarFour < 1500)
		robot.move(0.5);


	if (sonarFive < 1500)
		
		robot.move(0.5);

	if (sonarSix < 1500)
		robot.move(0.5);

	if (sonarSeven < 1500)
		robot.move(0.5);

	if (sonarEight < 1500)
		robot.move(0.5);
	*/
	/*for (counter = rand() % 100 + 1; counter < 100; counter++) // TODO: Fix this
	{
		deltaheading = 30; // Straight line

	}*/


//	printf("speed %d deltheading %d counter %d\n", speed, deltaheading, sonarZero);
	desiredState.setVel(speed); // set the speed of the robot in the desired state
	desiredState.setDeltaHeading(deltaheading); // Set the heading

	printf("Speed: %d\t Delta heading: %d \t\n", speed, deltaheading);


	return &desiredState; // give the desired state to the robot for actioning
}


