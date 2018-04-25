
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <regex.h>

#define BUFSIZE 128
#define WAYSIZE 100
#define ARRSIZE 10

typedef struct
{
	int value;
	char str[BUFSIZE];
} Pair;


void PrintFile(const char *file_name)
{
	char buf[BUFSIZE];
	FILE *file = fopen(file_name, "r");
	
	if(file)
	{
		printf("%s:\n", file_name);
		while(fgets(buf, BUFSIZE, file))
			printf("%s", buf);
	}
	else
		printf("Can't open file: %s\n", file_name);	
	fclose(file);
}


void PrintArrPair(Pair *arr_pair, int index)
{
	for(int i = 0; i < index; ++i)
		printf("%s", arr_pair[i].str);
}



//Check str from file for correct
int IsValid(char *str)
{
	char *regexp = "^[[:digit:]]+[[:space:]][[^:space:]]+";
	regex_t regex_comp;

	if(regcomp(&regex_comp, regexp, REG_EXTENDED))
		return 0;

	return !regexec(&regex_comp, str, 0, NULL, 0);
}


int IsTxtFile(const char *file_name)
{
	char *regexp = ".*\\.txt$";
	regex_t regex_comp;

	if(regcomp(&regex_comp, regexp, REG_EXTENDED))
		return 0;

	return !regexec(&regex_comp, file_name, 0, NULL, 0);
}


void AddPair(Pair *arr_pair, int index, const char *file_name)
{
	FILE *file = fopen(file_name, "r");

	if(file)
	{
		fgets(arr_pair[index].str, BUFSIZE, file);
		arr_pair[index].value = atoi(arr_pair[index].str);	
	}
	fclose(file);
}


void BypassingDirs(const char *dir_name, Pair *arr_pair, int *index_pair)
{
	DIR *cur_dir = opendir(dir_name);
	char file_name[WAYSIZE];
	char next_dir[WAYSIZE];
	strcpy(next_dir, dir_name);
	strcpy(file_name, dir_name);

	if(!cur_dir)
		return;
	struct dirent *cur_file = readdir(cur_dir);
	
	while(cur_file)
	{
		int len = strlen(next_dir);
	
		if(cur_file->d_type == DT_DIR && strcmp(cur_file->d_name, ".")!= 0 && strcmp(cur_file->d_name, "..")!= 0)
		{
			strcat(next_dir, "/");
			strcat(next_dir, cur_file->d_name);
			BypassingDirs(next_dir, arr_pair, index_pair);
			next_dir[len] = '\0';
		}
		if(cur_file->d_type == DT_REG && IsTxtFile(cur_file->d_name))
		{
			strcat(file_name, "/");
			strcat(file_name, cur_file->d_name);

			if(*index_pair % ARRSIZE == 0 && *index_pair!= 0)
				arr_pair = (Pair *)realloc(arr_pair, sizeof(Pair) * (*index_pair + ARRSIZE));
			AddPair(arr_pair, *index_pair, file_name);
			++*index_pair;

			file_name[len] = '\0';
		}	

		cur_file = readdir(cur_dir);
	}

	closedir(cur_dir);
}


void WriteInFile(Pair *arr_pair, int index, char *file_name)
{
	FILE *file = fopen(file_name, "w");
	char buf[BUFSIZE];

	if(file)
		for(int i = 0; i < index; ++i)
			fwrite(arr_pair[i].str, sizeof(char), strlen(arr_pair[i].str) + 1, file); 
}



int Compare(const void *pair1, const void *pair2)
{
	int v1 = ((Pair *)pair1)->value;
	int v2 = ((Pair *)pair2)->value;

	return v1 - v2;
}


int main()
{
	int index_pair = 0;
	Pair *arr_pair = (Pair *)malloc(ARRSIZE * sizeof(Pair));
	BypassingDirs(".", arr_pair, &index_pair);
	qsort(arr_pair, index_pair, sizeof(Pair), Compare);
//	PrintArrPair(arr_pair, index_pair);	
	WriteInFile(arr_pair, index_pair, "result.txt");

	return 0;
}
