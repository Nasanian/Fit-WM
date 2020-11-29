//////////////////////////////////////////////////////////////////////////////////////////////////
// DDDDDDDDDDDDD      WWWWWWWW                           WWWWWWWWMMMMMMMM               MMMMMMMM /
// D::::::::::::DDD   W::::::W                           W::::::WM:::::::M             M:::::::M /
// D:::::::::::::::DD W::::::W                           W::::::WM::::::::M           M::::::::M /
// DDD:::::DDDDD:::::DW::::::W                           W::::::WM:::::::::M         M:::::::::M /
//   D:::::D    D:::::DW:::::W           WWWWW           W:::::W M::::::::::M       M::::::::::M /
//   D:::::D     D:::::DW:::::W         W:::::W         W:::::W  M:::::::::::M     M:::::::::::M /
//   D:::::D     D:::::D W:::::W       W:::::::W       W:::::W   M:::::::M::::M   M::::M:::::::M /
//   D:::::D     D:::::D  W:::::W     W:::::::::W     W:::::W    M::::::M M::::M M::::M M::::::M /
//   D:::::D     D:::::D   W:::::W   W:::::W:::::W   W:::::W     M::::::M  M::::M::::M  M::::::M /
//   D:::::D     D:::::D    W:::::W W:::::W W:::::W W:::::W      M::::::M   M:::::::M   M::::::M /
//   D:::::D     D:::::D     W:::::W:::::W   W:::::W:::::W       M::::::M    M:::::M    M::::::M /
//   D:::::D    D:::::D       W:::::::::W     W:::::::::W        M::::::M     MMMMM     M::::::M /
// DDD:::::DDDDD:::::D         W:::::::W       W:::::::W         M::::::M               M::::::M /
// D:::::::::::::::DD           W:::::W         W:::::W          M::::::M               M::::::M /
// D::::::::::::DDD              W:::W           W:::W           M::::::M               M::::::M /
// DDDDDDDDDDDDD                  WWW             WWW            MMMMMMMM               MMMMMMMM /
//////////////////////////////////////////////////////////////////////////////////////////////////


#include <X11/XF86keysym.h>
#include "gaplessgrid.c"
#include "movestack.c"

/* appearance */
static const unsigned int borderpx  = 4;        /* border pixel of windows */
//static const unsigned int gappx     = 64;
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const unsigned int gappih    = 0;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 0;       /* vert inner gap between windows */
static const unsigned int gappoh    = 0;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 0;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const char *fonts[]          = { "tewi:size=10" };
static const char dmenufont[]       =  "tewi:size=10";
static const char normbordercolor[] = "#140417";
static const char normbgcolor[]     = "#090408";
static const char normfgcolor[]     = "#6b6b6b";
static const char selbordercolor[]  = "#1A0E1C";
static const char selbgcolor[]      = "#090408";
static const char selfgcolor[]      = "#8ea5ac";
static const char dmsbcolor[]       = "#5b6da6";
static const char dmselcolor[]      = "#1A0E1C";
static const char dmfgcolor[]       = "#cbcad9";
static const int usealtbar          = 0;        /* 1 means use non-dwm status bar */
static const int usestartcmd        = 1;        /* 1 = use herb-like autostarting script. location can be modified/checked down below. */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *alttrayname      = "tray";    /* Polybar tray instance name */
static const char *altbarcmd        = "~/.config/polybar/launch.sh"; /* Alternate bar launch command */
static const char *startcmd         = "~/suckless/autostart/autorun"; /* Autostart your stuff */
static const char *ipcsockpath = "/tmp/dwm.sock";



static const char *colors[][3]      = {
	/*               fg           bg           border   */
	[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
	[SchemeSel] =  { selfgcolor,  selbgcolor,  selbordercolor },
};


/*Scratch padding*/
typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "200x60", "-e", "tmux", NULL };
const char *spcmd2[] = {"st", "-n", "spfm", "-g", "144x41", "-e", "ranger", NULL };
const char *spcmd3[] = {"keepassxc", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"urxvtc",      spcmd1},
	//{"spranger",    spcmd2},
	//{"keepassxc",   spcmd3},
};


/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const char pp_moni[]  = "pdfpc - presenter";
static const char pp_proj[]  = "pdfpc - presentation";

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */

  // class      instance    title       tags mask     iscentered  isfloating isterminal noswallow   monitor
	{ "Pulseeffects",  NULL,  NULL,        1 << 8,      0,           0,         0,        0,        1 },
	{ "Pavucontrol",   NULL,  NULL,        1 << 8,      0,           0,         0,        0,        1 },
	{ "corectrl",      NULL,  NULL,        1 << 7,      0,           0,         0,        0,        1 },
	{ "discord",       NULL,  NULL,        1,           0,           0,         0,        0,        1 },
	{ "Audacious",     NULL,  NULL,        1 << 1,      0,           0,         0,        0,        1 },
	{ "qutebrowser",   NULL,  NULL,        0,          0,           0,         1,        0,       -1 },
	{ "Thunar",        NULL,  NULL,        0,          0,          0,          1,        0,      -1 },
	{ NULL,		         "spterm",		NULL,		SPTAG(0),		      1,      -1,     1,          0,      -1 },
