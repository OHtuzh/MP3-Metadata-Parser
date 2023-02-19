#include "EventTimingCodesFrame.h"

namespace mp3_idv2_4 {
    EventTimingCodesFrame::Event::Event(std::span<uint8_t> data)
        :
        event_type_(static_cast<EventType>(data[0])),
        timing_(0) {
        for (int i = 1; i < 5; ++i) {
            timing_ <<= 8;
            timing_ += static_cast<uint32_t>(data[i]);
        }
    }

    EventTimingCodesFrame::EventTimingCodesFrame(const FrameHeader& frame_header, const std::span<uint8_t> data)
        :
        Frame(frame_header),
        time_stamp_format_(static_cast<TimeStampFormat>(data[0])) {

        for (size_t i = 1; i < data.size() - 4; i += 5) {
            events_.emplace_back(std::span(data.begin() + i, data.begin() + i + 5));
        }
    }

    TimeStampFormat EventTimingCodesFrame::GetTimeStampFormat() const noexcept {
        return time_stamp_format_;
    }

    const std::list<EventTimingCodesFrame::Event>& EventTimingCodesFrame::GetEvents() const noexcept {
        return events_;
    }
    void EventTimingCodesFrame::GetInformation(std::ostream& out) {}

}