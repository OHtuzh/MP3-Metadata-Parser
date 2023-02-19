#pragma once

#include "UnsynchronisedTextTranscriptionFrame.h"

namespace mp3_idv2_4 {

    class CommentFrame : public UnsynchronisedTextTranscriptionFrame {
     public:
        CommentFrame(const FrameHeader& frame_header, std::span<uint8_t> data);
    };

}
