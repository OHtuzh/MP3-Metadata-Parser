#pragma once

#include "../Frame.h"
#include "../../StringFabric.h"

#include <span>

namespace mp3_idv2_4 {

    class TermsOfUseFrame : public Frame {
     public:
        TermsOfUseFrame(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] TextEncoding GetEncoding() const;
        [[nodiscard]] uint32_t GetLanguage() const;
        [[nodiscard]] const std::string& GetActualText() const;

        void GetInformation(std::ostream& out) override;
     private:
        TextEncoding encoding_;
        uint32_t language_;
        std::string actual_text_;

    };

}
