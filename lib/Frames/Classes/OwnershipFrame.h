#pragma once

#include "../Frame.h"
#include "../../StringFabric.h"

#include <span>

namespace mp3_idv2_4 {

    class OwnershipFrame : public Frame {
     public:
        OwnershipFrame(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] TextEncoding GetEncoding() const;
        [[nodiscard]] const std::string& GetPricePaid() const;
        [[nodiscard]] const std::string& GetDateOfPurchase() const;
        [[nodiscard]] const std::string& GetSeller() const;

        void GetInformation(std::ostream& out) const override;
     private:
        TextEncoding encoding_;
        std::string price_paid_;
        std::string date_of_purchase_;
        std::string seller_;
    };

}
