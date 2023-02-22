#pragma once

#include "../Frame.h"

#include <span>

namespace mp3_idv2_4 {

    class URLLinkFrame : public Frame {
     public:
        URLLinkFrame(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] const std::string& GetURL() const noexcept;

        void GetInformation(std::ostream& out) const override;
     private:
        std::string url_;
    };

}