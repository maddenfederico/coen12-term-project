/*Federico Madden
Prof. Liu COEN 12*/

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include "dataset.h"
#include<time.h>

int main()
{

	SET *sp = createDataSet();

	srand(time(0));

	int age, id;
	age = (rand() % 18) + 18;
	for(int i = 0; i < 1000; i++)
	{
		id += ((rand() % 2) +1);
		STUDENT stu;
		stu.age = age;
		stu.id = id;
		stu.next = NULL;
		stu.prev = NULL;

		insertion(sp, stu);
	}

	id = ((rand() % 2000) +1);
	STUDENT *p = searchID(sp, id);

	STUDENT *q = malloc(sizeof(STUDENT));
	q->age = (rand() % 18) + 18;
	q->id = (rand() % 2000);

	STUDENT *del = searchID(sp, q->id);

	if(del != NULL)
	{
		deletion(sp, del);
	}
	else
	{
		printf("Failed to delete student with id %d\n", q->id);
	}

	maxAgeGap(sp);
	free(q);
	destroyDataSet(sp);
}
