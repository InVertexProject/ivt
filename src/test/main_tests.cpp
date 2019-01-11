// Copyright (c) 2014 The Bitcoin Core developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2018 LightPayCoin developers
// Copyright (c) 2018 The InVertex developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "primitives/transaction.h"
#include "main.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(main_tests)

CAmount nMoneySupplyPoWEnd = 13000000 * COIN;

BOOST_AUTO_TEST_CASE(subsidy_limit_test)
{
    CAmount nSum = 0;
    //PoW + PoS Premine
    for (int nHeight = 0; nHeight < 1000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 500 * COIN);
        nSum += nSubsidy;
    }
    //Main PoS phase
    for (int nHeight = 1001; nHeight < 100000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 1 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 100001; nHeight < 110000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 25 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 110001; nHeight < 120000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 100 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 120001; nHeight < 130000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 50 * COIN);
        nSum += nSubsidy;
    }
    for (int nHeight = 130001; nHeight < 140000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 150 * COIN);
        nSum += nSubsidy;
    }
    for (int nHeight = 140001; nHeight < 150000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 75 * COIN);
        nSum += nSubsidy;
    }
    for (int nHeight = 150001; nHeight < 160000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 200 * COIN);
        nSum += nSubsidy;
    }
    for (int nHeight = 160001; nHeight < 170000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 100 * COIN);
        nSum += nSubsidy;
    }
    for (int nHeight = 170001; nHeight < 180000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 300 * COIN);
        nSum += nSubsidy;
    }
    for (int nHeight = 180001; nHeight < 190000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 150 * COIN);
        nSum += nSubsidy;
    }
    for (int nHeight = 190001; nHeight < 200000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 50 * COIN);
        nSum += nSubsidy;
        BOOST_CHECK(nSum > 0 && nSum <= nMoneySupplyPoWEnd);
    }

}

BOOST_AUTO_TEST_SUITE_END()
