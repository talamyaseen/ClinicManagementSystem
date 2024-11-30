#include <stdio.h>
#include <stdlib.h>
#include "Patient.h"
#include "Slot.h"

#define ADMIN_PASSWORD 1234
#define SLOTS_SIZE 5

Patient *patients = NULL;
Slot slots[SLOTS_SIZE] = {{"2pm to 2:30pm", -1}, {"2:30pm to 3pm", -1}, {"3pm to 3:30pm", -1}, {"4pm to 4:30pm", -1}, {"4:30pm to 5pm", -1}};
void main(void)
{
	int mode, password;
	int i;
	int choice;
	char name[50];
	int age;
	char gender;
	int ID, slotID;
	printf("-----------Clinic Management System-----------\n");
	while (1)
	{

		printf("\tEnter in admin mode or user mode?\n\tEnter '1' for admin, '2' for user: ");
		scanf("%d", &mode);
		if (mode == 1)
		{
			for (i = 0; i < 3; i++)
			{
				printf("\tEnter admin password, you have %d trails: ", 3 - i);
				scanf("%d", &password);
				if (password == ADMIN_PASSWORD)
					break;
			}

			if (password == ADMIN_PASSWORD)
			{
				printf("\tWelocme Admin\n");
				while (1)
				{
					printf("\t1. Add new patient record\n");
					printf("\t2. Edit patient record\n");
					printf("\t3. Reserve a slot with the doctor\n");
					printf("\t4. Cancel reservation\n");
					printf("\t5. Logout\n");
					printf("\tYour choice: ");
					scanf("%d", &choice);
					if (choice == 1)
					{

						printf("\tPlease enter patient name: ");
						scanf("%s", name);
						printf("\tPlease enter patient age: ");
						scanf("%d", &age);
						printf("\tPlease enter patient gender(M/F): ");
						scanf(" %c", &gender);
						printf("\tPlease enter patient ID: ");
						scanf("%d", &ID);
						int i = 0;
						for (i = 0; i < 2; i++)
						{
							if (search_patient_by_ID(patients, ID) == NULL)
								break;
							printf("\tThis ID exists, Please enter new patientID, you have %d trails: ", 2 - i);
							scanf("%d", &ID);
						}

						if (search_patient_by_ID(patients, ID) == NULL)
						{
							Patient *newPatient = create_patient(name, age, gender, ID);
							add_patient(&patients, newPatient);
							printf("\tPatient added successfully\n");
						}
						else
						{
							printf("\tPlease try again later\n");
						}
					}
					else if (choice == 2)
					{
						printf("\tPlease enter patient ID: ");
						scanf("%d", &ID);
						Patient *patientToEdit = search_patient_by_ID(patients, ID);
						if (patientToEdit == NULL)
						{
							printf("\tThis ID doesn't exist\n");
						}
						else
						{
							printf("\tPlease enter patient new name: ");
							scanf("%s", name);
							printf("\tPlease enter patient new age: ");
							scanf("%d", &age);
							printf("\tPlease enter patient gender(M/F): ");
							scanf(" %c", &gender);
							printf("\tPlease enter patient new ID: ");
							scanf("%d", &ID);
							if (search_patient_by_ID(patients, ID) != NULL && patientToEdit->ID != ID)
								printf("\tThis ID exists, information can't edited\n");
							else
							{
								edit_patient(patientToEdit, name, age, gender, ID);
								printf("\t Patient information edited successfully\n");
							}
						}
					}
					else if (choice == 3)
					{
						print_available_slots(slots, SLOTS_SIZE);
						printf("\tPlease choose the desired slot: ");
						scanf("%d", &slotID);
						printf("\tPlease enter patient ID: ");
						scanf("%d", &ID);

						if (search_patient_by_ID(patients, ID) == NULL)
						{
							printf("\tThis ID doesn't exist\n");
						}
						else
						{
							if (reserve_slot(slots, slotID - 1, ID, SLOTS_SIZE) == 0)
								printf("\tReservation Done\n");
							else
								printf("\tInvalid SlotID, or Slot reserved already. Try again\n");
						}
					}
					else if (choice == 4)
					{
						printf("\tPlease enter patient ID to cancel it's reservation: ");
						scanf("%d", &ID);
						if (search_patient_by_ID(patients, ID) == NULL)
						{
							printf("\tThis ID doesn't exist\n");
						}
						else
						{
							if (cancel_reservation(slots, SLOTS_SIZE, ID) == 0)
								printf("\tReservation cancelled\n");
							else
								printf("\tNo reservations for this patient ID\n");
						}
					}
					else if (choice == 5)
					{
						printf("\tGoodbye Admin\n");
						break;
					}
					else
					{
						printf("\tWrong entry, Try again\n");
					}
				}
			}
			else
			{
				printf("\tLogin Failed");
				break;
			}
		}
		else if (mode == 2)
		{
			printf("\tWelocme User\n");
			while (1)
			{
				printf("\t1. View patient record\n");
				printf("\t2. View today reservations\n");
				printf("\t3. Logout\n");
				printf("\tYour choice: ");
				scanf("%d", &choice);
				if (choice == 1)
				{
					printf("\tPlease enter patient ID: ");
					scanf("%d", &ID);
					Patient *patient = search_patient_by_ID(patients, ID);
					if (patient == NULL)
					{
						printf("\tThis ID doesn't exist\n");
					}
					else
						print_patient(patient);
				}
				else if (choice == 2)
				{
					print_reservations(slots, SLOTS_SIZE);
				}
				else if (choice == 3)
				{
					printf("\tGoodbye User\n");
					break;
				}
				else
				{
					printf("\tWrong entry, Try again\n");
				}
			}
		}
		else
		{
			printf("\tWrong entry, Try again\n");
		}
	}
}
