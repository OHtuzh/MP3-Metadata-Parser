#include "RecommendedBufferSizeFrame.h"

namespace mp3_idv2_4 {

    RecommendedBufferSizeFrame::RecommendedBufferSizeFrame(const FrameHeader& frame_header, std::span<uint8_t> data)
        :
        Frame(frame_header),
        buffer_size_(
            (static_cast<uint32_t>(data[0]) << 16) +
                (static_cast<uint32_t>(data[1]) << 8) +
                static_cast<uint32_t>(data[2])
        ),
        embedded_info_flag_(data[3]),
        offset_to_next_flag_(
            (static_cast<uint32_t>(data[0]) << 24) +
                (static_cast<uint32_t>(data[0]) << 16) +
                (static_cast<uint32_t>(data[1]) << 8) +
                static_cast<uint32_t>(data[2])
        ) {}

    uint32_t RecommendedBufferSizeFrame::GetBufferSize() const {
        return buffer_size_;
    }

    bool RecommendedBufferSizeFrame::IsEmbeddedInfoFlag() const {
        return embedded_info_flag_;
    }

    uint32_t RecommendedBufferSizeFrame::GetOffsetToNextFlag() const {
        return offset_to_next_flag_;
    }
    void RecommendedBufferSizeFrame::GetInformation(std::ostream& out) {}
}
