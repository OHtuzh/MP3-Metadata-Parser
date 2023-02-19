#include "PopularimeterFrame.h"

namespace mp3_idv2_4 {
    PopularimeterFrame::PopularimeterFrame(const FrameHeader& frame_header, std::span<uint8_t> data)
        :
        PlayCounterFrame(
            frame_header,
            std::span(std::find(data.begin(), data.end(), 0) + 2, data.end())
        ) {
        auto zero_position = std::find(data.begin(), data.end(), 0);
        email_ = std::string(data.begin(), zero_position);
        rating_ = *(zero_position + 1);
    }

    const std::string& PopularimeterFrame::GetEmail() const {
        return email_;
    }

    uint8_t PopularimeterFrame::GetRating() const {
        return rating_;
    }
}
