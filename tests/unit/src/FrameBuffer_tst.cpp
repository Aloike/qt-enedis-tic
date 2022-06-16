#include <catch2/catch.hpp>

#include <enedisTIC/FrameBuffer.h>
#include <enedisTIC/transport/Frame.h>


//TEST_CASE( "Extraction of frames", "[qt]" )
//{
//    TIC::FrameBuffer    lFrameBuffer;

//    GIVEN("A valid frame")
//    {
//        auto iData  =   GENERATE(
//            as<std::string>{},
//            "\x02\x0a" "ADSC" "\x09" "031764248983" "\x09" "D" "\x0d\x03"
//        );
//        REQUIRE( iData.size() > 0 );

//        std::string iDataStr    = iData;


//        lFrameBuffer.append( iData );
////        lFrameBuffer.append( iDataStr );

//        FAIL("Unimplemented test!");
//    }


//    GIVEN("An invalid frame")
//    {
//        FAIL("Unimplemented test!");
//    }

//}

/* ########################################################################## */
/* ########################################################################## */

TEST_CASE( "TIC::FrameBuffer - Frame detection", "[TIC::FrameBuffer]" )
{
    const std::string c_validFrame1
        = "\x02\x0a" "RELAIS" "\x09" "001" "\x09" "C" "\x0d\x03";

    const std::string c_validFrame2
        = "\x02"
            "\x0a"
                "SINSTS" "\x09" "00181" "\x09" "P"
            "\x0d"
            "\x0a"
                "SMAXSN" "\x09" "E220603125338" "\x09" "02124" "\x09" "6"
            "\x0d"
          "\x03";

    TIC::FrameBuffer    lFrameBuffer;

    /* Check pre-conditions */
    INFO( "FrameBuffer must be empty." );
    REQUIRE( lFrameBuffer.hasFrames() == false );
    REQUIRE( lFrameBuffer.framesCount() == 0 );
    REQUIRE_THROWS( lFrameBuffer.popOne() );


    std::string iData;

    GIVEN( "One valid full frame" )
    {
        WHEN("Data is added to the buffer")
        {
            iData   = c_validFrame1;
            lFrameBuffer.append( iData );

            THEN("The FrameBuffer has extracted the frame to its list")
            {
                INFO("There should be exactly one frame in the list.");
                REQUIRE( lFrameBuffer.hasFrames() == true );
                REQUIRE( lFrameBuffer.framesCount() == 1 );


                INFO("The frame can be popped out of the buffer.");
                std::string oFrame  = lFrameBuffer.popOne();
                REQUIRE( oFrame == iData );

                INFO("Once the frame has been popped out of the buffer,"
                     " it isn't available anymore.");
                REQUIRE( lFrameBuffer.hasFrames() == false );
                REQUIRE( lFrameBuffer.framesCount() == 0 );
            }
        }


        WHEN("Frame is surrounded by invalid/incomplete data")
        {
            iData   = GENERATE_COPY(
                as<std::string>{},
                "1" + c_validFrame1,
                c_validFrame1 + "2",
                c_validFrame1.substr(0, 5) + c_validFrame1,
                c_validFrame1.substr(5, std::string::npos ) + c_validFrame1,
                c_validFrame1 + c_validFrame1.substr(0, 5),
                c_validFrame1 + c_validFrame1.substr(5, std::string::npos )
            );
            CAPTURE( iData );


            lFrameBuffer.append( iData );

            THEN("The FrameBuffer has extracted the frame to its list")
            {
                INFO("There should be exactly one frame in the list.");
                REQUIRE( lFrameBuffer.hasFrames() == true );
                REQUIRE( lFrameBuffer.framesCount() == 1 );


                INFO("The frame can be popped out of the buffer.");
                std::string oFrame  = lFrameBuffer.popOne();
                REQUIRE( oFrame == c_validFrame1 );

                INFO("Once the frame has been popped out of the buffer,"
                     " it isn't available anymore.");
                REQUIRE( lFrameBuffer.hasFrames() == false );
                REQUIRE( lFrameBuffer.framesCount() == 0 );
            }
        }
    } /*< GIVEN( "One valid full frame" ) */


    GIVEN( "Multiple valid frames" )
    {
        WHEN("Two consecutive valid frames are added at the same time")
        {
            iData   = c_validFrame1 + c_validFrame2;
            lFrameBuffer.append( iData );

            THEN("The FrameBuffer has extracted the two frame to its list")
            {
                INFO("There should be exactly two frames in the list.");
                REQUIRE( lFrameBuffer.hasFrames() == true );
                REQUIRE( lFrameBuffer.framesCount() == 2 );


                INFO("Frame are popped out of the buffer in the right order.");
                /* Pop first frame */
                std::string oFrame  = lFrameBuffer.popOne();
                REQUIRE( oFrame == c_validFrame1 );
                REQUIRE( lFrameBuffer.hasFrames() == true );
                REQUIRE( lFrameBuffer.framesCount() == 1 );

                /* Pop second frame */
                oFrame  = lFrameBuffer.popOne();
                REQUIRE( oFrame == c_validFrame2 );


                INFO("Once the two frames have been popped out of the buffer,"
                     " the buffer's frames list is empty.");
                REQUIRE( lFrameBuffer.hasFrames() == false );
                REQUIRE( lFrameBuffer.framesCount() == 0 );
            }
        }


        WHEN("Two consecutive valid frames are added part by part")
        {
            iData   = c_validFrame1 + c_validFrame2;

            for(size_t lPos = 0 ; lPos < iData.length() ; ++lPos )
            {
                lFrameBuffer.append( iData[lPos] );
            }

            THEN("The FrameBuffer has extracted the two frame to its list")
            {
                INFO("There should be exactly two frames in the list.");
                REQUIRE( lFrameBuffer.hasFrames() == true );
                REQUIRE( lFrameBuffer.framesCount() == 2 );


                INFO("Frame are popped out of the buffer in the right order.");
                /* Pop first frame */
                std::string oFrame  = lFrameBuffer.popOne();
                REQUIRE( oFrame == c_validFrame1 );
                REQUIRE( lFrameBuffer.hasFrames() == true );
                REQUIRE( lFrameBuffer.framesCount() == 1 );

                /* Pop second frame */
                oFrame  = lFrameBuffer.popOne();
                REQUIRE( oFrame == c_validFrame2 );


                INFO("Once the two frames have been popped out of the buffer,"
                     " the buffer's frames list is empty.");
                REQUIRE( lFrameBuffer.hasFrames() == false );
                REQUIRE( lFrameBuffer.framesCount() == 0 );
            }
        }


        WHEN("Two valid frames are separated by invalid data")
        {
            iData   = GENERATE_COPY(
                as<std::string>{},
                "1" + c_validFrame1 + c_validFrame2,
                c_validFrame1 + "2" + c_validFrame2,
                c_validFrame1 + c_validFrame2 + "3",

                c_validFrame1.substr(0, 5) + c_validFrame1 + c_validFrame2,
                c_validFrame1 + c_validFrame1.substr(0, 5) + c_validFrame2,
                c_validFrame1 + c_validFrame2 + c_validFrame1.substr(0, 5),

                c_validFrame1.substr(5, std::string::npos ) + c_validFrame1 + c_validFrame2,
                c_validFrame1 + c_validFrame1.substr(5, std::string::npos ) + c_validFrame2,
                c_validFrame1 + c_validFrame2 + c_validFrame1.substr(5, std::string::npos )
            );
            CAPTURE( iData );

            lFrameBuffer.append( iData );

            THEN("The FrameBuffer has extracted the two frame to its list")
            {
                INFO("There should be exactly two frames in the list.");
                REQUIRE( lFrameBuffer.hasFrames() == true );
                REQUIRE( lFrameBuffer.framesCount() == 2 );


                INFO("Frame are popped out of the buffer in the right order.");
                /* Pop first frame */
                std::string oFrame  = lFrameBuffer.popOne();
                REQUIRE( oFrame == c_validFrame1 );
                REQUIRE( lFrameBuffer.hasFrames() == true );
                REQUIRE( lFrameBuffer.framesCount() == 1 );

                /* Pop second frame */
                oFrame  = lFrameBuffer.popOne();
                REQUIRE( oFrame == c_validFrame2 );


                INFO("Once the two frames have been popped out of the buffer,"
                     " the buffer's frames list is empty.");
                REQUIRE( lFrameBuffer.hasFrames() == false );
                REQUIRE( lFrameBuffer.framesCount() == 0 );
            }
        }
    }   /*< GIVEN( "Multiple valid frames" ) */
}

/* ########################################################################## */
/* ########################################################################## */

//TEST_CASE( "test ordre" )
//{
//    WARN("begin");

//    GIVEN("A first branch")
//    {
//        WARN("branch 1");
//    }

//    GIVEN("A second branch")
//    {
//        WARN("branch 2");
//    }

//    WARN("end");
//}

/* ########################################################################## */
/* ########################################################################## */
