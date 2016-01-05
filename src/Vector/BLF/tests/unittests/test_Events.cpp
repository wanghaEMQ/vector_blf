#define BOOST_TEST_MODULE Events
#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>

#include <fstream>
#include <iterator>
#include <string>

#include "Vector/BLF.h"

/* UNKNOWN = 0 */

/* CAN_MESSAGE = 1 */
BOOST_AUTO_TEST_CASE(CanMessage)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/CanMessage.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::AfdxFrame * afdxFrame;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* CAN_ERROR = 2 */
BOOST_AUTO_TEST_CASE(CanErrorFrame)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/CanErrorFrame.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::CanErrorFrame * canErrorFrame;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* CAN_OVERLOAD = 3 */
BOOST_AUTO_TEST_CASE(CanOverloadFrame)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/CanOverloadFrame.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::CanOverloadFrame * canOverloadFrame;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* CAN_STATISTIC = 4 */
BOOST_AUTO_TEST_CASE(CanDriverStatistic)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/CanDriverStatistic.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::CanDriverStatistic * canDriverStatistic;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* APP_TRIGGER = 5 */
BOOST_AUTO_TEST_CASE(AppTrigger)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/AppTrigger.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::AppTrigger * appTrigger;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* ENV_INTEGER = 6 */
/* ENV_DOUBLE = 7 */
/* ENV_STRING = 8 */
/* ENV_DATA = 9 */
BOOST_AUTO_TEST_CASE(EnvironmentVariable)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/EnvironmentVariable.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::EnvironmentVariable * environmentVariable;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LOG_CONTAINER = 10 */
// LogContainer is indirectly tested

/* LIN_MESSAGE = 11 */
BOOST_AUTO_TEST_CASE(LinMessage)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinMessage.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinMessage * linMessage;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_CRC_ERROR = 12 */
BOOST_AUTO_TEST_CASE(LinCrcError)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinCrcError.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinCrcError * linCrcError;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_DLC_INFO = 13 */
BOOST_AUTO_TEST_CASE(LinDlcInfo)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinDlcInfo.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinDlcInfo * linDlcInfo;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_RCV_ERROR = 14 */
BOOST_AUTO_TEST_CASE(LinReceiveError)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinReceiveError.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinReceiveError * linReceiveError;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_SND_ERROR = 15 */
BOOST_AUTO_TEST_CASE(LinSendError)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinSendError.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinSendError * linSendError;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_SLV_TIMEOUT = 16 */
BOOST_AUTO_TEST_CASE(LinSlaveTimeout)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinSlaveTimeout.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinSlaveTimeout * linSlaveTimeout;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_SCHED_MODCH = 17 */
BOOST_AUTO_TEST_CASE(LinSchedulerModeChange)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinSchedulerModeChange.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinSchedulerModeChange * linSchedulerModeChange;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_SYN_ERROR = 18 */
BOOST_AUTO_TEST_CASE(LinSyncError)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinSyncError.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinSyncError * linSyncError;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_BAUDRATE = 19 */
BOOST_AUTO_TEST_CASE(LinBaudrateEvent)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinBaudrateEvent.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinBaudrateEvent * linBaudrateEvent;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_SLEEP = 20 */
BOOST_AUTO_TEST_CASE(LinSleepModeEvent)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinSleepModeEvent.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinSleepModeEvent * linSleepModeEvent;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_WAKEUP = 21 */
BOOST_AUTO_TEST_CASE(LinWakeupEvent)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinWakeupEvent.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinWakeupEvent * linWakeupEvent;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_SPY = 22 */
BOOST_AUTO_TEST_CASE(MostSpy)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostSpy.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostSpy * mostSpy;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_CTRL = 23 */
BOOST_AUTO_TEST_CASE(MostCtrl)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostCtrl.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostCtrl * mostCtrl;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_LIGHTLOCK = 24 */
BOOST_AUTO_TEST_CASE(MostLightLock)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostLightLock.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostLightLock * mostLightLock;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_STATISTIC = 25 */
BOOST_AUTO_TEST_CASE(MostStatistic)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostStatistic.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostStatistic * mostStatistic;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* reserved_1 = 26 */
/* reserved_2 = 27 */
/* reserved_3 = 28 */

