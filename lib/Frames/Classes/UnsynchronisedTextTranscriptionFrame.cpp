//
// Created by OHtuz on 2/19/2023.
//

#include "UnsynchronisedTextTranscriptionFrame.h"

namespace mp3_idv2_4 {
    UnsynchronisedTextTranscriptionFrame::UnsynchronisedTextTranscriptionFrame(const FrameHeader& frame_header,
                                                                               std::span<uint8_t> data)
        :
        Frame(frame_header),
        encoding_(static_cast<TextEncoding>(data[0])),
        language_({data[1], data[2], data[3]}) {

        auto zero_position = std::find(data.begin() + 4, data.end(), 0);
        content_descriptor_ = CreateStringUTF_8(std::span(data.begin() + 4, zero_position), encoding_);
        content_descriptor_ = CreateStringUTF_8(std::span(zero_position + 1, data.end()), encoding_);
    }

    const std::array<uint8_t, 3>& UnsynchronisedTextTranscriptionFrame::GetLanguage() const {
        return language_;
    }

    const std::string& UnsynchronisedTextTranscriptionFrame::GetContentDescriptor() const {
        return content_descriptor_;
    }

    void UnsynchronisedTextTranscriptionFrame::GetInformation(std::ostream& out) {
        out << content_descriptor_ << std::endl;
    }

}
