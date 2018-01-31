
int PointerIsNull(const void *p)
{
	if(p == NULL)
	{
		printf("NULL pointer!\n");
		return 1;
	}
	else	
		return 0;
}


static void InitializeDictonary(Dictonary *pdict)
{
	if(PointerIsNull(pdict))
		return;

	*pdict = (Dictonary){.front = NULL, .count = 0};
}


static void PrintDictonary(const Dictonary *pdict)
{
	if(PointerIsNull(pdict))
		return;

	Record *time_record = pdict->front;

	for(int i = 0; i < pdict->count; ++i)
	{
		printf("%s %s\n", time_record->key, time_record->value);
		time_record = time_record->next;
	}	

	printf("---------------\n");
}


static Record *MakeRecord(const char *key, const char *value)
{
	if(PointerIsNull(key) || PointerIsNull(value))
		return NULL;

	Record *new_record = (Record *)malloc(sizeof(Record));
	
	if(PointerIsNull(new_record))
	{
		fprintf(stderr, "No memory!\n");
		return NULL;
	}

	strncpy(new_record->key, key, strlen(key) + 1);
	strncpy(new_record->value, value, strlen(value) + 1);

	return new_record;
}

static int AddRecord(const Record *new_record, Dictonary *pdict)
{
	if(PointerIsNull(new_record) || PointerIsNull(pdict))
		return 0;

	if(pdict->front == NULL)
	{
		pdict->front = new_record;
		++pdict->count;

		return 1;
	}
	else
	{
		Record *time_record = pdict->front;
		
		while(time_record!= NULL)
		{
			if(strncmp(new_record->key, time_record->key, strlen(new_record->key) + 1) == 0)
			{
				strncpy(time_record->value, new_record->value, strlen(new_record->value) + 1);
				++pdict->count;

				return 1;
			}
			
			if(time_record->next == NULL)
			{
				time_record->next = new_record;
				++pdict->count;

				return 1;
			}

			time_record = time_record->next;
		}

		return 0;
	}
}

static int DeleteRecord(const Record *delete_record, Dictonary *pdict)
{
	if(PointerIsNull(delete_record) || PointerIsNull(pdict))
		return 0;
	if(PointerIsNull(pdict->front))
		return 0;

	Record **current_record = &pdict->front;

	while(*current_record!= NULL)
	{
		if(*current_record == delete_record)
		{
			Record *time_record = *current_record;
			*current_record = (*current_record)->next;
			free(time_record);
			time_record = NULL;
			--pdict->count;

			return 1;
		}

		current_record = &(*current_record)->next;
	}
	printf("This record does not exits!\n");

	return 0;
}


static int DeleteDictonary(Dictonary *pdict)
{
	if(PointerIsNull(pdict))
		return 0;
	if(PointerIsNull(pdict->front))
		return 0;

	Record *current_record = pdict->front;

	for(int i = 0; i < pdict->count; ++i)
	{
		Record *time_record = current_record;
		current_record = current_record->next;
		free(time_record);
		time_record = NULL;
	}

	InitializeDictonary(pdict);

	return 1;
}




