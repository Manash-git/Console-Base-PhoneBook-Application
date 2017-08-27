/*
*	---------- Data Structure Project ------------------
*
*	===:>>	A Simple console based Phonebook Application.
*	Language:: C
*	Compiler: DEV C++
*
*
*	Copyright:: Manash Kumar Mondal
*
*/

//#include<stdio.h>
#include<bits/stdc++.h>
#include<ctype.h>
#define MAX_SIZE 100


typedef struct{				// Structure for holding data of contact.
//	int id;
	char first_name[20];
	char last_name[20];
	char phn_no[20];
}data;

/*
*		For define search type.
*/

typedef enum{
	First_name, Last_name, Phn_no
}search_type;

/*
*	Array to hold our data.
*/
data phonebook[MAX_SIZE];
/*
*	Current Size of phone book array.
*/

int current_size=0;

//	**------------  Function Prototype -------**


void add_entry();
void display(int index);
void search(char *key, search_type type);
void lower_convert(char *str);
void save_file();
void read_file();
void removeEntry(char *mobile_no);
void clear();


//  ********		Main Function.   ****************************

int main(){

	read_file();
	char selection[20];
	int choice=0;

	while(1){
	fflush(stdin);

	printf("\n		 PhoneBook Application.  ");		fflush(stdin);
	printf("\n   ----------------------------------------------------------");
	printf("\n");
	printf("\n	|	1. Insert A New Entry 			|");		fflush(stdin);
	printf("\n	|	2. Display all Entry		 	|");		fflush(stdin);
	printf("\n	|	3. Search by First Name			|");		fflush(stdin);
	printf("\n	|	4. Search by Last Name			|");		fflush(stdin);
	printf("\n	|	5. Search by Mobile Number		|");		fflush(stdin);
	printf("\n	|	6. Delete a contact			|");		fflush(stdin);
	printf("\n	|	7. Save PhoneBook			|");		fflush(stdin);
	printf("\n	|	8. Exit					|");
	printf("\n  ----------------------------------------------------------\n");

	do{
		fflush(stdin);
		printf("\n	==>> Enter your Choice::	");
		gets(selection);
		choice=atoi(selection);

	}while(choice<1 || choice>8 );

	//**********************	Menu.  ************************

	switch(choice)
        {
        case 1:
            add_entry();
            printf("\n\n 	Contact Added.");
            printf("\n-----------------------------------------------------------\n\n");
            clear();
            break;
        case 2:
            if(current_size==0){
            	printf("\n	PhoneBook is Empty !!.");
			}else{
				  printf("  ----------------------------------------------------------\n");
				  for(int i=0;i<current_size;i++){

				  display(i);
            	  printf("\n\n");
				  }
				  printf("   ----------------------------------------------------------");
	  	    }
	  	    printf("\n\n\n");
			clear();
            break;
        case 3:
            printf("\n	Enter first name to search::	");			fflush(stdin);
            gets(selection);
            search(selection, First_name);
            printf("\n\n\n");
            clear();
			break;
        case 4:
            printf("\n	Enter last name to search::		");			fflush(stdin);
            gets(selection);
            search(selection, Last_name);
            printf("\n\n\n");
            clear();
            break;
        case 5:
            printf("\n	Enter mobile number to search::		");		fflush(stdin);
            gets(selection);
            search(selection,Phn_no);
            printf("\n\n\n");
            clear();
            break;
        case 6:
            printf("\n	Enter mobile number to delete::		");			fflush(stdin);
            gets(selection);
            removeEntry(selection);
            printf("\n\n\n");
            clear();
            break;
        case 7:
            save_file();
            printf("\n\n\n");
            clear();
            break;
        case 8:
            exit(0);
            break;
        default:
            break;
        }
    }
//	add_entry();	printf("\n");
//	save_file();
//	read_file();
//	printf("\nCurrent size:: %d\n",current_size);
//	display(0);

/*	char my_search[]="sakib";
//	display(0);  	printf("\n");
	search(my_search,Last_name);
//	search("123",2);
	*/
return 0;
}






void add_entry(){

	if(current_size== MAX_SIZE){
		printf("\n Error:: PhoneBook is Full.");
		return;
	}
	 data c;
	 printf("\n Enter First Name  ::	");		gets(c.first_name);			fflush(stdin);
	 printf("\n Enter Last Name   :: 	");		gets(c.last_name);			fflush(stdin);
	 printf("\n Enter Phone Number:: 	");		gets(c.phn_no);				fflush(stdin);

	 phonebook[current_size]= c;
	 ++current_size;
}

