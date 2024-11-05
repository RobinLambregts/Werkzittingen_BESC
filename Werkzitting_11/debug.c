#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define NR_OF_PEOPLE 5
#define MAX_LENGTH_NAME 30
#define TOTAL_GIFTS 15
#define WISHLIST_SIZE 3

typedef struct Gift
{
	char name[MAX_LENGTH_NAME];
	float price;
} Gift;

typedef struct Person
{
	char name[MAX_LENGTH_NAME];
	Gift* wishList[WISHLIST_SIZE];
} Person;

typedef struct Assignment
{
	Person* buyer;
	Person* receiver;
} Assignment;

void initGifts(Gift* allGifts);
void sortWishList(float desiredPrice, Person* person);
int countItemsInWishlist(Person* person);
void assignPeople(Person people[], Assignment assignments[]);
bool receiverAlreadyAssigned(Assignment assignments[], Person* person);
void printAssignments(Assignment assignments[]);
void printAllGifts(Gift allGifts[]);
void fillInWishList(Person person, Gift allGifts[]);
Gift* getGiftItem(char giftName[], Gift allGifts[]);

void fillInWishList(Person person, Gift allGifts[])
{
	for (int i = 0; i < WISHLIST_SIZE; i++)
		person.wishList[i] = NULL;

	for (int i = 0; i < WISHLIST_SIZE; i++)
	{
		bool correctItem = false;
		do
		{
			printf("%s, enter wistlist item %d/%d ('/' to stop):", person.name, i + 1, WISHLIST_SIZE);
			char* giftName = malloc(sizeof(char*)*50);
			scanf("%s", giftName);
			if (strlen(giftName) == 1 && giftName[0] == '/')
				return;
			else
			{
				Gift* wishListItem = getGiftItem(giftName, allGifts);
				if (wishListItem == NULL)
					printf("Invalid wishlist item\n");
				else
				{
					correctItem = true;
					person.wishList[i] = wishListItem;
				}
			}
		} while (!correctItem);
	}
}

Gift* getGiftItem(char giftName[], Gift allGifts[])
{
	for (int i = 0; i < TOTAL_GIFTS; i++)
		if (strcmp(giftName, allGifts[i].name))
			return &allGifts[i];

	return NULL;
}

void printAllGifts(Gift allGifts[])
{
	printf("Gifts to choose from: \n");
	for (int i = 0; i < TOTAL_GIFTS; i++)
		printf("%s\n", allGifts[i].name);

	printf("\n");
}

void printAssignments(Assignment assignments[])
{
	for (int i = 0; i < NR_OF_PEOPLE; i++)
	{
		printf("%s gives to %s one of the following presents:\n", assignments[i].buyer->name, assignments[i].receiver->name);

		int itemsInWishList = countItemsInWishlist(assignments[i].receiver);
		for (int j = 0; j < itemsInWishList; j++)
			printf("\t%s \t %0.2f Euro\n", assignments[i].receiver->wishList[itemsInWishList]->name, assignments[i].receiver->wishList[itemsInWishList]->price);
	}
}

/**
* Deze functie is correct --> geen aanpassingen nodig
*/
void assignPeople(Person people[], Assignment assignments[])
{
	for (int i = 0; i < NR_OF_PEOPLE; i++)
	{
		assignments[i].buyer = &people[i];
		Person* receiver = NULL;
		do
		{
			int receiverIndex = rand() % NR_OF_PEOPLE; //generates a random integer from 0 to NR_OF_PEOPLE
			if (receiverIndex != i) //receiver cannot be the same as buyer
				if (!receiverAlreadyAssigned(assignments, &people[receiverIndex])) //one person cannot receive multiple gifts
					receiver = &people[receiverIndex];
		} while (receiver == NULL);

		assignments[i].receiver = receiver;
	}
}

/**
* Deze functie is correct --> geen aanpassingen nodig
*/
bool receiverAlreadyAssigned(Assignment assignments[], Person* person)
{
	for (int i = 0; i < NR_OF_PEOPLE; i++)
		if (assignments[i].receiver == person)
			return true;

	return false;
}

void sortWishList(float desiredPrice, Person* person)
{
	int itemsInWishList = countItemsInWishlist(person);
	for (int i = 0; i < itemsInWishList - 1; i++) {
		for (int j = i + 1; j < itemsInWishList; j++) {
			double priceDifferenceI = fabs(person->wishList[i]->price - desiredPrice); //absolute value of difference
			double priceDifferenceJ = fabs(person->wishList[j]->price - desiredPrice); //absolute value of difference

			if (priceDifferenceI > priceDifferenceJ) {
				Gift* temp = person->wishList[i];
				person->wishList[i] = person->wishList[j];
				person->wishList[j] = temp;
			}
		}
	}
}

int countItemsInWishlist(Person* person)
{
	int counter = 0;
	for (int i = 0; i < WISHLIST_SIZE; i++) {
		if (person->wishList[i] != NULL)
			counter++;
		else
			break;
	}

	return counter;
}

/**
* Deze functie is correct --> geen aanpassingen nodig
*/
void initGifts(Gift* allGifts)
{
	int i = 0;
	strcpy(allGifts[i].name, "sokken");
	allGifts[i++].price = 5.2f;
	strcpy(allGifts[i].name, "cadeaubon");
	allGifts[i++].price = 10.0f;
	strcpy(allGifts[i].name, "mok");
	allGifts[i++].price = 12.0f;
	strcpy(allGifts[i].name, "bier");
	allGifts[i++].price = 10.0f;
	strcpy(allGifts[i].name, "wijn");
	allGifts[i++].price = 7.2f;
	strcpy(allGifts[i].name, "boek");
	allGifts[i++].price = 21.0f;
	strcpy(allGifts[i].name, "pen");
	allGifts[i++].price = 35.0f;
	strcpy(allGifts[i].name, "trui");
	allGifts[i++].price = 25.0f;
	strcpy(allGifts[i].name, "handschoenen");
	allGifts[i++].price = 23.2f;
	strcpy(allGifts[i].name, "sjaal");
	allGifts[i++].price = 16.0f;
	strcpy(allGifts[i].name, "muts");
	allGifts[i++].price = 14.0f;
	strcpy(allGifts[i].name, "parfum");
	allGifts[i++].price = 40.0f;
	strcpy(allGifts[i].name, "slippers");
	allGifts[i++].price = 9.20f;
	strcpy(allGifts[i].name, "bordspel");
	allGifts[i++].price = 25.0f;
	strcpy(allGifts[i].name, "rugzak");
	allGifts[i++].price = 30.0f;
}

int main(void)
{
	Gift allGifts[TOTAL_GIFTS];
	Person people[NR_OF_PEOPLE];
	Assignment assignments[NR_OF_PEOPLE];

	int personIndex = 0;
	strcpy(people[personIndex++].name, "Piet");
	strcpy(people[personIndex++].name, "Jan");
	strcpy(people[personIndex++].name, "Mieke");
	strcpy(people[personIndex++].name, "Kris");
	strcpy(people[personIndex++].name, "Jef");

	initGifts(allGifts);

	printAllGifts(allGifts);
	for (int i = 0; i < NR_OF_PEOPLE; i++)
		fillInWishList(people[i], allGifts);

	float desiredPrice;
	printf("Entered the desired amount for everyone to spend: ");
	while ((scanf("%f", &desiredPrice) != 1) || desiredPrice < 0)
		printf("Error in input, please enter a price: ");

	for (int i = 0; i < NR_OF_PEOPLE; i++)
		sortWishList(desiredPrice, &people[i]);

	assignPeople(people, assignments);

	printAssignments(assignments);

	return 0;
}