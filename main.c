// Include libiraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Global Decalrations
#define MAX_NUM 100000
#define MAX_COURSES 10000
#define MAX_STUDENTS 10000

// Function protoypes
void Course_exams(int course_number[],int course_date[][3],char course_hall[]); // course input data: - codes - date - hall

void Students(int student_id[],int student_exam[][5]); // Students info: - ID - Exams enrolled

int number_students(int student_id[]);//func 1

int number_halls(char course_hall[]);//func 2

void course_students(int exam_code, int student_exam[][5], int student_id[]);//func 6

void function_of_date(int course_date[][3]);//func 5

int month_funct(int *ptr2, int *ptr1);//func 5

int min_id(int student_id[]);//func 3

int max_id(int student_id[]);//func 4 assist

void dropped_ids(int min, int max, int student_id[]);//func 4

void courses_students_more_n(int n,int course_code[],int student_exam[][5]);//func 7

void students_courses_less_n(int n,int student_exam[][5],int student_id[]);//func 8

void  list_hall_students(int course_date[][3],char course_hall[],int course_number[],int date[],char hall, int student_exam[][5], int student_id[]);//func 9

void  List_Hall_Students_InANyDay (char hall,char course_hall [MAX_COURSES],int student_id[MAX_STUDENTS],int student_exam[][5],int course_number[MAX_COURSES]);//func 10

void quit(void);//func 11

bool main_input1 = false; //  main_input1 is used to check if the user has inputted "Quit" so that the program can end
int main() {
    // Course data arrays
    int course_number[MAX_COURSES] = {0};
    int course_date[MAX_COURSES][3] = {{0}};
    char course_hall[MAX_COURSES] = {0};
    // Student data arrays
    int student_id[MAX_STUDENTS] = {0};
    int student_exam[MAX_STUDENTS][5] = {{0}};

    char main_input[MAX_NUM];//main input recieves user commands to call the required function
    start: // line 41 is used as a check-point where go to will return to
    main_input1 = false;
    fgets(main_input,100, stdin);//scan the user input then check which command gave by the user using strcmp defined in sring.h header file

    if (strcmp(main_input, "Courses exams:\n") == 0) {          // Course exams:
        Course_exams(course_number,course_date,course_hall);
    }
    else if (strcmp(main_input, "Students:\n") == 0) {         // Students:
        Students(student_id,student_exam);
    }
    else if (strcmp(main_input, "Number_Students\n") == 0) { // func 1
        if (number_students(student_id) == 0)
            printf("none\n");//if the user have not input any student id the program will print none
        else
            printf("%d\n",number_students(student_id));
    }
    else if (strcmp(main_input, "Number_Halls\n") == 0) {        //func 2
        if (number_halls(course_hall) == 0)
            printf("none\n");
        else
            printf("%d\n",number_halls(course_hall));
    }
    else if (strcmp(main_input, "Student_ID_Min\n") == 0) {      // func 3
        if(min_id(student_id) == 0)
            printf("none\n");
        else
            printf("%d\n",min_id(student_id));//
    }
    else if (strcmp(main_input, "Students_Dropped_IDs\n")== 0){  // func 4
        int minn=min_id(student_id);
        int maxx=max_id(student_id);
        // Get the max and min students IDs to assist the func algorithim
        dropped_ids(minn, maxx, student_id);
    }
    else if (strcmp(main_input, "Exams_Period_InDays\n") == 0){ // func 5
        function_of_date(course_date);
    }
    else if (strncmp(main_input,"Course_Students",15) == 0){     // func 6 the first 15 characters of the string are compared to the string "Course_Students"
        char code_conversion[3]; //array to store the course code
        code_conversion[0] = main_input[16];
        code_conversion[1] = main_input[17];
        code_conversion[2] = main_input[18];
        int exam_code = atoi(code_conversion); //convert the course code to int using atoi function deifned in stdlib.h header file.
        course_students(exam_code, student_exam, student_id);
    }
    else if (strncmp(main_input,"List_Course_Students_More",25) == 0){ // func 7
        // a pointer is made for the 26th character and the function atoi is used to convert the charachter variable into an integer.
        char *n_more_c = &main_input[26];
        int n_more = atoi(n_more_c);
        courses_students_more_n(n_more,course_number,student_exam);
    }
    else if (strncmp(main_input,"List_Student_Courses_Less",25) == 0){ // func 8
        char *n_less_c = &main_input[26];
        int n_less = atoi(n_less_c);
        students_courses_less_n(n_less,student_exam,student_id);
    }
    else if (strncmp(main_input,"List_Hall_Students",18) == 0 ){ // 9 & 10 the same first three words.
        if (strncmp(main_input,"List_Hall_Students_",19) == 0){
            //this if condition differentiate between function 10 and 9 by checking if the 19th character that the user input is "_"
            char HaLL = main_input[28];
            List_Hall_Students_InANyDay(HaLL,course_hall,student_id,student_exam,course_number);
        }
            // if there is no underscore the program will assume that the user is using function 9
        else{
            int Day,Month,Year;
            char Year_arr[4];
            if(main_input[23] == '/'){
                char *c = &main_input[22];
                Day = atoi(c);
                if(main_input[25] == '/'){
                    char *c = &main_input[24];
                    Month = atoi(c);
                    main_input[30] = '/';
                    c = &main_input[26];
                    Year = atoi(c);
                }
                else if(main_input[26] == '/'){
                    char *c = &main_input[24];
                    Month = atoi(c);
                    main_input[31] = '/';
                    c = &main_input[27];
                    Year = atoi(c);
                }
            }
            else if(main_input[24] == '/'){
                char *c = &main_input[22];
                Day = atoi(c);
                if(main_input[26] == '/'){
                    char *c = &main_input[25];
                    Month = atoi(c);
                    main_input[31] = '/';
                    c = &main_input[27];
                    Year = atoi(c);
                }
                else if(main_input[27] == '/'){
                    char *c = &main_input[25];
                    Month = atoi(c);
                    main_input[32] = '/';
                    c = &main_input[28];
                    Year = atoi(c);
                }
            }
            char HALL = main_input[19];
            int Date[3];
            Date[0] = Day;
            Date[1] = Month;
            Date[2] = Year;
            list_hall_students(course_date, course_hall, course_number, Date, HALL, student_exam, student_id);
        }
    }
    else if((strcmp(main_input, "Quit\n") == 0)){ // func 11
        quit();
    }

    if (main_input1) { // This if condition tests if main_input1 is true, if so it will go back line 41 where "start" is
        goto start;
    }
    return 0;}