//{ NULL,		         NULL,	      NULL,		-1,       1,      -1,     1,      0,     -1 },
	//{ NULL,		  "spfm",		NULL,		SPTAG(1),		1,			 -1 },
	//{ NULL,		  "keepassxc",	NULL,		SPTAG(2),		0,			 -1 },
};


/* layout(s) */
static const float mfact     = 0.5;  /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
  { "###",      gaplessgrid },
  { "|M|",      centeredmaster },
  { "<M>",      centeredfloatingmaster },
  { .symbol = NULL,   .arrange = NULL    },
};

static const MonitorRule monrules[] = {
	/* monitor  tag  layout  mfact  nmaster  showbar  topbar */
	{  0,       9,   2,      -1,    -1,      -1,      -1     },
	{  0,       1,   0,      -1,    -1,      -1,      -1     },
	{  1,       1,   0,      -1,    -1,      -1,      -1     }, // use a different layout for the second monitor
	{  -1,      -1,  0,      -1,    -1,      -1,      -1     }, // default
};


/* key definitions */
#define MODKEY Mod1Mask
#define TK(KEY,TAG) \
	{ KeyPress, MODKEY,                         KEY,  view,        {.ui = 1 << TAG} }, \
/*	{ KeyPress, MODKEY|ControlMask,               KEY,  toggleview,  {.ui = 1 << TAG} },*/ \
	{ KeyPress, MODKEY|ShiftMask,             KEY,  tag,         {.ui = 1 << TAG} }, \
	{ KeyPress, MODKEY|ControlMask|ShiftMask,   KEY,  toggletag,   {.ui = 1 << TAG} }
#define RK(MASK,KEY,ACTION) \
	{ KeyPress, MASK,                           KEY,  ACTION,      {.i  = +1 } }, \
	{ KeyPress, MASK|ShiftMask,                 KEY,  ACTION,      {.i  = -1 } }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define ESHCMD(cmd) SHCMD("exec " cmd)

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
//static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-i", "-fn", dmenufont, "-nb", "#ffd1dc", "-nf", dmfgcolor, "-sb", dmsbcolor, "-sf", dmselcolor, "-l", "10", "-b", NULL };
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-i", "-fn", dmenufont, "-nb", "#ffd1dc", "-nf", dmfgcolor, "-sb", dmsbcolor, "-sf", dmselcolor, "-l", "10", "-b", NULL };

