#include "MP3_Header.h"

namespace mp3_idv2_4 {

    MP3_Header::MP3_Header(std::istream& istream)
        :
        size_(0) {
        for (int i = 0; i < 3; ++i) {
            file_identifier_ += static_cast<char>(istream.get());
        }
        version_ = (static_cast<uint16_t>(istream.get()) << 8) + static_cast<uint16_t>(istream.get());
        flags_ = static_cast<uint8_t>(istream.get());

        for (int i = 0; i < 4; ++i) {
            size_ <<= 8;
            size_ += static_cast<uint16_t>(istream.get());
        }
        size_ = SyncSafeIntToRegularInt(size_);
        if (GetFileIdentifier() != "ID3") {
            throw -1; //TODO CUSTOM EXCEPTIONS
        }
    }

    const std::string& MP3_Header::GetFileIdentifier() const noexcept {
        return file_identifier_;
    }

    uint16_t MP3_Header::GetVersion() const noexcept {
        return version_;
    }

    uint32_t MP3_Header::GetSize() const noexcept {
        return size_;
    }

    bool MP3_Header::IsUnsynchronizationApplied() const noexcept {
        return flags_ & 0b1000000;
    }

    bool MP3_Header::IsExtendedHeaderProvided() const noexcept {
        return flags_ & 0b0100000;
    }

    bool MP3_Header::ExperimentalIndicator() const noexcept {
        return flags_ & 0b0010000;
    }

    bool MP3_Header::IsFooterProvided() const noexcept {
        return flags_ & 0b0001000;
    }

}