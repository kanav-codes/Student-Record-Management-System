#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define n 100
struct student {
    int r_no;
    char s_name[100];
    char course[100];
    int semester;
    float marks;
};
void saveToFile(struct student s[], int total);
void loadFromFile(struct student s[], int *total);

void addstudent(struct student s[n],int *total) {
    int n_add,i;
    printf("How many students to add? ");
    scanf("%d", &n_add);
    if (*total + n_add > n) {
    printf("Limit exceeded!\n");
    return;
}
else{
    for (i = 0; i < n_add; i++) {
        int in = *total + i;
        printf("Enter the details of student %d\n", i + 1);
        
        printf("Enter the roll number of student: ");
        scanf("%d", &s[in].r_no);
        getchar(); // consume leftover newline

        printf("Enter the student name: ");
        fgets(s[in].s_name, sizeof(s[in].s_name), stdin);
        s[in].s_name[strcspn(s[in].s_name, "\n")] = '\0';

        printf("Enter the course name of the student: ");
        fgets(s[in].course, sizeof(s[in].course), stdin);
        s[in].course[strcspn(s[in].course, "\n")] = '\0';

        printf("Enter the semester of the student: ");
        scanf("%d", &s[in].semester);

        printf("Enter the marks of the student: ");
        scanf("%f", &s[in].marks);

        printf("\n");}
         *total += n_add;
         saveToFile(s, *total);
        // blank line for readability
    
}}
void displayall(struct student s[n],int *total) {
    int i;
    if (*total == 0) {
    printf("No records available.\n");
    return;
}

    for(i = 0; i < *total; i++) {
        printf("displaying the details of student %d\n", i + 1);
        printf("the roll number of the student is %d\n",s[i].r_no);
        printf("the student name is %s\n",s[i].s_name);
        printf("the name of the course the student is pursuing is %s\n",s[i].course);
        printf("the semester of the student is %d\n",s[i].semester);
        printf("the marks of the student is %f\n",s[i].marks);}}
int searchstudent(struct student s[n],int r_no,int *total){
    int i;
    int found=0;
    if (*total == 0) {
    printf("No records available.\n");
    return 0;
}
else{
      for (i=0;i<*total;i++){
        if (s[i].r_no==r_no){
            printf("Roll Number: %d\n", s[i].r_no);
printf("Name: %s\n", s[i].s_name);
printf("Course: %s\n", s[i].course);
printf("Semester: %d\n", s[i].semester);
printf("Marks: %.2f\n", s[i].marks);

            found =1;
            break;
        }
      }
      return found;
}}
int updatestudent(struct student s[n],int r,int *total){
    int i,found =0;
    if (*total == 0) {
    printf("No records available.\n");
    return 0;
}
else{
    for(i=0;i<*total;i++){
        if (s[i].r_no==r){
            int rn,sem;
            float mark;
            char nam[100];
            char cor[100];
        printf("enter the roll number of student with which has to be modified");
    scanf("%d",&rn);
    printf("enter the semester witch which to be modified");
    scanf("%d",&sem);
    printf("enter the marks of student with which to be modified");
    scanf("%f",&mark);
    getchar();
    printf("enter the name of student with which to be modified");
    fgets(nam,sizeof(nam), stdin);
        nam[strcspn(nam, "\n")] = '\0';
        printf("enter the course of student with which to be modified");
        fgets(cor, sizeof(cor), stdin);
        cor[strcspn(cor, "\n")] = '\0';
        s[i].r_no=rn;
       strcpy(s[i].s_name, nam);
strcpy(s[i].course, cor);

        s[i].semester=sem;
        s[i].marks=mark;
        found=1;
        break;
        }
    }
    if (found) {
    saveToFile(s, *total);
}

    return found;
   
}}

int deletestudent(struct student s[n],int rno,int *total){
int i,found=0;
if (*total == 0) {
    printf("No records available.\n");
    return 0;
}
else{
for (i=0;i<*total;i++){
    if(s[i].r_no==rno){
     for(int j = i; j <*total - 1; j++) {
                s[j] = s[j + 1];
            }
            (*total)--; // reduce total count
            printf("Student deleted successfully.\n");
            found =1;
            break;
        }
        

    }
if(found ==0){
            printf("the record not found\n");
        }}
        if (found) {
    saveToFile(s, *total);
}
return found;
}
void saveToFile(struct student s[], int total) {
    FILE *fp = fopen("students.dat", "wb");
    if (fp == NULL) {
        printf("Error opening file for writing\n");
        return;
    }

    fwrite(&total, sizeof(int), 1, fp);
    fwrite(s, sizeof(struct student), total, fp);

    fclose(fp);
}
void loadFromFile(struct student s[], int *total) {
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        *total = 0;   // first run, no file yet
        return;
    }

    fread(total, sizeof(int), 1, fp);
    fread(s, sizeof(struct student), *total, fp);

    fclose(fp);
}


int main(){
    struct student s[n];
    int p=0;
    int *total = &p;
    char ch='Y';
     loadFromFile(s,total) ;
    do {
        int choice;
        printf("enter the choice(1-6)");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                addstudent(s,total);
                break;}
            case 2:{
            displayall(s,total);
            break;}
            case 3:{
            int k;
            int r_no;
             printf("enter the roll number to be searched");
    scanf("%d",&r_no);
            k=searchstudent(s,r_no,total);
            if(k==1){
                printf("the record is found\n");}
                else{
                    printf("the record not found\n");
                }
            break;}
            case 4:{
             int t;
             int r;
             printf("enter the roll number  of the student whose records has to be modified");
    scanf("%d",&r);
             t=updatestudent(s,r,total);
             if(t==1){
                printf("the record is updated\n");}
                else{
                    printf("the record not updated\n");
                }
            break;}
            case 5:{
            int rno;
            int l;
            printf("enter the rolll number acc to which record has to be deleted");
    scanf("%d",&rno);
            l=deletestudent(s,rno,total);
            if(l==1){
                printf("the record is deleted\n");}
                else{
                    printf("the record not deleted\n");
                }
            break;}
            case 6:{
            printf("Exiting...\n");
            exit(0);
            break;}
            default:{
                printf("Invalid choice!\n");}


            };
           printf("Do you want to continue (Y/N): ");

            getchar();
            scanf("%c",&ch);
        }
        while(ch=='Y');
        return 0;
    }
    

