#include "PrivateFrame.h"

namespace mp3_idv2_4 {
    PrivateFrame::PrivateFrame(const FrameHeader& frame_header, std::span<uint8_t> data)
        :
        Frame(frame_header) {
        auto zero_position = std::find(data.begin(), data.end(), 0);
        owner_identifier_ = std::string(data.begin(), zero_position);
        private_data_ = std::vector(zero_position + 1, data.end());
    }

    const std::string& PrivateFrame::GetOwnerIdentifier() const {
        return owner_identifier_;
    }

    const std::vector<uint8_t>& PrivateFrame::GetPrivateData() const {
        return private_data_;
    }
    void PrivateFrame::GetInformation(std::ostream& out) const {}
}