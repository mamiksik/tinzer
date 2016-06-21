//
// Created by Renata
//

#ifndef KETCHUPHOUSE_IBUTTON_H
#define KETCHUPHOUSE_IBUTTON_H

namespace Interfaces {
	namespace Hardware {

		class IButton
		{
		public:
			IButton()
			{}

			virtual ~IButton()
			{}

			virtual bool isPressed() = 0;
		};
	}
}
#endif //KETCHUPHOUSE_IBUTTON_H
