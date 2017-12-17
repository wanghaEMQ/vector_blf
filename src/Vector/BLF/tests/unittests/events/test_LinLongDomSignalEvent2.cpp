#define BOOST_TEST_MODULE LinLongDomSignalEvent2
#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>

#include <Vector/BLF.h>

/* LIN_LONG_DOM_SIG2 = 75 */
BOOST_AUTO_TEST_CASE(LinLongDomSignalEvent2)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/test_LinLongDomSignalEvent2.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::LIN_LONG_DOM_SIG2);
    Vector::BLF::LinLongDomSignalEvent2 * obj = static_cast<Vector::BLF::LinLongDomSignalEvent2 *>(ohb);

    /* ObjectHeaderBase */
    BOOST_CHECK_EQUAL(obj->signature, Vector::BLF::ObjectSignature);
    BOOST_CHECK_EQUAL(obj->headerSize, obj->calculateHeaderSize());
    BOOST_CHECK_EQUAL(obj->headerVersion, 1);
    BOOST_CHECK_EQUAL(obj->objectSize, obj->calculateObjectSize());
    BOOST_CHECK(obj->objectType == Vector::BLF::ObjectType::LIN_LONG_DOM_SIG2);

    /* ObjectHeader */
    BOOST_CHECK_EQUAL(obj->objectFlags, Vector::BLF::ObjectHeader::ObjectFlags::TimeOneNans);
    BOOST_CHECK_EQUAL(obj->clientIndex, 0x1111);
    BOOST_CHECK_EQUAL(obj->objectVersion, 0);
    BOOST_CHECK_EQUAL(obj->objectTimeStamp, 0x2222222222222222);

    /* LinBusEvent */
    BOOST_CHECK_EQUAL(obj->sof, 0x1111111111111111);
    BOOST_CHECK_EQUAL(obj->eventBaudrate, 0x22222222);
    BOOST_CHECK_EQUAL(obj->channel, 0x3333);
    BOOST_CHECK_EQUAL(obj->reservedLinBusEvent, 0x4444);

    /* LinLongDomSignalEvent2 */
    BOOST_CHECK_EQUAL(obj->type, 0x11);
    BOOST_CHECK_EQUAL(obj->reservedLinLongDomSignalEvent[0], 0x22);
    BOOST_CHECK_EQUAL(obj->reservedLinLongDomSignalEvent[1], 0x33);
    BOOST_CHECK_EQUAL(obj->reservedLinLongDomSignalEvent[2], 0x44);
    BOOST_CHECK_EQUAL(obj->reservedLinLongDomSignalEvent[3], 0x55);
    BOOST_CHECK_EQUAL(obj->reservedLinLongDomSignalEvent[4], 0x66);
    BOOST_CHECK_EQUAL(obj->reservedLinLongDomSignalEvent[5], 0x77);
    BOOST_CHECK_EQUAL(obj->reservedLinLongDomSignalEvent[6], 0x88);
    BOOST_CHECK_EQUAL(obj->length, 0xAAAAAAAAAAAAAAAA);

    delete ohb;

    /* read next */
    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::LIN_LONG_DOM_SIG2);

    delete ohb;

    file.close();
}