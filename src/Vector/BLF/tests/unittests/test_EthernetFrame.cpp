#define BOOST_TEST_MODULE EthernetFrame
#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>

#include <Vector/BLF.h>

#if 0
/* ETHERNET_FRAME = 71 */
BOOST_AUTO_TEST_CASE(EthernetFrame_1) {
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events_from_binlog/test_EthernetFrame.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb = file.read();
    BOOST_REQUIRE(ohb);
    BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::ETHERNET_FRAME);
    auto * obj = dynamic_cast<Vector::BLF::EthernetFrame *>(ohb);

    /* ObjectHeaderBase */
    BOOST_CHECK_EQUAL(obj->signature, Vector::BLF::ObjectSignature);
    BOOST_CHECK_EQUAL(obj->headerSize, obj->calculateHeaderSize());
    BOOST_CHECK_EQUAL(obj->headerVersion, 1);
    BOOST_CHECK_EQUAL(obj->objectSize, obj->calculateObjectSize());
    BOOST_CHECK(obj->objectType == Vector::BLF::ObjectType::ETHERNET_FRAME);

    /* ObjectHeader */
    BOOST_CHECK_EQUAL(obj->objectFlags, Vector::BLF::ObjectHeader::ObjectFlags::TimeOneNans);
    BOOST_CHECK_EQUAL(obj->clientIndex, 0x1111);
    BOOST_CHECK_EQUAL(obj->objectVersion, 0);
    BOOST_CHECK_EQUAL(obj->objectTimeStamp, 0x2222222222222222);

    /* EthernetFrame */
    BOOST_CHECK_EQUAL(obj->sourceAddress[0], 0x11);
    BOOST_CHECK_EQUAL(obj->sourceAddress[1], 0x22);
    BOOST_CHECK_EQUAL(obj->sourceAddress[2], 0x33);
    BOOST_CHECK_EQUAL(obj->sourceAddress[3], 0x44);
    BOOST_CHECK_EQUAL(obj->sourceAddress[4], 0x55);
    BOOST_CHECK_EQUAL(obj->sourceAddress[5], 0x66);
    BOOST_CHECK_EQUAL(obj->channel, 0x7777);
    BOOST_CHECK_EQUAL(obj->destinationAddress[0], 0x88);
    BOOST_CHECK_EQUAL(obj->destinationAddress[1], 0x99);
    BOOST_CHECK_EQUAL(obj->destinationAddress[2], 0xAA);
    BOOST_CHECK_EQUAL(obj->destinationAddress[3], 0xBB);
    BOOST_CHECK_EQUAL(obj->destinationAddress[4], 0xCC);
    BOOST_CHECK_EQUAL(obj->destinationAddress[5], 0xDD);
    BOOST_CHECK_EQUAL(obj->dir, 0xEEEE);
    BOOST_CHECK_EQUAL(obj->type, 0xFFFF);
    BOOST_CHECK_EQUAL(obj->tpid, 0x1111);
    BOOST_CHECK_EQUAL(obj->tci, 0x2222);
    BOOST_CHECK_EQUAL(obj->payLoadLength, 3); // @todo should be 3+2
    // reserved
    BOOST_CHECK_EQUAL(obj->payLoad[0], 4);
    BOOST_CHECK_EQUAL(obj->payLoad[1], 5);
    BOOST_CHECK_EQUAL(obj->payLoad[2], 6);

    delete ohb;

    /* read next */
    ohb = file.read();
    BOOST_REQUIRE(ohb);
    BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::ETHERNET_FRAME);

    delete ohb;

    /* read last */
    ohb = file.read();
    BOOST_REQUIRE(ohb);
    BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::Unknown115);

    delete ohb;

    /* read last */
    ohb = file.read();
    BOOST_REQUIRE(ohb);
    BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::Unknown115);

    delete ohb;

    /* read eof */
    BOOST_REQUIRE(!file.eof());
    ohb = file.read();
    BOOST_REQUIRE(ohb == nullptr);
    BOOST_CHECK(file.eof());
    file.close();
}
#endif

