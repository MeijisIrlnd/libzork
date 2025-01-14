#pragma once
#include "defs.h"

extern int water_level;

// Demons
bool robber(const HackP& dem);
bool sword_glow(const HackP& dem);
bool fighting(const HackP& dem);

bool advent();
bool alarm();
bool attacker();
bool bomb(ObjectP obj);
bool brush();
bool burner();
bool curses();
bool deflater();
void dput(std::string_view s);
bool dungeon();
bool eat();
bool exorcise();
bool fill();
bool hack_hack(ObjectP obj, std::string_view str, std::string_view obj2 = std::string_view());
bool hello();
bool infested(const RoomP& r);
bool inflater();
bool jargon();
bool kicker();
bool killer(std::string_view str);
inline bool killer() { return killer("kill"); }
bool leaper();
bool leave();
bool leaves_appear();
bool locker();
bool look_inside();
bool look_under();
bool melter();
bool munger();
bool oil();
bool open_close(const ObjectP& obj, std::string_view stropn, std::string_view strcls);
bool plugger();
bool pour_on();
bool prayer();
bool pumper();
bool pusher();
bool r_l();
bool reader();
bool repent();
bool ring();
bool rubber();
bool sinbad();
bool skipper();
bool squeezer();
bool swinger();
bool thief_in_treasure(ObjectP hobj);
bool tie();
bool tie_up();
bool torch_off(const ObjectP& t);
bool treas();
bool turner();
bool unlocker();
bool untie();
bool waver();
bool mumbler();
bool xb_cint();
bool xbh_cint();
bool xc_cint();
bool zork();

int otval_frob(const ObjList& l);
bool with_tell(ObjectP obj);
