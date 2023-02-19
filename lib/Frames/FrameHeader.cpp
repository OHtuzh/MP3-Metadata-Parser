#include "FrameHeader.h"

namespace mp3_idv2_4 {
    FrameHeader::FrameHeader(std::istream& istream) : frame_id_(), size_(0), flags_(0) {
        for (int i = 0; i < 4; ++i) {
            frame_id_ += static_cast<char>(istream.get());
        }
        if (frame_id_[0] == 0) {
            throw -1;
        }
        for (int i = 0; i < 4; ++i) {
            size_ <<= 8;
            size_ += static_cast<uint8_t>(istream.get());
        }
        for (int i = 0; i < 2; ++i) {
            flags_ <<= 8;
            flags_ += static_cast<uint8_t>(istream.get());
        }
        size_ = SyncSafeIntToRegularInt(size_);
    }

    const std::string& FrameHeader::GetFrameID() const noexcept {
        return frame_id_;
    }

    uint32_t FrameHeader::GetSize() const noexcept {
        return size_;
    }

    [[nodiscard]] bool FrameHeader::TagAlterPreservation() const noexcept {
        return (flags_ >> 14) & 1;
    }

    [[nodiscard]] bool FrameHeader::FileAlterPreservation() const noexcept {
        return (flags_ >> 13) & 1;
    }

    [[nodiscard]] bool FrameHeader::ReadOnly() const noexcept {
        return (flags_ >> 12) & 1;
    }

    [[nodiscard]] bool FrameHeader::GroupingIdentity() const noexcept {
        return (flags_ >> 6) & 1;
    }

    [[nodiscard]] bool FrameHeader::Compression() const noexcept {
        return (flags_ >> 3) & 1;
    }

    [[nodiscard]] bool FrameHeader::Encryption() const noexcept {
        return (flags_ >> 2) & 1;
    }

    [[nodiscard]] bool FrameHeader::Unsynchronisation() const noexcept {
        return (flags_ >> 1) & 1;
    }

    [[nodiscard]] bool FrameHeader::DataLengthIndicator() const noexcept {
        return flags_ & 1;
    }
}
