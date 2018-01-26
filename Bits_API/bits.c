#include <stdio.h>

#include "bits_types.h"
#include "bits_option.h"
#include "bits_API.h"




int main()
{
	BoxProps box = {YES, GREEN, NO, MAGGENTA, DOTTED};
	Views box1;

	box1.st_views = box;
	PrintSettings(&box1.st_views);
	printf("---------\n");
	PrintSettingsForUnion(box1.us_views);


	return 0;
}
