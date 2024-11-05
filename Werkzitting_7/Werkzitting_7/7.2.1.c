/*
	1e bolletje
	schets in boekje, b is de juiste

	2e bolletje
	in de malloc moet de * weg
	als je iets moet aanpassen moet je een pointer gebruiken, hier zit je in een kopie aan te passen

	3e bolletje
	je mist een stopconditie, recursieve functie blijft doorgaan tot dat die na de lijst garbage gaat printen

	4e bolletje
	geen free()
*/
#include <stdio.h>

typedef struct{
	int* next;
	int data;
}node;

void remove(struct node** list, int i)
{
	if (list != NULL) {
		if ((*list)->data == i) {
			*list = (*list)->next;
		}
		else {
			struct node* p = *list;
			while ((p != NULL) && (p->data != i))
				p = p->next;
			if (p != NULL) { /* p->data == i */
				free(p);
				p = p->next;
			}
		}
	}
}

void remove2(struct node** list, int i) {
	if (list == NULL) {
		return;
	}

	if ((*list) != NULL) {
		if ((*list)->data == i) {
			*list = (*list)->next;
			if (*list != NULL) {
				(*list)->prev = NULL;
			}
		}
		else {
			struct node* p = *list;
			while (p != NULL && p->data != i) {
				p = p->next;
			}

			if (p != NULL) {
				if (p->next != NULL) {
					p->next->prev = p->prev;
				}
				if (p->prev != NULL) {
					p->prev->next = p->next;
				}
				free(p);
			}
		}
	}
}

int main() {
	return 0;
}
