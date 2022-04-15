#include "grade_school.h"

void init_roster(roster_t *roster)
{
	roster->count = 0;
}

static void sort_add_student(roster_t *roster, student_t student)
{
	size_t insert_index = roster->count;	
	for (size_t i = 0; i < roster->count; i++)
	{
		student_t current_student = roster->students[i];
		if ((current_student.grade > student.grade) || 
				((current_student.grade == student.grade) && (strcmp(current_student.name, student.name) > 0)))
		{
			insert_index = i;
			break;			
		}	
	}

	for (size_t k = roster->count; k > insert_index; k--)
	{
		roster->students[k] = roster->students[k-1];
	}

	roster->students[insert_index] = student;
	roster->count++;
}

bool add_student(roster_t *roster, const char *name, int grade)
{
	if ((strlen(name) >= MAX_NAME_LENGTH) || (roster->count >= MAX_STUDENTS))
	{
		return false;
	}

	for(size_t i = 0; i < roster->count; i++)
	{
		if (strcmp(roster->students[i].name, name) == 0)
		{
			return false;
		}
	}

	student_t student = { .grade = grade };
	strcpy(student.name, name);
	sort_add_student(roster, student);
	return true;
}


roster_t get_grade(roster_t *roster, int grade)
{
	roster_t grade_roster;
	size_t count = 0;
	for (size_t i = 0; i < roster->count; i++)
	{
		if (roster->students[i].grade == grade)
		{
			grade_roster.students[count++] = roster->students[i];
		}
	}
	grade_roster.count = count;
	return grade_roster;
}
