
#ifndef _DICT_TYPES_H_
#define _DICT_TYPES_H_

#define MAXKEY 50

typedef struct record
{
	char key[MAXKEY]; 
	char value[MAXKEY];
	struct record *next;
} Record;


typedef struct dictonary
{
	Record *front;
	int count;
} Dictonary;

#endif
