//
// Created by OHtuz on 2/16/2023.
//

#include "TextInformationFrame.h"

namespace mp3_idv2_4 {
    TextInformationFrame::TextInformationFrame(const FrameHeader& frame_header, std::span<uint8_t> data_to_create_)
        :
        Frame(frame_header),
        encoding_(static_cast<TextEncoding>(data_to_create_[0])),
        description_utf8_(
            CreateStringUTF_8(std::span(data_to_create_.begin() + 1, data_to_create_.end()), encoding_)
        ) {}

    const std::string& TextInformationFrame::GetDescriptionUTF8() const noexcept {
        return description_utf8_;
    }
    TextEncoding TextInformationFrame::GetBaseEncoding() const noexcept {
        return encoding_;
    }
    void TextInformationFrame::GetInformation(std::ostream& out) {
        out << description_utf8_ << std::endl;
    }
}