#pragma once

#include "../Frame.h"

#include <vector>
#include <list>
#include <span>

namespace mp3_idv2_4 {

    class RelativeVolumeAdjustment : public Frame {
     public:

        enum class ChannelType {
            kOther = 0x00,
            kMasterVolume = 0x01,
            kFrontRight = 0x02,
            kFrontLeft = 0x03,
            kBackRight = 0x04,
            kBackLeft = 0x05,
            kFrontCentre = 0x06,
            kBackCentre = 0x07,
            kSubwoofer = 0x08
        };

        class Channel {
         public:
            Channel(ChannelType channel_type,
                    uint16_t volume_adjustment,
                    uint8_t bits_representing_peak,
                    std::vector<uint8_t> peak_volume);

            [[nodiscard]] ChannelType GetChannelType() const;
            [[nodiscard]] uint16_t GetVolumeAdjustment() const;
            [[nodiscard]] uint8_t GetBitsRepresentingPeak() const;
            [[nodiscard]] const std::vector<uint8_t>& GetPeakVolume() const;

         private:
            ChannelType channel_type_;
            uint16_t volume_adjustment_;
            uint8_t bits_representing_peak_;
            std::vector<uint8_t> peak_volume_;
        };

        RelativeVolumeAdjustment(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] const std::string& GetIdentification() const;
        [[nodiscard]] const std::list<Channel>& GetChannels() const;

        void GetInformation(std::ostream& out) override;

     private:
        std::string identification_;
        std::list<Channel> channels_;

    };

}
