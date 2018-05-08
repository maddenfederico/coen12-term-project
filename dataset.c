/*Federico Madden
COEN 12 Prof. Liu
MFW 10:30AM
5/8/2018
*/

#include<stdio.h>

typedef struct student
{
	int age;
	int id;
}STUDENT;

typedef struct set
{
	int count;
	int length;
	STUDENT* list;
}SET;



SET* createDataSet(int maxStudents);
void destroyDataSet(SET *sp);
STUDENT* searchAge(SET *sp, int age, bool *found);
void insertion(SET *sp, STUDENT stu);
void deletion(SET *sp, int age);
int maxAgeGap(SET *sp);


void insertion(SET *sp, STUDENT stu)//Add string elt to the passed set 
{
	bool found;
	int index = search(sp, stu->age, &found);//Find correct index for elt

	if((sp->count < sp->length) && (!found))//Check if array capacity has been reached and if elt already exists in the set
	{
		for(int i = sp->count; i >  index; i--)//Shift all elements below index down to make space for elt and add elt
		{
			sp->a[i] = sp->a[i-1];
		}
		sp->a[index] = malloc(sizeof(char)*(strlen(elt)+1));
		assert((sp->a[index]) != NULL);
		
		strcpy((sp->a[index]), elt);
		sp->count += 1;
	}
}

int searchAge(SET *sp, int age, bool *found)//Look for string elt in set sp and return index of where it is/should be placed. Also store search result in bool found. Not publicly accessed.
{

	int lo, hi, mid; lo = 0, hi = sp->count-1;
    
    while(lo <= hi)//Binary search for index of elt
    {
        mid = (lo+hi)/2;
        if(strcmp(elt, sp->a[mid]) < 0)
        {
            hi = mid - 1;
        }
        else if(strcmp(elt, sp->a[mid]) > 0)
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