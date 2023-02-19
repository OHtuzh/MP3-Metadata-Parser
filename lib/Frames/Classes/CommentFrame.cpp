#include "CommentFrame.h"

namespace mp3_idv2_4 {

    CommentFrame::CommentFrame(const FrameHeader& frame_header, std::span<uint8_t> data)
        : UnsynchronisedTextTranscriptionFrame(frame_header, data) {}
}
