#include <string>
#include <array>
#include <ctime>

namespace time_service
{
    // Формат timestamp: DD.MM.YYYY HH:MM:SS
    static const std::string get_current_timestamp()
    {
        struct tm newtime { };
        const time_t now = time(nullptr);
        (void)localtime_s(&newtime, &now);
        std::array<char, 40> s = {0};
        (void)strftime(s.data(), 40, "%d.%m.%Y %H:%M:%S", &newtime);
        std::string timestamp = s.data();

        return timestamp;
    }
}