/* FLEXRAY_DATA = 29 */
BOOST_AUTO_TEST_CASE(FlexRayData)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/FlexRayData.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::FlexRayData * flexRayData;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* FLEXRAY_SYNC = 30 */
BOOST_AUTO_TEST_CASE(FlexRaySync)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/FlexRaySync.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::FlexRaySync * flexRaySync;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* CAN_DRIVER_ERROR = 31 */
BOOST_AUTO_TEST_CASE(CanDriverError)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/CanDriverError.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::CanDriverError * canDriverError;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_PKT = 32 */
BOOST_AUTO_TEST_CASE(MostPkt)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostPkt.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostPkt * mostPkt;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_PKT2 = 33 */
BOOST_AUTO_TEST_CASE(MostPkt2)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostPkt2.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostPkt2 * mostPkt2;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_HWMODE = 34 */
BOOST_AUTO_TEST_CASE(MostHwMode)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostHwMode.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostHwMode * mostHwMode;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_REG = 35 */
BOOST_AUTO_TEST_CASE(MostReg)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostReg.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostReg * mostReg;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_GENREG = 36 */
BOOST_AUTO_TEST_CASE(MostGenReg)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostGenReg.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostGenReg * mostGenReg;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_NETSTATE = 37 */
BOOST_AUTO_TEST_CASE(MostNetState)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostNetState.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostNetState * mostNetState;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_DATALOST = 38 */
BOOST_AUTO_TEST_CASE(MostDataLost)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostDataLost.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostDataLost * mostDataLost;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_TRIGGER = 39 */
BOOST_AUTO_TEST_CASE(MostTrigger)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostTrigger.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostTrigger * mostTrigger;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* FLEXRAY_CYCLE = 40 */
BOOST_AUTO_TEST_CASE(FlexRayV6StartCycleEvent)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/FlexRayV6StartCycleEvent.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::FlexRayV6StartCycleEvent * flexRayV6StartCycleEvent;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* FLEXRAY_MESSAGE = 41 */
BOOST_AUTO_TEST_CASE(FlexRayV6Message)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/FlexRayV6Message.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::FlexRayV6Message * flexRayV6Message;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_CHECKSUM_INFO = 42 */
BOOST_AUTO_TEST_CASE(LinChecksumInfo)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinChecksumInfo.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinChecksumInfo * linChecksumInfo;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_SPIKE_EVENT = 43 */
BOOST_AUTO_TEST_CASE(LinSpikeEvent)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinSpikeEvent.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinSpikeEvent * linSpikeEvent;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* CAN_DRIVER_SYNC = 44 */
BOOST_AUTO_TEST_CASE(CanDriverHwSync)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/CanDriverHwSync.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::CanDriverHwSync * canDriverHwSync;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* FLEXRAY_STATUS = 45 */
BOOST_AUTO_TEST_CASE(FlexRayStatusEvent)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/FlexRayStatusEvent.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::FlexRayStatusEvent * flexRayStatusEvent;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* GPS_EVENT = 46 */
BOOST_AUTO_TEST_CASE(GpsEvent)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/GpsEvent.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::GpsEvent * gpsEvent;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* FR_ERROR = 47 */
BOOST_AUTO_TEST_CASE(FlexRayVFrError)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/FlexRayVFrError.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::FlexRayVFrError * flexRayVFrError;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* FR_STATUS = 48 */
BOOST_AUTO_TEST_CASE(FlexRayVFrStatus)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/FlexRayVFrStatus.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::FlexRayVFrStatus * flexRayVFrStatus;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* FR_STARTCYCLE = 49 */
BOOST_AUTO_TEST_CASE(FlexRayVFrStartCycle)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/FlexRayVFrStartCycle.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::FlexRayVFrStartCycle * flexRayVFrStartCycle;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* FR_RCVMESSAGE = 50 */
BOOST_AUTO_TEST_CASE(FlexRayVFrReceiveMsg)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/FlexRayVFrReceiveMsg.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::FlexRayVFrReceiveMsg * flexRayVFrReceiveMsg;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* REALTIMECLOCK = 51 */
BOOST_AUTO_TEST_CASE(RealtimeClock)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/RealtimeClock.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::RealtimeClock * realtimeClock;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* AVAILABLE2 = 52 */
/* AVAILABLE3 = 53 */

