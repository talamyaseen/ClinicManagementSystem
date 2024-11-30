#ifndef SLOT_H
#define SLOT_H
typedef struct Slot
{
	char *SlotTime;
	int patientID;
} Slot;

void print_available_slots(Slot *slots, int size);
int reserve_slot(Slot *slots, int slotID, int ID, int size);
void print_reservations(Slot *slots, int size);
int cancel_reservation(Slot *slots, int size, int ID);
#endif