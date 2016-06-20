//
// Created by Martin Mikšík
//

#include "GateControl.h"
#include "../../../../framework/Helpers/Helpers.h"

void GateControl::threadTask()
{
	do {
		if (stepQueue.empty()) {
			continue;
		}

		bool task = stepQueue.front();
		stepQueue.pop();

		if (task) {
			leftMotor.setPower(-80);
			rightMotor.setPower(80);
			Helpers::delay(600);
			leftMotor.setPower(0);
			rightMotor.setPower(0);
		} else {
			leftMotor.setPower(80);
			rightMotor.setPower(-80);
			Helpers::delay(600);
			leftMotor.setPower(0);
			rightMotor.setPower(0);
		}

		/*if (task.first == 0) {
			if (task.second == 0) {
				leftMotor.setPower(-80);
				Helpers::delay(600);
				leftMotor.setPower(0);
			}else if (task.second == 1){
				leftMotor.setPower(80);
				Helpers::delay(600);
				leftMotor.setPower(0);
			}
		} else if (task.first == 1) {
			if (task.second == 0) {
				rightMotor.setPower(80);
				Helpers::delay(600);
				rightMotor.setPower(0);
			}else if (task.second == 1){
				rightMotor.setPower(-80);
				Helpers::delay(600);
				rightMotor.setPower(0);
			}
		}*/



	}

	while (repeatTask);
}

/*

void GateControl::openLeft()
{
	stepQueue.push(make_pair(1, 0));
}

void GateControl::openRight()
{
	stepQueue.push(make_pair(1, 1));
}

void GateControl::closeLeft()
{
	stepQueue.push(make_pair(0, 0));
}

void GateControl::closeRight()
{
	stepQueue.push(make_pair(0, 1));
}
*/

void GateControl::release()
{
	stepQueue.push(false);
}

void GateControl::gatePenetrated()
{
	if (stackSize == stackMaxSize) {
		Helpers::dump(Helpers::Warning, "Both stacks are full");
	} else if (stackSize < stackMaxSize) {
		stackSize++;
	}

	if (stackSize == stackMaxSize && !stackFull) {
		stackFull = true;
		Helpers::dump(Helpers::Info, "Closing stacks");
		Helpers::delay(1000);
		stepQueue.push(false);
	}
}