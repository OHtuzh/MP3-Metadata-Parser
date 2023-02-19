#include "EncryptionMethodRegistrationFrame.h"

namespace mp3_idv2_4 {
    EncryptionMethodRegistrationFrame::EncryptionMethodRegistrationFrame(const FrameHeader& frame_header,
                                                                         std::span<uint8_t> data)
        :
        Frame(frame_header) {
        auto zero_position = std::find(data.begin(), data.end(), 0);
        owner_identifier_ = std::string(data.begin(), zero_position);
        method_symbol_ = *(++zero_position);
        encryption_data_ = std::vector(zero_position + 1, data.end());
    }

    const std::string& EncryptionMethodRegistrationFrame::GetOwnerIdentifier() const {
        return owner_identifier_;
    }

    uint8_t EncryptionMethodRegistrationFrame::GetMethodSymbol() const {
        return method_symbol_;
    }

    const std::vector<uint8_t>& EncryptionMethodRegistrationFrame::GetEncryptionData() const {
        return encryption_data_;
    }
    void EncryptionMethodRegistrationFrame::GetInformation(std::ostream& out) {}
}