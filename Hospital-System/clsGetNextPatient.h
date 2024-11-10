#pragma once

#include "GlobalSpecialization.h"
#include "clsSpecializationLogic.h"

class clsGetNextPatient {

public:

	static void GetNextPatient() {

		short number = readIn::ReadNumberBetweenFromTo(1, 20, "\nEnter specialization : ", "Number is out of Range, Please enter a vaild number [1:20] >> ");
		Specialization[number].GetNextPatient();

	}



};

