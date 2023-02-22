#pragma once

#include "../Frame.h"

#include <span>
#include <vector>

namespace mp3_idv2_4 {

    class MusicCD_ID_Frame : public Frame{
     public:
        MusicCD_ID_Frame(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] const std::vector<uint8_t>& GetBinaryData() const noexcept;

        void GetInformation(std::ostream& out) const override;
     private:
        std::vector<uint8_t> binary_data_;
    };

}
