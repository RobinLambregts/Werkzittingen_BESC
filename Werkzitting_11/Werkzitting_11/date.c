#include "date.h"
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

void read_date(date* d) {
    printf("Enter day: ");
    scanf_s("%d", &d->day);

    printf("Enter month: ");
    scanf_s("%d", &d->month);

    printf("Enter year: ");
    scanf_s("%d", &d->year);
}

void print_date(const date* d) {
    printf("Date: %02d-%02d-%04d\n", d->day, d->month, d->year);
}