static const char *btmenu_connect[]  = { "btmenu", "-c", "::", "-i", "-l", "20", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *btmenu_disconnect[] = { "btmenu", "-d", "::", "-i", "-l", "20", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *clipmenu[]         = { "clipmenu", "-i", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *passmenu[]         = { "passmenu", "-i", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };

static Key keys[] = {

		     TK(                     XK_1,            0               ),
		     TK(                     XK_2,            1               ),
		     TK(                     XK_3,            2               ),
		     TK(                     XK_4,            3               ),
		     TK(                     XK_5,            4               ),
		     TK(                     XK_6,            5               ),
		     TK(                     XK_7,            6               ),
		     TK(                     XK_8,            7               ),
		     TK(                     XK_9,            8               ),
		     TK(                     XK_a,            SPTAG(0)        ),
//		     RK( MODKEY|ControlMask, XK_comma,        pushstack       ),
//		     RK( MODKEY,             XK_Up,         focusstack      ),
//		     RK( MODKEY,             XK_Down,        focusstack      ),
//		     RK( MODKEY,             XK_Left,           focusmon        ),
//		     RK( MODKEY,             XK_Right,         focusmon        ),

	{ KeyPress,   MODKEY,   XK_Left,                 focusstack,         {.i = -1 } },
	{ KeyPress,   MODKEY,   XK_Right,                focusstack,         {.i = +1 } },

	{ KeyPress,   MODKEY,   XK_Up,                 focusmon,         {.i = -1 } },
	{ KeyPress,   MODKEY,   XK_Down,                focusmon,         {.i = +1 } },

	{ KeyPress,   MODKEY|ShiftMask,   XK_Up,                 pushstack,         {0} },
  { KeyPress,   MODKEY|ShiftMask,   XK_Up,                 tagmon,         {.i = -1 } },
	{ KeyPress,   MODKEY|ShiftMask,   XK_Down,               tagmon,         {.i = +1 } },

	{ KeyPress,   MODKEY|ShiftMask,   XK_Left,               pushstack,      {.i = -1 } },
	{ KeyPress,   MODKEY|ShiftMask,   XK_Right,              pushstack,      {.i = +1 } },

  { KeyPress,   MODKEY,             XK_d,                    spawn,          ESHCMD("dmenu_run -sb '#45303d' -nb '#09020b'  -fn 'tewi' -sf '#0d0d0d' -nf '#4f4f4f' -l 10 -b")},
	{ KeyPress,   MODKEY,             XK_2,                    spawn,          {.v = passmenu } },
	{ KeyPress,   MODKEY,             XK_3,                    spawn,          {.v = clipmenu } },
	{ KeyPress,   MODKEY,             XK_Return,               spawn,          ESHCMD("st -e tmux") },
	{ KeyPress,   MODKEY,            	XK_h,  	                 togglescratch,  {.ui = 0 } },
	{ KeyPress,   MODKEY,             XK_n,                    prevlayout,      {0} },
	{ KeyPress,   MODKEY,             XK_m,                    nextlayout,      {0} },
	{ KeyPress,   MODKEY,             XK_g,                    togglebar,       {0} },
	{ KeyPress,   MODKEY,             XK_o,                    setmfact,       {.f = -0.05} },
	{ KeyPress,   MODKEY,             XK_p,                    setmfact,       {.f = +0.05} },
	{ KeyPress,   MODKEY,             XK_u,                    setmfact,       {.f = 1.5} },  /* >1.0 sets absolute value */
  { KeyPress,   False,              XK_Print,                spawn,          ESHCMD("flameshot gui") },
  { KeyPress,   ShiftMask,          XK_Print,                redrawwin,      {0}},
	{ KeyPress,   MODKEY,             XK_r,                    spawn,          ESHCMD("nota-todo-reminder") },
	{ KeyPress,   MODKEY,             XK_Tab,                  zoom,           {0} },
	{ KeyPress,   MODKEY,             XK_BackSpace,            killclient,     {0} },

  //Gappy bois
	{ KeyPress,   MODKEY,             XK_minus,                incrigaps,        {.i = +2 } },
	{ KeyPress,   MODKEY|ShiftMask,   XK_minus,                incrigaps,        {.i = -2 } },
	{ KeyPress,   MODKEY,             XK_equal,                incrogaps,        {.i = +2 } },
  { KeyPress,   MODKEY|ShiftMask,   XK_equal,                incrogaps,        {.i = -2 } },
//  { KeyPress,   ControlMask,        XK_Return,               smartgaps,        {0} },
  { KeyPress,   MODKEY|ControlMask, XK_Return,               smartgaps,        {.i = 0  } },

  //MoveStack
  { KeyPress,   MODKEY|ShiftMask,    XK_j,                   movestack,        {.i = +1 } },
  { KeyPress,   MODKEY|ShiftMask,    XK_k,                   movestack,        {.i = -1 } },


  /*
  { KeyPress,   MODKEY,             XK_minus,                gappih,        {.i = +2 } },
	{ KeyPress,   MODKEY|ShiftMask,   XK_minus,                gappih,        {.i = -2 } },
	{ KeyPress,   MODKEY,             XK_equal,                gappoh,        {.i = +2 } },
  { KeyPress,   MODKEY|ShiftMask,   XK_equal,                gappoh,        {.i = -2 } },
  { KeyPress,   MODKEY,             XK_0,                    gappiv,        {.i = +2 } },
  { KeyPress,   MODKEY|ShiftMask,   XK_0,                    gappiv,        {.i = -2 } },
  { KeyPress,   MODKEY,             XK_9,                    gappov,        {.i = +2 } },
  { KeyPress,   MODKEY|ShiftMask,   XK_9,                    gappov,        {.i = -2 } },
  */



	//{ KeyPress,   Mod1Mask,   XK_0,                    tag,            {.ui = ~0 } },
	{ KeyPress,   Mod1Mask|ShiftMask,   XK_s,                    tag,            {.ui = ~0} },

	{ KeyPress,   MODKEY|ShiftMask,   XK_BackSpace,            killunsel,      {0} },
	{ KeyPress,   MODKEY,             XK_s,                    togglefloating, {0} },
	{ KeyPress,   MODKEY,             XK_f,                    fullscreen,  {0} },
	{ KeyPress,   Mod1Mask|ShiftMask,           XK_q,                    spawn,          ESHCMD("xkill") },
	//{ KeyPress,   Mod1Mask|ShiftMask, XK_c,                    killclient,     {0} },
	{ KeyPress,   Mod1Mask|ShiftMask, XK_r,                    quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

/*
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  spawn,               1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};
*/
/*vim: set noexpandtab: */
