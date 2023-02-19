#include "StringFabric.h"

#include <codecvt>
#include <locale>

namespace mp3_idv2_4 {
    std::string CreateStringUTF_8(std::span<uint8_t> data, TextEncoding encoding) noexcept {
        std::u16string utf16_string;
        switch (encoding) {
            case TextEncoding::UTF_8:
            case TextEncoding::ISO_8859_1:
                return {data.begin(), data.end()};
            case TextEncoding::UTF_16:
            case TextEncoding::UTF_16BE:
                utf16_string = std::u16string(data.size() / 2 + 1, 0x0A);
                memcpy(reinterpret_cast<char*>(utf16_string.data()), data.data(), data.size());
                return std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}.to_bytes(utf16_string);
        }
    }
}