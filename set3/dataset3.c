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
void deletion(SET *sp, int age);
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
void deletion(SET *sp, STUDENT* stu)//Vulnerability: Doesn't check that stu is a member of sp
{
	assert(sp != NULL);
	assert(sp->dummy->next != sp->dummy);//Check that list isn't empty
	assert(stu != NULL);

	//Unhook node from list
	stu->next->prev = stu->prev;
	stu->prev->next = stu->next;	
	free(p);
	sp->count -= 1;
}


//Adapted
STUDENT *searchAge(SET *sp, int age)
{
	assert(sp != NULL);

	STUDENT** stuList = malloc(sizeof(STUDENT*)*sp->count);
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

	return(stuList);
}

//Adapted
static int searchID(SET *sp, int id)
{
	assert(sp != NULL);

	NODE *p = sp->dummy->next;

	while(p != sp->dummy)//Loop though list in search of item
	{
		if(p->id == id)
		{
			return(p);
		}
		p = p->next;
	}
	return NULL;
}

//Not Adapted
int maxAgeGap(SET *sp)
{
	assert(sp != NULL);

	if(sp->count > 1)
		return((sp->students[count-1].age) - (sp->students[0].age));
	else
		return NULL;
}
