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
//!
//!  @file
//!  Declare the ts::DektecOutputPlugin class.
//!
//----------------------------------------------------------------------------

#pragma once
#include "tsPlugin.h"

namespace ts {
    // Dektec output plugin for tsp.
    class TSDUCKDLL DektecOutputPlugin: public OutputPlugin
    {
    public:
        // Implementation of plugin API
        DektecOutputPlugin(TSP*);
        virtual ~DektecOutputPlugin();
        virtual bool start();
        virtual bool stop();
        virtual bool send(const TSPacket*, size_t);
        virtual BitRate getBitrate();

#if !defined(TS_NO_DTAPI)
    private:
        class Guts;
        Guts* _guts;

        // Output start error: log error, detach channel & device, return false.
        bool startError(const std::string&, unsigned int); // Dtapi::DTAPI_RESULT

        // Update, when possible, the _opt_bitrate and _cur_bitrate fields based on a
        // user-specified symbol rate (and other modulation parameters). Return false
        // and close channel on error. Return true if the bitrate was successfully computed.
        bool setBitrate(int symbol_rate, int dt_modulation, int param0, int param1, int param2);

        // Set modulation parameters (modulators only). Return true on success, false on error.
        bool setModulation(int& modulation_type);
#endif
    };
}