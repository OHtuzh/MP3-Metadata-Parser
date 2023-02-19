#pragma once

#include "PlayCounterFrame.h"

namespace mp3_idv2_4 {

    class PopularimeterFrame : public PlayCounterFrame {
     public:
        PopularimeterFrame(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] const std::string& GetEmail() const;
        [[nodiscard]] uint8_t GetRating() const;

     private:
        std::string email_;
        uint8_t rating_;

    };

}