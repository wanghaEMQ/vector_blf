/*
 * Copyright (C) 2013 Tobias Lorenz.
 * Contact: tobias.lorenz@gmx.net
 *
 * This file is part of Tobias Lorenz's Toolkit.
 *
 * Commercial License Usage
 * Licensees holding valid commercial licenses may use this file in
 * accordance with the commercial license agreement provided with the
 * Software or, alternatively, in accordance with the terms contained in
 * a written agreement between you and Tobias Lorenz.
 *
 * GNU General Public License 3.0 Usage
 * Alternatively, this file may be used under the terms of the GNU
 * General Public License version 3.0 as published by the Free Software
 * Foundation and appearing in the file LICENSE.GPL included in the
 * packaging of this file.  Please review the following information to
 * ensure the GNU General Public License version 3.0 requirements will be
 * met: http://www.gnu.org/copyleft/gpl.html.
 */

#pragma once

#include "AbstractFile.h"
#include "ObjectHeaderBase.h"
#include "VectorTypes.h"

#include "vector_blf_export.h"

namespace Vector {
namespace BLF {

/**
 * @brief Object header
 *
 * Object header. Version 2.
 */
class VECTOR_BLF_EXPORT ObjectHeader2 : public ObjectHeaderBase
{
public:
    ObjectHeader2();

    virtual void read(AbstractFile & is);
    virtual void write(AbstractFile & os);
    virtual const size_t calculateHeaderSize();
    virtual size_t calculateObjectSize();

    /** enumeration for objectFlags */
    enum class ObjectFlags : DWORD {
        /**
         * @brief 10 micro second timestamp
         *
         * Object time stamp is saved as multiple of ten
         * microseconds.
         * (BL_OBJ_FLAG_TIME_TEN_MICS)
         */
        TimeTenMics = 0x00000001,

        /**
         * @brief 1 nano second timestamp
         *
         * Object time stamp is saved in nanoseconds.
         * (BL_OBJ_FLAG_TIME_ONE_NANS)
         */
        TimeOneNans = 0x00000002
    };

    /**
     * @brief object flags
     *
     * Unit of object timestamp.
     */
    ObjectFlags objectFlags;

    /** enumeration for timeStampStatus */
    enum TimeStampStatus : BYTE {
        /**
         * @brief 1: valid orig. timestamp
         *
         * Determines whether original timestamp member
         * is valid (1) or not (0).
         */
        Orig = 0x01,

        /**
         * @brief 1: sw generated ts; 0: hw
         *
         * Timestamp is generated by software (1) or by
         * hardware (0).
         */
        SwHw = 0x02,

        /**
         * @brief protocol specific meaning
         *
         * This bit has protocol specific meaning.
         */
        User = 0x10
    };

    /**
     * @brief time stamp status
     *
     * Bit field.
     */
    BYTE timeStampStatus;

    /** reserved */
    BYTE reserved;

    /**
     * @brief object specific version
     *
     * Object specific version, has to be set to 0 unless
     * stated otherwise in the description of a specific
     * event.
     */
    WORD objectVersion;

    /**
     * @brief object timestamp
     *
     * Time stamp of this object in the unit specified in
     * objectFlags.
     */
    ULONGLONG objectTimeStamp;

    /**
     * @brief original object timestamp
     *
     * Original timestamp in the unit specified in
     * objectFlags.
     */
    ULONGLONG originalTimeStamp;
};

}
}
