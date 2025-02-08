#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void clrscr(void)
{
    system("cls()");
}
void emp(void);
void menu(void);
void pat(void);
void inv(void);
struct address
{
    int hno;
    char street[40];
    char city[40];
    char state[40];
};
struct patient
{
    char name[40];
    char fname[40];
    int age;
    char bg[3];
    char gender;
    char regn[10];
    struct address a;
    char ph[10];
    char disease[60];
    char doc_name[40];
    char history[200];
    char date[10];
    char treatment[40];
    char med[40];
};

struct inventory
{
    int sno;
    char name[30];
    char dop[20];
    int qnty;
    float price;
    float amount;
};//check
void menu()
{
    char choice;
    printf("\t\t*******");
    printf("\n\t\t  * WELCOME TO HOSPITAL MANAGEMENT SYSTEM *");
    printf("\n\t\t*******");
    printf("\n\n\n\n\n\n\n");
    printf("\t\t1.PATIENT");
    printf("\n\t\t2.INVENTORY");
    printf("\n\t\t0.EXIT");
    printf("\n\n\tEnter your choice: ");
    fflush(stdin);
    choice=getche();
    switch(choice)
        {
            case '1':
                pat();
                break;
               case '2':
                inv();
                break;
            case '0':
                exit(1);
        }
}//check
int main()
{
    menu();
}
void pat()
{
    FILE *fp,*ft;
    char ch,another,z;
    char reg[20],pname[40];
    int i=0;
    long int recsize;
    struct patient p;
    fp=fopen("pat.txt","rb+");
    if(fp==NULL)
        {
            fp=fopen("pat.txt","wb+");
            if(fp==NULL)
                {
                    puts("\nSorry!! Cannot open file");
                    exit(1);
                }
        }
    recsize=sizeof(p);
    while(1)
        {
            clrscr();
            printf("\n\n\t\t\tPATIENT");
            printf("\n\t\t1.Enter a New Entry");
            printf("\n\t\t2.Search an Entry");
            printf("\n\t\t3.Listing of records");
            printf("\n\t\t4.Main Menu");
            printf("\n\n\t\tEnter your choice here: ");
            fflush(stdin);
            ch=getche();
            switch(ch)
                {
                    case '1':
                    clrscr();
                    
                    another='Y';
                    while(another=='Y'||another=='y')
                        {
                            w:
                            printf("\n\n\nEnter Registration Number: ");
                            scanf("%s",reg);
                            rewind(fp);
                            while(fread(&p,recsize,1,fp)==1)
                                {
                                    if(strcmp(p.regn,reg)==0)
                                        {
                                            i=1;
                                            printf("\n\t\tTHIS REGISTRATION NUMBER ALREADY EXISTS. ENTER ANOTHER ONE");
                                            goto w;
                                        }
                                }
                            if(i==0||fread(&p,recsize,1,fp)==0)
                                {
                                    fflush(stdin);
                                    printf("\nEnter the name of the patient: ");
                                    gets(p.name);
                                    printf("\nEnter the name of the Guardian: ");
                                    gets(p.fname);
                                    printf("\nEnter the gender of the patient(M.male or F.female): ");
                                    scanf("%c",&p.gender);
                                    fflush(stdin);
                                    printf("\nEnter the Blood group of the patient: ");
                                    scanf("%s",p.bg);
                                    fflush(stdin);
                                    printf("\nEnter the age of the patient: ");
                                    scanf("%d",&p.age);
                                    printf("\nEnter the address of the patient:\n");
                                    printf("\n\tEnter the house number: ");
                                    scanf("%d",&p.a.hno);
                                    fflush(stdin);
                                    printf("\n\tEnter the street/colony: ");
                                    scanf("%s",p.a.street);
                                    printf("\n\tEnter the city: ");
                                    scanf("%s",p.a.city);
                                    printf("\n\tEnter the state: ");
                                    scanf("%s",p.a.state);
                                    printf("\nEnter the phone number of the patient: ");
                                    scanf("%s",p.ph);
                                    fflush(stdin);
                                    printf("\nEnter the Disease or problem for which he/she wants treatment: ");
                                    gets(p.disease);
                                    printf("\nEnter the name of the Doctor to which he/she being referred: ");
                                    gets(p.doc_name);
                                    printf("\nEnter the history, if any, related to treatment of the patient(If yes then write 'Y' if NO then write 'N'): ");
                                    scanf("%c",&z);
                                    if(z=='N'||z=='n')
                                        {
                                            goto out;
                                        }
                                    else
                                        {
                                            fflush(stdin);
                                            printf("\nHistory:");
                                            gets(p.history);
                                            fflush(stdin);
                                            printf("\nEnter the date of treatment:");
                                            scanf("%s",p.date);
                                            printf("\nTreatment Given:");
                                            scanf("%s",p.treatment);
                                            printf("\nMedicine Prescribed:");
                                            scanf("%s",p.med);
                                        }
                                    
									fwrite(&p,recsize,1,fp);                                                                               out: printf("\n----------------------------------------------------");
                                    printf("\nWant to add entry of the another Patient(Y/N): ");
                                    fflush(stdin);
                                    another=getche();
                                    }
                                }
                            break;
                            case '2':
                                clrscr();
                                another='Y';
                                while(another=='Y'||another=='y')
                                    {
                                        printf("\nEnter name to search: ");
                                        gets(pname);
                                        rewind(fp);
                                        while(fread(&p,recsize,1,fp)==1)
                                            {
                                                if(strcmp(p.name,pname)==0)
                                                    {
                                                        printf("\nRegistration Number of the Patient : ");
                                                        puts(p.regn);
                                                        printf("\nName of the Patient : ");
                                                        puts(p.name);
                                                        printf("\nName of the Guardian : ");
                                                        puts(p.fname);
                                                        printf("\nAge : %d",p.age);
                                                        printf("\nGender : %c",p.gender);
                                                        printf("\nBlood group: %s",p.bg);
                                                        printf("\nAddress  : %d,%s,%s,%s",p.a.hno,p.a.street,p.a.city,p.a.state);
                                                        printf("\nphone number : +91-%s",p.ph);
                                                        printf("\nDisease : %s",p.disease);
                                                        printf("\nEarlier History : ");
                                                        puts(p.history);
                                                        printf("\nDetails of treatment given and medicine prescribed:");
                                                        printf("\nDATE\t\tTREATMENT GIVEN\t\tMEDICINE PRESCRIBED\n");
                                                        printf("%s\t\t %s\t\t %s\n",p.date,p.treatment,p.med);
                                                        printf("\nName of the Doctor : ");
                                                        puts(p.doc_name);
                                                    }
                                                }//check
                                            printf("\n----------------------------------------------------");
                                            printf("\nSearch another Entry(Y/N): ");
                                            fflush(stdin);
                                            another=getche();
                                        }
                                    break;
                                case '3':
                                    clrscr();
                                    rewind(fp);
                                    while(fread(&p,recsize,1,fp)==1)
                                        {
                                            printf("\nRegistration Number of the Patient : ");
                                            puts(p.regn);
                                            printf("\nName of the Patient : ");
                                            puts(p.name);
                                            printf("\nName of the Guardian : ");
                                            puts(p.fname);
                                            printf("\nAge : %d",p.age);
                                            printf("\nGender : %c",p.gender);
                                            printf("\nBlood group: %s",p.bg);
                                            printf("\nAddress  : %d,%s,%s,%s",p.a.hno,p.a.street,p.a.city,p.a.state);
                                            printf("\nphone number : +91-%s",p.ph);
                                            printf("\nDisease : %s",p.disease);
                                            printf("\nEarlier History : ");
                                            puts(p.history);
                                            printf("\nDetails of treatment given and medicine prescribed:");
                                            printf("\nDATE\t\t TREATMENT GIVEN\t\t\t MEDICINE PRESCRIBED\n");
                                            printf("%s\t\t %s\t\t\t %s\n",p.date,p.treatment,p.med);
                                            printf("\nName of the Doctor : ");
                                            puts(p.doc_name);
                                            printf("\n----------------------------------------------------\n");
                                        }
                                    getch();
                                break;

                            case '4':
                                {
                                    fclose(fp);
                                    clrscr();
                                    menu();
                                }
                            break;
                  }
                }
}//check

