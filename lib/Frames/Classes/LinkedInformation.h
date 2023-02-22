#pragma once

#include "../Frame.h"

#include <span>

namespace mp3_idv2_4 {

    class LinkedInformation : public Frame {
     public:
        LinkedInformation(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] const std::string& GetFrameIdentifier() const;
        [[nodiscard]] const std::string& GetUrl() const;
        [[nodiscard]] const std::string& GetIdAndAdditionalData() const;

        void GetInformation(std::ostream& out) const override;
     private:
        std::string frame_identifier_;
        std::string url_;
        std::string id_and_additional_data_;
    };

}