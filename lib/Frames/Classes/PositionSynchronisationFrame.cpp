#include "PositionSynchronisationFrame.h"

namespace mp3_idv2_4 {

    PositionSynchronisationFrame::PositionSynchronisationFrame(const FrameHeader& frame_header,
                                                               std::span<uint8_t> data)
        :
        Frame(frame_header),
        time_stamp_format_(static_cast<TimeStampFormat>(data[0])),
        position_(0) {

        for (int i = 1; i < data.size(); ++i) {
            position_ <<= 8;
            position_ += data[i];
        }
    }

    TimeStampFormat PositionSynchronisationFrame::GetTimeStampFormat() const {
        return time_stamp_format_;
    }

    uint64_t PositionSynchronisationFrame::GetPosition() const {
        return position_;
    }
    void PositionSynchronisationFrame::GetInformation(std::ostream& out) const {}
}