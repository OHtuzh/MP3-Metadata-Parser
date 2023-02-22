#pragma once

#include "../Frame.h"

#include <vector>
#include <span>

namespace mp3_idv2_4 {

    class GroupIdentificationRegistration : public Frame {
     public:
        GroupIdentificationRegistration(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] const std::string& GetOwnerIdentifier() const;
        [[nodiscard]] uint8_t GetGroupSymbol() const;
        [[nodiscard]] const std::vector<uint8_t>& GetGroupDependentData() const;

        void GetInformation(std::ostream& out) const override;
     private:
        std::string owner_identifier_;
        uint8_t group_symbol_;
        std::vector<uint8_t> group_dependent_data_;
    };

}
