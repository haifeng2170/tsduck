//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------
//!
//!  @file
//!  DirectShow AM_MEDIA_TYPE utilities (Windows-specific).
//!
//-----------------------------------------------------------------------------

#pragma once
#include "tsPlatform.h"

namespace ts {

    // Delete a heap allocated AM_MEDIA_TYPE structure which is useful when
    // calling IEnumMediaTypes::Next as the interface implementation allocates
    // the structures which you must later delete the format block may also be
    // a pointer to an interface to release.
    TSDUCKDLL void DeleteMediaType (::AM_MEDIA_TYPE*);

    // Free an existing media type (ie free resources it holds)
    TSDUCKDLL void FreeMediaType (::AM_MEDIA_TYPE&);

    // Copy a media type to another
    TSDUCKDLL ::HRESULT CopyMediaType (::AM_MEDIA_TYPE& dst, const ::AM_MEDIA_TYPE& src);

    // Initialize a media type with "null" values
    TSDUCKDLL void InitMediaType (::AM_MEDIA_TYPE&);
}