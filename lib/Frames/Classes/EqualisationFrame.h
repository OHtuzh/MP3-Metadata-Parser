#pragma once

#include "../Frame.h"

#include <list>
#include <span>

namespace mp3_idv2_4 {

    class EqualisationFrame : public Frame {
     public:
        enum class InterpolationMethod {
            kBand = 0x00,
            kLinear = 0x01
        };

        class AdjustmentPoint {
         public:
            AdjustmentPoint(uint16_t frequency, uint16_t volume_adjustment);

            [[nodiscard]] uint16_t GetFrequency() const;
            [[nodiscard]] uint16_t GetVolumeAdjustment() const;
         private:
            uint16_t frequency_;
            uint16_t volume_adjustment_;
        };

        EqualisationFrame(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] InterpolationMethod GetInterpolationMethod() const;
        [[nodiscard]] const std::string& GetIdentification() const;
        [[nodiscard]] const std::list<AdjustmentPoint>& GetAdjustmentPoints() const;

        void GetInformation(std::ostream& out) const override;
     private:
        InterpolationMethod interpolation_method_;
        std::string identification_;
        std::list<AdjustmentPoint> adjustment_points_;
    };

}
