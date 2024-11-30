#include "Patient.h"
#include <stdio.h>
#include <stdlib.h>

Patient *create_patient(char *name, int age, char gender, int ID)
{
	Patient *newPatient = (Patient *)malloc(sizeof(Patient));
	int i = 0;
	while (name[i] != '\0')
	{
		newPatient->name[i] = name[i];
		i++;
	}
	newPatient->name[i] = '\0';
	newPatient->age = age;
	newPatient->gender = gender;
	newPatient->ID = ID;
	newPatient->nextPatient = NULL;
	return newPatient;
}

void add_patient(Patient **patients, Patient *newPatient)
{
	if (*patients == NULL)
	{
		*patients = newPatient;
	}
	else
	{
		Patient *ptr = *patients;
		while (ptr->nextPatient != NULL)
		{
			ptr = ptr->nextPatient;
		}
		ptr->nextPatient = newPatient;
	}
}
Patient *search_patient_by_ID(Patient *patients, int id)
{
	if (patients == NULL)
	{
		return NULL;
	}
	Patient *ptr = patients;
	while (ptr != NULL)
	{
		if (ptr->ID == id)
			return ptr;
		ptr = ptr->nextPatient;
	}
	return NULL;
}
void edit_patient(Patient *patientToEdit, char *name, int age, char gender, int ID)
{
	int i = 0;
	while (name[i] != '\0')
	{
		patientToEdit->name[i] = name[i];
		i++;
	}
	patientToEdit->name[i] = '\0';
	patientToEdit->age = age;
	patientToEdit->gender = gender;
	patientToEdit->ID = ID;
}
void print_patient(Patient *patient)
{
	printf("\tPatient Name: %s\n", patient->name);
	printf("\tPatient Age: %d\n", patient->age);
	printf("\tPatient Gender: %c\n", patient->gender);
	printf("\tPatient ID: %d\n", patient->ID);
}