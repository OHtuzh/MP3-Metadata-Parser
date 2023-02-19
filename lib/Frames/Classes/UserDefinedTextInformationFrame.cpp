#include "UserDefinedTextInformationFrame.h"

namespace mp3_idv2_4 {
    UserDefinedTextInformationFrame::
    UserDefinedTextInformationFrame(const FrameHeader& frame_header, std::span<uint8_t> data)
        :
        TextInformationFrame(frame_header, std::span(data.begin(), std::find(data.begin() + 1, data.end(), 0))),
        value_(CreateStringUTF_8(std::span(std::find(data.begin() + 1, data.end(), 0) + 1, data.end()),
                                 GetBaseEncoding())) {}

    const std::string& UserDefinedTextInformationFrame::GetValue() const noexcept {
        return value_;
    }
    void UserDefinedTextInformationFrame::GetInformation(std::ostream& out) {
        TextInformationFrame::GetInformation(out);
        out << value_ << std::endl;
    }
}