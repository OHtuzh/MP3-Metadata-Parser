//
// Created by OHtuz on 2/19/2023.
//

#include "TermsOfUseFrame.h"

namespace mp3_idv2_4 {
    TermsOfUseFrame::TermsOfUseFrame(const FrameHeader& frame_header, std::span<uint8_t> data)
        :
        Frame(frame_header),
        encoding_(static_cast<TextEncoding>(data[0])),
        language_(
            (static_cast<uint32_t>(data[1]) << 16) +
                (static_cast<uint32_t>(data[2]) << 8) +
                static_cast<uint32_t>(data[3])
        ),
        actual_text_(CreateStringUTF_8(std::span(data.begin() + 4, data.end()), encoding_)) {}

    TextEncoding TermsOfUseFrame::GetEncoding() const {
        return encoding_;
    }

    uint32_t TermsOfUseFrame::GetLanguage() const {
        return language_;
    }

    const std::string& TermsOfUseFrame::GetActualText() const {
        return actual_text_;
    }
    void TermsOfUseFrame::GetInformation(std::ostream& out) {
        out << actual_text_ << std::endl;
    }
}
