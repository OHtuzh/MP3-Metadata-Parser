#pragma once

#include "../Frame.h"
#include "../../StringFabric.h"

#include <vector>
#include <span>

namespace mp3_idv2_4 {

    class CommercialFrame : public Frame {
     public:
        enum class ReceivedType {
            kOther = 0x00,
            kStandardCDAlbumWithOtherSongs = 0x01,
            kCompressedAudioOnCD = 0x02,
            kFileOverTheInternet = 0x03,
            kStreamOverTheInternet = 0x04,
            kAsNoteSheets = 0x05,
            kAsNoteSheetsInABookWithOtherSheets = 0x06,
            kMusicOnOtherMedia = 0x07,
            kNonMusicalMerchandise = 0x08
        };

        CommercialFrame(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] TextEncoding GetEncoding() const;
        [[nodiscard]] const std::string& GetPriceString() const;
        [[nodiscard]] const std::string& GetValidUntil() const;
        [[nodiscard]] const std::string& GetContactUrl() const;
        [[nodiscard]] ReceivedType GetReceivedAs() const;
        [[nodiscard]] const std::string& GetNameOfSeller() const;
        [[nodiscard]] const std::string& GetDescription() const;
        [[nodiscard]] const std::string& GetPictureMimeType() const;
        [[nodiscard]] const std::vector<uint8_t>& GetSellerLogo() const;

        void GetInformation(std::ostream& out) override;
     private:
        TextEncoding encoding_;
        std::string price_string_;
        std::string valid_until_;
        std::string contact_url_;
        ReceivedType received_as_;
        std::string name_of_seller_;
        std::string description_;
        std::string picture_MIME_type_;
        std::vector<uint8_t> seller_logo_;

    };

}
