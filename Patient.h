#ifndef PATIENT_H
#define PATIENT_H
typedef struct Patient
{
	char *name;
	char gender;
	int age;
	int ID;
	struct Patient *nextPatient;
} Patient;
Patient *create_patient(char *name, int age, char gender, int ID);
void add_patient(Patient **patients, Patient *newPatient);
Patient *search_patient_by_ID(Patient *patients, int id);
void edit_patient(Patient *patientToEdit, char *name, int age, char gender, int ID);
void print_patient(Patient *patient);
#endif