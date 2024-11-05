#include "appointment.h"
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

void read_appointment(appointment* apt) {
    printf("Enter appointment date:\n");
    read_date(&apt->date);

    printf("Enter appointment description: ");
    scanf_s(" %[^\n]", apt->description);
}

void print_appointment(const appointment* apt) {
    printf("Appointment on ");
    print_date(&apt->date);
    printf("Description: %s\n", apt->description);
}