BOOST_AUTO_TEST_CASE(EthernetFrame_2) {
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events_from_converter/test_EthernetFrame.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb = file.read();
    BOOST_REQUIRE(ohb);
    BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::ETHERNET_FRAME);
    auto * obj = dynamic_cast<Vector::BLF::EthernetFrame *>(ohb);

    /* ObjectHeaderBase */
    BOOST_CHECK_EQUAL(obj->signature, Vector::BLF::ObjectSignature);
    BOOST_CHECK_EQUAL(obj->headerSize, obj->calculateHeaderSize());
    BOOST_CHECK_EQUAL(obj->headerVersion, 1); // Vector bug: This should be 2 for ObjectHeader2
    BOOST_CHECK_EQUAL(obj->objectSize, obj->calculateObjectSize());
    BOOST_CHECK(obj->objectType == Vector::BLF::ObjectType::ETHERNET_FRAME);

    /* ObjectHeader */
    BOOST_CHECK_EQUAL(obj->objectFlags, Vector::BLF::ObjectHeader::ObjectFlags::TimeOneNans);
    // reserved
    BOOST_CHECK_EQUAL(obj->objectVersion, 0);
    BOOST_CHECK_EQUAL(obj->objectTimeStamp, 0); // ns

    /* EthernetFrame */
    BOOST_CHECK_EQUAL(obj->sourceAddress[0], 0x40);
    BOOST_CHECK_EQUAL(obj->sourceAddress[1], 0x00);
    BOOST_CHECK_EQUAL(obj->sourceAddress[2], 0x00);
    BOOST_CHECK_EQUAL(obj->sourceAddress[3], 0x00);
    BOOST_CHECK_EQUAL(obj->sourceAddress[4], 0x00);
    BOOST_CHECK_EQUAL(obj->sourceAddress[5], 0x04);
    BOOST_CHECK_EQUAL(obj->channel, 2);
    BOOST_CHECK_EQUAL(obj->destinationAddress[0], 0xff);
    BOOST_CHECK_EQUAL(obj->destinationAddress[1], 0xff);
    BOOST_CHECK_EQUAL(obj->destinationAddress[2], 0xff);
    BOOST_CHECK_EQUAL(obj->destinationAddress[3], 0xff);
    BOOST_CHECK_EQUAL(obj->destinationAddress[4], 0xff);
    BOOST_CHECK_EQUAL(obj->destinationAddress[5], 0xff);
    BOOST_CHECK_EQUAL(obj->dir, 1);
    BOOST_CHECK_EQUAL(obj->type, 0x0806);
    BOOST_CHECK_EQUAL(obj->tpid, 0x0000);
    BOOST_CHECK_EQUAL(obj->tci, 0x0000);
    BOOST_CHECK_EQUAL(obj->payLoadLength, 0x2e);
    // reserved
    BOOST_CHECK_EQUAL(obj->payLoad[0x00], 0x08);
    BOOST_CHECK_EQUAL(obj->payLoad[0x01], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x02], 0x06);
    BOOST_CHECK_EQUAL(obj->payLoad[0x03], 0x04);
    BOOST_CHECK_EQUAL(obj->payLoad[0x04], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x05], 0x01);
    BOOST_CHECK_EQUAL(obj->payLoad[0x06], 0x40);
    BOOST_CHECK_EQUAL(obj->payLoad[0x07], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x08], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x09], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x0a], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x0b], 0x04);
    BOOST_CHECK_EQUAL(obj->payLoad[0x0c], 0xc0);
    BOOST_CHECK_EQUAL(obj->payLoad[0x0d], 0xa8);
    BOOST_CHECK_EQUAL(obj->payLoad[0x0e], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x0f], 0x01);
    BOOST_CHECK_EQUAL(obj->payLoad[0x10], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x11], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x12], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x13], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x14], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x15], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x16], 0xc0);
    BOOST_CHECK_EQUAL(obj->payLoad[0x17], 0xa8);
    BOOST_CHECK_EQUAL(obj->payLoad[0x18], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x19], 0x01);
    BOOST_CHECK_EQUAL(obj->payLoad[0x1a], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x1b], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x1c], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x1d], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x1e], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x1f], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x20], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x21], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x22], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x23], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x24], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x25], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x26], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x27], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x28], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x29], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x2a], 0x00);
    BOOST_CHECK_EQUAL(obj->payLoad[0x2b], 0x00);

    delete ohb;

    /* read eof */
    BOOST_REQUIRE(!file.eof());
    ohb = file.read();
    BOOST_REQUIRE(ohb == nullptr);
    BOOST_CHECK(file.eof());
    file.close();
}