void inv()
{
    FILE *fi,*fy;
    char a,m;
    char i_name[40];
    int iF=0,j=1;
    long int recsize2;
    struct inventory v;
    fi=fopen("inv.txt","rb+");
    if(fi==NULL)
        {
            fi=fopen("inv.txt","wb+");
            if(fi==NULL)
                {
                    puts("\nSorry!! Cannot open file");
                    exit(1);
                }
        }
    recsize2=sizeof(v);
    while(1)
        {
            clrscr();
            printf("\n\t\t\tINVENTORY");
            printf("\n\t\t1.Add an Entry for Item");
            printf("\n\t\t2.Search an Entry");
            printf("\n\t\t3.Listing of all Entries");
            printf("\n\t\t4.Main Menu");
            printf("\n\n\t\tEnter your choice here: ");
            fflush(stdin);
            m=getche();
            switch(m)
                {
                    case '1':
                    clrscr();
                    
                    a='Y';
                    while(a=='Y'||a=='y')
                        {
                            x:
                            printf("\n\n\nEnter the Name of the Item: ");
                            scanf("%s",i_name);
                            rewind(fi);
                            while(fread(&v,recsize2,1,fi)==1)
                                {
                                    if(strcmp(v.name,i_name)==0)
                                        {
                                            iF=1;
                                            printf("\n\t\tTHIS ITEM ALREADY EXISTS. ENTER ANOTHER ONE");
                                            goto x;
                                        }
                                }
                            if(iF==0||fread(&v,recsize2,1,fi)==0)
                                {
                                    fflush(stdin);
                                    printf("\nEnter the Date of purchase: ");
                                    scanf("%s",v.dop);
                                    fflush(stdin);
                                    printf("\nEnter the Quantity of the Item: ");
                                    scanf("%d",&v.qnty);
                                    printf("\nEnter the price of One Item: ");
                                    scanf("%f",&v.price);
                                    v.amount=v.qnty*v.price;
                                    printf("\nThe amount of %d %s is = %f",v.qnty,v.name,v.amount);
                                    fwrite(&v,recsize2,1,fi);
                                    printf("\n----------------------------------------------------");
                                    printf("\nWant to add entry of the another Item(Y/N): ");
                                    fflush(stdin);
                                    a=getche();
                                }
                            }
                        break;
                  
                    case '2':
                        clrscr();
                        a='Y';
                        while(a=='Y'||a=='y')
                            {
                                printf("\nEnter name of item to search: ");
                                gets(i_name);
                                rewind(fi);
                                while(fread(&v,recsize2,1,fi)==1)
                                    {
                                        if(strcmp(v.name,i_name)==0)
                                            {
                                                printf("\nThe Name of the Item: ");
                                                puts(v.name);
                                                printf("\nEnter the Date of purchase: %s",v.dop);
                                                printf("\nQuantity of the Item: %d",v.qnty);
                                                printf("\nPrice of One Item: %f",v.price);
                                                v.amount=v.qnty*v.price;
                                                printf("\nThe amount of %d %s is = %f",v.qnty,v.name,v.amount);
                                            }
                                    }
                                printf("\n----------------------------------------------------");
                                printf("\nSearch another Entry(Y/N): ");
                                fflush(stdin);
                                a=getche();
                            }
                        break;
                            case '3':
                            clrscr();
                            printf("S.No.\t ITEM\t DOP\t\t QUANTITY\t PRICE\t\t AMOUNT\n");
                            printf("-----------------------------------------------------------------------------\n");
                            rewind(fi);
                            while(fread(&v,recsize2,1,fi)==1)
                                {
                                    printf("%d\t \n%s\t %s\t %d\t\t Rs.%f\t Rs.%f\n",j,v.name,v.dop,v.qnty,v.price,v.amount);
                                    j++;
                                }
                            getch();
                            break;
                           case '4':
                                {
                                    fclose(fi);
                                    clrscr();
                                    menu();
                                }
                            break;
                        }
                    }
}