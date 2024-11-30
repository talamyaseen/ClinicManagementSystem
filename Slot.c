#include "Slot.h"
#include <stdio.h>

void print_available_slots(Slot *slots, int size)
{
    int i, j = 0;
    printf("\tAvailable time slots:\n");
    for (i = 0; i < size; i++)
    {
        if (slots[i].patientID != -1)
            continue;
        printf("\t %d. %s\n", i + 1, slots[i].SlotTime);
        j++;
    }
    if (j == 0)
    {
        printf("\tSorry, Time slots are full\n");
    }
}

int reserve_slot(Slot *slots, int slotID, int ID, int size)
{
    if (slotID >= 0 && slotID < size && slots[slotID].patientID == -1)
        slots[slotID].patientID = ID;
    else
        return -1;
    return 0;
}

void print_reservations(Slot *slots, int size)
{
    int i, j = 0;
    printf("\tToday reservations:\n");
    for (i = 0; i < size; i++)
    {
        if (slots[i].patientID != -1)
        {
            j++;
            printf("\t%d. %s reserved by patientID : %d\n", j, slots[i].SlotTime, slots[i].patientID);
        }
    }
    if (j == 0)
    {
        printf("\tNo reservations yet\n");
    }
}

int cancel_reservation(Slot *slots, int size, int ID)
{
    int i, j = 0;
    for (i = 0; i < size; i++)
    {
        if (slots[i].patientID == ID)
        {
            j++;
            slots[i].patientID = -1;
        }
    }
    if (j == 0)
    {
        return -1;
    }
    return 0;
}