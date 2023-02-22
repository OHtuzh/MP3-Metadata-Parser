#include "URLLinkFrame.h"

namespace mp3_idv2_4 {
    URLLinkFrame::URLLinkFrame(const FrameHeader& frame_header, std::span<uint8_t> data)
        :
        Frame(frame_header),
        url_(data.begin(), data.end()) {}

    const std::string& URLLinkFrame::GetURL() const noexcept {
        return url_;
    }
    void URLLinkFrame::GetInformation(std::ostream& out) const {
        out << url_ << std::endl;
    }
}
