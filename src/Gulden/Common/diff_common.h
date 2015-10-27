// Copyright (c) 2015 The Gulden developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef GULDEN_DIFF_COMMON_H
#define GULDEN_DIFF_COMMON_H

#include "../consensus/params.h"
#include "../arith_uint256.h"
#include "util.h"

#include "diff_delta.h"
#include "diff_old.h"

unsigned int static GetNextWorkRequired(const CBlockIndex* pindexLast, const CBlockHeader *pblock, int64_t nPowTargetSpacing, unsigned int nPowLimit)
{
    static int nDeltaSwitchoverBlock = GetBoolArg("-testnet", false) ? 350000 : (GetBoolArg("-testnetaccel", false) ? 1 : 213500);
    static int nOldDiffSwitchoverBlock = GetBoolArg("-testnet", false) ? 500 : (GetBoolArg("-testnetaccel", false) ? 500 : 260000);

    if (pindexLast->nHeight+1 >= nOldDiffSwitchoverBlock)
    {
        if (pindexLast->nHeight+1 >= nDeltaSwitchoverBlock)
        {
            return GetNextWorkRequired_DELTA(pindexLast, pblock, nPowTargetSpacing, nPowLimit, nDeltaSwitchoverBlock);
        }
        else
        {
            return 524287999;
        }
    }
    return diff_old(pindexLast->nHeight+1);
}


#endif

