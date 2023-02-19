#pragma once

#include "../Frame.h"

#include <span>

namespace mp3_idv2_4 {

    class PositionSynchronisationFrame : public Frame {
     public:
        PositionSynchronisationFrame(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] TimeStampFormat GetTimeStampFormat() const;
        [[nodiscard]] uint64_t GetPosition() const;

        void GetInformation(std::ostream& out) override;
     private:
        TimeStampFormat time_stamp_format_;
        uint64_t position_;
    };

}
