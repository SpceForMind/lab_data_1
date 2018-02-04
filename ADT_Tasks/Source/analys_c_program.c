
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pointer.h"

#define MAXSIZE 20
#define TYPESIZE 7


char const *type[] = {"int", "double", "float", "char"};

typedef struct variable
{
	char type[TYPESIZE];
	char name[MAXSIZE];
} Variable;


typedef struct dictonary
{
	Variable **arr_var;
	int count;
} Dictonary;


void InitializeDictonary(Dictonary *pdict)
{
	if(PointerIsNull(pdict))
		return;
	
	pdict->arr_var = (Variable **)malloc(sizeof(Variable *) * MAXSIZE);
	pdict->count = 0;
}


Variable *MakeVariable(char *type, char *name)
{
	if(PointerIsNull(type) || PointerIsNull(name))
		return NULL;

	Variable *new_variable = (Variable *)malloc(sizeof(Variable));
	
	if(PointerIsNull(new_variable))
	{
		fprintf(stderr, "No memory!\n");
		exit(1);
	}
	
	strncpy(new_variable->type, type, strlen(type) + 1);
	strncpy(new_variable->name, name, strlen(name) + 1);

	return new_variable;
}


void AddVariable(Variable *new_variable, Dictonary *pdict)
{
	if(PointerIsNull(new_variable) || PointerIsNull(pdict))
		return;
	if(PointerIsNull(pdict->arr_var))
		return;

	if(pdict->count % MAXSIZE == 0 && pdict->count!= 0)
	{
		pdict->arr_var = (Variable **)realloc(pdict->arr_var, sizeof(Variable *) * pdict->count + MAXSIZE);
		
		if(PointerIsNull(pdict->arr_var))
		{
			fprintf(stderr, "No memory!\n");
			exit(1);
		}
	}

	pdict->arr_var[pdict->count] = new_variable;
	++pdict->count;
}


void PrintDictonary(Dictonary *pdict)
{
	if(PointerIsNull(pdict))
		return;
	if(PointerIsNull(pdict->arr_var))
		return;

	for(int i = 0; i < pdict->count; ++i)
		printf("%s %s\n", pdict->arr_var[i]->type, pdict->arr_var[i]->name);

	printf("-------------\n");
}


void DeleteDictonary(Variable *delete_variable, Dictonary *pdict)
{
	if(PointerIsNull(delete_variable) || PointerIsNull(pdict))
		return;
	if(PointerIsNull(pdict->arr_var))
		return;

	for(int i = 0; i < pdict->count; ++i)
		free(pdict->arr_var[i]);

	free(pdict->arr_var);
	pdict->arr_var = NULL;
	pdict->count = 0;
}




void CreateDictonary(Dictonary *pdict)
{
	if(PointerIsNull(pdict))
		return;

	Variable time_variable;
	char c;

	int do_flag = 1;

	while((c = getchar())!= '{')
		continue;

	while(1)
	{
		if(do_flag)
		{
			while((c = getchar())!= '\t')
				continue;

			do_flag = 0;
		}


		if(scanf("%s %s;", time_variable.type, time_variable.name) == 2)
		{
			Variable *current_variable = MakeVariable(time_variable.type, time_variable.name);

			if(PointerIsNull(current_variable))
			{
				fprintf(stderr, "Error by create Variable!\n");
				exit(1);
			}

			AddVariable(current_variable, pdict);
		}

		while((c = getchar())!= '\t')
		{
			int break_flag = 0;

			if(c == '}')
			{
				while((c = getchar())!= EOF)
					if(c == '{')
					{
						do_flag = 1;
						break_flag = 1;
						break;
					}	
				if(c == EOF)
					return;
			}

			if(break_flag)
				break;
		}
	}
}


int main()
{
	Dictonary dict;
	
	InitializeDictonary(&dict);
	CreateDictonary(&dict);
	PrintDictonary(&dict);

	/*
	Variable *new_variable = MakeVariable("int", "n");
	AddVariable(new_variable, &dict);
	PrintDictonary(&dict);
	DeleteDictonary(new_variable, &dict);
	PrintDictonary(&dict);
	*/
	return 0;
}
