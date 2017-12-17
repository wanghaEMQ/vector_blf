#define BOOST_TEST_MODULE CanMessage
#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>

#include <Vector/BLF.h>

/* CAN_MESSAGE = 1 */
BOOST_AUTO_TEST_CASE(CanMessage)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/test_CanMessage.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::CAN_MESSAGE);
    Vector::BLF::CanMessage * obj = static_cast<Vector::BLF::CanMessage *>(ohb);

    /* ObjectHeaderBase */
    BOOST_CHECK_EQUAL(obj->signature, Vector::BLF::ObjectSignature);
    BOOST_CHECK_EQUAL(obj->headerSize, obj->calculateHeaderSize());
    BOOST_CHECK_EQUAL(obj->headerVersion, 1);
    BOOST_CHECK_EQUAL(obj->objectSize, obj->calculateObjectSize());
    BOOST_CHECK(obj->objectType == Vector::BLF::ObjectType::CAN_MESSAGE);

    /* ObjectHeader */
    BOOST_CHECK_EQUAL(obj->objectFlags, Vector::BLF::ObjectHeader::ObjectFlags::TimeOneNans);
    BOOST_CHECK_EQUAL(obj->clientIndex, 0x1111);
    BOOST_CHECK_EQUAL(obj->objectVersion, 0);
    BOOST_CHECK_EQUAL(obj->objectTimeStamp, 0x2222222222222222);

    /* CanMessage */
    BOOST_CHECK_EQUAL(obj->channel, 0x1111);
    BOOST_CHECK_EQUAL(obj->flags, 0x22);
    BOOST_CHECK_EQUAL(obj->dlc, 0x33);
    BOOST_CHECK_EQUAL(obj->id, 0x44444444);
    BOOST_CHECK_EQUAL(obj->data[0], 0x55);
    BOOST_CHECK_EQUAL(obj->data[1], 0x66);
    BOOST_CHECK_EQUAL(obj->data[2], 0x77);
    BOOST_CHECK_EQUAL(obj->data[3], 0x88);
    BOOST_CHECK_EQUAL(obj->data[4], 0x99);
    BOOST_CHECK_EQUAL(obj->data[5], 0xAA);
    BOOST_CHECK_EQUAL(obj->data[6], 0xBB);
    BOOST_CHECK_EQUAL(obj->data[7], 0xCC);

    delete ohb;

    /* read next */
    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::CAN_MESSAGE);

    delete ohb;

    file.close();
}