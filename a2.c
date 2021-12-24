#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// structures
typedef struct student {
    char *name;
    int  id;
    struct clist *courses;
} student;

typedef struct course {
    char *title;
    int  number;
    struct slist *students;
} course;

typedef struct slist {
    student      *info;
    struct slist *next;
} slist;

typedef struct clist {
    course       *info;
    struct clist *next;
} clist;


// prototypes
void *my_malloc (size_t size)       //malloc function
{
    void *addr = malloc(size);
    if(addr == NULL)exit(1);
    //printf("malloc addr=0x%x, size=%d\n",addr , size);
    return addr;
}

void my_free (void *ptr)            //free function
{
    //printf("free addr=0x%x\n", ptr);
    free(ptr);
}

slist* add_student(slist *students, char *name, int id)
{
    struct slist *newSlist;
    struct slist *currStd;
    struct student *newStd;
    struct slist *temp;

    //allocate new student
    newStd = (student *)my_malloc(sizeof(student));
    newStd->name = (char *)my_malloc(strlen(name));
    strcpy(newStd->name , name);
    newStd->id = id;
    newStd->courses = NULL;

    //allocate list element for the new student
    newSlist = (struct slist *)my_malloc(sizeof(slist));
    newSlist->info = newStd;
    newSlist->next = NULL;

    if(students)
        newSlist->info = students->info;

    //student list is null, just add it
    if(!students)
    {
        return newSlist;
    }

    //add the new student to be first on the list
    if(newStd->id < newSlist->info->id)
    {
        newSlist->info = newStd;
        struct slist *temp = students;
        students = newSlist;
        students->next = temp;
        return newSlist;
    }

    //find where to put the new element
    currStd = students;
    while (currStd->next && newStd->id > currStd->next->info->id)
    {
        currStd = currStd->next;
    }

    //insert the new element
    newSlist->info = newStd;
    temp = currStd->next;
    currStd->next = newSlist;
    newSlist->next = temp;
    return students;
}
clist* add_course(clist *courses, char *title, int number)
{
    struct clist *newClist;
    struct clist *currCrs;
    struct course *newCrs;

    //allocate new course
    newCrs = (course *)my_malloc(sizeof(course));
    newCrs->title = (char *)my_malloc(strlen(title));
    strcpy(newCrs->title , title);
    newCrs->number = number;
    newCrs->students = NULL;

    //allocate list element for the new course
    newClist = (struct clist *)my_malloc(sizeof(clist));
    newClist->info = newCrs;
    newClist->next = NULL;

    if(courses)
    {
        newClist->info = courses->info;
    }

    //course list is null, just add it
    if(!courses)
    {
        return newClist;
    }

    //add the new course to be first on the list
    if(newCrs->number < newClist->info->number)
    {
        newClist->info = newCrs;
        struct clist *temp1 = courses;
        courses = newClist;
        courses->next = temp1;
        return newClist;
    }

    //find where to put the new element
    currCrs = courses;
    while (currCrs->next && newCrs->number > currCrs->next->info->number)
    {
        currCrs = currCrs->next;
    }

    //insert the new element
    newClist->info = newCrs;
    struct clist *temp2 = currCrs->next;
    currCrs->next = newClist;
    newClist->next = temp2;
    return courses;
}

struct slist *searchS(slist *students, int id)
{
    //search the address of the wanted student
    while (students)
    {
        if(students->info->id == id)
            return students;
        students = students->next;
    }
    return NULL;
}

struct clist *searchC(clist *courses, int number)
{
    //search the address of the wanted course
    while (courses)
    {
        if(courses->info->number == number)
            return courses;
        courses = courses->next;
    }
    return NULL;
}

