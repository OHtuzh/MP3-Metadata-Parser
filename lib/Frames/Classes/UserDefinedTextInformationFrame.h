#pragma once

#include "TextInformationFrame.h"

namespace mp3_idv2_4 {

    class UserDefinedTextInformationFrame : public TextInformationFrame {
     public:
        UserDefinedTextInformationFrame(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] const std::string& GetValue() const noexcept;

        void GetInformation(std::ostream& out) override;
     private:
        std::string value_;
    };

}