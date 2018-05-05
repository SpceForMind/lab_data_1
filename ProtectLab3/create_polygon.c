
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <dirent.h>
#include <string.h>

#define ROOTDIRECTORY "root"
#define MAXDEEP 6
#define MAXCOUNTFILES 2000
#define MAXFILESINDIR 3

#define WAYSIZE 100
#define FILENAMESIZE 10
#define DIRECTORYNAMESIZE 3

const char *valid_names = "ABCDEDFGHIJKLMNOPQRSTUVWXYZ";
const char *arr_strings[] = {"Good morning!", "Fruits great for health.", "3 p.m."};


void AddDirWay(char dir_way[WAYSIZE])
{
	char new_alpha[2];
	for(int i = 0; i < DIRECTORYNAMESIZE; ++i)
	{
		new_alpha[0] = valid_names[rand() % 27];
		new_alpha[1] = '\0';
		strcat(dir_way, new_alpha);
	}
}	

void GenerateFileName(char file_name[FILENAMESIZE])
{
	int name_len = rand() % (FILENAMESIZE - 5) + 1; //5 characters for end of name(.txt)
	char new_alpha[2];
	for(int i = 0; i < name_len; ++i)
	{
		new_alpha[0] = tolower(valid_names[rand() % 27]);
		new_alpha[1] = '\0';
		strcat(file_name, new_alpha);
	}
	strcat(file_name, ".txt");
}


void WriteInFile(FILE *file)
{
	int index = rand() % 3;
	long int num = rand();
	char buf[100] = {0};
	if(rand() % 2 == 1)
		num = -num;
	sprintf(buf, "%ld", num);
	strcat(buf, " ");
	strcat(buf, arr_strings[index]);
	fwrite(buf, sizeof(char), strlen(buf), file);
}



void CreatePolygon(int count_files)
{
	char dir_way[WAYSIZE] = {0};
	strcat(dir_way, ROOTDIRECTORY);
	DIR *root = opendir(dir_way);
	if(!root)
	{
		printf("mkdir %s\n", dir_way);
		mkdir(dir_way, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	}
	else
		closedir(root);
	strcat(dir_way, "/"); 
	char file_name[FILENAMESIZE] = {0}; //file in format <alpha>.txt

	while(count_files > 0)
	{
		int dyrectory_deep = rand() % MAXDEEP + 1;
		int count_files_in_dir = rand() % MAXFILESINDIR + 1;
		
		//create directory way for set of files
		for(int i = 0; i < dyrectory_deep; ++i)
		{
			printf("dir_way: %s\n", dir_way);
			AddDirWay(dir_way);
			DIR *cur_dir = opendir(dir_way);
			if(!cur_dir)
			{
				printf("mkdir %s\n", dir_way);
				mkdir(dir_way, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
			}
			else
				closedir(cur_dir);
			if(i != dyrectory_deep - 1)
				strcat(dir_way, "/");
		}
	
		//create files
		for(int j = 0; j < count_files_in_dir; ++j)
		{
			int len = strlen(dir_way);
			GenerateFileName(file_name);
			strcat(dir_way, "/");
			strcat(dir_way, file_name);
			printf("create file %s\n", dir_way);
			FILE *new_file = fopen(dir_way, "w");
			if(new_file)
			{
				WriteInFile(new_file);
				fclose(new_file);
				--count_files;
			}
			dir_way[len] = '\0';
			file_name[0] = '\0';
		}
		dir_way[strlen(ROOTDIRECTORY) + 1] = '\0'; //because all directorys creating in root/
	}
}


int main()
{
	int count_files;
	srand(time(NULL));
	count_files = rand() % MAXCOUNTFILES + MAXCOUNTFILES;
	printf("count_files = %d\n", count_files);
	CreatePolygon(count_files);

	return 0;
}