void display(int index){

	if(index<0 || index>=current_size){
		printf("\n Error:: Invalid Entry !!!");
		return;
	}

	data c=phonebook[index];							fflush(stdin);
	printf("\n	||	First Name  ::	%s",c.first_name);
	printf("\n	||	Last Name   :: 	%s",c.last_name);
	printf("\n	||	Phone Number:: 	%s",c.phn_no);
}



void search(char *key, search_type type){
	int found=0;
	char content[40];
	lower_convert(key);
	if(type==First_name){		// search by first name.
		for(int i=0;i<current_size;i++){
			strcpy(content,phonebook[i].first_name);
			lower_convert(content);
			if(strcmp(content,key)==0){
				display(i);
				printf("\n   ----------------------------------------------------------");
				found=1;
			}
		}
	}else if(type==Last_name){		// search by last name.
		for(int i=0;i<current_size;i++){
				strcpy(content,phonebook[i].last_name);
				lower_convert(content);
				if(strcmp(content,key)==0){
				display(i);
				printf("\n   ----------------------------------------------------------");
				found=1;
				}
		}
	}
	else if(type==Phn_no){
		 for(int i=0;i<current_size;i++){
		 	strcpy(content,phonebook[i].phn_no);
			lower_convert(content);
   				  if(strcmp(content,key)==0){
				display(i);
				printf("\n   ----------------------------------------------------------");
				found=1;
			}
		}
	}
	else{
		printf("\n	Error:: Invalid search type.");
		return;
	}
	if(!found){
		printf("\n	Error:: Not found in the phone book.");
	}
}


void lower_convert(char *str){
	int len=strlen(str);
//	printf("\n\n Length== :: 	%d\n\n",len);
	for(int i=0;i<len;i++){
		str[i]=tolower(str[i]);
	}

}


void save_file(){
	 FILE *fp;
	 if((fp=fopen("phonebook.db","wb"))==NULL){					fflush(stdin);
	 	printf("\n	Error:: Can't creat a database file !!");
	 	return;
	 }
	 // Save the current size of phonebook.

	 if(fwrite(&current_size,sizeof(current_size),1,fp)!=1){		fflush(stdin);
	 	printf("\n	Error::	Can't save data !!");
	 	return;
	 }
	 // save phonebook content.

	 if(fwrite(phonebook,sizeof(phonebook),1,fp)!=1){				fflush(stdin);
	 	printf("\n	Error::	Can't save data !!");
	 	return;
	 }
	 printf("\n PhoneBook is saved succesfully. *_* \n");
	 printf("\n   ----------------------------------------------------------");
}

void read_file(){

	FILE *fp;
	 if((fp=fopen("phonebook.db","rb"))==NULL){					fflush(stdin);
	 	printf("\n		Wellcome Sir	\n");
	 	return;
	 }
	 // Read the current size of phonebook.

	 if(fread(&current_size,sizeof(current_size),1,fp)!=1){		fflush(stdin);
	 	printf("\n	Error:: Can't read data !!");
	 	return;
	 }
	 // save phonebook content.

	 if(fread(phonebook,sizeof(phonebook),1,fp)!=1){			fflush(stdin);
	 	printf("\n	Error::	Can't read data !!");
	 	return;
	 }
}

void removeEntry(char *mobile_no){


	if(current_size == 0) {											fflush(stdin);
        printf("\n	Phonebook is empty ! Nothing to delete!");
        return;
    }


    int i, j;
    int count = 0;
    for(i=0; i<current_size; i++) {
        if(strcmp(phonebook[i].phn_no, mobile_no) == 0) {
            for(j=i; j<current_size-1; j++) {
                phonebook[j] = phonebook[j+1];
            }

            strcpy(phonebook[j].first_name, "");
            strcpy(phonebook[j].last_name, "");
            strcpy(phonebook[j].phn_no, "");

            current_size -= 1;
            ++count;
        }
    }
    if(count == 0) {
        printf("\n	No entry deleted.");
    }
    else {
        printf("\n	%d entries deleted\n", count);
    }
}

void clear(){			// Avoid to control flooding of screen
	system("PAUSE");
	system("CLS");
}


