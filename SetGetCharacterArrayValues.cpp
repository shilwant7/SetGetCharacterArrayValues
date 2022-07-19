#include<iostream>
#include <string.h>
using namespace std;

char name[10]="Nitin";
int score=10;
double average=7.5;

void set_packet(char *arr)
{
    //filling values in string
    strncpy(arr, name, strlen(name));//char array
    arr+=strlen(name);
    *(int *) arr = score;//int
    arr += sizeof (int);
    *(double *) arr = average;//double
}

void get_packet(char *arr)
{
    //retrieving values from string
    char stud_name[10];
    int stud_score;
    double stud_average;
    strncpy(stud_name,arr,strlen(name));//name copied
    stud_name[strlen(name)] = '\0';
    arr+=strlen(name);
    stud_score = *(int *)arr;//int score copied
    arr += sizeof (int);
    stud_average = *(double *) arr;//double average copied
    cout<<"Name    : "<<stud_name<<endl;
    cout<<"Score   : "<<stud_score<<endl;
    cout<<"Average : "<<stud_average<<endl;
}

int main()
{
    char arr[100];
    set_packet(arr);//to fill buffer
    get_packet(arr);//to retrieve buffer
    return 0;
}

/* OUTPUT :
             Name    : Nitin
             Score   : 10
             Average : 7.5

             */
