#include "Frame.h"

namespace mp3_idv2_4 {
    Frame::Frame(const FrameHeader& frame_header) noexcept
        : FrameHeader(std::move(frame_header)) {}
}