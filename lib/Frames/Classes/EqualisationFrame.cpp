#include "EqualisationFrame.h"

namespace mp3_idv2_4 {

    EqualisationFrame::AdjustmentPoint::AdjustmentPoint(uint16_t frequency, uint16_t volume_adjustment)
        :
        frequency_(frequency),
        volume_adjustment_(volume_adjustment) {}

    uint16_t EqualisationFrame::AdjustmentPoint::GetFrequency() const {
        return frequency_;
    }

    uint16_t EqualisationFrame::AdjustmentPoint::GetVolumeAdjustment() const {
        return volume_adjustment_;
    }
    EqualisationFrame::EqualisationFrame(const FrameHeader& frame_header, std::span<uint8_t> data)
        :
        Frame(frame_header),
        interpolation_method_(static_cast<InterpolationMethod>(data[0])) {

        auto zero_position = std::find(data.begin(), data.end(), 0);
        identification_ = std::string(data.begin() + 1, zero_position);
        size_t current = (zero_position - data.begin()) + 1;
        for (; current + 4 < data.size(); current += 4) {
            adjustment_points_.emplace_back(
                (static_cast<uint16_t>(data[current]) << 8) + static_cast<uint16_t>(data[current + 1]),
                (static_cast<uint16_t>(data[current + 2]) << 8) + static_cast<uint16_t>(data[current + 3])
            );
        }
    }

    EqualisationFrame::InterpolationMethod EqualisationFrame::GetInterpolationMethod() const {
        return interpolation_method_;
    }

    const std::string& EqualisationFrame::GetIdentification() const {
        return identification_;
    }

    const std::list<EqualisationFrame::AdjustmentPoint>& EqualisationFrame::GetAdjustmentPoints() const {
        return adjustment_points_;
    }
    void EqualisationFrame::GetInformation(std::ostream& out) {}
}