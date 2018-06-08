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



static int search(SET *sp, STUDENT *stu, bool *found);

//Adapted
//Create a set of size maxStudents
SET *createDataSet(int maxStudents)//O(n)
{
	SET *sp;
	sp = malloc(sizeof(*sp));
	assert(sp != NULL);

	sp->length = maxStudents+1;
	sp->count = 0;
	
	sp->students = malloc(sizeof(STUDENT*)*maxStudents);
	assert(sp->students != NULL);

	sp->flags = malloc(sizeof(int)*maxStudents);
	assert(sp->flags != NULL);
	for(int i = 0; i < maxStudents; i++)
		sp->flags[i] = EMPTY;

	return sp;
}

//Adapted
//Hash the passed element and place it into the table of the passed set
void insertion(SET *sp, STUDENT *stu)//O(1) avg case, O(n) worst case
{
	assert(sp != NULL);
	assert(stu != NULL);
	bool found = false;
	int idx = search(sp, stu, &found);

	if(sp->count < sp->length)//check if array capacity has been reached
	{				
		sp->students[idx] = stu;		
		sp->count++;
		sp->flags[idx] = FILLED;
	}
}

//Search through the table for passed stu in sp and remove if found.
void deletion(SET *sp, STUDENT *stu)//O(1) avg case, O(n) worst case
{
	assert(sp!= NULL);
	assert(stu != NULL);

	bool found = false;
	int idx = search(sp, stu, &found);
	
	if(found)
	{
		free(sp->students[idx]);
		sp->flags[idx] = DELETED;
		sp->count -= 1;
		printf("Deleted student with age %d and ID %d\n", stu->age, stu->id);
	}
	else
	{
		int age = stu->age;
		int id = stu->id;
		printf("Failed to delete student with age %d and ID %d;Not found\n", age, id);
	}
}

//Adapted
//Free all members of passed set struct, then free struct
void destroyDataSet(SET *sp)//O(n)
{
	assert(sp != NULL);

	for(int i = 0; i < sp->count; i++)//Loop though and free remaining students
	{
		if(sp->flags[i] == FILLED)
		{
			free(sp->students[i]);
		}		
	}

	free(sp->students);
	free(sp->flags);
	free(sp);
}

//Adapted
/*Search through hash table for actual/appropriate location of passed stu.
 * Passed bool will store whether stu was found or not
 Returns index of where passed elt is if found and appropriate location if not*/
static int search(SET *sp, STUDENT *stu, bool *found)//O(n) worst case, O(1) avg case
{
	
	assert(sp!=NULL);
	assert(stu != NULL);

	int start = stu->id % sp->length;//Initial hash location
	int idx;

	bool foundDel = false;
	int idxDel;

	//Return 
	for(int i = 0; i < sp->length; i++)//Will probe linerly in case of collisions
	{
		idx = (start + i) % sp->length;
		if(sp->flags[idx] == FILLED)
		{
			if(stu->id == sp->students[idx]->id)
			{
				*found = true;
				return idx;
			}
		}
		else if(sp->flags[idx] == DELETED && !foundDel)//Will return this location if elt not found
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
STUDENT* searchID(SET *sp, int id)//O(1) avg case, O(n) worst case
{
	assert(sp!=NULL);

	bool found = false;
	STUDENT* searcher = malloc(sizeof(STUDENT));//dummy student to use for search
	searcher->age = -1;
	searcher->id = id;

	printf("Searching for ID: %d\n", id);
	int index = search(sp, searcher, &found);
	
	free(searcher); 

	if(found)
	{
		printf("Match found for ID: %d\n", id);
		return(sp->students[index]);
	}
	else
	{
		printf("No match found for ID: %d\n", id);
		return NULL;
	}
}


