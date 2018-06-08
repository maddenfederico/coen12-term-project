/*Federico Madden
COEN 12 Prof. Liu
MFW 10:30AM
5/8/2018
*/

#include<stdio.h>
#include<assert.h>
#include "dataset.h"
#include<stdlib.h>
#include<string.h>

#define AGE_INTERVAL 18


//Creates a STUDENT set in the form of a circular linked list
SET* createDataSet()//O(1)
{
    SET *sp = malloc(sizeof(SET));
    assert(sp !=NULL);

    sp->count = 0;
	memset(sp->ageCount, 0, AGE_INTERVAL);//ageCount stores the number of entries of each age 

    sp->dummy = malloc(sizeof(STUDENT));
    assert(sp->dummy!= NULL);

    sp->dummy->prev = sp->dummy;
    sp->dummy->next = sp->dummy;

    return sp;
}

//Loop through and free all members of linked list
void destroyDataSet(SET *sp)//O(n)
{
	assert(sp!=NULL);

    STUDENT *pDel;
    STUDENT *pPrev = sp->dummy->prev;

    do{
        pDel = pPrev;
        pPrev = pDel->prev;
        free(pDel);
    }while(pDel != sp->dummy);
        
    free(sp);
}

//Add passed student to front of list 
void insertion(SET *sp, STUDENT stu)//O(n) 
{
	assert(sp != NULL);

	STUDENT *p = malloc(sizeof(STUDENT));
	assert(p != NULL);
	*p = stu;

	//Hook p up to the nodes next to it
	sp->dummy->next->prev = p;
	p->next = sp->dummy->next;
	sp->dummy->next = p;
	p->prev = sp->dummy;

	//Increment count and ageCount
	sp->ageCount[(p->age) - AGE_INTERVAL] += 1;
	sp->count += 1;
}

//Deletes passed student pointer from passed SET
void deletion(SET *sp, STUDENT *p)//O(1)
{
	assert(sp != NULL);
	assert(sp->dummy->next != sp->dummy);//Check that list isn't empty
	assert(p != NULL);



	//Unhook node from list
	p->next->prev = p->prev;
	p->prev->next = p->next;	

	sp->ageCount[(p->age) - AGE_INTERVAL] -= 1;
	sp->count -= 1;
	free(p);
	printf("Deleted student with age %d and ID %d\n", p->age, p->id);
}



STUDENT** searchAge(SET *sp, int age)//O(n)
{
	assert(sp != NULL);

	printf("Searching for age: %d\n", age);

	STUDENT** stuList = malloc(sizeof(STUDENT*) * sp->ageCount[age - AGE_INTERVAL] + 1);//Array will be returned 
	assert(stuList != NULL);

	STUDENT *p = sp->dummy->next;
	int i = 0;
	while(p != sp->dummy)//Loop though list in search of item
	{
		if(p->age == age)
		{
			stuList[i] = p;
			i++;
		}
		p = p->next;
	}
	stuList[i] = NULL;//Add a null terminator to array

	if(stuList[0] == NULL)//If list is empty
	{
		printf("No match found for age: %d\n", age);
	}
	else
	{
		printf("Match found for age: %d\n", age);
	}
	return(stuList);
}

//Iterates through list to find student with matching ID
STUDENT* searchID(SET *sp, int id)//O(n)
{
	assert(sp != NULL);

	printf("Searching for ID: %d\n", id);

	STUDENT *p = sp->dummy->next;

	while(p != sp->dummy)//Loop though list in search of item
	{
		if(p->id == id)
		{
			printf("Match found for ID: %d\n", id);
			return(p);
		}
		p = p->next;
	}
	printf("No match found for ID: %d\n", id);
	return NULL;
}

//Uses ageCount to calculate max age 
int maxAgeGap(SET *sp)//O(1)
{
	assert(sp != NULL);

	//Loop in from both sides to find max and min ages that exist
	if(sp->count > 1)
	{
		int min = 0;
		while(sp->ageCount[min] == 0)
			min++;

		int max = AGE_INTERVAL-1;
		while(sp->ageCount[max] == 0)
			max--;

		printf("Max age gap is %d\n", max-min);
		return(max - min);
	}
	else
		return -1; 
}
