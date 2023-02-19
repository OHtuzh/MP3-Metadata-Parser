#include "FrameFabric.h"
#include "../Classes/UniqueFileIdentifierFrame.h"
#include "../Classes/UserDefinedTextInformationFrame.h"
#include "../Classes/UserDefinedURLLinkFrame.h"
#include "../Classes/MusicCD_ID_Frame.h"
#include "../Classes/EventTimingCodesFrame.h"
#include "../Classes/UnsynchronisedTextTranscriptionFrame.h"
#include "../Classes/SynchronisedTextFrame.h"
#include "../Classes/CommentFrame.h"
#include "../Classes/RelativeVolumeAdjustment.h"
#include "../Classes/EqualisationFrame.h"
#include "../Classes/PlayCounterFrame.h"
#include "../Classes/PopularimeterFrame.h"
#include "../Classes/RecommendedBufferSizeFrame.h"
#include "../Classes/LinkedInformation.h"
#include "../Classes/PositionSynchronisationFrame.h"
#include "../Classes/TermsOfUseFrame.h"
#include "../Classes/OwnershipFrame.h"
#include "../Classes/CommercialFrame.h"
#include "../Classes/EncryptionMethodRegistrationFrame.h"
#include "../Classes/GroupIdentificationRegistration.h"
#include "../Classes/PrivateFrame.h"
#include "../Classes/SeekFrame.h"

#include <vector>

namespace mp3_idv2_4 {
    std::unique_ptr<Frame> CreateFrame(std::istream& istream, uint32_t& left) {
        FrameHeader frame_header(istream);
        std::vector<uint8_t> data(frame_header.GetSize());

        for (auto& v: data) {
            v = static_cast<uint8_t>(istream.get());
        }
        left = left - 10 - frame_header.GetSize();

        const auto frame_id = frame_header.GetFrameID();

        if (frame_id == "UFID") {
            return std::make_unique<UniqueFileIdentifierFrame>(frame_header, data);
        }
        if (frame_id.starts_with('T')) {
            if (frame_id == "TXXX") {
                return std::make_unique<UserDefinedTextInformationFrame>(frame_header, data);
            }
            return std::make_unique<TextInformationFrame>(frame_header, data);
        }
        if (frame_id.starts_with('W')) {
            if (frame_id == "WXXX") {
                return std::make_unique<UserDefinedURLLinkFrame>(frame_header, data);
            }
            return std::make_unique<URLLinkFrame>(frame_header, data);
        }
        if (frame_id == "MCDI") {
            return std::make_unique<MusicCD_ID_Frame>(frame_header, data);
        }
        if (frame_id == "ETCO") {
            return std::make_unique<EventTimingCodesFrame>(frame_header, data);
        }
        if (frame_id == "USLT") {
            return std::make_unique<UnsynchronisedTextTranscriptionFrame>(frame_header, data);
        }
        if (frame_id == "SYLT") {
            return std::make_unique<SynchronisedTextFrame>(frame_header, data);
        }
        if (frame_id == "COMM") {
            return std::make_unique<CommentFrame>(frame_header, data);
        }
        if (frame_id == "RVA2") {
            return std::make_unique<RelativeVolumeAdjustment>(frame_header, data);
        }
        if (frame_id == "EQU2") {
            return std::make_unique<EqualisationFrame>(frame_header, data);
        }
        if (frame_id == "PCNT") {
            return std::make_unique<PlayCounterFrame>(frame_header, data);
        }
        if (frame_id == "POPM") {
            return std::make_unique<PopularimeterFrame>(frame_header, data);
        }
        if (frame_id == "RBUF") {
            return std::make_unique<RecommendedBufferSizeFrame>(frame_header, data);
        }
        if (frame_id == "LINK") {
            return std::make_unique<LinkedInformation>(frame_header, data);
        }
        if (frame_id == "POSS") {
            return std::make_unique<PositionSynchronisationFrame>(frame_header, data);
        }
        if (frame_id == "USER") {
            return std::make_unique<TermsOfUseFrame>(frame_header, data);
        }
        if (frame_id == "OWNE") {
            return std::make_unique<OwnershipFrame>(frame_header, data);
        }
        if (frame_id == "COMR") {
            return std::make_unique<CommercialFrame>(frame_header, data);
        }
        if (frame_id == "ENCR") {
            return std::make_unique<EncryptionMethodRegistrationFrame>(frame_header, data);
        }
        if (frame_id == "GRID") {
            return std::make_unique<GroupIdentificationRegistration>(frame_header, data);
        }
        if (frame_id == "PRIV") {
            return std::make_unique<PrivateFrame>(frame_header, data);
        }
        if (frame_id == "SEEK") {
            return std::make_unique<SeekFrame>(frame_header, data);
        }

        return nullptr;
    }
}

