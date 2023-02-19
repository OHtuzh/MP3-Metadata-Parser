#include "OwnershipFrame.h"

namespace mp3_idv2_4 {
    OwnershipFrame::OwnershipFrame(const FrameHeader& frame_header, std::span<uint8_t> data)
        :
        Frame(frame_header),
        encoding_(static_cast<TextEncoding>(data[0])) {
        auto zero_position = std::find(data.begin(), data.end(), 0);
        price_paid_ = std::string(data.begin() + 1, zero_position);
        for (int i = 1; i <= 8; i++) {
            date_of_purchase_ += static_cast<char>(*(zero_position + i));
        }
        seller_ = CreateStringUTF_8(std::span(zero_position + 9, data.end()), encoding_);
    }

    TextEncoding OwnershipFrame::GetEncoding() const {
        return encoding_;
    }

    const std::string& OwnershipFrame::GetPricePaid() const {
        return price_paid_;
    }

    const std::string& OwnershipFrame::GetDateOfPurchase() const {
        return date_of_purchase_;
    }

    const std::string& OwnershipFrame::GetSeller() const {
        return seller_;
    }

    void OwnershipFrame::GetInformation(std::ostream& out) {
        out << price_paid_ << std::endl << date_of_purchase_ << std::endl << seller_ << std::endl;
    }
}