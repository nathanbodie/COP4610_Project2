#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int main()
{
    double test = 0;
    int rc, i;

    for (i = 1; i <= 5; i++)
    {
        rc = fork();
        if (rc == 0)
        {
            settickets(i * 10);
            for (;;)
            {
                test += 1;
            }
        }

        else if (rc < 0)
        {
            return -1;
        }

        // Collect information using getpinfo
        struct pstat stat;
        if (getpinfo(&stat) != -1)
        {
            // Print the elements of the pstat table
            for (int i = 0; i < NPROC; i++)
            {
                if (stat.inuse[i])
                {
                    printf(1, "PID: %d, Tickets: %d, Ticks: %d\n", stat.pid[i], stat.tickets[i], stat.ticks[i]);
                }
            }
        }
        else
        {
            printf(1, "Error in getpinfo\n");
        }
    }

    exit();
}