/* LIN_STATISTIC = 54 */
BOOST_AUTO_TEST_CASE(LinStatisticEvent)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinStatisticEvent.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinStatisticEvent * linStatisticEvent;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* J1708_MESSAGE = 55 */
/* J1708_VIRTUAL_MSG = 56 */
BOOST_AUTO_TEST_CASE(J1708Message)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/J1708Message.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::J1708Message * j1708Message;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_MESSAGE2 = 57 */
BOOST_AUTO_TEST_CASE(LinMessage2)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinMessage2.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinMessage2 * linMessage2;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_SND_ERROR2 = 58 */
BOOST_AUTO_TEST_CASE(LinSendError2)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinSendError2.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinSendError2 * linSendError2;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_SYN_ERROR2 = 59 */
BOOST_AUTO_TEST_CASE(LinSyncError2)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinSyncError2.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinSyncError2 * linSyncError2;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_CRC_ERROR2 = 60 */
BOOST_AUTO_TEST_CASE(LinCrcError2)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinCrcError2.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinCrcError2 * linCrcError2;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_RCV_ERROR2 = 61 */
BOOST_AUTO_TEST_CASE(LinReceiveError2)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinReceiveError2.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinReceiveError2 * linReceiveError2;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_WAKEUP2 = 62 */
BOOST_AUTO_TEST_CASE(LinWakeupEvent2)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinWakeupEvent2.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinWakeupEvent2 * linWakeupEvent2;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_SPIKE_EVENT2 = 63 */
BOOST_AUTO_TEST_CASE(LinSpikeEvent2)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinSpikeEvent2.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinSpikeEvent2 * linSpikeEvent2;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_LONG_DOM_SIG = 64 */
BOOST_AUTO_TEST_CASE(LinLongDomSignalEvent)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinLongDomSignalEvent.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinLongDomSignalEvent * linLongDomSignalEvent;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* APP_TEXT = 65 */
BOOST_AUTO_TEST_CASE(AppText)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/AppText.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::AppText * appText;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* FR_RCVMESSAGE_EX = 66 */
BOOST_AUTO_TEST_CASE(FlexRayVFrReceiveMsgEx)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/FlexRayVFrReceiveMsgEx.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::FlexRayVFrReceiveMsgEx * flexRayVFrReceiveMsgEx;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_STATISTICEX = 67 */
BOOST_AUTO_TEST_CASE(MostStatisticEx)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostStatisticEx.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostStatisticEx * mostStatisticEx;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_TXLIGHT = 68 */
BOOST_AUTO_TEST_CASE(MostTxLight)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostTxLight.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostTxLight * mostTxLight;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_ALLOCTAB = 69 */
BOOST_AUTO_TEST_CASE(MostAllocTab)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostAllocTab.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostAllocTab * mostAllocTab;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_STRESS = 70 */
BOOST_AUTO_TEST_CASE(MostStress)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostStress.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostStress * mostStress;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* ETHERNET_FRAME = 71 */
BOOST_AUTO_TEST_CASE(EthernetFrame)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/EthernetFrame.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::EthernetFrame * ethernetFrame;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* SYS_VARIABLE = 72 */
BOOST_AUTO_TEST_CASE(SystemVariable)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/SystemVariable.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::SystemVariable * systemVariable;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* CAN_ERROR_EXT = 73 */
BOOST_AUTO_TEST_CASE(CanErrorFrameExt)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/CanErrorFrameExt.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::CanErrorFrameExt * canErrorFrameExt;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* CAN_DRIVER_ERROR_EXT = 74 */
BOOST_AUTO_TEST_CASE(CanDriverErrorExt)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/CanDriverErrorExt.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::CanDriverErrorExt * canDriverErrorExt;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_LONG_DOM_SIG2 = 75 */
BOOST_AUTO_TEST_CASE(LinLongDomSignalEvent2)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinLongDomSignalEvent2.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinLongDomSignalEvent2 * linLongDomSignalEvent2;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_150_MESSAGE = 76 */
BOOST_AUTO_TEST_CASE(Most150Message)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/Most150Message.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::Most150Message * most150Message;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_150_PKT = 77 */
BOOST_AUTO_TEST_CASE(Most150Pkt)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/Most150Pkt.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::Most150Pkt * most150Pkt;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_ETHERNET_PKT = 78 */
BOOST_AUTO_TEST_CASE(MostEthernetPkt)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostEthernetPkt.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostEthernetPkt * mostEthernetPkt;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_150_MESSAGE_FRAGMENT = 79 */
BOOST_AUTO_TEST_CASE(Most150MessageFragment)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/Most150MessageFragment.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::Most150MessageFragment * most150MessageFragment;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_150_PKT_FRAGMENT = 80 */
BOOST_AUTO_TEST_CASE(Most150PktFragment)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/Most150PktFragment.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::Most150PktFragment * most150PktFragment;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_ETHERNET_PKT_FRAGMENT = 81 */
BOOST_AUTO_TEST_CASE(MostEthernetPktFragment)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostEthernetPktFragment.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostEthernetPktFragment * mostEthernetPktFragment;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_SYSTEM_EVENT = 82 */
BOOST_AUTO_TEST_CASE(MostSystemEvent)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostSystemEvent.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostSystemEvent * mostSystemEvent;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_150_ALLOCTAB = 83 */
BOOST_AUTO_TEST_CASE(Most150AllocTab)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/Most150AllocTab.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::Most150AllocTab * most150AllocTab;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_50_MESSAGE = 84 */
BOOST_AUTO_TEST_CASE(Most50Message)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/Most50Message.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::Most50Message * most50Message;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_50_PKT = 85 */
BOOST_AUTO_TEST_CASE(Most50Pkt)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/Most50Pkt.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::Most50Pkt * most50Pkt;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* CAN_MESSAGE2 = 86 */
BOOST_AUTO_TEST_CASE(CanMessage2)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/CanMessage2.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::CanMessage2 * canMessage2;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_UNEXPECTED_WAKEUP = 87 */
BOOST_AUTO_TEST_CASE(LinUnexpectedWakeup)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinUnexpectedWakeup.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinUnexpectedWakeup * linUnexpectedWakeup;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_SHORT_OR_SLOW_RESPONSE = 88 */
BOOST_AUTO_TEST_CASE(LinShortOrSlowResponse)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinShortOrSlowResponse.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinShortOrSlowResponse * linShortOrSlowResponse;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* LIN_DISTURBANCE_EVENT = 89 */
BOOST_AUTO_TEST_CASE(LinDisturbanceEvent)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/LinDisturbanceEvent.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::LinDisturbanceEvent * linDisturbanceEvent;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* SERIAL_EVENT = 90 */
BOOST_AUTO_TEST_CASE(SerialEvent)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/SerialEvent.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::SerialEvent * serialEvent;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* OVERRUN_ERROR = 91 */
BOOST_AUTO_TEST_CASE(DriverOverrun)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/DriverOverrun.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::DriverOverrun * driverOverrun;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* EVENT_COMMENT = 92 */
BOOST_AUTO_TEST_CASE(EventComment)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/EventComment.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::EventComment * eventComment;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* WLAN_FRAME = 93 */
BOOST_AUTO_TEST_CASE(WlanFrame)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/WlanFrame.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::WlanFrame * wlanFrame;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* WLAN_STATISTIC = 94 */
BOOST_AUTO_TEST_CASE(WlanStatistic)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/WlanStatistic.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::WlanStatistic * wlanStatistic;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* MOST_ECL = 95 */
BOOST_AUTO_TEST_CASE(MostEcl)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/MostEcl.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::MostEcl * mostEcl;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* GLOBAL_MARKER = 96 */
BOOST_AUTO_TEST_CASE(GlobalMarker)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/GlobalMarker.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::GlobalMarker * globalMarker;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::GLOBAL_MARKER);
    globalMarker = static_cast<Vector::BLF::GlobalMarker *>(ohb);
    BOOST_CHECK(globalMarker->commentedEventType == 0x00000000);
    BOOST_CHECK(globalMarker->foregroundColor == 0x00000000);
    BOOST_CHECK(globalMarker->backgroundColor == 0x00ffffff);
    BOOST_CHECK(globalMarker->isRelocatable == 1);
    // reserved1
    BOOST_CHECK(globalMarker->groupNameLength == 0x00000083);
    BOOST_CHECK(globalMarker->markerNameLength == 0x00000083);
    BOOST_CHECK(globalMarker->descriptionLength == 0x00000105);
    // groupName
    BOOST_CHECK(globalMarker->groupName == "Marker Group");
    BOOST_CHECK(globalMarker->markerName == "[1]");
    BOOST_CHECK(globalMarker->description == "description");

    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* AFDX_FRAME = 97 */
