#include <stdio.h>

//#include "bits_types.h"
//#include "bits_option.h"
//#include "bits_API.h"

#define RED 1
#define GREEN 2
#define BLUE 4

#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

#define SOLID 0
#define DOTTED 1
#define DASHED 2


#define OPAQUE 0x1

#define FILL_RED 0x2
#define FILL_GREEN 0x4
#define FILL_BLUE 0x8
#define COLOR_MASK (FILL_RED | FILL_GREEN | FILL_BLUE)

#define BORDER 0x100

#define BORDER_RED 0x200
#define BORDER_GREEN 0x400
#define BORDER_BLUE 0x800
#define BORDER_MASK (BORDER_RED | BORDER_GREEN | BORDER_BLUE)

#define B_SOLID 0x0
#define B_DOTTED 0x1000
#define B_DASHED 0x2000
#define STYLE_MASK (B_SOLID | B_DOTTED | B_DASHED)

#define YES 1
#define NO 0

typedef struct box_props
{
	unsigned int opaque : 1;
	unsigned int fill_color : 3;
	unsigned int : 4;
	unsigned int show_border : 1;
	unsigned int border_color : 3;
	unsigned int border_style : 2;
	unsigned int : 2;
} BoxProps;


typedef union views
{
	BoxProps st_views;
	unsigned short us_views;
} Views;



const char *colors[] = {"Black", "Red", "Green", "Yellow", "Blue", "Maggenta", "Cyan", "White"};


int PointerIsNull(void *p)
{
	if(p == NULL)
	{
		printf("NULL pointer!\n");
		return 1;
	}
	else
		return 0;
}

static void PrintSettings(BoxProps *box)
{
	if(PointerIsNull(box))
		return;
	
	printf("Window is %s\n", box->opaque == YES ? "opaque" : "not opaque");
	printf("File color %s\n", colors[box->fill_color]);
	printf("Border %s\n", box->show_border == YES ? "apparent" : "invisible");
	printf("Border color %s\n", colors[box->border_color]);
	
	switch(box->border_style)
	{
		case SOLID:
			printf("Border style solid\n");
			break;
		case DOTTED:
			printf("Border style dotted\n");
			break;
		case DASHED:
			printf("Border style dashed\n");
			break;
		default:
			printf("Border style unknown\n");
	}
}

static void PrintSettingsForUnion(unsigned short us)
{
	printf("Window: %s\n", (us & OPAQUE) == OPAQUE ? "opaque" : "not opaque");
	printf("File color: %s\n", colors[(us >> 1) & COLOR_MASK]);
	printf("Border: %s\n", (us & BORDER) == BORDER ? "apparent" : "invisible");
	printf("Border color: %s\n", colors[(us >> 9) & (BORDER_MASK >> 9)]);
	
	switch(us & STYLE_MASK)
	{
		case B_SOLID:
			printf("Border style: solid\n");
			break;
		case B_DOTTED:
			printf("Border style: dotted\n");
			break;
		case B_DASHED:
			printf("Border style: dashed\n");
			break;
		default:
			printf("Unknown style!\n");
			break;
	}
}


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
