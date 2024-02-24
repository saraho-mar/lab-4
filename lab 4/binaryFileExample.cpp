/** Store a set of student records from an array into a binary file **/


#define _CRT_SECURE_NO_WARNINGS
#define bool int
#define false 0
#define true (!false)
#include <stdio.h>
#define MAX 3


struct student {
	char studentId[10];
	char name[40];
	char course[5];
	int year;
};

//Function prototypes
void inputAStudent(int);
void saveToFile(FILE *);
void getFromFile(FILE *);
void displayStudents();

// Global variables
struct student classOfStudents[MAX];


void main()
{
	FILE *fp;
	int i;
	
    char delay;

	if ((fp = fopen("students.dat", "rb")) == NULL) {

	//file DOES NOT exist so get user to input students
	
	     for (i=0; i< MAX; i++)
		 	inputAStudent(i);
	}//end if
	else  //file DOES exist
		getFromFile(fp);

	displayStudents();

  
	saveToFile(fp);
	
    getchar();
	getchar();
	
}

void inputAStudent(int i) {
	printf("Enter student id : ");
	scanf("%s", classOfStudents[i].studentId);
	printf("Enter student name : ");
	scanf("%s", classOfStudents[i].name);
}

void saveToFile(FILE *fp) {

	fp = fopen("students.dat", "wb");

	for (int i=0; i< MAX; i++) 
		fwrite(&classOfStudents[i], sizeof(struct student), 1, fp);

	fclose(fp);
}

	void getFromFile(FILE *fp)  {
		int i = 0;
	   char c;
		printf("Retriving students from file...\n");
		while (fread(&classOfStudents[i], sizeof(struct student), 1, fp) != NULL) 
			i++; 
		fclose(fp);
	}


	void displayStudents() {
		int i;
		for (i=0; i< MAX; i++)
			printf("Student %d is %s\n", i+1, classOfStudents[i].studentId);
}

