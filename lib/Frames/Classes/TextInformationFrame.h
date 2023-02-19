#pragma once

#include "../Frame.h"
#include "../../StringFabric.h"

namespace mp3_idv2_4 {

    class TextInformationFrame : public Frame {
     public:
        TextInformationFrame(const FrameHeader& frame_header, std::span<uint8_t> data_to_create_);

        [[nodiscard]] const std::string& GetDescriptionUTF8() const noexcept;
        [[nodiscard]] TextEncoding GetBaseEncoding() const noexcept;

        void GetInformation(std::ostream& out) override;
     private:
        TextEncoding encoding_;
        std::string description_utf8_;
    };

}