// Courses input
/*
Users can input information about courses, including course numbers, exam dates, and halls.
function objective to store data of courses in arrays
return: none

*/
void Course_exams(int course_number[],int course_date[][3],char course_hall[]) {
    for (int i = 0; i < MAX_COURSES; i++) {
        if (scanf("%d", &course_number[i]) == 1) {
            scanf("%d/%d/%d", &course_date[i][0], &course_date[i][1], &course_date[i][2]);
            scanf(" %c", &course_hall[i]);
        } else {
            main_input1 = true;
            break;
        }
    }
}

// Students input
/*
Users can input student information, including student IDs and exam codes for up to five exams per student.
function objective to store data of students in arrays
return: none
*/
void Students(int student_id[],int student_exam[][5]) {
    int buffer;
    int x = 0, i = -1;
    while (true) {
        if ((scanf("%d", &buffer)) != EOF) {
            if (buffer > 99999) {
                x = 0;
                i++;
                student_id[i] = buffer;
            } else if (buffer < 1000) {
                student_exam[i][x] = buffer;
                x++;
            }
        } else {
            main_input1 = true;
            break;
        }
    }
}

// Number of students (1)
/*
Displays the total number of students recorded in the system.
paramater 1: students ID array
return: number of students
  */
int number_students(int student_id[]) {
    int n = 0;
    while (student_id[n] != 0) {
        n++;

    }
    main_input1 = true;
    return n;
}
// Number of halls (2)
/*
Displays the total number of unique halls used for exams.
paramater 1: course_hall array
return: number of unique halls
  */
int number_halls(char course_hall[]) {
    int n = 0, n_halls = 0;
    while (course_hall[n] != 0) {
        n++;
    }
    for (int i = 0; i < n; i++){
        bool duplicate = false;
        for (int j = 0; j < i; j++){
            if (course_hall[i] == course_hall[j] && i != j){
                duplicate = true;
            }
        }
        if (duplicate == false){
            n_halls++;
        }
    }
    main_input1 = true;

    return n_halls;
}

