#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char letter;
    struct node *next;
} node;

// Returns number of nodes in the linkedList.
int length(node *head)
{
    int nodeCount = 0;
    while (head != NULL)
    {
        // add 1 for node Count.
        nodeCount++;
        head = head->next;
    }
    return nodeCount;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char *toCString(node *head)
{
    char *cString = (char *)malloc((((length(head))) + 1) * sizeof(char));
    if (cString == NULL)
    {
        exit(-1);
    }

    int i = 0;
    while (head != NULL)
    {
        cString[i++] = head->letter;
        head = head->next;
    }
    cString[i] = '\0';
    return cString;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node **pHead, char c)
{
    // Malloc data in the linked list
    node *characterData = (node *)malloc(sizeof(node));
    if (characterData == NULL)
    {
        exit(-2);
    }
    characterData->letter = c;
    characterData->next = NULL;

    if (*pHead == NULL)
    {
        *pHead = characterData;
    }
    else
    {
        node *temp = *pHead;

        while (characterData->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = characterData;
    }
}

// deletes all nodes in the linkedList.
void deleteList(node **pHead)
{
    // establish temporary variable to update head for loop
    node *temp = *pHead;
    // declaring next in function
    node *next;

    while (temp != NULL)
    {
        free(temp);
        temp = next;
    }
    *pHead = NULL;
}

int main(void)
{
    int i, strLen, numInputs;
    node *head = NULL;
    char *str;
    char c;
    FILE *inFile = fopen("input.txt", "r");

    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile, " %c", &c);
            insertChar(&head, c);
        }

        str = toCString(head);
        printf("String is : %s\n", str);

        free(str);
        deleteList(&head);

        if (head != NULL)
        {
            printf("deleteList is not correct!");
            break;
        }
    }

    fclose(inFile);
}
