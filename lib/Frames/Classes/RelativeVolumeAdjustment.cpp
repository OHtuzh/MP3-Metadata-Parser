#include "RelativeVolumeAdjustment.h"

namespace mp3_idv2_4 {
    RelativeVolumeAdjustment::Channel::Channel(RelativeVolumeAdjustment::ChannelType channel_type,
                                               uint16_t volume_adjustment,
                                               uint8_t bits_representing_peak,
                                               std::vector<uint8_t> peak_volume)
        :
        channel_type_(channel_type),
        volume_adjustment_(volume_adjustment),
        bits_representing_peak_(bits_representing_peak),
        peak_volume_(std::move(peak_volume)) {}

    RelativeVolumeAdjustment::ChannelType RelativeVolumeAdjustment::Channel::GetChannelType() const {
        return channel_type_;
    }

    uint16_t RelativeVolumeAdjustment::Channel::GetVolumeAdjustment() const {
        return volume_adjustment_;
    }

    uint8_t RelativeVolumeAdjustment::Channel::GetBitsRepresentingPeak() const {
        return bits_representing_peak_;
    }

    const std::vector<uint8_t>& RelativeVolumeAdjustment::Channel::GetPeakVolume() const {
        return peak_volume_;
    }
    RelativeVolumeAdjustment::RelativeVolumeAdjustment(const FrameHeader& frame_header, std::span<uint8_t> data)
        :
        Frame(frame_header) {
        auto zero_position = std::find(data.begin(), data.end(), 0);
        identification_ = std::string(data.begin(), zero_position);
        size_t current = zero_position - data.begin() + 1;
        for (; current + 4 < data.size(); ++current) {
            uint16_t volume_adjustment = (static_cast<uint16_t>(data[current + 1]) << 8) + static_cast<uint16_t>(data[current + 2]);
            uint8_t bits_representing_peak = static_cast<uint16_t>(data[current + 3]);
            uint8_t bytes_representing_peak = (bits_representing_peak + 7) / 8;
            if (current + 3 + bytes_representing_peak > data.size()) {
                return;
            }
            std::vector<uint8_t> peak_volume(data.begin() + current + 4, data.begin() + current + 4 + bytes_representing_peak);
            channels_.emplace_back(
                static_cast<ChannelType>(data[current]),
                volume_adjustment,
                bits_representing_peak,
                std::move(peak_volume)
            );
            current += 3 + bytes_representing_peak;
        }
    }
    const std::string& RelativeVolumeAdjustment::GetIdentification() const {
        return identification_;
    }
    const std::list<RelativeVolumeAdjustment::Channel>& RelativeVolumeAdjustment::GetChannels() const {
        return channels_;
    }
    void RelativeVolumeAdjustment::GetInformation(std::ostream& out) {}
}