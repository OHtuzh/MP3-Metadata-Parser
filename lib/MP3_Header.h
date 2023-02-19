#pragma once

#include "ImportantMethods.h"

#include <string_view>
#include <istream>

namespace mp3_idv2_4 {

    class MP3_Header {
     public:
        explicit MP3_Header(std::istream& istream);

        [[nodiscard]] const std::string& GetFileIdentifier() const noexcept;

        [[nodiscard]] uint16_t GetVersion() const noexcept;
        [[nodiscard]] uint32_t GetSize() const noexcept;

        [[nodiscard]] bool IsUnsynchronizationApplied() const noexcept;
        [[nodiscard]] bool IsExtendedHeaderProvided() const noexcept;
        [[nodiscard]] bool ExperimentalIndicator() const noexcept;
        [[nodiscard]] bool IsFooterProvided() const noexcept;

     private:
        std::string file_identifier_;
        uint16_t version_;
        uint8_t flags_;
        uint32_t size_;
    };

}
