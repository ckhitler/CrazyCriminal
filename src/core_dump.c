#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

char tracebuf[4096] = "";
char *mstart = tracebuf;

int dbgprintf(const char *fmt, ...)
    __attribute__((__format__(__printf__, 1, 2)));

int dbgprintf(const char *fmt, ...)
{
    int n = 0;

    va_list ap;
    va_start(ap, fmt);

    int nchars = sizeof(tracebuf) - (mstart - tracebuf);

    if (nchars <= 2){
        mstart = tracebuf;
        nchars = sizeof(tracebuf);
    }

    n = vsnprintf(mstart, nchars, fmt, ap);
    mstart += n +1;

    va_end(ap);
    return n;
}

int defective(int x)
{
    int y = 1;
    dbgprintf("defective(%u)", x);
    if (x == 10){
        dbgprintf("time to corrupt the stack!");

        memset(&y, 0xa5, sizeof(y) + 128);
        dbgprintf("I'm still here; returning now.");
        return 0;
    }
    return defective(x+1);
}

int main (int argc, char *argv[])
{
    defective(1);
    dbgprintf("exiting...");
    return 0;
}

