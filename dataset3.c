/*Federico Madden
COEN 12 Prof. Liu
MFW 10:30AM
5/8/2018
*/

#include<stdio.h>
#include<assert.h>

#define AGE_INTERVAL 18

//Just use ages array

typedef struct student
{
	int age;
	int id;
	int ageCount[AGE_INTERVAL];
	STUDENT *next;
	STUDENT *prev;
}STUDENT;

typedef struct set
{
	int count;
	STUDENT* dummy;
}SET;



SET* createDataSet();
void destroyDataSet(SET *sp);
STUDENT* searchAge(SET *sp, int age);
STUDENT* searchID(SET *sp, int id);
void insertion(SET *sp, STUDENT stu);
void deletion(SET *sp, STUDENT *p);
int maxAgeGap(SET *sp);

static int search(SET *sp, STUDENT stu);

//Adapted
SET* createDataSet()
{
    SET *sp = malloc(sizeof(SET));
    assert(sp !=NULL);

    sp->count = 0;
    sp->ageCount[] = {0};

    sp->dummy = malloc(sizeof(STUDENT));
    assert(sp->dummy!= NULL);

    sp->dummy->prev = sp->dummy;
    sp->dummy->next = sp->dummy;

    return sp;
}

//Adapted
void destroyDataSet(SET *sp)
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
//Adapted
void insertion(SET *sp, STUDENT stu)
{
	assert(sp != NULL);

	STUDENT *p = malloc(sizeof(STUDENT));
	assert(p != NULL);
	*p = stu;

	//Hook p up to the nodes next to it
	sp->dummy->next->prev = p;
	sp->next = sp->dummy->next;
	sp->dummy->next = p;
	p->prev = sp->dummy;

	sp->ageCount[(p->age) - AGE_INTERVAL] += 1;
	sp->count += 1;
}
//Adapted
void deletion(SET *sp, STUDENT *p)//Vulnerability: Doesn't check that stu is a member of sp
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


//Adapted
STUDENT *searchAge(SET *sp, int age)
{
	assert(sp != NULL);

	printf("Searching for age: %d\n", age);

	STUDENT** stuList = malloc(sizeof(STUDENT*) * sp->ageCount[age - AGE_INTERVAL] + 1);
	assert(stuList != NULL);

	NODE *p = sp->dummy->next;
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
	stuList[i] = NULL;

	if(stuList[0] = NULL)
	{
		printf("No match found for age: %d\n", age);
	}
	else
	{
		printf("Match found for age: %d\n", age);
	}
	return(stuList);
}

//Adapted
static int searchID(SET *sp, int id)
{
	assert(sp != NULL);

	printf("Searching for ID: %d\n", id);

	NODE *p = sp->dummy->next;

	while(p != sp->dummy)//Loop though list in search of item
	{
		if(p->id == id)
		{
			printf("Match found for ID: %d", id);
			return(p);
		}
		p = p->next;
	}
	printf("No match found for ID: %d", id);
	return NULL;
}

//Not Adapted
int maxAgeGap(SET *sp)
{
	assert(sp != NULL);

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
		return NULL;
}