// Min student ID (3)
/*
Identifies and displays the minimum student ID in the system.
paramater 1: student ID array
return: minimum student ID
  */
int min_id(int student_id[]){
    int n = number_students(student_id);
    int min = student_id[0];
    for (int x = 0; x < n; x++) {
        if(min < student_id[x]){
            min = min;
        }
        else{
            min = student_id[x];
        }
    }
    main_input1 = true;
    return min;
}

// Dropped IDs (4) Done!
/*
Displays IDs that are missing from the sequential range of IDs.
paramater 1: minimum ID
paramater 2: maximum ID
paramater 3: student ID array
return: none
output: IDs that are missing from the sequential range of IDs
  */
void dropped_ids(int min, int max, int student_id[]){
    int i = 1;
    bool num_check = false;
    bool test=false;
    int value = min + 1;
    while (i <= (max - min) && value <= max) {
        num_check = false;
        for (int j = 0; j < MAX_STUDENTS; j++) {
            if (value == student_id[j]) {
                num_check = true;
                break;
            }
        }
        if (num_check == false) {
            printf("%d\n", value);
            test=true;
        }
        i++;
        value++;
    }
    if(test==false){
        printf("none \n");
    }
    main_input1 = true;
}


// Period in days (5) Done!
/*
Calculates and displays the period (in days) between the earliest and latest exam dates.
paramater 1: courses dates 2d array
return: none
output: period in days
  */
void function_of_date(int course_date[][3]){
    int i=0;
    int j=0;
    int daydiff=0;
    int monthdiff=0 ;
    int yeardiff=0;
    int totaldaydiff=0;
    int tempdate=0;
    for( i=0;i<20;i++){
        for(int k=0;k<21;k++){
            if(course_date[i][j]!=0){
                daydiff=(course_date[k][j]-course_date[i][j]);
                int month1=course_date[i][j+1] ;
                int month2=course_date[k][j+1] ;
                monthdiff=month_funct(&month2 , &month1);
                yeardiff=((course_date[k][j+2]-course_date[i][j+2]))*365 +(((course_date[k][j+2])/4)-((course_date[i][j+2])/4));
                totaldaydiff=daydiff+monthdiff+yeardiff;
                if(tempdate<totaldaydiff){
                    tempdate=totaldaydiff+1;
                }
            }
        }
    }
    if(tempdate == 0 && course_date[0][0] == 0){
        printf("none\n");
    }
    else{
        printf("%d\n",tempdate);
    }
    main_input1 = true;

}

//Months
/*
Finds the length of the months needed in the calculation for function 5.
Parameter 1: month of the latest date
Parameter 2: month of the earliest date
return: number of days between the two months
*/
int month_funct(int *month2 ,int *month1){
    int monthlength[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int monthday2=0;
    int monthday1=0;
    for(int i=0;i<(*month2);i++){
        monthday2+=monthlength[i];
    }
    for(int i=0;i<(*month1);i++){
        monthday1+=monthlength[i];
    }
    return (monthday2-monthday1);
}

// Course students (6)
/*
Displays the IDs of students enrolled in a specific course based on the provided course code.
paramater 1: entered course code
paramater 2: student's enrolled courses
paramater 3: student's IDs
return: none
output: IDs of students enrolled in a specific course based on the provided course code
  */
void course_students(int exam_code, int student_exam[][5], int student_id[]) {
    bool test=false;
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 5; j++) {
            if (exam_code == student_exam[i][j]) {
                printf("%d\n",student_id[i]);
                test=true;
            }
        }
    }
    if(test == false){
        printf("none\n");
    }
    main_input1 = true;
}


// List courses with more than n (7)
/*
Displays course numbers with more than n students enrolled.
paramater 1: min number of students enrolled in a course
paramater 2: courses codes
paramater 3: student's enrolled courses
return: none
output: course code with more than n students enrolled.
  */
void courses_students_more_n(int n,int course_number[MAX_STUDENTS],int student_exam[MAX_STUDENTS][5]){
    bool test=false;
    for (int i = 0; i < 20; i++){
        int num = 0;
        if (course_number [i] > 0){
            num = 0;
            for (int j = 0; j < 50; j++){
                for (int k = 0; k < 5; k++){
                    if (course_number[i] == student_exam[j][k]) {
                        num++;
                    }
                }
            }
            if (num > n){
                printf("%d\n",course_number[i]);
                test=true;
            }
        }
    }
    if(test == false){
        printf("none\n");
    }
    main_input1=true;
}

