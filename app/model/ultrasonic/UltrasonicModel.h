//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_ULTRASONICMODEL_H
#define KETCHUPHOUSE_ULTRASONICMODEL_H

#include "../../../framework/hardware/IUltrasonicSensor.h"

using namespace Interfaces::Hardware;

namespace Model {
	class UltrasonicModel
	{
	public:
		UltrasonicModel(IUltrasonicSensor &ultrasonicSensor) : ultrasonicSensor(ultrasonicSensor)
		{
			ultrasonicSensor.enable();
			distance = ultrasonicSensor.getDistanceInCm();
		}

		bool isGatePenetrated();

	private:
		double distance;

		IUltrasonicSensor &ultrasonicSensor;
	};
}


#endif //KETCHUPHOUSE_ULTRASONICMODEL_H
