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
//!  Basic monotonic clock & timer class
//!
//----------------------------------------------------------------------------

#pragma once
#include "tsPlatform.h"
#include "tsException.h"

namespace ts {

    class TSDUCKDLL Monotonic
    {
    public:
        // Exceptions
        tsDeclareException (MonotonicError);

        // Default constructor.
        Monotonic() throw (MonotonicError) : _value (0) {init();}

        // Copy constructor
        Monotonic (const Monotonic& t) throw (MonotonicError) : _value (t._value) {init();}

        // Destructor
        ~Monotonic();

        // Get system time value
        void getSystemTime() throw (MonotonicError);

        // Assigment
        Monotonic& operator= (const Monotonic& t) {_value = t._value; return *this;}

        // Comparisons
        bool operator== (const Monotonic& t) const {return _value == t._value;}
        bool operator!= (const Monotonic& t) const {return _value != t._value;}
        bool operator<  (const Monotonic& t) const {return _value <  t._value;}
        bool operator<= (const Monotonic& t) const {return _value <= t._value;}
        bool operator>  (const Monotonic& t) const {return _value >  t._value;}
        bool operator>= (const Monotonic& t) const {return _value >= t._value;}

        // Arithmetic
        Monotonic& operator+= (const NanoSecond& ns) {_value += ns / NS_PER_TICK; return *this;}
        Monotonic& operator-= (const NanoSecond& ns) {_value -= ns / NS_PER_TICK; return *this;}
        NanoSecond operator- (const Monotonic& t) const {return (_value - t._value) * NS_PER_TICK;}

        // Wait until the time of the monotonic clock.
        void wait() throw (MonotonicError);

        // This static method requests a minimum resolution, in nano-seconds, for the timers.
        // Return the guaranteed value (can be equal to or greater than the requested value.
        // Default system resolution is 20 ms on Win32, can be too long for applications.
        static NanoSecond SetPrecision (const NanoSecond&) throw (MonotonicError);

    private:
        // Monotonic clock value in system ticks
        int64_t _value;

        // System-specific initialization
        void init() throw (MonotonicError);

#if defined (__windows)
        // Timer handle
        ::HANDLE _handle;

        // On Win32, a FILETIME is a 64-bit value representing the number
        // of 100-nanosecond intervals since January 1, 1601.
        // Number of nanoseconds per FILETIME ticks:
        static const int64_t NS_PER_TICK = 100;
#else
        // Jiffies per second (set by init())
        unsigned long _jps;

        // On POSIX systems, the clock unit is the nanosecond.
        static const int64_t NS_PER_TICK = 1;
#endif
    };
}