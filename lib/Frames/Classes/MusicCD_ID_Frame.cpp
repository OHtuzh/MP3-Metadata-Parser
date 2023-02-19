#include "MusicCD_ID_Frame.h"

namespace mp3_idv2_4 {

    MusicCD_ID_Frame::MusicCD_ID_Frame(const FrameHeader& frame_header, std::span<uint8_t> data)
        :
        Frame(frame_header),
        binary_data_(data.begin(), data.end()) {}

    const std::vector<uint8_t>& MusicCD_ID_Frame::GetBinaryData() const noexcept {
        return binary_data_;
    }

    void MusicCD_ID_Frame::GetInformation(std::ostream& out) {}
}