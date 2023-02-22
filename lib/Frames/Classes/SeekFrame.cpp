#include "SeekFrame.h"

namespace mp3_idv2_4 {
    SeekFrame::SeekFrame(const FrameHeader& frame_header, std::span<uint8_t> data)
        :
        Frame(frame_header),
        minimum_offset_to_next_tag_(
            (static_cast<uint32_t>(data[0]) << 24) +
                (static_cast<uint32_t>(data[1]) << 16) +
                (static_cast<uint32_t>(data[2]) << 8) +
                static_cast<uint32_t>(data[3])
        ) {}

    uint32_t SeekFrame::GetMinimumOffsetToNextTag() const {
        return minimum_offset_to_next_tag_;
    }
    void SeekFrame::GetInformation(std::ostream& out) const {}
}