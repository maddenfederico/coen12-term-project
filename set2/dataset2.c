/*Federico Madden
COEN 12 MWF 10:30AM
Prof. Liu
PROJECT 3 */

#include "dataset.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define EMPTY 0
#define FILLED 1
#define DELETED 2



static int search(SET *sp, void *stu, bool *found);

//Adapted
//Create a set of size maxStudents and initialize with functions passed by client.
SET *createDataSet(int maxStudents)
{
	SET *sp;
	sp = malloc(sizeof(*sp));
	assert(sp != NULL);

	sp->length = maxStudents;
	sp->count = 0;
	
	sp->students = malloc(sizeof(STUDENT)*maxStudents);
	assert(sp->students != NULL);

	sp->flags = malloc(sizeof(int)*maxStudents);
	assert(sp->flags != NULL);
	for(int i = 0; i < maxStudents; i++)
		sp->flags[i] = EMPTY;

	return sp;
}

//Adapted
//Hash the passed element and place it into the table of the passed set
void insertion(SET *sp, STUDENT stu)
{
	assert(sp != NULL);
	assert(stu != NULL);
	bool found = false;
	int idx = search(sp, stu, &found);

	if(sp->count < sp->length)//check if array capacity has been reached and if stu already exists in the set
	{
		sp->students[idx] = stu;		
		sp->count++;
		sp->flags[idx] = FILLED;
	}
}

//Adapted
//Search through the table for passed stu in sp and remove if found.
void deletion(SET *sp, STUDENT stu)
{
	assert(sp!= NULL);
	assert(stu != NULL);
	bool found = false;
	int idx = search(sp, stu, &found);
	
	if(found)
	{
		sp->flags[idx] = DELETED;
		sp->count -= 1;
	}
}

//Adapted
//Free all members of passed set struct, then free struct
void destroyDataSet(SET *sp)
{
	assert(sp != NULL);
	free(sp->students);
	free(sp->flags);
	free(sp);
}

//Adapted
/*Search through hash table for actual/appropriate location of passed stu.
 * Passed bool will store whether stu was found or not*/
static int search(SET *sp, STUDENT stu, bool *found)
{
	
	assert(sp!=NULL);
	assert(stu != NULL);

	int start = stu.id % sp->length;
	int idx;

	bool foundDel = false;
	int idxDel;
	for(int i = 0; i < sp->length; i++)
	{
		idx = (start + i) % sp->length;
		if(sp->flags[idx] == FILLED)
		{
			if(stu.id == sp->students[idx].id)
			{
				*found = true;
				return idx;
			}
		}
		else if(sp->flags[idx] == DELETED && !foundDel)
		{
			foundDel = true;
			idxDel = idx;
		}
		else if(sp->flags[idx] == EMPTY)
		{
			if(foundDel)
				return idxDel;
			else 
				return idx;
		}
	}
	return -1;
}

//Client accessible function to search()
STUDENT searchID(SET *sp, int id)
{
	assert(sp!=NULL);

	bool found;
	STUDENT dummy = {NULL, id};
	int index = search(sp, dummy, &found);
	
	if(found)
	{
		return(sp->students[index]);
	}
	else
	{
		return NULL;
	}
}


