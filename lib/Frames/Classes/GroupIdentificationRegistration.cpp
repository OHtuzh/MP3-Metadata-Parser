#include "GroupIdentificationRegistration.h"

namespace mp3_idv2_4 {
    GroupIdentificationRegistration::GroupIdentificationRegistration(const FrameHeader& frame_header,
                                                                     std::span<uint8_t> data)
        :
        Frame(frame_header) {
        auto zero_position = std::find(data.begin(), data.end(), 0);
        owner_identifier_ = std::string(data.begin(), zero_position);
        group_symbol_ = *(++zero_position);
        group_dependent_data_ = std::vector<uint8_t>(zero_position + 1, data.end());
    }

    const std::string& GroupIdentificationRegistration::GetOwnerIdentifier() const {
        return owner_identifier_;
    }

    uint8_t GroupIdentificationRegistration::GetGroupSymbol() const {
        return group_symbol_;
    }

    const std::vector<uint8_t>& GroupIdentificationRegistration::GetGroupDependentData() const {
        return group_dependent_data_;
    }
    void GroupIdentificationRegistration::GetInformation(std::ostream& out) const {}
}