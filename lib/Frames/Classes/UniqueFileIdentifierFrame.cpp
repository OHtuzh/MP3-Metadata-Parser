//
// Created by OHtuz on 2/15/2023.
//

#include "UniqueFileIdentifierFrame.h"

#include <string>

namespace mp3_idv2_4 {
    UniqueFileIdentifierFrame::UniqueFileIdentifierFrame(const FrameHeader& frame_header, std::span<uint8_t> data_to_create_)
        :
        Frame(frame_header) {
        auto separator_position = std::find(data_to_create_.begin(), data_to_create_.end(), '\0');
        owner_identifier_ =
            std::string(data_to_create_.begin(), separator_position);
        identifier_ =
            std::vector(separator_position + 1, data_to_create_.end());
    }

    const std::string& UniqueFileIdentifierFrame::GetOwnerIdentifier() const {
        return owner_identifier_;
    }

    const std::vector<uint8_t>& UniqueFileIdentifierFrame::GetIdentifier() const {
        return identifier_;
    }
    void UniqueFileIdentifierFrame::GetInformation(std::ostream& out) const {}
}
