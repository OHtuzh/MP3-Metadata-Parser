#include "LinkedInformation.h"

namespace mp3_idv2_4 {

    LinkedInformation::LinkedInformation(const FrameHeader& frame_header, std::span<uint8_t> data)
        :
        Frame(frame_header),
        frame_identifier_(
            {
                static_cast<char>(data[0]),
                static_cast<char>(data[1]),
                static_cast<char>(data[2]),
                static_cast<char>(data[3])
            }
        ) {
        auto zero_position = std::find(data.begin() + 4, data.end(), 0);
        url_ = std::string(data.begin(), zero_position);
        id_and_additional_data_ = std::string(zero_position + 1, data.end());
    }

    const std::string& LinkedInformation::GetFrameIdentifier() const {
        return frame_identifier_;
    }

    const std::string& LinkedInformation::GetUrl() const {
        return url_;
    }

    const std::string& LinkedInformation::GetIdAndAdditionalData() const {
        return id_and_additional_data_;
    }
    void LinkedInformation::GetInformation(std::ostream& out) {}
}
