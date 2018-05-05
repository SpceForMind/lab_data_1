
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <regex.h>

#define BUFSIZE 128
#define WAYSIZE 200
#define ARRSIZE 10

#define ROOTDIR "root"
#define RESULTFILE "result.txt"

typedef struct
{
	long long int value;
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
		printf("index %d:%s\n", i, arr_pair[i].str);
}



//Check str from file for correct
int IsValid(char *file_name)
{
	FILE *file = fopen(file_name, "r");

	char str[BUFSIZE];
	fgets(str, BUFSIZE, file);

	char *regexp = "^-?[[:digit:]]+[[:space:]]";
	regex_t regex_comp;

	if(regcomp(&regex_comp, regexp, REG_EXTENDED))
		return 0;
	
	fclose(file);
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


void AddPair(Pair **arr_pair, int index, const char *file_name)
{
	FILE *file = fopen(file_name, "r");
	
	if(file)
	{
		fgets((*arr_pair)[index].str, BUFSIZE, file);
	//	if(strstr((*arr_pair)[index].str, "\n"))
	//		*strstr((*arr_pair)[index].str, "\n") = '\0';
		(*arr_pair)[index].value = atoll((*arr_pair)[index].str);	
		fclose(file);
	}
}


void BypassingDirs(const char *dir_name, Pair **arr_pair, int *index_pair)
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
				*arr_pair = (Pair *)realloc(*arr_pair, sizeof(Pair) * (*index_pair + ARRSIZE));
			if(IsValid(file_name))
			{
				AddPair(arr_pair, *index_pair, file_name);
				++*index_pair;
			}
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
		{
			if(arr_pair[i].str[strlen(arr_pair[i].str) - 1]!= '\n')
				strcat(arr_pair[i].str, "\n");
			
			fwrite(arr_pair[i].str, sizeof(char), strlen(arr_pair[i].str), file); 
		}
	fclose(file);
}



int Compare(const void *pair1, const void *pair2)
{
	long int v1 = ((Pair *)pair1)->value;
	long int v2 = ((Pair *)pair2)->value;
	
	if(v1 > v2)
		return 1;
	else if(v1 == v2)
		return 0;
	else if(v1 < v2)	
		return -1;
}


int main()
{
	int index_pair = 0;
	Pair *arr_pair = (Pair *)malloc(ARRSIZE * sizeof(Pair));
	BypassingDirs(ROOTDIR, &arr_pair, &index_pair);
	qsort(arr_pair, index_pair, sizeof(Pair), Compare);
	WriteInFile(arr_pair, index_pair, RESULTFILE);
	
	return 0;
}
