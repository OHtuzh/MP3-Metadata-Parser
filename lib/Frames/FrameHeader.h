#pragma once

#include "../ImportantMethods.h"

#include <istream>
#include <array>

namespace mp3_idv2_4 {
    class FrameHeader {
     public:
        explicit FrameHeader(std::istream& istream);

        [[nodiscard]] const std::string& GetFrameID() const noexcept;
        [[nodiscard]] uint32_t GetSize() const noexcept;

        [[nodiscard]] bool TagAlterPreservation() const noexcept;
        [[nodiscard]] bool FileAlterPreservation() const noexcept;
        [[nodiscard]] bool ReadOnly() const noexcept;
        [[nodiscard]] bool GroupingIdentity() const noexcept;
        [[nodiscard]] bool Compression() const noexcept;
        [[nodiscard]] bool Encryption() const noexcept;
        [[nodiscard]] bool Unsynchronisation() const noexcept;
        [[nodiscard]] bool DataLengthIndicator() const noexcept;
     private:
        std::string frame_id_;
        uint32_t size_;
        uint16_t flags_;
    };
}
