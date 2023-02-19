#pragma once

#include "../Frame.h"

#include <span>

namespace mp3_idv2_4 {

    class RecommendedBufferSizeFrame : public Frame {
     public:
        RecommendedBufferSizeFrame(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] uint32_t GetBufferSize() const;
        [[nodiscard]] bool IsEmbeddedInfoFlag() const;
        [[nodiscard]] uint32_t GetOffsetToNextFlag() const;

        void GetInformation(std::ostream& out) override;
     private:
        uint32_t buffer_size_;
        bool embedded_info_flag_;
        uint32_t offset_to_next_flag_;
    };

}
