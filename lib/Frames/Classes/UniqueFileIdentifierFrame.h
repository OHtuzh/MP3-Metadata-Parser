#pragma once

#include "../Frame.h"

#include <vector>
#include <span>

namespace mp3_idv2_4 {

    class UniqueFileIdentifierFrame : public Frame {
     public:
        UniqueFileIdentifierFrame(const FrameHeader& frame_header, std::span<uint8_t> data_to_create_);

        [[nodiscard]] const std::string& GetOwnerIdentifier() const;
        [[nodiscard]] const std::vector<uint8_t>& GetIdentifier() const;

        void GetInformation(std::ostream& out) const override;
     private:
        std::string owner_identifier_;
        std::vector<uint8_t> identifier_;
    };

}
