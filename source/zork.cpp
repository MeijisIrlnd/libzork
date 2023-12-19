#include "zork.h"
#include "stdafx.h"
#include <string>
#include "funcs.h"
#include "dung.h"
#include "rooms.h"
#include "globals.h"
#pragma warning(disable : 4244)
/* #include <boost/process.hpp>
#include <boost/dll.hpp> */
#pragma warning(default : 4244)
namespace Zork {


    int startZork(bool useQueue) {
        e_useQueue = useQueue;
        // Seems to just initialise the game?
        init_dung();
        save_it(true);
        bool restart = false;
        try {
            // event loop..
            rdcom();
        } catch (ExitException& e) {
            restart = e.restart_flag();
        }
        return restart;
    }
} // namespace Zork