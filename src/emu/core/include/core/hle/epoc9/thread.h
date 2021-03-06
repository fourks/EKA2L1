/*
 * Copyright (c) 2018 EKA2L1 Team.
 * 
 * This file is part of EKA2L1 project 
 * (see bentokun.github.com/EKA2L1).
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <hle/bridge.h>
#include <epoc9/types.h>
#include <epoc9/mem.h>
#include <epoc9/allocator.h>
#include <epoc9/des.h>

#include <ptr.h>

using namespace eka2l1;

typedef void(*TThreadFunction)(int);

struct SThreadCreateInfo {
    eka2l1::ptr<TAny>          iHandle;
    TInt                       iType;
    eka2l1::ptr<TAny>          iFunction;
    eka2l1::ptr<TAny>          iPtr;
    eka2l1::ptr<TAny>          iSupervisorStack;
    TInt                       iSupervisorStackSize;
    eka2l1::ptr<TAny>          iUserStack;
    TInt                       iUserStackSize;
    TInt                       iInitThreadPriority;
    TPtrC                      iName;
    TInt                       iTotalSize;
};

struct SStdEpocThreadCreateInfo : public SThreadCreateInfo {
    eka2l1::ptr<RAllocator>  iAllocator;
    TInt                     iHeapInitialSize;
    TInt                     iHeapMaxSize;
    TInt                     iPadding;
};

BRIDGE_FUNC(TInt, UserHeapCreateThreadHeap, ptr<SStdEpocThreadCreateInfo> aInfo, ptr<address> iHeapPtr, TInt aAlign, TBool aSingleThread);
BRIDGE_FUNC(ptr<RHeap>, UserHeapChunkHeap, RChunk aChunk, TInt aMinLength, TInt aOffset, TInt aGrowBy, TInt aMaxLength, TInt aAlign, TBool aSingleThread, TUint32 aMode);

extern const eka2l1::hle::func_map thread_register_funcs;
