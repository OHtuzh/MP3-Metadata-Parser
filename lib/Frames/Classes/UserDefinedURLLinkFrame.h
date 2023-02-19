#pragma once

#include "URLLinkFrame.h"
#include "TextInformationFrame.h"

namespace mp3_idv2_4 {

    class UserDefinedURLLinkFrame : public URLLinkFrame {
     public:
        UserDefinedURLLinkFrame(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] const std::string& GetDescription() const noexcept;

        void GetInformation(std::ostream& out) override;
     private:
        std::string description_;
    };

}
