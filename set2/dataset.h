#ifndef DATASET_H
#define DATASET_H

typedef struct student
{
	int age;
	int id;
}STUDENT;

typedef struct set
{
	int count;
	int length;
    STUDENT** students;
	int *flags;
}SET;

extern SET* createDataSet();

extern void destroyDataSet(SET *sp);//Rename these eventually

extern STUDENT* searchID(SET *sp, int id);

extern void insertion(SET *sp, STUDENT *stu);

extern void deletion(SET *sp, STUDENT *stu);

#endif
