//
// Created by Martin Mikšík on 21/04/16.
//

#ifndef KETCHUPHOUSE_IENGINE_H
#define KETCHUPHOUSE_IENGINE_H

namespace Interfaces {
	namespace Hardware {
		class IMotor
		{
		public:
			IMotor()
			{}

			virtual ~IMotor()
			{}

			virtual void setPower(int power) = 0;
		};
	}
}

#endif //KETCHUPHOUSE_IENGINE_H
