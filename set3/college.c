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

	if(p != NULL)
	{
		deletion(sp, p);
	}

	maxAgeGap(sp);

	destroyDataSet(sp);
}
