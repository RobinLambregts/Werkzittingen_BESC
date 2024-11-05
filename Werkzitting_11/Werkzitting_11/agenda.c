#include "date.h"
#include "appointment.h"
#include <stdio.h>


int main() {
    appointment apt;

    printf("Enter appointment details:\n");
    read_appointment(&apt);

    printf("\nAppointment details:\n");
    print_appointment(&apt);

    return 0;
}