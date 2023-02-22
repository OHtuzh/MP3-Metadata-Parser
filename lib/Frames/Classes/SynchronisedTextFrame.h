#pragma once

#include "../Frame.h"
#include "../../StringFabric.h"

#include <list>

namespace mp3_idv2_4 {

    class SynchronisedTextFrame : public Frame {
     public:
        enum class ContentType {
             kOther = 0x00,
             kLyrics = 0x01,
             kTextTranscription = 0x02,
             kPartName = 0x03,
             kEvents = 0x04,
             kChord = 0x05,
             kTriviaInformation = 0x06,
             kURLsToWebpages = 0x07,
             kURLsToImages = 0x08
        };

        class SynchronisedText {
         public:
            SynchronisedText(std::string text, uint32_t timing);

            [[nodiscard]] const std::string& GetText() const;
            [[nodiscard]] uint32_t GetTiming() const;
         private:
            std::string text_;
            uint32_t timing_;
        };

        SynchronisedTextFrame(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] const std::array<uint8_t, 3>& GetLanguage() const noexcept;
        [[nodiscard]] TimeStampFormat GetTimeStampFormat() const noexcept;
        [[nodiscard]] ContentType GetContentType() const noexcept;
        [[nodiscard]] const std::list<SynchronisedText>& GetContentDescriptor() const noexcept;

        void GetInformation(std::ostream& out) const override;
     private:
        TextEncoding encoding_;
        std::array<uint8_t, 3> language_;
        TimeStampFormat time_stamp_format_;
        ContentType content_type_;
        std::list<SynchronisedText> content_descriptor_;


    };

}
