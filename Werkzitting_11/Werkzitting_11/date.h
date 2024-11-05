#pragma once

#ifndef DATE_H
#define DATE_H

typedef struct {
    int year;
    int month;
    int day;
} date;

void read_date(date* d);
void print_date(const date* d);

#endif