#pragma once

#include <cinttypes>

namespace mp3_idv2_4 {
    inline uint32_t SyncSafeIntToRegularInt(uint32_t sync_safe_integer) {
        return (sync_safe_integer & 0x000000FF) |
            ((sync_safe_integer & 0x0000FF00) >> 1) |
            ((sync_safe_integer & 0x00FF0000) >> 2) |
            ((sync_safe_integer & 0xFF000000) >> 3);
    }
}
