/*
 * A reimplementation of gpacalc.py for polytechnics in Singapore.
 * Written in ANSI C.
 * Created on: Friday, 1 October 2021
 *
 * Copyright (c) 2021, Ashlee Tan. Licensed as attached.
 */

/* Grades and their respective GPA; set accordingly */
const float GRADE_DIST  = 4.0;
const float GRADE_A     = 4.0;
const float GRADE_BPLUS = 3.5;
const float GRADE_B     = 3.0;
const float GRADE_CPLUS = 2.5;
const float GRADE_C     = 2.0;
const float GRADE_DPLUS = 1.5;
const float GRADE_D     = 1.0;
const float GRADE_F     = 0.0;
const float GRADE_ARRAY[] = {GRADE_DIST, GRADE_A, GRADE_BPLUS, GRADE_B,
			     GRADE_CPLUS, GRADE_C, GRADE_DPLUS, GRADE_D,
			     GRADE_F};

/* Grade strings, in ALL CAPS. Keep the order the same as above! */
const char GRADESTR_DIST[]  = "DIST";
const char GRADESTR_A[]     = "A";
const char GRADESTR_BPLUS[] = "B+";
const char GRADESTR_B[]     = "B";
const char GRADESTR_CPLUS[] = "C+";
const char GRADESTR_C[]     = "C";
const char GRADESTR_DPLUS[] = "D+";
const char GRADESTR_D[]     = "D";
const char GRADESTR_F[]     = "F";
const char *GRADESTR_ARRAY[] = {GRADESTR_DIST, GRADESTR_A, GRADESTR_BPLUS,
			        GRADESTR_B, GRADESTR_CPLUS, GRADESTR_C,
			        GRADESTR_DPLUS, GRADESTR_D, GRADESTR_F};

/*
 * Some fixed constants used by the program.
 * Edit with reasonable values as necessary.
 */
const int MIN_SUBJECT = 1;
const int MAX_SUBJECT = 20;
const int ACCEPT_NUMERIC = 0;  /* also accept number in place of alphabet? */
const float MAX_CUSTOM_GPA = 5.0;  /* if a numerical grade is entered */
#define   MAX_SUBJECT_NAME_LENGTH   14   /* no variable-length arrays */
#define   MAX_ALPHA_GRADE_LENGTH    5      /* in C89 */

/*
 * What comes after here isn't meant to be user-edited!
 */

/* Custom structs */
typedef struct subject {
	char  name[MAX_SUBJECT_NAME_LENGTH+1];  /* '\0' */
	float grade;
	float credit;
} SUBJECT;

/* Function prototypes */
float numgrade(char *);

/* Defines and constants*/
#define   i_NUMGRD_ERR   -1.1  /* internal use; .1 for type-casting to int */
#define   NUMGRD_ERR       -1  /* normal use */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Calculates the total cumulative GPA, based on subject grades.
 */
