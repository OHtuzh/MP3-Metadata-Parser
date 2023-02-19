#pragma once

#include "../Frame.h"

#include <vector>
#include <span>

namespace mp3_idv2_4 {

    class PlayCounterFrame : public Frame {
     public:
        PlayCounterFrame(const FrameHeader& frame_header, std::span<uint8_t> data);
        [[nodiscard]] size_t GetCounter() const;

        void GetInformation(std::ostream& out) override;
     private:
        size_t counter_;

    };

}
