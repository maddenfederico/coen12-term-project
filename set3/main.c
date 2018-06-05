/*Federico Madden
Prof. Liu COEN 12*/

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

int main()
{

	SET *sp = createSet();

	srand(time(0));

	int age, id;
	for(int i = 0; i < 1000; i++)
	{
		id += ((rand() % 2) +1);
		STUDENT stu = {((rand() % 18)+18), id, NULL, NULL};//Check the mod
		insertion(sp, stu);
	}

	id = ((rand() % 2000) +1);
	STUDENT *p = searchID(sp, id);

	if(p != NULL)
	{
		deletion(sp, p);
	}

	printf("Max age gap is: %d", maxAgeGap(sp));

	destroySet(sp);
}