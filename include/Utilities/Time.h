//
// Created by Roger on 6/11/2024.
//

#ifndef TIME_H
#define TIME_H

#include <chrono>

// Classe estàtica usada per mesuraments diversos de temps, com temps des d'inici d'execució o temps transcorregut des de l'últim frame
class Time
{
public:
    // Time in milliseconds since app start
    template <
    class result_t   = std::chrono::milliseconds,
    class clock_t    = std::chrono::steady_clock,
    class duration_t = std::chrono::milliseconds
>
[[nodiscard]] static auto since(std::chrono::time_point<clock_t, duration_t> const& start)
    {
        return std::chrono::duration_cast<result_t>(clock_t::now() - start);
    }
    
    [[nodiscard]] static long long GetTime();
    [[nodiscard]] static float GetDeltaTime();
    static void UpdateDeltaTime(std::chrono::duration<float> const& delta);
    
private:
    static std::chrono::duration<float> timeDelta;
    static std::chrono::time_point<std::chrono::steady_clock,std::chrono::milliseconds> startTime;
    static float timeScale;
};

#endif //TIME_H
