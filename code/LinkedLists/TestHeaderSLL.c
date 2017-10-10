#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *link;
};

typedef struct node* NODEPTR;

NODEPTR fnGetNode(void);
void fnFreeNode(NODEPTR x);
NODEPTR fnInsertFront(int ,NODEPTR);
NODEPTR fnDeleteFront(NODEPTR);
NODEPTR fnInsertPosition(int ,int ,NODEPTR);
void fnDisplay(NODEPTR first);
NODEPTR fnReverse(NODEPTR);
NODEPTR fnInsertRear(int ,NODEPTR);
NODEPTR fnDeleteRear(NODEPTR);
NODEPTR fnDeletePosition(int ,NODEPTR);
NODEPTR fnDeleteKey(int ,NODEPTR);

int main()
{
//	NODEPTR first = NULL;
    NODEPTR head;
    head = fnGetNode();
    head->link = NULL;
    head->info = 0;
    
	int iElem, iChoice, iPos;
	for(;;)
	{
		printf("\n1.Insert Front\n2.Delete Front");
		printf("\n3.Display\n4.Insert Rear\n5.Delete Rear\n6.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1: printf("\nEnter a element\n");
			        scanf("%d", &iElem);
			        head = fnInsertFront(iElem, head);
					break;

			case 2: head = fnDeleteFront(head);
					break;

			case 3: fnDisplay(head);
					break;

			case 4: printf("\nEnter a element\n");
			        scanf("%d", &iElem);
			        first = fnInsertRear(iElem, first);
					break;
					
			case 5: first = fnDeleteRear(first);
					break;
					
			case 6: exit(0);
		}
	}
	return 0;
}

NODEPTR fnGetNode(void)
{
	NODEPTR newNode;
	newNode = ( NODEPTR ) malloc (sizeof(struct node));
	if(newNode == NULL)
	{
		printf("\nOut of Memory");
		exit(0);
	}
	return newNode;
}

void fnFreeNode(NODEPTR x)
{
	free(x);
}

NODEPTR fnInsertFront(int elem,NODEPTR head)
{
	NODEPTR temp;
	temp = fnGetNode();
	temp->info = elem;
	
	temp->link = head->link;
	head->link = temp;
	(head->info)++;
	
	return head;
}

NODEPTR fnDeleteFront(NODEPTR head)
{
	NODEPTR first;
	if(head->link == NULL)
	{
	    printf("\nList is Empty cannot delete\n");
	    return head;
	}

    first = head->link;
    printf("\nElement deleted is %d\n", first->info);

	head->link = first->link;
	(head->info)--;
    fnFreeNode(first);
	return head;
}

NODEPTR fnInsertPosition(int elem,int pos,NODEPTR first)
{
	NODEPTR temp,prev,cur;
	int count;

	temp = fnGetNode();
	temp->info = elem;
	temp->link = NULL;

	if(first == NULL && pos == 1)
    	return temp;

	if(first == NULL)
	{
		printf("\nInvalid Position");
		return first;
	}

	if(pos == 1)
	{
		temp->link = first;
		return temp;
	}


	count = 1;
	prev = NULL;
	cur = first;

	while(cur != NULL && count != pos)
	{
		prev = cur;
		cur = cur->link;
		count++;
	}

	if(count == pos)
	{
		prev->link = temp;
		temp->link = cur;
		return first;
	}

	printf("\nInvalid Position");
	return first;
}

void fnDisplay(NODEPTR first)
{
	NODEPTR temp;

	if(first == NULL)
	{
		printf("\nList is Empty\n");
		return;
	}

	printf("\nList Contents\n");
	printf("==================================\n");
	for(temp = first; temp != NULL; temp = temp->link)
    	printf("%4d",temp->info);
	printf("\n==================================\n");
	printf("\n\n");

}

NODEPTR fnReverse(NODEPTR first)
{
    NODEPTR cur, prev, next;
    prev = first;
    cur = first->link;
    next = cur->link;
    prev->link = NULL;
    while(cur->link!=NULL)
    {
        cur->link = prev;
        prev = cur;
        cur = next;
        next = next->link;
    }
    cur->link = prev;
    return cur;
}

NODEPTR fnInsertRear(int iElem,NODEPTR head)
{
	NODEPTR temp,cur;

	temp = fnGetNode();
	temp->info = iElem;
	temp->link = NULL;

    (head->info)++;
    if(head->link == NULL)
    {
        head->link = temp;
        return head;
    }


    cur = head->link;
    while(cur->link != NULL)
    {
        cur = cur->link;
    }
    
    cur->link = temp;

    return head;
}

NODEPTR fnDeleteRear(NODEPTR head)
{
	NODEPTR cur, prev;
	if(head->link == NULL)
	{
	    printf("\nList is Empty cannot delete\n");
	    return head;
	}

    prev = head;
    cur = head->link;
    while(cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }

    printf("\nElement deleted is %d\n", cur->info);

	prev->link = NULL;
    fnFreeNode(cur);
    (head->info)--;
	return header;
}

NODEPTR fnDeletePosition(int pos,NODEPTR first)
{
	NODEPTR temp,prev,cur;
	int count;

	if(first == NULL)
	{
		printf("\nEmpty List cannot delete\n");
		return first;
	}

	if(pos == 1)
	{
	    temp = first;
		first = first->link;
		printf("\nElement deleted is %d\n", temp->info);
		fnFreeNode(temp);
		return first;
	}

	count = 1;
	prev = NULL;
	cur = first;

	while(cur != NULL && count != pos)
	{
		prev = cur;
		cur = cur->link;
		count++;
	}

	if(count == pos)
	{
		prev->link = cur->link;
		printf("\nElement deleted is %d\n", cur->info);
		fnFreeNode(cur);
		return first;
	}

	printf("\nInvalid Position");
	return first;
}

NODEPTR fnDeleteKey(int key,NODEPTR first)
{
	NODEPTR temp,prev,cur;

	if(first == NULL)
	{
		printf("\nEmpty List cannot delete\n");
		return first;
	}

	if(first->info == key)
	{
	    temp = first;
		first = first->link;
		printf("\nElement deleted is %d\n", temp->info);
		fnFreeNode(temp);
		return first;
	}

	prev = NULL;
	cur = first;

	while(cur != NULL && cur->info != key)
	{
		prev = cur;
		cur = cur->link;

	}

	if(cur->info == key)
	{
		prev->link = cur->link;
		printf("\nElement deleted is %d\n", cur->info);
		fnFreeNode(cur);
		return first;
	}

	printf("\nKey element not found in the list\n");
	return first;
}

