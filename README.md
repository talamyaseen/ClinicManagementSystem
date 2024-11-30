# Clinic Management System (C)

A simple **Clinic Management System** written in **C** that utilizes linked lists and structures to manage patient records and doctor reservations. The system allows both **Admin** and **User** modes for handling various clinic operations.

## Features

### Admin Mode:

1. **Login**:

   - Admin is prompted to enter a password (default is `1234`).
   - The system allows 3 login attempts. After 3 failed attempts, the system exits.

2. **Add New Patient Record**:

   - Admin can add a new patient by entering their name, age, gender, and a unique patient ID.
   - The system ensures the patient ID is unique; duplicate IDs are rejected.

3. **Edit Patient Record**:

   - Admin can update the details of an existing patient by entering their unique patient ID.
   - If the patient ID doesn't exist, the system will display an "incorrect ID" message.

4. **Reserve a Slot with Doctor**:

   - The system provides 5 default time slots:
     - 2pm to 2:30pm
     - 2:30pm to 3pm
     - 3pm to 3:30pm
     - 4pm to 4:30pm
     - 4:30pm to 5pm
   - Admin selects a patient by ID and reserves one of the available slots. Once reserved, the slot will no longer appear for other patients.

5. **Cancel Reservation**:
   - Admin can cancel an existing reservation by entering the patient's ID.
   - The canceled slot will be made available for other reservations.

### User Mode:

1. **View Patient Record**:

   - Users can view their own patient record by entering their unique patient ID.

2. **View Today's Reservations**:
   - Users can view all the reservations for the day, showing the patient IDs associated with each time slot.

## Data Structures

- **Linked List**: Used for managing the list of patients.
- **Structures**: Define the patient data (name, ID, age, gender) and slot data (time slot, reserved patient ID).

## Compilation

To compile the program, use the following command:

```bash
gcc Patient.c Slot.c ClinicManagementSystem.c -o ClinicManagementSystem
```

## Running

- **Instructions for Running on Linux**: After compiling, you can run the program using `./ClinicManagementSystem`.
- **Instructions for Running on Windows**: After compiling, you can run the program using `ClinicManagementSystem.exe`
