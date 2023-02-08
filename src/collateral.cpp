// Copyright (c) 2020 The Qodex developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
 
#include <amount.h>
#include <util.h>

/**
 * The number of blocks that both new and old MN collateral value will
 * be accepted, for smoother transition.
 */
const unsigned int COLLATERAL_TRANSITION_BLOCKS = 100;

/**
 * Determine the masternode collateral value based on block height
 */
CAmount CollateralRequired(int nHeight)
{
    CAmount nCollateralRequired;
    
    if (nHeight >= 1 && nHeight <= 1000) {
        nCollateralRequired = 300000 * COIN;
    } else if (nHeight >= 1001 && nHeight <= 100000) {
        nCollateralRequired = 300000 * COIN;
    } else if (nHeight >= 100001 && nHeight <= 200000) {
        nCollateralRequired = 300000 * COIN;
    } else if (nHeight >= 200001 && nHeight <= 300000) {
        nCollateralRequired = 300000 * COIN;
    } else if (nHeight >= 300001 && nHeight <= 400000) {
        nCollateralRequired = 300000 * COIN;
    } else if (nHeight >= 400001 && nHeight <= 500000) {
        nCollateralRequired = 300000 * COIN;
    } else if (nHeight >= 500001 && nHeight <= 600000) {
        nCollateralRequired = 300000 * COIN;
    } else if (nHeight >= 600001 && nHeight <= 800000) {
        nCollateralRequired = 300000 * COIN;
    } else if (nHeight >= 800001 && nHeight <= 900000) {
        nCollateralRequired = 300000 * COIN;
    } else if (nHeight >= 900001) {
        nCollateralRequired = 300000 * COIN;
    } else {
       nCollateralRequired = 300000 * COIN; 
    }

    return nCollateralRequired;
}


/**
 * Provide transition period for masternode collateral change to avoid
 * unneccessary issues to masternode operators for the amount of 
 * COLLATERAL_TRANSITION_BLOCKS blocks during the collateral change.
 */
bool IsValidCollateral(CAmount nAmountToCheck, int nHeight)
{
    return (
        nAmountToCheck == CollateralRequired(nHeight) || 
        nAmountToCheck == CollateralRequired(nHeight - floor(COLLATERAL_TRANSITION_BLOCKS / 2)) ||
        nAmountToCheck == CollateralRequired(nHeight + floor(COLLATERAL_TRANSITION_BLOCKS / 2))
        );
}
