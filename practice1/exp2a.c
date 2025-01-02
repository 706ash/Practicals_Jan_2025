#include <stdio.h>
#include <utmp.h>
#include <time.h>
int main()
{
    struct utmp *n;
    setutent();
    n = getutent();
    
    while (n)
    {
        if(n->ut_type == USER_PROCESS)
        {
            time_t time = n->ut_tv.tv_sec;

            printf("%12s %9s (%s) %s", n->ut_user, n->ut_line, n->ut_host, ctime(&time));

            
        }
        n= getutent();

    }
    

    return 0;

}