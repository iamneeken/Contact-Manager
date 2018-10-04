#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct contact{
 	char name[20];
 	int number;
 }contacts[100];
 
 int view_contact();
 int add_contact();
 int edit_contacts();
 int search_contacts();
 int delete_contacts();
 
 int main()
 {
 	system("cls");
 	int options;
 		while(1)
 	{
 	printf("\n**********************************PHONEBOOK**********************************");
	printf("\n1:View");
 	printf("\n2:Add");
 	printf("\n3:Edit");
 	printf("\n4:Search");
 	printf("\n5:Delete\n");
 	printf("\nChoose Options:");
	 scanf("%d",&options);
 
	 
	 switch(options)
 	{
 		case 1:
 			view_contact();
 			break;
 			
 			case 2:
 				add_contact();
 				break;
 				
 				case 3:
 					edit_contacts();
 					break;
 					
 					case 4:
 						search_contacts();
 						break;
 						
 						case 5:
 							delete_contacts();
 							break;
 							
 							default:
 								system("cls");
 								continue;
 							
 							}
 							break;
	 }
	 getch();
 return 0;
 }
 int add_contact()
 {
 	char blank;
 	int i=0;
 	FILE *fp;
 	while(1)
 	{
	printf("\nEnter name:");
 	scanf(" %[^\n]s",&contacts[i].name);
 	printf("\nEnter Number: 9");
 	scanf(" %d",&contacts[i].number);
 	fp=fopen("phonebook.txt","a+");
	fwrite(&contacts[i],sizeof(contacts[i]),1,fp);
	fclose(fp);
	printf("do you wnat to add more(y/n):\n");
	scanf(" %c",&blank);
	i++;
	if(blank=='y'|| blank=='Y'){
		continue;
	}
	break;
 	}
 	
  main();
return 0;
}


int view_contact()
{
	int i=0;
	FILE *fp;
	fp=fopen("phonebook.txt","r");
	while(fread(&contacts[i],sizeof(contacts[i]),1,fp)>0)
 	{
	printf("%s , 9%d",contacts[i].name,contacts[i].number);
	printf("\n");
	i++;
	}
	fclose(fp);
	printf("press enter to go to main menu");
	getch();
	main();
return 0;
}

int edit_contacts()
{
	int i=0,j=0;
	char name[20];
	FILE *fp;
	fp=fopen("phonebook.txt","a+");
	printf("\nenter name:");
	scanf(" %[^\n]s",&name);
	while(fread(&contacts[i],sizeof(contacts[i]),1,fp)>0){
		i++;
	}
	fclose(fp);
	while (1){
		if(strcmp(contacts[j].name,name)==0){
			break;
		}
		j++;
	}
	printf("\nedit Name:");
 	scanf(" %[^\n]s",&contacts[j].name);
 	printf("\nedit Number: 9");
 	scanf(" %d",&contacts[j].number);
 	fp=fopen("phonebook.txt","w");
 	for(j=0;j!=i;j++){
	fwrite(&contacts[j],sizeof(contacts[j]),1,fp);
	}
	fclose(fp);
	printf("\nViewing Contacts:\n");
	view_contact();	
	return 0;
}
int search_contacts()
{
	int i=0,j=0;
	char name[20];
	FILE *fp;
	fp=fopen("phonebook.txt","a+");
	printf("\nenter name:");
	scanf(" %[^\n]s",&name);
	while(fread(&contacts[i],sizeof(contacts[i]),1,fp)>0){
		i++;
	}
	fclose(fp);
	while (1){
		if(strcmp(contacts[j].name,name)==0){
			printf("%s , 9%d",contacts[j].name,contacts[j].number);
			printf("\n");
		}
		j++;
		
}
return 0;
}
int delete_contacts()
{
	int i=0,j=0,k=0,c=0;
	char name[20];
	FILE *fp;
	fp=fopen("phonebook.txt","r");
	printf("\nenter name:");
	scanf(" %[^\n]s",&name);
	while(fread(&contacts[i],sizeof(contacts[i]),1,fp)>0){
		i++;
	}
	fclose(fp);
	while (1){
		if(strcmp(contacts[j].name,name)==0){
			break;
		}
		j++;
	}
	for (c=j;c<i-1;c++){
        	contacts[c].number = contacts[c+1].number;
        	strcpy(contacts[c].name,contacts[c+1].name);
	}
	fp=fopen("phonebook.txt","w");
 	for(k=0;k!=i-1;k++){
	fwrite(&contacts[k],sizeof(contacts[k]),1,fp);
	}
	fclose(fp);
	printf("\nViewing Contacts:\n");
	view_contact();
	return 0;
}
