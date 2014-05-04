/* See LICENSE file for copyright and license details. */

/* appearance */
//static const char font[]            = "Source Code Pro 14"
static const char font[]            = "-*-ubuntu mono-medium-r-*-*-15-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#4b4c4d";   /* Color of unfocused windows' borders */
static const char normbgcolor[]     = "#141414";   /* Unfocused tag, and dmenu color */
static const char normfgcolor[]     = "#bbbbbb";   /* Unfocused tag text, dmenu typing text and cursor color */
static const char selbordercolor[]  = "#1d5891";   /* Focused window border color */
static const char selbgcolor[]      = "#141414";   /* Focused tag and dmenu option background color */
static const char selfgcolor[]      = "#1d5891";   /* Focused tag and dmenu option text color */
//static const unsigned int gappx     = 6;
static const unsigned int borderpx  = 1;           /* border pixel of windows */
static const unsigned int snap      = 32;          /* snap pixel */
static const Bool showbar           = True;        /* False means no bar */
static const Bool topbar            = True;        /* False means bottom bar */
//static const Bool statusmarkup      = True;        /* True means use pango markup in status message */

/* tagging */
static const char *tags[] = {
    "browser", "[ S ]", "[ D ]",
    "[ F ]", "[ Q ]", "[ W ]",
    "[ E ]", "[ R ]", "[ Z ]" };

static const Rule rules[] = {
	/* class                 instance        title           tags mask      isfloating     monitor */
	{ "Google-chrome",       NULL,           NULL,           1 << 0,        False,            -1 },
	{ NULL,                  "st-256color",  NULL,           1 << 2,        False,            -1 },
	{ "Steam",               NULL,           NULL,           1 << 4,        True,             -1 },
	{ "jetbrains-idea-ce",	 NULL,           NULL,           1 << 1,        False,            -1 },
	{ "MuPDF",               NULL,           NULL,           1 << 3,        False,            -1 },
	{ NULL,                  "st-exception", "st_cmus",      1 << 6,        False,            -1 },
	{ NULL,                  "st-exception", "st_irssi",     1 << 7,        False,            -1 },
	{ NULL,                  "st-exception", "st_rtorrent",  1 << 8,        False,            -1 },
	};

/* layout(s) */
static const float mfact      = 0.55;  /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;     /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol   addgap   arrange function */
	{ "[]=",  /*  True, */       tile },     /* first entry is default */
	{ "><>",  /*  False, */      NULL },     /* no layout function means floating behavior */
	{ "[M]",  /*  False,  */      monocle },
};

/* key definitions */
/* check 'xmodmap' for further details on mod keys */
#define MODKEY1 Mod4Mask /* Mod4Mask = Left windows key */
#define MODKEY2 Mod3Mask /* Mod3Mask = reconfigured to right menu key */
#define TAGKEYS(KEY,TAG) \
	{ MODKEY1,                       KEY,            toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY2,                       KEY,            view,           {.ui = 1 << TAG} }, \
	{ MODKEY2|ShiftMask,             KEY,            tag,            {.ui = 1 << TAG} }, \
	{ MODKEY1|ShiftMask,             KEY,            toggletag,      {.ui = 1 << TAG} },

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *torrentcmd[] = { "st", "-t", "st_rtorrent", "-e", "rtorrent", NULL};

static Key keys[] = {
	/* modifier                      key             function        argument */
	{ MODKEY1,                       XK_p,           spawn,          {.v = dmenucmd } },
	{ MODKEY2,                       XK_j,           spawn,          {.v = termcmd } },
	{ MODKEY2,                       XK_9,           spawn,          {.v = torrentcmd } },
	{ MODKEY1,                       XK_b,           togglebar,      {0} },
	{ MODKEY1,                       XK_j,           focusstack,     {.i = +1 } },
	{ MODKEY1,                       XK_k,           focusstack,     {.i = -1 } },
	{ MODKEY1,                       XK_i,           incnmaster,     {.i = +1 } },
	{ MODKEY1,                       XK_o,           incnmaster,     {.i = -1 } },
	{ MODKEY1,                       XK_h,           setmfact,       {.f = -0.05} },
	{ MODKEY1|MODKEY2,               XK_h,           setmfact,       {.f = -0.01} },
	{ MODKEY1,                       XK_l,           setmfact,       {.f = +0.05} },
	{ MODKEY1|MODKEY2,               XK_l,           setmfact,       {.f = +0.01} },
	{ MODKEY1,                       XK_Return,      zoom,           {0} },
	{ Mod1Mask,                      XK_Tab,         view,           {0} },
	{ MODKEY1|ShiftMask,             XK_c,           killclient,     {0} },
	{ MODKEY1,                       XK_t,           setlayout,      {.v = &layouts[0]} },
	{ MODKEY1,                       XK_y,           setlayout,      {.v = &layouts[1]} },
	{ MODKEY1,                       XK_u,           setlayout,      {.v = &layouts[2]} },
	{ MODKEY1,                       XK_space,       setlayout,      {0} },
	{ MODKEY1|ShiftMask,             XK_space,       togglefloating, {0} },
	{ MODKEY1,                       XK_0,           view,           {.ui = ~0 } },
	{ MODKEY1|ShiftMask,             XK_0,           tag,            {.ui = ~0 } },
	{ MODKEY1,                       XK_comma,       focusmon,       {.i = -1 } },
	{ MODKEY1,                       XK_period,      focusmon,       {.i = +1 } },
	{ MODKEY1|ShiftMask,             XK_comma,       tagmon,         {.i = -1 } },
	{ MODKEY1|ShiftMask,             XK_period,      tagmon,         {.i = +1 } },
	TAGKEYS(                         XK_a,                           0)
	TAGKEYS(                         XK_s,                           1)
	TAGKEYS(                         XK_d,                           2)
	TAGKEYS(                         XK_f,                           3)
	TAGKEYS(                         XK_q,                           4)
	TAGKEYS(                         XK_w,                           5)
	TAGKEYS(                         XK_e,                           6)
	TAGKEYS(                         XK_r,                           7)
	TAGKEYS(                         XK_z,                           8)
	{ MODKEY2,                       XK_F10,          quit,            {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask       button          function        argument */
	{ ClkLtSymbol,          0,               Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,               Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,               Button2,        zoom,           {0} },
	{ ClkStatusText,        0,               Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY1,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY1,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY1,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,               Button1,        view,           {0} },
	{ ClkTagBar,            0,               Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY1,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY1,         Button3,        toggletag,      {0} },
};

