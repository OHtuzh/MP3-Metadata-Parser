#pragma once

#include "FrameHeader.h"

#include <array>

namespace mp3_idv2_4 {
    enum class TimeStampFormat {
        kMPEGFramesAsUnit = 0x01,
        kMillisecondsAsUnit = 0x02
    };


    class Frame : public FrameHeader {
     public:
        explicit Frame(const FrameHeader& frame_header) noexcept;

        virtual void GetInformation(std::ostream& out) const = 0 ;
        virtual ~Frame() = default;
    };


}

std::ostream& operator<<(std::ostream& ostream, const mp3_idv2_4::Frame& frame);
