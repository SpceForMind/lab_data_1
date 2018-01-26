
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

