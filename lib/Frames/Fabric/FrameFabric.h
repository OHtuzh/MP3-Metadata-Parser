#pragma once

#include "../Frame.h"
#include "../FrameHeader.h"

#include "memory"

namespace mp3_idv2_4 {
    std::unique_ptr<Frame> CreateFrame(std::istream& istream, uint32_t& left);

}
