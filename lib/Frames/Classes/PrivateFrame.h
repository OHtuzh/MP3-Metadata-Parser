#pragma once

#include "../Frame.h"

#include <vector>
#include <span>

namespace mp3_idv2_4 {

    class PrivateFrame : public Frame {
     public:
        PrivateFrame(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] const std::string& GetOwnerIdentifier() const;
        [[nodiscard]] const std::vector<uint8_t>& GetPrivateData() const;

        void GetInformation(std::ostream& out) const override;
     private:
        std::string owner_identifier_;
        std::vector<uint8_t> private_data_;

    };

}