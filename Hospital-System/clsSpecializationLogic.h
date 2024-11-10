#pragma once

#include <iostream>
#include <iomanip>
#include <string>


class clsSpecializationLogic {

	class Node {

	public:

		std::string _Name = "";
		bool _Status = 0;

		Node* _NextNode = NULL;

		Node(std::string name, bool status) {

			_Name = name;
			_Status = status;

		}


	};

	Node* head = NULL;

	void _InsertAtBegin(std::string name) {

		Node* newNode = new Node(name, 1);

		if (head == nullptr) {

			head = newNode;
			return;

		}

		newNode->_NextNode = head;
		head = newNode;


	}

	void _InsertAtEnd(std::string name) {

		Node* newNode = new Node(name, 0);

		if (head == nullptr) {

			head = newNode;
			return;

		}

		Node* travelseNode = head;
		while (travelseNode->_NextNode != NULL) {
			travelseNode = travelseNode->_NextNode;
		}

		travelseNode->_NextNode = newNode;


	}

	std::string _DeleteAtBegin() {

		std::string name = head->_Name;

		Node* delNode = head;
		head = head->_NextNode;

		delete delNode;

		return name;

	}


	void _FormatingPatient(Node* info) {

		std::string status = "regular";
		if (info->_Status != 0)
			status = "urgent";

		std::cout << std::left << std::setw(25) << info->_Name << '|' << std::left << std::setw(25) << status << '\n';

	}

public:


	short NumberOfPatientINWaitingList() {

		if (head == NULL)
			return 0;

		int counter = 0;
		Node* travelsNode = head;

		while (travelsNode != nullptr) {

			counter++;
			travelsNode = travelsNode->_NextNode;

		}

		return counter;

	}


	void AddNewPatients(std::string nameOfPatient, bool status = 0) {


		if (status == 0)
			_InsertAtEnd(nameOfPatient);
		else
			_InsertAtBegin(nameOfPatient);

	}

	bool PrintAllPatients(short numberOfSpecialization) {

		short numberOfPatient = NumberOfPatientINWaitingList();
		
		if (numberOfPatient == 0) 
			return false;

		std::cout << "\n============================================================\n";
		std::cout << "There are " << numberOfPatient << " Patient in specialization " << numberOfSpecialization << '\n';
		std::cout << "============================================================\n";
		std::cout << std::left << std::setw(25) << "Name of patient" << '|' << std::left << std::setw(25) << "status of patient" << '\n' << std::endl;

		Node* info = head;
		while (info != NULL) {

			_FormatingPatient(info);
			info = info->_NextNode;

		}

		std::cout << "\n============================================================\n\n";
		return true;

	}

	void GetNextPatient() {

		short numberOfPatient = NumberOfPatientINWaitingList();

		if (numberOfPatient == 0) {

			std::cout << "No patients at the moment. have a rest, Dr\n";
			return;

		}

		std::cout << _DeleteAtBegin() << " ,Please go with the Dr\n";


	}

};

