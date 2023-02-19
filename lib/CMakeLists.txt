add_library(
        MP3_METADATA

        ImportantMethods.h

        Frames/Frame.h
        Frames/Frame.cpp
        Frames/FrameHeader.h
        Frames/FrameHeader.cpp

        Frames/Classes/UniqueFileIdentifierFrame.h
        Frames/Classes/UniqueFileIdentifierFrame.cpp
        Frames/Classes/TextInformationFrame.h
        Frames/Classes/TextInformationFrame.cpp
        Frames/Classes/UserDefinedTextInformationFrame.h
        Frames/Classes/UserDefinedTextInformationFrame.cpp
        Frames/Classes/URLLinkFrame.h
        Frames/Classes/URLLinkFrame.cpp
        Frames/Classes/UserDefinedURLLinkFrame.h
        Frames/Classes/UserDefinedURLLinkFrame.cpp
        Frames/Classes/MusicCD_ID_Frame.h
        Frames/Classes/MusicCD_ID_Frame.cpp
        Frames/Classes/EventTimingCodesFrame.h
        Frames/Classes/EventTimingCodesFrame.cpp
        Frames/Classes/UnsynchronisedTextTranscriptionFrame.h
        Frames/Classes/UnsynchronisedTextTranscriptionFrame.cpp
        Frames/Classes/SynchronisedTextFrame.h
        Frames/Classes/SynchronisedTextFrame.cpp
        Frames/Classes/CommentFrame.h
        Frames/Classes/CommentFrame.cpp
        Frames/Classes/RelativeVolumeAdjustment.h
        Frames/Classes/RelativeVolumeAdjustment.cpp
        Frames/Classes/EqualisationFrame.h
        Frames/Classes/EqualisationFrame.cpp
        Frames/Classes/PlayCounterFrame.h
        Frames/Classes/PlayCounterFrame.cpp
        Frames/Classes/PopularimeterFrame.h
        Frames/Classes/PopularimeterFrame.cpp
        Frames/Classes/RecommendedBufferSizeFrame.h
        Frames/Classes/RecommendedBufferSizeFrame.cpp
        Frames/Classes/LinkedInformation.h
        Frames/Classes/LinkedInformation.cpp
        Frames/Classes/PositionSynchronisationFrame.h
        Frames/Classes/PositionSynchronisationFrame.cpp
        Frames/Classes/TermsOfUseFrame.h
        Frames/Classes/TermsOfUseFrame.cpp
        Frames/Classes/OwnershipFrame.h
        Frames/Classes/OwnershipFrame.cpp
        Frames/Classes/CommercialFrame.h
        Frames/Classes/CommercialFrame.cpp
        Frames/Classes/EncryptionMethodRegistrationFrame.h
        Frames/Classes/EncryptionMethodRegistrationFrame.cpp
        Frames/Classes/GroupIdentificationRegistration.h
        Frames/Classes/GroupIdentificationRegistration.cpp
        Frames/Classes/PrivateFrame.h
        Frames/Classes/PrivateFrame.cpp
        Frames/Classes/SeekFrame.h
        Frames/Classes/SeekFrame.cpp

        Frames/Fabric/FrameFabric.h
        Frames/Fabric/FrameFabric.cpp


        StringFabric.h
        StringFabric.cpp

        MP3_Header.h
        MP3_Header.cpp
        MP3_Metadata.h
        MP3_Metadata.cpp
)