// List students have courses less than n (8)
/*
Displays the IDs of students with fewer than n enrolled courses.
paramater 1: max number of courses enrolled in a student
paramater 2: student's enrolled courses
paramater 3: student's IDs
retrun: none
outpur: IDs of students with fewer than n enrolled courses.
  */
void students_courses_less_n(int n,int student_exam[MAX_STUDENTS][5],int student_id[MAX_STUDENTS]){
    bool test=false;
    for (int i = 0 ; i < 50; i++){
        int num = 0;
        for (int k = 0; k < 5; k++){
            if (student_exam[i][k]>0) {
                num++;
            }
        }
        if (num < n){
            if(student_id[i] > 0){
                printf("%d\n", student_id[i]);
                test=true;
            }
        }
    }
    if(test == false){
        printf("none\n");
    }
    main_input1 = true;
}

// Max student ID
/*
 Identifies the max student ID in the system to assist func of dropped ids.
 paramater 1: student's IDs
 returm: max student ID
   */
int max_id(int student_id[]){
    int n = number_students(student_id);
    int max = student_id[0];
    for (int x = 0; x < n; x++) {
        if(max > student_id[x]){
            max = max;
        }
        else{
            max = student_id[x];
        }
    }
    return max;
}


//function 9
/*
Displays unique student IDs taking exams in a specific hall across all recorded dates.
 paramater 1: the given date
 paramater 2: the given hall
 paramater 3: courses codes
 paramater 4: courses dates
 paramater 5: courses halls
 paramater 6: student's enrolled courses
 paramater 7: student's IDs
 return: none
 output: unique student IDs taking exams in a specific hall across all recorded dates.
   */
void list_hall_students(int course_date[][3],char course_hall[],int course_number[],int date[],char hall, int student_exam[][5], int student_id[]){
    int temp_value=0;
    bool test=false;
    for(int i=0;i<20 ;i++){
        int num=0 ;
        if(date[0] == (course_date[i][0]) && hall==course_hall[i])
            num++ ;
        if(date[1] == (course_date[i][1]) && hall==course_hall[i])
            num++ ;
        if(date[2]== (course_date[i][2]) && hall==course_hall[i])
            num++ ;
        if(num==3){
            temp_value=course_number[i];
            for (int k = 0; k < 50; k++) {
                for (int j = 0; j < 5; j++) {
                    if (temp_value == student_exam[k][j]) {
                        printf("%d\n",student_id[k]);
                        test=true;
                    }
                }
            }
        }
    }
    if(test == false){
        printf("none\n");
    }
    main_input1 = true;
}

//function 10
/*
Displays unique student IDs taking exams in a specific hall across all recorded dates.
 paramater 1: the given hall
 paramater 2: courses halls
 paramater 3: student's IDs
 paramater 4: student's enrolled courses
 paramater 5: courses codes
 return: none
 ouptut: unique student IDs taking exams in a specific hall across all recorded dates.
   */
void List_Hall_Students_InANyDay(char hall,char course_hall [20],int student_id[50],int student_exam[][5],int course_number[20]){
    bool test=false;
    int arr[1000];
    int arr_index=0;
    for (int k=0;k<20;k++) {
        if (hall == course_hall[k]) {
            for (int i = 0; i < 50; i++) {
                for (int j = 0; j < 5; j++) {
                    if (course_number[k] == student_exam[i][j]) {
                        arr[arr_index] = student_id[i];
                        arr_index++;
                    }
                }
            }
        }
    }
    int n = 0;
    while (arr[n] != 0) {
        n++;
    }
    for (int i = 0; i < n; i++){
        bool duplicate = false;
        for (int j = 0; j < i; j++){
            if (arr[i] == arr[j] && i != j){
                duplicate = true;
            }
        }
        if (duplicate == false){
            printf("%d\n",arr[i]);
            test=true;
        }
    }
    if(test==false){
        printf("none \n");
    }
    main_input1 = true;
}
// Quit (11)
// Displays a goodbye message and exits the program.
void quit(void){
    printf("Thanks!");
    main_input1 = false;
}
