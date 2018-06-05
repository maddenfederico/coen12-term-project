/*Federico Madden
COEN 12 Prof. Liu
MFW 10:30AM
5/8/2018
*/





#include<stdio.h>
#include<assert.h>


typedef struct student
{
	int age;
	int id;
}STUDENT;

typedef struct set
{
	int count;
	int length;
	STUDENT* students;
}SET;



SET* createDataSet(int maxStudents);
void destroyDataSet(SET *sp);
STUDENT* searchAge(SET *sp, int age, bool *found);
void insertion(SET *sp, STUDENT stu);
void deletion(SET *sp, int age);
int maxAgeGap(SET *sp);

static int search(SET *sp, STUDENT stu);

//Adapted
SET* createDataSet(int maxStudents)
{
	SET *sp = malloc(sizeof(SET));
	assert(sp != NUll);

	sp->count = 0;
	sp->length = maxStudents;

	sp->students = malloc(sizeof(STUDENT)*sp->length);

	return sp;
}
//Adapted
void insertion(SET *sp, STUDENT stu)
{
	bool found;//We don't care whether its found. Search just needs this
	int index = search(sp, stu->age, &found);//Find correct index for stu

	if(sp->count < sp->length)
	{
		for(int i = sp->count; i >  index; i--)//Shift all elements below index down to make space for elt and add elt
		{
			sp->list[i] = sp->list[i-1];
		}
		
		sp->list[idx] = stu;

		sp->count += 1;
	}
}

void deletion(SET *sp, int age)
{
	assert(sp != NULL);
}


//Not Adapted
STUDENT *searchAge(SET *sp, int age)
{
	bool found;
	STUDENT dummy = {age, NULL};

	int idx = search(sp, dummy, &found);

	

}

static int search(SET *sp, STUDENT stu, *found)
{
	int lo, hi, mid; lo = 0, hi = sp->count-1;
    
    while(lo <= hi)//Binary search for index of elt
    {
        mid = (lo+hi)/2;
        if(age < sp->students[mid].age)
        {
            hi = mid - 1;
        }
        else if(age < sp->students[mid].age)
        {
            lo = mid + 1;
        }
        else
        {
        	*found = true;
            return mid;
        }
    }
    *found = false;
    return lo;
}

int maxAgeGap(SET *sp)
{
	assert(sp != NULL);

	if(sp->count > 1)
		return((sp->students[count-1].age) - (sp->students[0].age));
	else
		return NULL;
}
