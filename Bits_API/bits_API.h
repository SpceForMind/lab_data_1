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

