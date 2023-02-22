#pragma once

#include "../Frame.h"

#include <span>
#include <vector>

namespace mp3_idv2_4 {

    class EncryptionMethodRegistrationFrame : public Frame {
     public:
        EncryptionMethodRegistrationFrame(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] const std::string& GetOwnerIdentifier() const;
        [[nodiscard]] uint8_t GetMethodSymbol() const;
        [[nodiscard]] const std::vector<uint8_t>& GetEncryptionData() const;

        void GetInformation(std::ostream& out) const override;
     private:
        std::string owner_identifier_;
        uint8_t method_symbol_;
        std::vector<uint8_t> encryption_data_;

    };

}