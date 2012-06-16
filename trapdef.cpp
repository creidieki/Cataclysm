#include "game.h"

void game::init_traps()
{
 int id = -1;
#define TRAP(name, sym, color, visibility, avoidance, difficulty, action, ...) \
id++;\
traps.push_back(new trap(id, sym, color, name, visibility, avoidance,\
                    difficulty, action, __VA_ARGS__));
 TRAP("none", '?', c_white, 20, 0, 0, &trapfunc::none, &trapfuncm::none,
      &trapfuncshoot::none,
      NULL);

//	Name			Symbol	Color		Vis Avd Diff
 TRAP("bubblewrap",		'_',	c_ltcyan,	 0,  8,  0,
      &trapfunc::bubble,	&trapfuncm::bubble, &trapfuncshoot::none, 
      itm_bubblewrap, NULL);


//	Name			Symbol	Color		Vis Avd Diff
 TRAP("cot",		'#',	c_green,	         0,  8,  0,
 &trapfunc::cot,	&trapfuncm::cot, &trapfuncshoot::none,
	itm_cot, NULL);

//	Name			Symbol	Color		Vis Avd Diff
 TRAP("bear trap",		'^',	c_blue,		 2,  7,  3,
 &trapfunc::beartrap,	&trapfuncm::beartrap, &trapfuncshoot::none,
	itm_beartrap, NULL);

//	Name			Symbol	Color		Vis Avd Diff
 TRAP("buried bear trap",	'^',	c_blue,		 9,  8,  4,
 &trapfunc::beartrap,	&trapfuncm::beartrap, &trapfuncshoot::none,
	itm_beartrap, NULL);

//	Name			Symbol	Color		Vis Avd Diff
 TRAP("rabbit snare",		'\\',	c_brown,	 5, 10,  2,
 &trapfunc::snare,	&trapfuncm::snare, &trapfuncshoot::none,
	itm_stick, itm_string_36, NULL);

 TRAP("spiked board",		'_',	c_ltgray,	 1,  6,  0,
 &trapfunc::board,	&trapfuncm::board, &trapfuncshoot::none,
	itm_board_trap, NULL);

 TRAP("tripwire",		'^',	c_ltred,	 6,  4,  3,
	&trapfunc::tripwire,	&trapfuncm::tripwire, &trapfuncshoot::none,
	itm_string_36, NULL);

 TRAP("crossbow trap",		'^',	c_green,	 5,  4,  5,
	&trapfunc::crossbow,	&trapfuncm::crossbow, &trapfuncshoot::none,
	itm_string_36, itm_crossbow, NULL);

 TRAP("shotgun trap",		'^',	c_red,		 4,  5,  6,// 2 shots
	&trapfunc::shotgun,	&trapfuncm::shotgun, &trapfuncshoot::none,
	itm_string_36, itm_shotgun_sawn, NULL);

 TRAP("shotgun trap",		'^',	c_red,		 4,  5,  6,// 1 shot
	&trapfunc::shotgun,	&trapfuncm::shotgun, &trapfuncshoot::none,
	itm_string_36, itm_shotgun_sawn, NULL);

 TRAP("spinning blade engine",	'_',	c_ltred,	 0,  0,  2,
	&trapfunc::none,	&trapfuncm::none, &trapfuncshoot::none,
	itm_motor, itm_machete, itm_machete, NULL);

 TRAP("spinning blade",		'\\',	c_cyan,		 0,  4, 99,
	&trapfunc::blade,	&trapfuncm::blade, &trapfuncshoot::none,
	NULL);

//	Name			Symbol	Color		Vis Avd Diff
 TRAP("land mine",		'_',	c_red,		10, 14, 10,
	&trapfunc::landmine,	&trapfuncm::landmine, &trapfuncshoot::landmine,
	itm_landmine, NULL);

//	Name			Symbol	Color		Vis Avd Diff
 TRAP("teleport pad",		'_',	c_magenta,	 0, 15, 20,
	&trapfunc::telepad,	&trapfuncm::telepad, &trapfuncshoot::none,
	itm_null, NULL);

//	Name			Symbol	Color		Vis Avd Diff
 TRAP("goo pit",		'_',	c_dkgray,	 0, 15, 15,
	&trapfunc::goo,		&trapfuncm::goo, &trapfuncshoot::none,
	itm_null, NULL);

//	Name			Symbol	Color		Vis Avd Diff
 TRAP("dissector",		'7',	c_cyan,		 2, 20, 99,
	&trapfunc::dissector,	&trapfuncm::dissector, &trapfuncshoot::none,
	itm_null, NULL);

//	Name			Symbol	Color		Vis Avd Diff
 TRAP("sinkhole",		'_',	c_brown,	10, 14, 99,
	&trapfunc::sinkhole,	&trapfuncm::sinkhole, &trapfuncshoot::none,
	itm_null, NULL);

 TRAP("pit",			'0',	c_brown,	 0,  8, 99,
	&trapfunc::pit,		&trapfuncm::pit, &trapfuncshoot::none,
	itm_null, NULL);

 TRAP("spiked pit",		'0',	c_blue,		 0,  8, 99,
	&trapfunc::pit_spikes,	&trapfuncm::pit_spikes, &trapfuncshoot::none,
	itm_null, NULL);

// The '%' symbol makes the portal cycle through ~*0&
//	Name			Symbol	Color		Vis Avd Diff
 TRAP("shimmering portal",	'%',	c_magenta,	 0, 30, 99,
	&trapfunc::portal,	&trapfuncm::portal, &trapfuncshoot::none,
	itm_null, NULL);

 TRAP("ledge",			' ',	c_black,	 0, 99, 99,
	&trapfunc::ledge,	&trapfuncm::ledge, &trapfuncshoot::none,
	itm_null, NULL);

 TRAP("boobytrap",		'^',	c_ltcyan,	 5,  4,  7,
 	&trapfunc::boobytrap,	&trapfuncm::boobytrap, &trapfuncshoot::none,
 	itm_null, NULL);

 TRAP("raised tile",		'^',	c_ltgray,	 9, 20, 99,
	&trapfunc::temple_flood,&trapfuncm::none, &trapfuncshoot::none,
	itm_null, NULL);

// Toggles through states of RGB walls
 TRAP("",			'^',	c_white,	99, 99, 99,
	&trapfunc::temple_toggle,	&trapfuncm::none, &trapfuncshoot::none,
	itm_null, NULL);

}
