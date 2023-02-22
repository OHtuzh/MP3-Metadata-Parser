#include "UserDefinedURLLinkFrame.h"

namespace mp3_idv2_4 {
    UserDefinedURLLinkFrame::UserDefinedURLLinkFrame(const FrameHeader& frame_header, std::span<uint8_t> data)
        :
        URLLinkFrame(frame_header, std::span(std::find(data.begin() + 1, data.end(), 0) + 1, data.end())),
        description_(
            CreateStringUTF_8(std::span(data.begin() + 1, std::find(data.begin() + 1, data.end(), 0)),
                              static_cast<TextEncoding>(data[0]))
        ) {}

    const std::string& UserDefinedURLLinkFrame::GetDescription() const noexcept {
        return description_;
    }
    void UserDefinedURLLinkFrame::GetInformation(std::ostream& out) const {
        URLLinkFrame::GetInformation(out);
        out << description_ << std::endl;
    }
}
