
#include <ihttpd.hpp>
#include <daemon.hpp>

#include <unistd.h>

#define TRACE_DAEMON_DETAIL
#ifdef TRACE_DAEMON_DETAIL
#define TRX_(...) printf(__VA_ARGS__)
#else
#define TRX_(...)
#endif

IHTTPD::Daemon::Daemon(const std::string& hostname, ushort port, int tick_msec/*=100*/)
    : sp_(-1), running_(false),
      hostname_(hostname), port_(port), tick_msec_(tick_msec)
{
    
}

IHTTPD::Daemon::~Daemon()
{
}

bool IHTTPD::Daemon::run()
{
    running_ = true;

    while( running_ ) {
        // TRX_("working...\n");
        sleepmsec( tick_msec_);
    }

    return true;
}

void IHTTPD::Daemon::stop()
{
    running_ = false;
}
