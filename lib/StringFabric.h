#pragma once

#include <string>
#include <span>

namespace mp3_idv2_4 {

    enum class TextEncoding {
        ISO_8859_1 = 0x00,
        UTF_16 = 0x01,
        UTF_16BE = 0x02,
        UTF_8 = 0x03
    };

    [[nodiscard]] std::string CreateStringUTF_8(std::span<uint8_t> data, TextEncoding encoding) noexcept;

}
