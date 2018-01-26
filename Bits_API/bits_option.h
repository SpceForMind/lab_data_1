#ifndef _BITS_OPTION_H_
#define _BITS_OPTION_H_

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

const char *colors[] = {"Black", "Red", "Green", "Yellow", "Blue", "Maggenta", "Cyan", "White"};

#endif
