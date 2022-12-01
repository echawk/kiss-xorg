/* magnification factor. must be >0.0 */
static float MAG_FACTOR = 10.5f;
/* zoom in/out factor */
static const float MAG_STEP = 1.25f;
/* size of the magnifier */
static const uint MAG_SIZE = 240;

/* default scaling function */
static const MagFunc mag_func = nearest_neighbour;

/*
 * COLORS: All the colors here are in ARGB32 format, e.g 0xAARRGGBB.
 */

/* square() options */
static const uint SQUARE_WIDTH = 2;
static const XcursorPixel SQUARE_COLOR = 0x80ebdbb2;

/* xhair() options */
static const uint XHAIR_SIZE = 5;
static const uint XHAIR_BORDER_WIDTH = 2;
static const XcursorPixel XHAIR_COLOR = 0xffebdbb2;

/* grid() options */
static const uint GRID_SIZE = 5 * 2; /* best kept 2x XHAIR_SIZE */
static const XcursorPixel GRID_COLOR = 0xff3C3836;

/* circle_border() options */
static const uint CIRCLE_RADIUS = MAG_SIZE / 2; /* best kept 0.5x MAG_SIZE */
static const uint CIRCLE_WIDTH = 4;
static const XcursorPixel CIRCLE_COLOR = 0xff3c3836;
static const Bool CIRCLE_TRANSPARENT_OUTSIDE = True;

/* example filter sequences */
static const FilterFunc sq_cross[] = { square, xhair };
static const FilterFunc sq_grid_cross[] = { square, xhair };
static const FilterFunc circle_grid_cross[] = { circle, xhair };

/* default filter sequence, overridden via cli arg `--mag-filters` */
static const FilterSeq filter_default = FILTER_SEQ_FROM_ARRAY(circle_grid_cross);

/* max time (in ms) allowed to go on without a redraw */
static const int MAX_FRAME_TIME = 16;

/* default output format, overridden via cli arg.
 * available options: OUTPUT_{NONE,HEX,RGB,HSL,ALL}
 * the options may be OR-ed together, e.g: `OUTPUT_RGB | OUTPUT_HSL`
 */
static const enum output OUTPUT_DEFAULT = OUTPUT_ALL;

/* convenient macro for populating the filter table */
#define FILTER_TABLE_ENTRY(X) #X, sizeof (#X) - 1, X
/* table of filter functions, used by filter_parse() for mapping --mag-filters */
static const struct { const char *str; uint len; FilterFunc f; } FILTER_TABLE[] = {
	{ FILTER_TABLE_ENTRY(square) },
	{ FILTER_TABLE_ENTRY(xhair)  },
	{ FILTER_TABLE_ENTRY(grid)   },
	{ FILTER_TABLE_ENTRY(circle) },
};
