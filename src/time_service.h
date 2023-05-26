#ifndef TIME_SERVICE_H
#define TIME_SERVICE_H

#include <string>
#include <time.h>

namespace time_service
{
    // Формат timestamp:: DD.MM.YYYY HH:MM:SS
    std::string get_current_timestamp()
    {
        struct tm newtime;
        time_t now = std::time(nullptr);
        localtime_s(&newtime,&now);

        char s[40];
        for (int i = 0; i < 40; ++i) 
        {
            s[i] = 0;
        }

        strftime(s, 40, "%d.%m.%Y %H:%M:%S", &newtime);
        std::string timestamp = s;

        return timestamp;
    }
}

#endif