clist* insert_course(clist *courses, struct course *course)
{
    //insert course to the list
    struct clist *newClist;
    struct clist *currCrs;
    newClist = (struct clist *)my_malloc(sizeof(clist));
    newClist->info = course;
    newClist->next = NULL;

    if(courses)
    {
        newClist->info = courses->info;
    }
    //course list is null, open new place for courses
    if(!courses)
    {
        return newClist;
    }

    //add the new course to be first on the list
    if(course->number < newClist->info->number)
    {
        newClist->info = course;
        struct clist *temp1 = courses;
        courses = newClist;
        courses->next = temp1;
        return newClist;
    }

    //find where to put the new element
    currCrs = courses;
    while (currCrs->next && course->number > currCrs->next->info->number)
    {
        currCrs = currCrs->next;
    }

    //insert the new element
    newClist->info = course;
    struct clist *temp2 = currCrs->next;
    currCrs->next = newClist;
    newClist->next = temp2;
    return courses;
}

slist* insert_student(slist *students, struct student *student)
{
    //insert student to the list
    struct slist *newSlist;
    struct slist *currStd;
    newSlist = (struct slist *)my_malloc(sizeof(slist));
    newSlist->info = student;
    newSlist->next = NULL;

    if(students)
    {
        newSlist->info = students->info;
    }
    //students list is null, open new place for students
    if(!students)
    {
        return newSlist;
    }

    //add the new student to be first on the list
    if(student->id < newSlist->info->id)
    {
        newSlist->info = student;
        struct slist *temp1 = students;
        students = newSlist;
        students->next = temp1;
        return newSlist;
    }

    //find where to put the new element
    currStd = students;
    while (currStd->next && student->id > currStd->next->info->id)
    {
        currStd = currStd->next;
    }

    //insert the new element
    newSlist->info = student;
    struct slist *temp2 = currStd->next;
    currStd->next = newSlist;
    newSlist->next = temp2;
    return students;
}

void reg_student(slist *students, clist *courses, int id, int number)
{
    struct slist *foundStd;
    struct clist *foundCrs;

    // find each pointer of the course and student that want to register
    foundStd = searchS(students, id);
    foundCrs = searchC(courses, number);

    //add course to student in the slist
    if (foundStd != NULL)
    {
        foundStd->info->courses = insert_course(foundStd->info->courses , foundCrs->info);
    }

    // add student to course in the clist
    if (foundCrs != NULL)
    {
        foundCrs->info->students = insert_student(foundCrs->info->students , foundStd->info);
    }
}

clist *removeC(struct clist *courses, int number)
{
    //remove course from student's course list
    clist *curr = courses;
    clist *prev = NULL;

    if(!courses)
    {
        return NULL;
    }
    if(courses->info->number == number)
    {
        courses = courses->next;
        my_free(curr);
        return courses;
    }
    while(curr)
    {
        if(number == curr->info->number)
        {
            prev->next = curr->next;
            my_free(curr);
            return courses;
        }
        prev = curr;
        curr = curr->next;
    }
    return courses;
}

slist *removeS(struct slist *students, int id)
{
    //remove student from course's student list
    slist *curr = students;
    slist *prev = NULL;

    if(!students)
    {
        return NULL;
    }
    if(students->info->id == id){
        students = students->next;
        my_free(curr);
        return students;
    }
    while(curr){
        if(id == curr->info->id){
            prev->next = curr->next;
            my_free(curr);
            return students;
        }
        prev = curr;
        curr = curr->next;
    }
    return students;
}

void unreg_student(slist *students, int id, int number)
{
    struct slist *foundStd;
    struct clist *foundCrs;

    foundStd = searchS(students, id);
    foundCrs = searchC(foundStd->info->courses, number);
    foundCrs->info->students = removeS(foundCrs->info->students, id);
    foundStd->info->courses = removeC(foundStd->info->courses , number);
}

void print_students(slist *students)
{
    printf("STUDENT LIST: ");
    if (!students)
    {
        printf("EMPTY!\n");
    } else {
        printf("\n");
    }

    //print every student
    while(students)
    {
        struct clist *currCrs = students->info->courses;
        printf("%d:%s\n", students->info->id ,students->info->name);
        while (!currCrs)
        {
            printf("student is not registered for courses.");
            break;
        }
        if (currCrs)
        {
            printf("courses: ");
        }

        //print courses list that student register to
        while (currCrs)
        {
            printf("%d-%s", currCrs->info->number , currCrs->info->title);
            if(currCrs->next != NULL)
            {
                printf(", ");
            }
            if (currCrs == NULL)
            {
                printf("\n");
            }
            currCrs = currCrs->next;
        }
        printf("\n");
        students = students->next;
    }
}

