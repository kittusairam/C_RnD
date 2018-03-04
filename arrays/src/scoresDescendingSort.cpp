/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SD
*/

#include <stdio.h>
#include<string.h>
struct student {
	char name[10];
	int score;
};

void sortsstudents(struct student *students, int len);
void swapsstudents(struct student *students, int counter1, int counter2);

void * scoresDescendingSort(struct student *students, int len) {
	if (students == NULL || len < 1)
		return NULL;
	else
	{
		if (len == 1){
			return 0;
		}
		else
		{
			sortsstudents(students, len);
			return 0;
		}
	}
}

void sortsstudents(struct student *students, int len){
	int counter1 = 0, counter2 = 0;
	for (counter1 = 0; counter1 < len - 1; counter1++){
		for (counter2 = counter1 + 1; counter2 < len; counter2++){
			if (students[counter1].score < students[counter2].score){
				swapsstudents(students, counter1, counter2);
			}
		}
	}
}

void swapsstudents(struct student *students, int counter1, int counter2){
	struct student s = students[counter1];
	students[counter1] = students[counter2];
	students[counter2] = s;
}