#pragma once

#include "../Frame.h"
#include "../../StringFabric.h"

namespace mp3_idv2_4 {

    class UnsynchronisedTextTranscriptionFrame : public Frame {
     public:
        UnsynchronisedTextTranscriptionFrame(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] const std::array<uint8_t, 3>& GetLanguage() const;
        [[nodiscard]] const std::string& GetContentDescriptor() const;
        void GetInformation(std::ostream& out) const override;

     private:
        TextEncoding encoding_;
        std::array<uint8_t, 3> language_;
        std::string content_descriptor_;

    };

}
