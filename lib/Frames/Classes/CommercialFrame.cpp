#include "CommercialFrame.h"

namespace mp3_idv2_4 {
    CommercialFrame::CommercialFrame(const FrameHeader& frame_header, std::span<uint8_t> data)
        :
        Frame(frame_header),
        encoding_(static_cast<TextEncoding>(data[0])) {
        auto it = std::find(data.begin() + 1, data.end(), 0);
        price_string_ = std::string(data.begin() + 1, it);

        for (int i = 0; i < 8; ++i, ++it) {
            valid_until_ += static_cast<char>(*it);
        }
        auto end = std::find(it, data.end(), 0);
        contact_url_ = std::string(it, end);
        it = end + 1;
        received_as_ = static_cast<ReceivedType>(*it);

        ++it;
        end = std::find(it, data.end(), 0);
        name_of_seller_ = CreateStringUTF_8(std::span(it, end), encoding_);

        it = end + 1;
        end = std::find(it, data.end(), 0);
        description_ = CreateStringUTF_8(std::span(it, end), encoding_);

        it = end + 1;
        end = std::find(it, data.end(), 0);
        picture_MIME_type_ = std::string(it, end);

        seller_logo_ = std::vector(end + 1, data.end());
    }

    TextEncoding CommercialFrame::GetEncoding() const {
        return encoding_;
    }

    const std::string& CommercialFrame::GetPriceString() const {
        return price_string_;
    }

    const std::string& CommercialFrame::GetValidUntil() const {
        return valid_until_;
    }

    const std::string& CommercialFrame::GetContactUrl() const {
        return contact_url_;
    }

    CommercialFrame::ReceivedType CommercialFrame::GetReceivedAs() const {
        return received_as_;
    }

    const std::string& CommercialFrame::GetNameOfSeller() const {
        return name_of_seller_;
    }

    const std::string& CommercialFrame::GetDescription() const {
        return description_;
    }

    const std::string& CommercialFrame::GetPictureMimeType() const {
        return picture_MIME_type_;
    }

    const std::vector<uint8_t>& CommercialFrame::GetSellerLogo() const {
        return seller_logo_;
    }

    void CommercialFrame::GetInformation(std::ostream& out) {
        out << price_string_ << std::endl << valid_until_ << std::endl << contact_url_ << std::endl << name_of_seller_
            << std::endl << description_ << std::endl;
    }

}