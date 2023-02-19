#pragma once

#include "MP3_Header.h"
#include "Frames/Fabric/FrameFabric.h"

#include <list>

namespace mp3_idv2_4 {
    class MP3_Metadata : public MP3_Header {
     public:
        explicit MP3_Metadata(std::istream& istream);

        [[nodiscard]] const std::list<std::unique_ptr<Frame>>& GetFrames() const;
     private:

        std::list<std::unique_ptr<Frame>> frames_;
    };
}