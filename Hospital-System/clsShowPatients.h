#pragma once

#include "GlobalSpecialization.h"
#include "clsSpecializationLogic.h"

class clsShowPatients {


public:

	static void PrintPatient() {

		char showAllSpecialization = 'y';
		std::cout << "Do you want show all patient in each specialization? [y/n]: ";
		std::cin >> showAllSpecialization;

		if (showAllSpecialization == 'y') {

			short num = -1;
			for (clsSpecializationLogic& e : Specialization) {

				num++;
				e.PrintAllPatients(num);

			}

		}
		else {

			short num = readIn::ReadNumberBetweenFromTo(1, 20, "   >> Enter your specialization : ", "Number is out of Range, Please enter a vaild number [1:20] >> ");

			if (!Specialization[num].PrintAllPatients(num)) {

				std::cout << "No patient :-)";

			}

		}

	}



};

