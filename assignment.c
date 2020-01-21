#include<stdio.h>
#include <string.h>

struct date{
	int day;
	int month;
	int year;
}player_date;

struct player{
	char name[100];
	int age;
	struct date player_date;
}footballer[100];

struct team{
	char name[100];
	int number_of_players;
	struct player list_of_players[21];
}new_team[100];

struct player CreateFootballPlayer(struct player footballer[],int n){
	printf("Enter name:");
	gets(footballer[n].name);
	printf("Enter age:");
	scanf("%d",&footballer[n].age);
	printf("Enter birth day:");
	scanf("%d",&footballer[n].player_date.day);
	printf("Enter birth month:");
	scanf("%d",&footballer[n].player_date.month);
	printf("Enter birth year:");
	scanf("%d",&footballer[n].player_date.year);
	
	return footballer[n];	
}

struct team CreateEmptyTeam(struct team new_team[]){
	printf("Enter team name:");
	gets(new_team[0].name);
	
	return new_team[0];
}

void AddPlayer(struct player footballer[],struct team new_team[],int n){
	int i,x=0;
	new_team[x].number_of_players=n;
	for (i=0;i<n;i++){
		new_team[x].list_of_players[i]=footballer[i];
	}	
}

void StoreTeam(struct team new_team[],FILE *file){
	int i=0;
	file=fopen("team.txt","w");
	while(i<new_team[0].number_of_players){
		fprintf(file,"%s;%d;%d;%d;%d,",new_team[0].list_of_players[i].name,new_team[0].list_of_players[i].age,new_team[0].list_of_players[i].player_date.day,new_team[0].list_of_players[i].player_date.month,new_team[0].list_of_players[i].player_date.year);
		i++;
	}
	fclose(file);
}

void ReadTeam(FILE *file,struct team new_team[]){
	char check[1000];
	int i=0;
	file=fopen("team.txt","r");
	fscanf(file,"%s",check);
	if((new_team[0].list_of_players[i].name)==(check)){
		new_team[0].list_of_players[i].age=new_team[0].list_of_players[i].age+3;
	}
}



int main(){
	FILE *file;
	int check,n=0;
	printf("Add player(Press 1):");
	scanf("%d",&check);
	fflush(stdin);
	while(check==1 && n<22){
		CreateFootballPlayer(footballer,n);
		printf("\nAdd player(Press 1):");
		scanf("%d",&check);
		fflush(stdin);
		n++;
	}
	CreateEmptyTeam(new_team);
	AddPlayer(footballer,new_team,n);
	StoreTeam(new_team,file);
	ReadTeam(file,new_team);
	StoreTeam(new_team,file);	

	
	return 0;
}
