/*
	table = het adres van je table (eerste waarde)
	table+i = adres van het i de element
	*(table+i) = adres van het 1ste element van de i de rij
	*(table+i)+j =  point naar het adres van het j de element in de i de row
	* *(*(table+i)+j) = point naar die waarde
	* 
	* FIGUUR 3.7 IN DE STUDIELEIDRAAD IS EEN PERFECTE SCHETS
*/ 

#include <stdio.h>

#define j 2
#define i 3
#define ROWS 4
#define COLS 5

int main() {
	int table[ROWS][COLS] =
	{ { 13, 15, 17, 19, 21 },
	{ 20, 22, 24, 26, 28 },
	{ 31, 33, 35, 37, 39 },
	{ 40, 42, 44, 46, 48 } };

	printf("einde programma");
}