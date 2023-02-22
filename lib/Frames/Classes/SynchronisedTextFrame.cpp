#include "SynchronisedTextFrame.h"

namespace mp3_idv2_4 {
    SynchronisedTextFrame::SynchronisedText::SynchronisedText(std::string text, uint32_t timing)
        :
        text_(std::move(text)),
        timing_(timing) {}

    const std::string& SynchronisedTextFrame::SynchronisedText::GetText() const {
        return text_;
    }
    uint32_t SynchronisedTextFrame::SynchronisedText::GetTiming() const {
        return timing_;
    }

    SynchronisedTextFrame::SynchronisedTextFrame(const FrameHeader& frame_header,
                                                 std::span<uint8_t> data)
        :
        Frame(frame_header),
        encoding_(static_cast<TextEncoding>(data[0])),
        language_({data[1], data[2], data[3]}),
        time_stamp_format_(static_cast<TimeStampFormat>(data[4])),
        content_type_(static_cast<ContentType>(data[5])) {

        size_t string_start = 6;

        for (size_t string_end = 6; string_end < data.size(); ++string_end) {
            if (data[string_end] == 0) {
                if (data.size() - string_end < 5) {
                    return;
                }
                uint32_t time = 0;
                for (size_t i = string_end + 1; i < string_end + 5; ++i) {
                    time <<= 8;
                    time += static_cast<uint32_t>(data[i]);
                }
                content_descriptor_.emplace_back(
                    CreateStringUTF_8(
                        std::span(data.begin() + string_start, data.begin() + string_end),
                        encoding_
                    ),
                    time
                );
                string_start = string_end + 1;
                string_end += 4;
            }
        }
    }

    const std::array<uint8_t, 3>& SynchronisedTextFrame::GetLanguage() const noexcept {
        return language_;
    }

    TimeStampFormat SynchronisedTextFrame::GetTimeStampFormat() const noexcept {
        return time_stamp_format_;
    }

    SynchronisedTextFrame::ContentType SynchronisedTextFrame::GetContentType() const noexcept {
        return content_type_;
    }

    const std::list<SynchronisedTextFrame::SynchronisedText>& SynchronisedTextFrame::GetContentDescriptor() const noexcept {
        return content_descriptor_;
    }
    void SynchronisedTextFrame::GetInformation(std::ostream& out) const {
        for (const auto& synch_text: content_descriptor_) {
            out << synch_text.GetTiming() << " | " << synch_text.GetText() << std::endl;
        }
    }
}
