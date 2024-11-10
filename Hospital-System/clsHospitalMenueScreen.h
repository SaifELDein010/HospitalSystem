#pragma once

#include <iostream>
#include "clsAddNewPatient.h"
#include "clsShowPatients.h"
#include "clsGetNextPatient.h"

#include "ReadInput.h"

class clsHospitalMenueScreen {

private:


	static void _Restert() {

		system("color F");
		system("cls");

	}

	static void _GoBack() {

		std::cout << "\nEnter any key to go back...";

		system("Pause>0");
		_Restert();
		PrintHospitalMenueScreen();

	}

	static void _PerformOperations(short numberOfChoices) {

		switch (numberOfChoices) {

		case 1:
			clsAddNewPatient::AddNewPatient();
			_GoBack();
			break;

		case 2:
			clsShowPatients::PrintPatient();
			_GoBack();
			break;

		case 3:
			clsGetNextPatient::GetNextPatient();
			_GoBack();
			break;

		case 4:
			break;

		}

	}

	static void _HeaderScreen() {

		std::cout << "\n\t\t\t\t\t< Hospital menue system >\n";

	}

	static void _MenueScreen() {

		int numberOfChoices = 0;

		std::cout << "[1] Add new patient.\n";
		std::cout << "[2] Print watinig list.\n";
		std::cout << "[3] Get next patient.\n";
		std::cout << "[4] Exit.\n";

		std::cout << "   ----------------------\n";

		numberOfChoices = readIn::ReadNumberBetweenFromTo(1, 4, "   >> Enter your Choices : ", "Number is out of Range, Please enter a vaild number [1:4] >> ");
		_PerformOperations(numberOfChoices);

	}

public:


	static void PrintHospitalMenueScreen() {

		_HeaderScreen();

		_MenueScreen();	

	}


};