void print_courses(clist *courses)
{
    printf("COURSE LIST: ");
    if (!courses)
    {
        printf("EMPTY!\n");
    } else {
        printf("\n");
    }

    //print every course
    while(courses)
    {
        struct slist *currStd = courses->info->students;
        printf("%d:%s\n", courses->info->number ,courses->info->title);
        while (!currStd)
        {
            printf("course has no students.");
            break;
        }
        if (currStd)
        {
            printf("students: ");
        }

        //print students list that register to this course
        while (currStd)
        {
            printf("%d-%s", currStd->info->id , currStd->info->name);
            if(currStd->next != NULL)
            {
                printf(", ");
            }
            currStd = currStd->next;
        }
        printf("\n");
        courses = courses->next;
    }
}

void free_student(slist *sList, int fullS_free)
{
    // Finished freeing. Empty list
    if (sList== NULL)
        return;

    // Recursively free what’s ahead
    free_student(sList->next, fullS_free);

    if(fullS_free)
    {
        my_free(sList->info->name);
        my_free(sList->info);
    }
    my_free(sList);
}

void free_course(clist *cList, int fullC_free)
{
    // Finished freeing. Empty list
    if (cList == NULL)
        return;

    // Recursively free what’s ahead
    free_course(cList->next, fullC_free);

    if (fullC_free)
    {
        my_free(cList->info->title);
        my_free(cList->info);
    }
    my_free(cList);
}

void free_all(slist *sl, clist *cl)
{
    struct slist *std = sl;
    struct clist *crs = cl;

    while (std)
    {
        free_course(std->info->courses, 0);
        std->info->courses = NULL;
        std = std->next;
    }
    while (crs)
    {
        free_student(crs->info->students,0);
        crs->info->students = NULL;
        crs = crs->next;
    }

    free_student(sl,1);
    free_course(cl, 1);
}


//DO NOT TOUCH THIS FUNCTION
static void getstring(char *buf, int length) {
    int len;
    buf = fgets(buf, length, stdin);
    len = (int) strlen(buf);
    if (buf[len-1] == '\n')
        buf[len-1] = '\0';
}

//DO NOT TOUCH THIS FUNCTION 
int main() {
    slist* students = 0;
	clist* courses = 0;
    char  c;
    char  buf[100];
    int   id, num;
 
    do {
        printf("Choose:\n"
               "    add (s)tudent\n"
               "    add (c)ourse\n"
               "    (r)egister student\n"
               "    (u)nregister student\n"
			   "    (p)rint lists\n"
               "    (q)uit\n");
 
        while ((c = (char) getchar()) == '\n');
        getchar();
 
        switch (c) {
        case 's':
            printf("Adding new student.\n");
 
            printf("Student name: ");
            getstring(buf, 100);
 
            printf("Student ID: ");
            scanf("%d", &id);
 
            students = add_student(students, buf, id);
 
            break;
 
        case 'c':
            printf("Adding new course.\n");
 
            printf("Course name: ");
            getstring(buf, 100);
 
            printf("Course number: ");
            scanf("%d", &num);
 
            courses = add_course(courses, buf, num);
 
            break;
 
        case 'r':
            printf("Registering a student to a course.\n");
 
            printf("Student ID: ");
            scanf("%d", &id);
            
            printf("Course number: ");
            scanf("%d", &num);
 
            reg_student(students, courses, id, num);
 
            break;
 
        case 'u':
            printf("Unregistering a student from a course.\n");
 
            printf("Student ID: ");
            scanf("%d", &id);
            
            printf("Course number: ");
            scanf("%d", &num);
 
            unreg_student(students, id, num);
 
            break;
 
        case 'p':
            printf("Printing Information.\n");
 
			print_students(students);
			print_courses(courses);
 
            break;
 
        case 'q':
			printf("Quitting...\n");
            break;
        }
 
        if (c != 'q')
            printf("\n");
    } while (c != 'q');
	
	free_all(students,courses);
    return 0;
}