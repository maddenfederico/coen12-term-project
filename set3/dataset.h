#ifndef DATASET_H
#define DATASET_H

typedef struct student
{
	int age;
	int id;
    struct student *next;
	struct student *prev;
}STUDENT;

typedef struct set
{
	int count;
	int ageCount[18];
	STUDENT *dummy;
}SET;

extern SET* createSet();

extern void destroySet(SET *sp);//Rename these eventually

extern STUDENT** searchAge(SET *sp, int age);

extern STUDENT* searchID(SET *sp, int id);

extern void insertion(SET *sp, STUDENT stu);

extern void deletion(SET *sp, STUDENT *p);

extern int maxAgeGap(SET *sp);

#endif
