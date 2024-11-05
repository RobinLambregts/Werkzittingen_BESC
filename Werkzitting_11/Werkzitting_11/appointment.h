#pragma once

#ifndef AFSPRAAK_H
#define AFSPRAAK_H

#include "date.h"

// Definitie van de struct appointment
typedef struct appointment {
    date date;
    char description[100];
} appointment;

void read_appointment(appointment* apt);
void print_appointment(const appointment* apt);

#endif