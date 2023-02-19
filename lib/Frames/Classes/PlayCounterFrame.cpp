#include "PlayCounterFrame.h"

namespace mp3_idv2_4 {
    PlayCounterFrame::PlayCounterFrame(const FrameHeader& frame_header, std::span<uint8_t> data)
        :
        Frame(frame_header),
        counter_(0) {
        for (auto byte : data) {
            counter_ <<= 8;
            counter_ += byte;
        }
    }

    size_t PlayCounterFrame::GetCounter() const {
        return counter_;
    }
    void PlayCounterFrame::GetInformation(std::ostream& out) {}

}