int
main(void)
{
	int i;
	int nsub;
	SUBJECT **asub;  /* pointer to an array of pointers to subjects */

	float egps;
	float tcreds;
	float gpa;

	printf("Enter number of graded subjects: ");
	i = scanf("%d", &nsub);
	getchar();  /* flush newline '\n'; scanf only */

	/* Error checking */
	if (!i || nsub < MIN_SUBJECT || nsub > MAX_SUBJECT) {
		printf("Invalid number of subjects. Try again?\n");
		return(EXIT_FAILURE);
	}

	/* Allocate memory for subject array */
	asub = malloc(sizeof(SUBJECT *) * nsub);
	if (!asub) {
		printf("Error allocating memory for %d subjects\n", nsub);
		return(EXIT_FAILURE);
	}

	/* Collect data for each subject */
	for (i = 0; i < nsub; i++) {
		SUBJECT *newsub;
		char subname[MAX_SUBJECT_NAME_LENGTH+3]; /* +3: '\0' '\n' err */
		char alphagrade[MAX_ALPHA_GRADE_LENGTH+3]; /* '\0' '\n' err */
		int len;
		float ngrade;

		newsub = malloc(sizeof(SUBJECT));
		if (!newsub) {
			printf("Error allocating memory for subject %d\n",
			       i+1);

			/* Routine to free memory; current one not yet in */
			for (; i > 0; i--)
				free(asub[i-1]);
			free(asub);
			free(newsub);

			return(EXIT_FAILURE);
		}

		printf("Friendly Name (subject %d): ", i+1);
		fgets(subname, sizeof(subname), stdin);
		subname[strcspn(subname, "\n")] = '\0';
		len = strnlen(subname, MAX_SUBJECT_NAME_LENGTH+1);
		if (len < 1) {
			printf("You need to enter a subject name!\n");

			/* Routine to free memory; current one not yet in */
			for (; i > 0; i--)
				free(asub[i-1]);
			free(asub);
			free(newsub);

			return(EXIT_FAILURE);
		}
		if (len > MAX_SUBJECT_NAME_LENGTH) {
			printf("Subject name is too long!\n");

			/* Routine to free memory; current one not yet in */
			for (; i > 0; i--)
				free(asub[i-1]);
			free(asub);
			free(newsub);

			return(EXIT_FAILURE);
		}
		strcpy(newsub->name, subname);

		printf("Alphabetical Grade (subject %d): ", i+1);
		fgets(alphagrade, sizeof(alphagrade), stdin);
		alphagrade[strcspn(alphagrade, "\n")] = '\0';
		len = strnlen(alphagrade, MAX_ALPHA_GRADE_LENGTH+1);
		if (len < 1) {
			printf("You need to enter an alphabetical grade!\n");

			/* Routine to free memory; current one not yet in */
			for (; i > 0; i--)
				free(asub[i-1]);
			free(asub);
			free(newsub);

			return(EXIT_FAILURE);
		}
		if (len > MAX_ALPHA_GRADE_LENGTH) {
			printf("Alphabetical grade entered is too long!\n");

			/* Routine to free memory; current one not yet in */
			for (; i > 0; i--)
				free(asub[i-1]);
			free(asub);
			free(newsub);

			return(EXIT_FAILURE);
		}

		/* Call numgrade() and set struct properties accordingly */
		ngrade = numgrade(alphagrade);
		if ((int) ngrade == NUMGRD_ERR) {
			printf("Invalid grade entered!\n");

			/* Routine to free memory; current one not yet in */
			for (; i > 0; i--)
				free(asub[i-1]);
			free(asub);
			free(newsub);

			return(EXIT_FAILURE);
		}
		if (ngrade > MAX_CUSTOM_GPA+0.001) { /* precision errors? */
			printf("Invalid grade entered!\n");

			/* Routine to free memory; current one not yet in */
			for (; i > 0; i--)
				free(asub[i-1]);
			free(asub);
			free(newsub);

			return(EXIT_FAILURE);
		}   /* numgrd(s) doesn't accept negative as numerical */
		newsub->grade = ngrade;

		printf("Credits (hours per week) (subject %d): ", i+1);
		len = scanf("%f", &(newsub->credit));
		getchar();  /* flush newline '\n'; scanf only */
		if (!len || newsub->credit < 0) {
			printf("You need to enter a valid "
			       "number of credits!\n");

			/* Routine to free memory; current one not yet in */
			for (; i > 0; i--)
				free(asub[i-1]);
			free(asub);
			free(newsub);

			return(EXIT_FAILURE);
		}
		
		asub[i] = newsub;
	}

	/*
	 * Actual GPA calculation routine.
	 * GPA = summation(Module Grade Point * Module Credit Value) /
	 *       summation(Module Credit Value)
	 */

	egps = 0;   /* effective grade points */
	tcreds = 0; /* total credits */

	for (i = 0; i < nsub; i++) {
		egps += asub[i]->grade * asub[i]->credit;
		tcreds += asub[i]->credit;
	}
	gpa = egps/tcreds;

	/* Print grade table */
	printf("-------------- YOUR GRADES -------------\n");
	printf("|     NAME     |   GRADE   |  CREDITS  |\n");
	printf("----------------------------------------\n");
	
	for (i = 0; i < nsub; i++)
		printf("|%-14s|    %-5.1f  |     %-6.0f|\n",
		       asub[i]->name, asub[i]->grade, asub[i]->credit);

	printf("----------------------------------------\n");
	printf("Overall GPA is: %1.3f\n", gpa);

	/* Routine to free memory */
	for (i = 0; i < nsub; i++)
		free(asub[i]);
	free(asub);

	return(EXIT_SUCCESS);
}


/*
 * Translates an alphabetical grade into a numerical grade.
 * If a number is supplied, it is returned as a float.
 * Else if not found, returns -1 = (int) NUMGRD_ERR.
 * Minimum valid value is 0.
 */
float
numgrade(char *s)
{
	int i;
	int found;
	char *temp;

	int isnum;
	int isdec;
	int buf;

	/* Handle the case of numerical input */
	if (ACCEPT_NUMERIC) {
		temp = s;
		isnum = 0;
		isdec = 0;
		buf = MAX_ALPHA_GRADE_LENGTH+2;  /* buffer overflow detection */
		for (; *temp && --buf > 0; ++temp)
			if (*temp >= '0' && *temp <= '9')
				isnum = 1;
			else if (*temp == '.' && !isdec) {
				isnum = 1;
				isdec = 1;
			} else {
				isnum = 0;
				break;
			}
		if (!buf) {  /* should never reach here in normal use */
			printf("buffer overflow in numgrade()\n");
			return(i_NUMGRD_ERR);
		}
		if (isnum)
			return((float) atof(s));
	}

	/* Converts whatever is in s to uppercase before processing. */
	temp = s;
	while (*temp) {
		*temp = toupper(*temp);
		++temp;
	}
	
	/* Compares the grade entered with grade-strings above */
	found = 0;
	for (i = 0; i < (sizeof(GRADESTR_ARRAY) / sizeof(GRADESTR_ARRAY[0]));
			++i)
		if (strcmp(s, GRADESTR_ARRAY[i]) == 0) {
			found = 1;
			break;
		}

	/* If it's found, get the grade and return it */
	if (found)
		return(GRADE_ARRAY[i]);
	else
		return(i_NUMGRD_ERR);
}
