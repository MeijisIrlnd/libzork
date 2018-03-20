// Generated at 03-19-18 21:12:59
#pragma once
#include "objdefs.h"

#include <initializer_list>
#include <string>
typedef std::initializer_list<const char *> StringList;
struct GObjectDefinition {
    const char *name;
    StringList syns;
    StringList adj;
    const char *desc;
    std::initializer_list<Bits> bits;
    rapplic obj_fun;
    std::initializer_list<ObjectP> contents;
    std::initializer_list<OP> props;
};

const GObjectDefinition gobjects[] = {
{"", { "IT", "THAT", "THIS", "HIM" }, {  }, "random object", { ovison, ndescbit } },
{"", { "GBROC", "BROCH", "MAIL" }, { "FREE" }, "free brochure", { ovison } , obj_funcs::brochure},
{"", { "#####", "ME", "CRETI", "MYSEL", "SELF" }, {  }, "cretin", { ovison, villain } , obj_funcs::cretin, { }, { OP(ksl_oglobal, 0), OP(ksl_oactor, oa_player) }},
{"", { "WISH", "BLESS" }, {  }, "wish", { ovison, ndescbit } },
{"", { "EVERY", "ALL" }, {  }, "everything", { ovison, takebit, ndescbit, no_check_bit, bunchbit } , obj_funcs::valuables_c},
{"", { "POSSE" }, {  }, "possessions", { ovison, takebit, ndescbit, no_check_bit, bunchbit } , obj_funcs::valuables_c},
{"", { "VALUA", "TREAS" }, {  }, "valuables", { ovison, takebit, ndescbit, no_check_bit, bunchbit } , obj_funcs::valuables_c},
{"", { "SAILO" }, {  }, "sailor", { ovison, ndescbit } },
{"", { "TEETH" }, {  }, "set of teeth", { ovison, ndescbit } },
{"", { "WALL", "WALLS" }, {  }, "wall", { ovison } , obj_funcs::wall_function},
{"", { "GWALL", "WALL" }, { "GRANI" }, "granite wall", { ovison } , obj_funcs::granite},
{"", { "GROUN", "EARTH", "SAND" }, {  }, "ground", { ovison, digbit } , obj_funcs::ground_function},
{"", { "GRUE" }, {  }, "lurking grue", { ovison } , obj_funcs::grue_function},
{"", { "HANDS", "HAND" }, { "BARE" }, "pair of hands", { ovison, ndescbit, toolbit } },
{"", { "LUNGS", "AIR" }, {  }, "breath", { ovison, ndescbit, toolbit } },
{"", { "AVIAT", "FLYER" }, {  }, "flyer", { ovison, ndescbit } },
{"", { "EXCEP", "BUT" }, {  }, "moby lossage", { ovison, ndescbit } },
{"WELLBIT", { "WELL" }, { "MAGIC" }, "well", { ovison, ndescbit } , obj_funcs::well_function},
{"ROPEBIT", { "SROPE", "ROPE", "PIECE" }, {  }, "piece of rope", { ovison, climbbit, no_check_bit } , obj_funcs::slide_rope},
{"SLIDEBIT", { "SLIDE", "CHUTE" }, {  }, "chute", { ovison} , obj_funcs::slide_function},
{"CPWALL", { "CPEWL", "WALL" }, { "EAST", "EASTE" }, "eastern wall", { ovison} , obj_funcs::cpwall_object},
{"CPWALL", { "CPWWL", "WALL" }, { "WEST", "WESTE" }, "western wall", { ovison} , obj_funcs::cpwall_object},
{"CPWALL", { "CPSWL", "WALL" }, { "SOUTH" }, "southern wall", { ovison} , obj_funcs::cpwall_object},
{"CPWALL", { "CPNWL", "WALL" }, { "NORTH" }, "northern wall", { ovison} , obj_funcs::cpwall_object},
{"CPLADDER", { "CPLAD", "LADDE" }, {  }, "ladder", { ovison} , obj_funcs::cpladder_object},
{"BIRDBIT", { "BIRD", "SONGB" }, { "SONG" }, "bird", { ovison, ndescbit } , obj_funcs::bird_object},
{"HOUSEBIT", { "HOUSE" }, { "WHITE" }, "white house", { ovison, ndescbit } , obj_funcs::house_function},
{"TREEBIT", { "TREE" }, {  }, "tree", { ovison, ndescbit } },
{"GUARDBIT", { "GUARD" }, {  }, "Guardian of Zork", { ovison, vicbit, villain } , obj_funcs::guardians},
{"ROSEBIT", { "ROSE", "COMPA" }, {  }, "compass rose", { ovison } },
{"MASTERBIT", { "MASTE", "KEEPE", "DUNGE" }, { "DUNGE" }, "dungeon master", { ovison, vicbit, actorbit } , obj_funcs::master_function, { }, { OP(ksl_odesc1, "The dungeon master is quietly leaning on his staff here."), OP(ksl_oactor, oa_master), OP(ksl_oglobal, 0) }},
{"MIRRORBIT", { "MIRRO", "STRUC" }, {  }, "mirror", { ovison } , obj_funcs::mirror_function},
{"PANELBIT", { "PANEL" }, {  }, "panel", { ovison } , obj_funcs::panel_function},
{"CHANBIT", { "CHANN" }, {  }, "stone channel", { ovison } },
{"WALL-ESWBIT", { "WEAST", "WALL" }, { "EAST", "EASTE" }, "eastern wall", { ovison, ndescbit } , obj_funcs::scolwall},
{"WALL-ESWBIT", { "WSOUT", "WALL" }, { "SOUTH" }, "southern wall", { ovison, ndescbit } , obj_funcs::scolwall},
{"WALL-ESWBIT", { "WWEST", "WALL" }, { "WEST", "WESTE" }, "western wall", { ovison, ndescbit } , obj_funcs::scolwall},
{"WALL-NBIT", { "WNORT", "WALL" }, { "NORTH" }, "northern wall", { ovison, ndescbit } , obj_funcs::scolwall},
{"RGWATER", { "GWATE", "WATER", "QUANT", "LIQUI", "H2O" }, {  }, "water", { drinkbit, ovison } , obj_funcs::water_function},
{"DWINDOW", { "WINDO" }, {  }, "window", { ovison} , nullptr},
};
