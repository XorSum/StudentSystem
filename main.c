#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30

typedef struct
{
    long long ID;
    char name[17];
    double score[6];
    double totalscore;
} Student;

int menu()
{
    printf("1. Input record\n");
    printf("2. Calculate total and average score of every course\n");
    printf("3. Calculate total and average score of every student\n");
    printf("4. Sort in descending order by total score of every student\n");
    printf("5. Sort in ascending order by total score of every student\n");
    printf("6. Sort in ascending order by ID\n");
    printf("7. Sort in dictionary order by name\n");
    printf("8. Search by ID\n");
    printf("9. Search by name\n");
    printf("10. Statistic analysis for every course\n");
    printf("11. List record\n");
    printf("12. Write to a file\n");
    printf("13. Read from a file\n");
    printf("0.Exit\n");
    printf("Please enter your choice\n");
    return 0;
}
long long  readnum(long long low,long long high)
{
    long long ID;
    char str[30];
    while(1)
    {
        printf(">_<:");
        scanf("%s",str);
        int flag=1,i;
        for (i=0;i<30&&str[i]!='\0';i++)
            if (str[i]>'9'||str[i]<'0')
            {
                flag=0;
                break;
            }
        if (flag==0)
            printf("error,please input again\n");
        else
        {
            sscanf(str,"%lld",&ID);
            if (ID>high||ID<low)
                printf("error,please input again\n");
            else break;
        }
    }
    return ID;
}
int fun_0(Student soft4[],int*StuSum,int *CorSum,char coursename[][17])
{
    exit(0);
}
int fun_1(Student soft4[],int*StuSum,int *CorSum,char coursename[][17])
{
    // Input record
    int i,j;
    printf("Please input the sum of course\n");
    *CorSum=(int)readnum(1,6);
    for (i=0; i<*CorSum; i++)
    {
        printf("Please input the NO.%d course's name\n",i+1);
        printf(">_<:");
        scanf("%s",coursename[i]);
    }
    printf("Please input the sum of student\n");
    *StuSum=(int)readnum(1,30);
    for (i=0; i<*StuSum; i++)
    {
        printf("Please input the NO.%d student's name\n",i+1);
        printf(">_<:");
        scanf("%s",soft4[i].name);
        printf("Please input the %s's ID\n",soft4[i].name);
        soft4[i].ID=readnum(1,10000000000);
        for (j=0; j<*CorSum; j++)
        {
            printf("Please input %s's score of %s\n",soft4[i].name,coursename[j]);
            printf(">_<:");
            scanf("%lf",&soft4[i].score[j]);
        }
    }
    for (i=0; i<*StuSum; i++)
        soft4[i].totalscore=0;
    for (i=0; i<*StuSum; i++)
        for (j=0; j<*CorSum; j++)
            soft4[i].totalscore+=soft4[i].score[j];
    for (j=0; j<*CorSum; j++)
        soft4[N].score[j]=0;
    for (i=0; i<*StuSum; i++)
        for (j=0; j<*CorSum; j++)
            soft4[N].score[j]+=soft4[i].score[j];
    soft4[N].totalscore=0;
    for (i=0; i<*StuSum; i++)
        soft4[N].totalscore+=soft4[i].totalscore;
    printf("Completed\n\n");
    return 0;
}
int fun_2(Student soft4[],int*StuSum,int *CorSum,char coursename[][17])
{
    //Calculate total and average score of every course
    int j;
    printf("course name     total score         average score\n");
    printf("-------------------------------------------------\n");
    for (j=0; j<*CorSum; j++)
        printf("%-16s%-20.2lf%-20.2lf\n",coursename[j],soft4[N].score[j],soft4[N].score[j]/(*StuSum));
    return 0;
}
int fun_3(Student soft4[],int*StuSum,int *CorSum,char coursename[][17])
{
    //Calculate total and average score of every student
    int i;
    printf("student name    total score         average score\n");
    printf("-------------------------------------------------\n");
    for (i=0; i<*StuSum; i++)
        printf("%-16s%-20.2lf%-20.2lf\n",soft4[i].name,soft4[i].totalscore,soft4[i].totalscore/(*CorSum));
    return 0;
}
int cmp_totalscore(const void*a,const void*b)
{
    return ((Student*)a)->totalscore-((Student*)b)->totalscore;
}
int fun_4(Student soft4[],int*StuSum,int *CorSum,char coursename[][17])
{
    //Sort in descending order by total score of every student
    int i;
    qsort(soft4,*StuSum,sizeof(Student),cmp_totalscore);
    printf("student name    total score         ID       \n");
    printf("---------------------------------------------\n");
    for (i=*StuSum-1; i>=0; i--)
        printf("%-16s%-20.2lf%-20lld\n",soft4[i].name,soft4[i].totalscore,soft4[i].ID);
    return 0;
}
int fun_5(Student soft4[],int*StuSum,int *CorSum,char coursename[][17])
{
    //Sort in ascending order by total score of every student
    int i;
    qsort(soft4,*StuSum,sizeof(Student),cmp_totalscore);
    printf("student name    total score         ID       \n");
    printf("---------------------------------------------\n");
    for (i=0; i<*StuSum; i++)
        printf("%-16s%-20.2lf%-20lld\n",soft4[i].name,soft4[i].totalscore,soft4[i].ID);
    return 0;
}
int cmp_ID(const void*a,const void*b)
{
    return ((Student*)a)->ID-((Student*)b)->ID;
}
int fun_6(Student soft4[],int*StuSum,int *CorSum,char coursename[][17])
{
    //Sort in ascending order by ID
    int i;
    qsort(soft4,*StuSum,sizeof(Student),cmp_ID);
    printf("ID              name           total score\n");
    printf("------------------------------------------\n");
    for (i=0; i<*StuSum; i++)
        printf("%-16lld%-16s%-6.2lf\n",soft4[i].ID,soft4[i].name,soft4[i].totalscore);
    return 0;
}
int cmp_name(const void*a,const void*b)
{
    return strcmp(((Student*)a)->name,((Student*)b)->name);
}
int fun_7(Student soft4[],int*StuSum,int *CorSum,char coursename[][17])
{
    //Sort in dictionary order by name
    int i;
    qsort(soft4,*StuSum,sizeof(Student),cmp_name);
    printf("name            ID           total score\n");
    printf("----------------------------------------\n");
    for (i=0; i<*StuSum; i++)
        printf("%-16s%-13lld%-6.2lf\n",soft4[i].name,soft4[i].ID,soft4[i].totalscore);
    return 0;
}
int fun_8(Student soft4[],int*StuSum,int *CorSum,char coursename[][17])
{
    //Search by ID
    int i,j,flag=0;
    long long tmpID;
    printf("please input the ID\n");
    tmpID=readnum(1,10000000000);
    qsort(soft4,*StuSum,sizeof(Student),cmp_totalscore);
    for (i=0; i<*StuSum; i++)
        if(soft4[i].ID==tmpID)
        {
            flag=1;
            break;
        }
    if (flag==0)
        printf("no student have the ID of %lld\n",tmpID);
    else
    {
        printf("name:     %s\n",soft4[i].name);
        printf("rank:     %d\n",i+1);
        printf("course           score\n");
        printf("-----------------------\n");
        printf("total           %-4.2lf\n",soft4[i].totalscore);
        for (j=0;j<*CorSum;j++)
            printf("%-16s%-4.2lf\n",coursename[j],soft4[i].score[j]);
    }
    return 0;
}
int fun_9(Student soft4[],int*StuSum,int *CorSum,char coursename[][17])
{
    // Search by name
    int i,j,flag=0;
    char name[17];
    printf("please input the name\n>_<:");
    scanf("%s",name);
    qsort(soft4,*StuSum,sizeof(Student),cmp_totalscore);
    for (i=0; i<*StuSum; i++)
        if(strcmp(soft4[i].name,name)==0)
        {
            flag=1;
            break;
        }
    if (flag==0)
        printf("%s is not in this class\n",name);
    else
    {
        printf("ID:       %lld\n",soft4[i].ID);
        printf("rank:     %d\n",i+1);
        printf("course           score\n");
        printf("-----------------------\n");
        printf("total           %-4.2lf\n",soft4[i].totalscore);
        for (j=0;j<*CorSum;j++)
            printf("%-16s%-5.2lf\n",coursename[j],soft4[i].score[j]);
    }
    return 0;
}
int fun_10(Student soft4[],int*StuSum,int *CorSum,char coursename[][17])
{
    //Statistic analysis for every course
    int yx,lh,zd,jg,bjg,i,j;
    printf("course name          yx       lh       zd       jg       bjg\n");
    printf("------------------------------------------------------------\n");
    for (j=0;j<*CorSum;j++)
    {
        printf("%-16s",coursename[j]);
        yx=lh=zd=jg=bjg=0;
        for (i=0;i<*StuSum;i++)
        {
            if (soft4[i].score[j]>=90)
                yx++;
            else if (soft4[i].score[j]>=80&&soft4[i].score[j]<89)
                lh++;
            else if (soft4[i].score[j]>=70&&soft4[i].score[j]<79)
                zd++;
            else if (soft4[i].score[j]>=60&&soft4[i].score[j]<69)
                jg++;
            else if (soft4[i].score[j]<60)
                bjg++;
        }
        printf(" %2d %5.2lf ",yx,(double)yx/(*StuSum)*100);
        printf("%2d %5.2lf ",lh,(double)lh/(*StuSum)*100);
        printf("%2d %5.2lf ",zd,(double)zd/(*StuSum)*100);
        printf("%2d %5.2lf ",jg,(double)jg/(*StuSum)*100);
        printf("%2d %5.2lf ",bjg,(double)bjg/(*StuSum)*100);
        printf("\n");
    }
    return 0;
}
int fun_11(Student soft4[],int*StuSum,int *CorSum,char coursename[][17])
{
    //List record
    int i,j;
    for (j=0; j<*CorSum; j++)
        soft4[N].score[j]=0;
    printf("                 ");
    for (j=0;j<*CorSum;j++)
        printf("%-16s",coursename[j]);
    printf("\n");
    for (i=0;i<*StuSum;i++)
    {
        printf("%-16s ",soft4[i].name);
        for (j=0;j<*CorSum;j++)
        {
            printf("%-16.2lf",soft4[i].score[j]);
            soft4[N].score[j]+=soft4[i].score[j];
        }
        printf("\n");
    }
    return 0;
}
int fun_12(Student soft4[],int*StuSum,int *CorSum,char coursename[][17])
{
    // Write to a file
    FILE*fp=fopen("data.txt","w");
    if (fp==NULL)
    {
        printf("file can't open\n");
        return 1;
    }
    int i,j;
    fprintf(fp,"course sum :%d\n",*CorSum);
    fprintf(fp,"student sum :%d\n",*StuSum);
    for (j=0; j<*CorSum; j++)
        fprintf(fp,"%s\n",coursename[j]);
    for (i=0; i<*StuSum; i++)
    {
        fprintf(fp,"%s %lld",soft4[i].name,soft4[i].ID);
        fprintf(fp," %lf",soft4[i].totalscore);
        for (j=0; j<*CorSum; j++)
            fprintf(fp," %lf",soft4[i].score[j]);
        fprintf(fp,"\n");
    }
    fprintf(fp,"total :");
    fprintf(fp," %lf",soft4[N].totalscore);
    for (j=0; j<*CorSum; j++)
        fprintf(fp," %lf",soft4[N].score[j]);
    fprintf(fp,"\n");
    fclose(fp);
    printf("successful\n");
    return 0;
}
int fun_13(Student soft4[],int*StuSum,int *CorSum,char coursename[][17])
{
    //Read from a file
    FILE*fp=fopen("data.txt","r");
    if (fp==NULL)
    {
        printf("file can't open\n");
        return 1;
    }
    int i,j;
    fscanf(fp,"course sum :%d\n",CorSum);
    fscanf(fp,"student sum :%d\n",StuSum);
    for (j=0; j<*CorSum; j++)
        fscanf(fp,"%s\n",coursename[j]);
    for (i=0; i<*StuSum; i++)
    {
        fscanf(fp,"%s %lld",soft4[i].name,&soft4[i].ID);
        fscanf(fp,"%lf",&soft4[i].totalscore);
        for (j=0; j<*CorSum; j++)
            fscanf(fp,"%lf",&soft4[i].score[j]);
        fscanf(fp,"\n");
    }
    fscanf(fp,"total :");
    fscanf(fp,"%lf",&soft4[i].totalscore);
    for (j=0; j<*CorSum; j++)
        fscanf(fp,"%lf",&soft4[N].score[j]);
    fclose(fp);
    printf("name           ID       total score     ");
    for (j=0; j<*CorSum; j++)
        printf("%-16s",coursename[j]);
    printf("\n");
    printf("--------------------------------------------------------\
--------------------------------------------------------\n");
    for (i=0; i<*StuSum; i++)
    {
        printf("%-16s%-8lld",soft4[i].name,soft4[i].ID);
        printf("%-16.2lf",soft4[i].totalscore);
        for (j=0; j<*CorSum; j++)
            printf("%-16.2lf",soft4[i].score[j]);
        printf("\n");
    }
    return 0;
}
int main()
{
    int cmd=0,CorSum=0,StuSum=0;
    Student soft4[N+1];
    char coursename[6][17];
    int (*p[14])(Student*,int*,int*,char[][17])={fun_0,fun_1,fun_2,fun_3,\
fun_4,fun_5,fun_6,fun_7,fun_8,fun_9,fun_10,fun_11,fun_12,fun_13};
    menu();
    while(1)
    {
        cmd=(int)readnum(0,13);
        (p[cmd])(soft4,&StuSum,&CorSum,coursename);
    }
    return 0;
}
