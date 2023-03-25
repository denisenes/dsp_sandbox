#pragma once

#include "GlobalDecls.h"


class GlobalClock {
    public:
        inline static void tick() {
            clock++;
        }

        inline static smp_time_t getGlobalTime() {
            return clock;
        }

    private:
        static smp_time_t clock;
};