BOOST_AUTO_TEST_CASE(AfdxFrame)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/AfdxFrame.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::AfdxFrame * afdxFrame;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    BOOST_CHECK(afdxFrame->sourceAddress[1] == 0x00);
    BOOST_CHECK(afdxFrame->sourceAddress[2] == 0x00);
    BOOST_CHECK(afdxFrame->sourceAddress[3] == 0x00);
    BOOST_CHECK(afdxFrame->sourceAddress[4] == 0x00);
    BOOST_CHECK(afdxFrame->sourceAddress[5] == 0x04);
    BOOST_CHECK(afdxFrame->channel == 0x0001);
    BOOST_CHECK(afdxFrame->destinationAddress[0] == 0xff);
    BOOST_CHECK(afdxFrame->destinationAddress[1] == 0xff);
    BOOST_CHECK(afdxFrame->destinationAddress[2] == 0xff);
    BOOST_CHECK(afdxFrame->destinationAddress[3] == 0xff);
    BOOST_CHECK(afdxFrame->destinationAddress[4] == 0xff);
    BOOST_CHECK(afdxFrame->destinationAddress[5] == 0xff);
    BOOST_CHECK(afdxFrame->dir == Vector::BLF::AfdxFrame::Dir::Tx);
    BOOST_CHECK(afdxFrame->type == 0x0806);
    BOOST_CHECK(afdxFrame->tpid == 0x0000);
    BOOST_CHECK(afdxFrame->tci == 0x0000);
    BOOST_CHECK(afdxFrame->ethChannel == 0x01);
    // reserved1
    BOOST_CHECK(afdxFrame->afdxFlags == 0x0040);
    // reserved2
    BOOST_CHECK(afdxFrame->bagUsec == 0);
    BOOST_CHECK(afdxFrame->payLoadLength == 0x002e);
    // reserved3
    // @todo payLoad
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* AFDX_STATISTIC = 98 */
BOOST_AUTO_TEST_CASE(AfdxStatistic)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/AfdxStatistic.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::AfdxStatistic * afdxStatistic;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* KLINE_STATUSEVENT = 99 */
BOOST_AUTO_TEST_CASE(KLineStatusEvent)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/KLineStatusEvent.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::KLineStatusEvent * kLineStatusEvent;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* CAN_FD_MESSAGE = 100 */
BOOST_AUTO_TEST_CASE(CanFdMessage)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/CanFdMessage.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::CanFdMessage * canFdMessage;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* CAN_FD_MESSAGE_64 = 101 */
BOOST_AUTO_TEST_CASE(CanFdMessage64)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/CanFdMessage64.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::CanFdMessage64 * canFdMessage64;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* ETHERNET_RX_ERROR = 102 */
BOOST_AUTO_TEST_CASE(EthernetRxError)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/EthernetRxError.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::EthernetRxError * ethernetRxError;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* ETHERNET_STATUS = 103 */
BOOST_AUTO_TEST_CASE(EthernetStatus)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/EthernetStatus.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::EthernetStatus * ethernetStatus;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}

/* CAN_FD_ERROR_64 = 104 */
BOOST_AUTO_TEST_CASE(CanFdErrorFrame64)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/CanFdErrorFrame64.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    Vector::BLF::CanFdErrorFrame64 * canFdErrorFrame64;

    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    //BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::AFDX_FRAME);
    //afdxFrame = static_cast<Vector::BLF::AfdxFrame *>(ohb);
    // BOOST_CHECK(afdxFrame->sourceAddress[0] == 0x40);
    delete ohb;

    BOOST_CHECK(file.eof());
    file.close();
}