#pragma once

#include "../Frame.h"

#include <span>

namespace mp3_idv2_4 {

    class SeekFrame : public Frame {
     public:
        SeekFrame(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] uint32_t GetMinimumOffsetToNextTag() const;

        void GetInformation(std::ostream& out) override;
     private:
        uint32_t minimum_offset_to_next_tag_;
    };

}