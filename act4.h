#pragma once
#include "defs.h"
#include "room.h"
#include "parser.h"

extern std::vector<QuestionP> qvec;
extern std::string spell_flag;
extern int mdir;

bool answer();
ObjectP beam_stopped();
void cell_move();
const std::string dpr(ObjectP obj);
inline void dopen(ObjectP obj) { tro(obj, openbit); }
inline void dclose(ObjectP obj) { trz(obj, openbit); }
bool eg_infested(RoomP r);
bool enter_end_game();
bool follow();
RoomP go_e_w(RoomP rm, direction dir);
bool incant();
bool inqstart();
bool inquisitor(Iterator<ParseContV> ans);
inline bool inquisitor() { return inquisitor(Iterator<ParseContV>()); }

typedef std::variant<std::monostate, bool, const char *> LookToVal;
enum { kltv_none, kltv_bool, kltv_string };
bool look_to(const std::string &nstr,
    std::optional<std::string> sstr = std::optional<std::string>(),
    LookToVal ntrll = LookToVal(),
    LookToVal stell = LookToVal(),
    bool htell = true);
bool mirblock(direction dir, int mdir);
RoomP mirew();
bool mirmove(bool northq, RoomP rm);
RoomP mirns(bool northq = (mdir < 180), bool exitq = false);
std::optional<int> mirror_here(RoomP rm);
bool mrgo();
bool start_end();
bool stats();
bool stay();
bool turnto();