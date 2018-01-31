
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dict_types.h"
#include "dict_API.h"


int main()
{
	Dictonary dict;

	InitializeDictonary(&dict);
	
	Record *new_record = MakeRecord("John Vatson", "Baiker street 342");
	
	if(AddRecord(new_record, &dict) == 1)
		PrintDictonary(&dict);
	DeleteRecord(new_record, &dict);
		PrintDictonary(&dict);
	DeleteDictonary(&dict);
		
	return 0;
}
