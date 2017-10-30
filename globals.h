#pragma once

#include <limits>
#include <limits.h>
#include <string>
#include <bitset>
#include <chrono>
#include "defs.h"

int score_max();
void inc_score_max(int inc);
extern int eg_score_max;
const int bigfix = INT_MAX;
extern std::string inbuf;
extern std::string inbuf1;
const std::vector<std::string> &months();
extern std::chrono::steady_clock::time_point start_time;

extern ObjectP last_it;

enum FlagId
{
    null_flag,
    rug_moved,
    troll_flag,
    low_tide,
    dome_flag,
    glacier_flag,
    glacier_melt,
    echo_flag,
    riddle_flag,
    lld_flag,
    xb,
    xc,
    cyclops_flag,
    magic_flag,
    rainbow,
    gnome_door,
    carousel_flip,
    carousel_zoom,
    cage_solve,
    bank_solve,
    egg_solve,
    sing_song,
    cpsolve,
    palan_solve,
    slide_solve,
    light_load,
    egypt_flag,
    empty_handed,
    deflate,
    cpout,
    mirror_open,
    wood_open,
    grate_revealed,
    grunlock,
    end_game_flag,
    tell_flag,
    parse_won,
    lucky,
    no_obj_print,
    mr1,
    mr2,
    mrswpush,
    mud,
    brflag1,
    brflag2,
    brief_flag,
    super_brief,
    thief_engrossed,
    dead,
    zgnome,
    cpblock,
    cppush,
    dead_flag,
    gate_flag,
    mirror_mung,
    plook,
    ptouch,
    punlock,
    cage_top,
    on_pole,
    buoy_flag,
    bucket_top,
    blab,
    gnome_flag,
    folflag,
    inqstartflag,
    safe_flag,
    num_flag_bits
};

// Puzzle room
extern int cphere;
extern std::vector<ObjList> cpobjs;
extern std::vector<int> cpuvec;
typedef std::tuple<ObjectP, int> cpwall_val;
cpwall_val memq(ObjectP obj, const std::vector<cpwall_val> &v);
extern std::vector<cpwall_val> cpwalls;
std::bitset<num_flag_bits> &flags();

int load_max();
void load_max(int new_load);
