#include "MP3_Metadata.h"
#include "Frames/Fabric/FrameFabric.h"

#include <span>

namespace mp3_idv2_4 {

    MP3_Metadata::MP3_Metadata(std::istream& istream) : MP3_Header(istream) {
        uint32_t left_size = GetSize();
        if (IsExtendedHeaderProvided()) {
            uint32_t extended_header_size;
            istream.get(reinterpret_cast<char*>(&extended_header_size), 4);
            extended_header_size = SyncSafeIntToRegularInt(extended_header_size);
            istream.ignore(extended_header_size - 4);
            left_size -= extended_header_size + 4;
        }
        while (left_size != 0) {
            try {
                frames_.push_back(CreateFrame(istream, left_size));
            } catch (...) {
                break;
            }
        }

    }

    const std::list<std::unique_ptr<Frame>>& MP3_Metadata::GetFrames() const {
        return frames_;
    }
}