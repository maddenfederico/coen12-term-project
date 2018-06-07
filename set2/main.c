/*Federico Madden
Prof. Liu COEN 12*/

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include "dataset.h"
#include<time.h>

int main()
{

	SET *sp = createDataSet(3000);

	srand(time(0));

	int age, id;
	for(int i = 0; i < 1000; i++)
	{
		id += ((rand() % 2) +1);
		age = (rand() % 18) + 18;

		STUDENT* stu = malloc(sizeof(STUDENT));
		assert(stu != NULL);

		stu->age = age;
		stu->id = id;

		insertion(sp, stu);
	}

	id = ((rand() % 2000) +1);
	age = (rand() % 18) + 18;

	STUDENT* stuSearch = malloc(sizeof(STUDENT));
	assert(stuSearch != NULL);
	
	stuSearch->age = age;
	stuSearch->id = id;
	STUDENT *p = searchID(sp, stuSearch->id);

	free(stuSearch);

	id = ((rand() % 2000) +1);
	age = (rand() % 18) + 18;
	
	STUDENT* stuDel = malloc(sizeof(STUDENT));
	assert(stuDel != NULL);
	
	stuDel->age = age;
	stuDel->id = id;
		
	deletion(sp, stuDel);

	free(stuDel);

	destroyDataSet(sp);
}
