#pragma once

#include "GlobalSpecialization.h"
#include "clsSpecializationLogic.h"

#include "ReadInput.h"

class clsAddNewPatient {

public:

	static void AddNewPatient() {

		short NumberOfSpecialization = readIn::ReadNumberBetweenFromTo(1, 20, "\nEnter Specialization : ", "Number is out of Range, Please enter a vaild number [1:20] >> ");
		short numberOfWaitingList = Specialization[NumberOfSpecialization].NumberOfPatientINWaitingList();

		if (numberOfWaitingList == 5) {

			std::cout << "Sorry we can`t add more patients for this specialization\n";
			return;

		}

		std::string nameOfPatient = readIn::ReadText("Enter your name : ");
		bool status = 0;
		std::cout << "Enter your status : ";
		std::cin >> status;

		Specialization[NumberOfSpecialization].AddNewPatients(nameOfPatient, status);

	}


};

