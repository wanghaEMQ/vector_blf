#define BOOST_TEST_MODULE MostEthernetPkt
#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>

#include <Vector/BLF.h>

/* MOST_ETHERNET_PKT = 78 */
BOOST_AUTO_TEST_CASE(MostEthernetPkt)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/test_MostEthernetPkt.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::MOST_ETHERNET_PKT);
    Vector::BLF::MostEthernetPkt * obj = static_cast<Vector::BLF::MostEthernetPkt *>(ohb);

    /* ObjectHeaderBase */
    BOOST_CHECK_EQUAL(obj->signature, Vector::BLF::ObjectSignature);
    BOOST_CHECK_EQUAL(obj->headerSize, obj->calculateHeaderSize());
    BOOST_CHECK_EQUAL(obj->headerVersion, 1);
    BOOST_CHECK_EQUAL(obj->objectSize, obj->calculateObjectSize());
    BOOST_CHECK(obj->objectType == Vector::BLF::ObjectType::MOST_ETHERNET_PKT);

    /* ObjectHeader2 */
    BOOST_CHECK_EQUAL(obj->objectFlags, Vector::BLF::ObjectHeader2::ObjectFlags::TimeOneNans);
    BOOST_CHECK_EQUAL(obj->timeStampStatus, 0x22);
    BOOST_CHECK_EQUAL(obj->reservedObjectHeader2, 0x33);
    BOOST_CHECK_EQUAL(obj->objectVersion, 0);
    BOOST_CHECK_EQUAL(obj->objectTimeStamp, 0x4444444444444444);
    BOOST_CHECK_EQUAL(obj->originalTimeStamp, 0x5555555555555555);

    /* MostEthernetPkt */
    BOOST_CHECK_EQUAL(obj->channel, 0x1111);
    BOOST_CHECK_EQUAL(obj->dir, 0x22);
    BOOST_CHECK_EQUAL(obj->reservedMostEthernetPkt1, 0x33);
    BOOST_CHECK_EQUAL(obj->reservedMostEthernetPkt2, 0);
    BOOST_CHECK_EQUAL(obj->sourceMacAdr, 0x44444444);
    BOOST_CHECK_EQUAL(obj->destMacAdr, 0x55555555);
    BOOST_CHECK_EQUAL(obj->transferType, 0x66);
    BOOST_CHECK_EQUAL(obj->state, 0x77);
    BOOST_CHECK_EQUAL(obj->ackNack, 0x88);
    BOOST_CHECK_EQUAL(obj->reservedMostEthernetPkt3, 0x99);
    BOOST_CHECK_EQUAL(obj->crc, 0xAAAA);
    BOOST_CHECK_EQUAL(obj->pAck, 0xBB);
    BOOST_CHECK_EQUAL(obj->cAck, 0xCC);
    BOOST_CHECK_EQUAL(obj->reservedMostEthernetPkt4, 0);
    BOOST_CHECK_EQUAL(obj->pktDataLength, 3);
    BOOST_CHECK_EQUAL(obj->reservedMostEthernetPkt5, 0);
    BOOST_CHECK_EQUAL(obj->pktData[0], 4);
    BOOST_CHECK_EQUAL(obj->pktData[1], 5);
    BOOST_CHECK_EQUAL(obj->pktData[2], 6);

    delete ohb;

    /* read next */
    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::MOST_ETHERNET_PKT);

    delete ohb;

    file.close();
}