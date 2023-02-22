#include "Frame.h"

namespace mp3_idv2_4 {
    Frame::Frame(const FrameHeader& frame_header) noexcept
        : FrameHeader(frame_header) {}
}

std::ostream& operator<<(std::ostream& ostream, const mp3_idv2_4::Frame& frame) {
    frame.GetInformation(ostream);
    return ostream;
}
