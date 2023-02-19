#pragma once

#include "../Frame.h"

#include <span>
#include <list>

namespace mp3_idv2_4 {

    class EventTimingCodesFrame : public Frame {
     public:
        enum class EventType {
            kPadding = 0x00,
            kEndOfInitialSilence = 0x01,
            kIntroStart = 0x02,
            kMainPartStart = 0x03,
            kOutroStart = 0x04,
            kOutroEnd = 0x05,
            kVerseStart = 0x06,
            kRefrainStart = 0x07,
            kInterludeStart = 0x08,
            kThemeStart = 0x09,
            kVariationStart = 0x0A,
            kKeyChange = 0x0B,
            kTimeChange = 0x0C,
            kMomentaryUnwantedNoise = 0x0D,
            kSustainedNoise = 0x0E,
            kSustainedNoiseEnd = 0x0F,
            kIntroEnd = 0x10,
            kMainPartEnd = 0x11,
            kVerseEnd = 0x12,
            kRefrainEnd = 0x13,
            kThemeEnd = 0x14,
            kProfanity = 0x15,
            kProfanityEnd = 0x16,
            // "reserved for future use" (0x17-0xDF) are not defined, because they are not in use
            kNotPredefinedSynch0 = 0xE0,
            kNotPredefinedSynch1 = 0xE1,
            kNotPredefinedSynch2 = 0xE2,
            kNotPredefinedSynch3 = 0xE3,
            kNotPredefinedSynch4 = 0xE4,
            kNotPredefinedSynch5 = 0xE5,
            kNotPredefinedSynch6 = 0xE6,
            kNotPredefinedSynch7 = 0xE7,
            kNotPredefinedSynch8 = 0xE8,
            kNotPredefinedSynch9 = 0xE9,
            kNotPredefinedSynchA = 0xEA,
            kNotPredefinedSynchB = 0xEB,
            kNotPredefinedSynchC = 0xEC,
            kNotPredefinedSynchD = 0xED,
            kNotPredefinedSynchE = 0xEE,
            kNotPredefinedSynchF = 0xEF,
            kAudioEnd = 0xFD,
            kAudioFileEnds = 0xFE,
            kOneMoreByteOfEventsFollows = 0xFF
        };

        class Event {
         public:
            explicit Event(std::span<uint8_t> data);
         private:
            EventType event_type_;
            uint32_t timing_;
        };

        EventTimingCodesFrame(const FrameHeader& frame_header, std::span<uint8_t> data);

        [[nodiscard]] TimeStampFormat GetTimeStampFormat() const noexcept;
        [[nodiscard]] const std::list<Event>& GetEvents() const noexcept;

        void GetInformation(std::ostream& out) override;
     private:
        TimeStampFormat time_stamp_format_;
        std::list<Event> events_;

    };

}
