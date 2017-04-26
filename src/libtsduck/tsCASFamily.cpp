//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2017, Thierry Lelegard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------
//
//  Conditional Access Systems families
//
//----------------------------------------------------------------------------

#include "tsCASFamily.h"

// Return a CAS family from a CA system id.
// Useful to analyze CA descriptors.

ts::CASFamily ts::CASFamilyOf (uint16_t casid)
{
    if (casid >= 0x0100 && casid <= 0x01FF) {
        return CAS_MEDIAGUARD;
    }
    else if (casid >= 0x0500 && casid <= 0x05FF) {
        return CAS_VIACCESS;
    }
    else if (casid >= 0x1800 && casid <= 0x18FF) {
        return CAS_NAGRA;
    }
    else if (casid >= 0x4A80 && casid <= 0x4A8F) {
        return CAS_THALESCRYPT;
    }
    else if (casid == 0x4ADC) {
        return CAS_SAFEACCESS;
    }
    else {
        return CAS_OTHER;
    }
}