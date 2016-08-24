#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define datalen 99

struct node *newNode(struct node *list, char dataToAdd[datalen], int priorityToAdd);
struct node *addNodeToEnd(struct node *list, struct node *nodeToAdd);
void printLL(struct node *list);

struct node {
    char data[datalen];
    int priority;
    struct node *next;
};

int main() {
    
	printf("\n--------------------------------------------------------------------------\n");
	printf("Input a print job and a priority number for that print job.\n");
	printf("Priority should be between 0 and 9, inclusive. Default priority is 0.\n");
	printf("Both should be on the same line and separated by a space. \n");
	printf("Press enter to input the next print job. Input \"DONE\" to execute the jobs.\n");
	printf("Example: abcdefghijklmnopqrstuvwxyz 4\n");
	printf("--------------------------------------------------------------------------\n\n");

	struct node *list = NULL;

	while(1) {

		char dataToAdd[datalen];
		int priorityToAdd = 0;

		scanf("%s", dataToAdd);

		if (strcmp(dataToAdd, "DONE") == 0) {
			break;
		}

    	scanf("%d", &priorityToAdd);

    	if (priorityToAdd < 0 || priorityToAdd > 9) {
    		printf("Priority must be between 0 and 9, inclusive. Data discarded.\n");
    		continue;
    	}

    	//printf("CREATING NEW NODE \n");

    	struct node *new = newNode(list, dataToAdd, priorityToAdd);

    	//printf("ADDING NODE TO END \n");

    	list = addNodeToEnd(list, new);

    	//printf("SUCCESS \n");

	}

	printLL(list);
    
	
}

struct node *newNode(struct node *list, char dataToAdd[datalen], int priorityToAdd) {

	struct node *newNode = malloc(sizeof(struct node));
	if (newNode == NULL) {
		printf("Error allocating memory.\n");
		exit(0);
	}

	strcpy(newNode->data, dataToAdd);
	newNode->priority = priorityToAdd;
	newNode->next = NULL;

	return newNode;

}

struct node *addNodeToEnd(struct node *list, struct node *nodeToAdd) {

	// If list is empty, simply point to new node.
	// Else, find last node and set its next to the new node.
	if (list == NULL) {
		//printf("LIST WAS NULL. ADDING NODE. \n");
		list = nodeToAdd;
		//printf("SUCCESS ADDING NODE. \n");
	} else {

		struct node *p = list;
		while (1) {

			if (p->next == NULL) {
				//printf("ADDING TO END \n");
				p->next = nodeToAdd;
				break;
			}

			p = p->next;

		}

	}

	return list;

}

void printLL(struct node *list) {

	printf("\n------------------------------------\n");
	// Outer loop: cyles through different priorities.
	// Inner loop: cycles through the list printing the data with the current priority.
	int prior = 9;
	for (; prior >= 0; prior--) {
		struct node *p = list;
		for (; p != NULL; p = p->next) {

			if (p->priority == prior) {
				printf("%s\n", p->data);
			}

		}
	}
	printf("------------------------------------\n\n");

}























