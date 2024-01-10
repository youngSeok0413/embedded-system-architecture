#include <stdint.h>

/*library include*/
#include "system.h"
#include "clock.h"

int main()
{
    flash_set_waitstates();
    rcc_init();
    systick_init(71);

    while(1)
    {
        ;
    }
    
    return 0;
}