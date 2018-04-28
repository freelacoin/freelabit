// Copyright (c) 2011-2018 The Cryptonote developers
// Copyright (c) 2014-2018 XDN developers
// Copyright (c) 2016-2018 BXC developers
// Copyright (c) 2017-2018 Royalties developers
// Copyright (c) 2017-2018 Freelabit developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

//pragma once not working so using belo
#ifndef CRYPTONOTECONFIG
#define CRYPTONOTECONFIG

#include <cstdint>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0x32b59c; // address start with "TFLB"
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 10;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;
const uint64_t CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE           = 10;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 30;

const uint64_t MONEY_SUPPLY                                  = (uint64_t)(-1);

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 100000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 6;
// COIN - number of smallest units in one coin
const uint64_t POINT                                         = UINT64_C(1000);        // pow(10, 3)
const uint64_t COIN                                          = UINT64_C(1000000);     // pow(10, 6)
const uint64_t MINIMUM_FEE                                   = UINT64_C(1000);        // pow(10, 3)
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(100);         // pow(10, 2)

const uint64_t DIFFICULTY_TARGET                             = 120; // seconds
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = 20; // blocks
const size_t   DIFFICULTY_CUT                                = 5;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 1;
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const uint64_t DEPOSIT_MIN_AMOUNT                            = 1 * COIN;
const uint32_t DEPOSIT_MIN_TERM                              = 22000; //~1 month
const uint32_t DEPOSIT_MAX_TERM                              = 1 * 12 * 22000; //~1 year
const uint64_t DEPOSIT_MIN_TOTAL_RATE_FACTOR                 = 0; //rate is constant
const uint64_t DEPOSIT_MAX_TOTAL_RATE                        = 15; //percentage rate for DEPOSIT_MAX_TERM
static_assert(DEPOSIT_MIN_TERM > 0, "Bad DEPOSIT_MIN_TERM");
static_assert(DEPOSIT_MIN_TERM <= DEPOSIT_MAX_TERM, "Bad DEPOSIT_MAX_TERM");
static_assert(DEPOSIT_MIN_TERM * DEPOSIT_MAX_TOTAL_RATE > DEPOSIT_MIN_TOTAL_RATE_FACTOR, "Bad DEPOSIT_MIN_TOTAL_RATE_FACTOR or DEPOSIT_MAX_TOTAL_RATE");

const uint64_t MULTIPLIER_FACTOR                             = 250; //early depositor multiplier
const uint32_t END_MULTIPLIER_BLOCK                          = 3600; //block at which the multiplier ceases to be applied

const size_t   MAX_BLOCK_SIZE_INITIAL                        = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 10;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = (60 * 60 * 14); //seconds, 14 hours
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = (60 * 60 * 24); //seconds, one day
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint64_t UPGRADE_HEIGHT_V2                             = 1;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;               // percent
const size_t   UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const size_t   UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

const uint64_t START_BLOCK_REWARD                            = (UINT64_C(10000) * parameters::POINT);
const uint64_t ICO_BLOCK_REWARD	                            = (UINT64_C(8446744) * parameters::COIN); 
const uint64_t MAX_BLOCK_REWARD                              = (UINT64_C(100) * parameters::COIN);
const uint64_t REWARD_INCREASE_INTERVAL                      = (UINT64_C(264000));

const char     CRYPTONOTE_NAME[]                             = "Freelabit";
const char     GENESIS_COINBASE_TX_HEX[]                     = "010a01ff000180ade204029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880712101c0785a24009b03f151f73f97d93ee2f593a5405c48b0495e7f8e65297db7fcc7";
const uint32_t GENESIS_NONCE                                 = 70;
const uint64_t GENESIS_TIMESTAMP                             = 1496764095;

const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  200;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              = 31002;
const int      RPC_DEFAULT_PORT                              = 31006;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 16 * 1024 * 1024; // 16 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "0000000000000000000000000000000000000000000000000000000000000000";

const std::initializer_list<const char*> SEED_NODES = {
   "54.164.132.83:31002",
   "18-218-248-71:31002",
   "52.205.252.90:31002",
   // "155.254.33.76:31002",
   // "18.216.107.49:31002",
   // "162.218.211.151:31002",
   // "162.218.211.202:31002",
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

// You may add here other checkpoints using the following format:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS = { 
{ 10, "ca481ea67e03a057466cf6645d5c7a65035bff36e69819dc89265ca4dd66b324" },
{ 100, "037bf398cca6d11b2e8bee9de964ea26478ca301d56b6bc63467cfe09c6f31cb" },
{ 1000, "e5c438ed9806d0126816a5c089dfe2f2ae27ea3133cca64e1140a7e5fe6ec477" },
{ 2000, "3ed05d3666c6021542c3dc9bbc7ed24fe8455a7e34160361b7df9d9309743550" }, 
{ 10000, "6c5b74d3131514baf0476806144fed8a57dce9a6c7c6df2bc6f389b9b3a1bb5a" },
{ 20000, "5bd26730f7148657d432d84cc525ea69038dc063958c0c5e627f0e982525e661" },
{ 30000, "4edaaae9cb42b46cd4fd767ad3d529bda704e24ab9d191e7d65d93585b2a57a4" },
{ 40000, "3bf1571d359306fee15d8782abf32bc609cf6f67af2d529128cf13e14b11e059" },
{ 50000, "8b94e0aa8cfa2366f73b8c1c19ff717dea8b720d8ab97b56edd547c137fbf5ce" },
{ 60000, "0db4046af5069a969b2867c376cf03b13179cb1076f90aad2588911f144a58a0" },
{ 70000, "e391dd85a88081fc500094111fe31596bb2967de211caca343d8df562be17719" },
{ 80000, "4487a06b2c6938321b5731fe15b90711bdeb2d2c9fac880903b0b66331a41528" },
{ 90000, "5b172d9739198ee23b30acf210d0b91172f9fdd76ed8e3df609a1a9e9d6d4167" },
{ 100000, "3e89b27544f3db7a39b857ef770350ac22a01f61e489a3109e69f971b5fc1945" },
{ 101000, "6ec898ee794da3db532ada15d6e316177d96b97cb683c91bd75d5f86daa68fa3" },
{ 102000, "ac6e513227471eb0b4f789e481c41e9255e950a0d5225a237692ba300508a8da" },
{ 103000, "8114ddf515df39ceaa4c6b017e8e8820c60d337c5d87f8eaf94c2a1a676d1db6" },
{ 104000, "622b65a2906a8b3b876a900cf315a18d33e2359163295413c7ef100a53a5d35b" },
{ 105000, "2f1bd99b33e5b71ebb4f7067692aa3b99a9bfd71ff64b491dabf9e3a6bc109e9" },
{ 106000, "cb1b9061c4374683e822895165a3a0d1ef100da45624919762c65e736639cc2c" },
{ 107000, "eda4c7389e2e09715578adad0934b709a67d8223841639e1c31da445f4d94a85" },
{ 108000, "1217b5e1ffd47e085495489a904b98c72e80a07adfd7cb4a7da0d7bb9b26fd62" },
{ 109000, "4bb1a4f45432ae6dc4757214b8a7b05889b05e048b9b9159877efb497054bfa0" },
{ 110000, "d8fe6378fe01814d5020527d0312b9a9408e078b1abab5bfee505d43c60241ca" },
{ 111000, "2a2dd28bd7b9ddd9fe9f695b28f1f34f6333ba687f3d9beaca7db10ccbffd468" },
{ 112000, "315e7930101a72ad7e33b071d1c1f1dc479ff8ee53c9b2622255293c73460897" },
{ 113000, "bd9294098d819ff26bc2194ae61886f178569bf7295d34de91c7965c5b1388b9" },
{ 114000, "f5bcc7fd68e0d1981b2f6d164083a47353ce4e22b0c5075df0c0c45ade9eff12" },
{ 115000, "4abf0340dc6605248a4d997ac38ef44499ec88fc81f15fe1352ff0c9489c2d51" },
{ 116000, "0bd369906eead14da0f2c983502faee29060c88fec18eba4156db3a16b0e9ca7" },
{ 117000, "038d0e2250292a4558e8174681f739c2f58f5e388daf72d3d5b46fc2c15ab9f4" },
{ 118000, "f96221c55c342fe968f6dd4c521b19800ea8011bc6a6f6494ba45d090a52ba9a" },
{ 119000, "05bb7342a82e17e681d01ac9b95c1f3a95246b5bc7d5f96f52a4a7b66e3e0c5a" },
{ 120000, "b43aa588b9a3c805ca1456c9b036975a65b175e69efed4d02e2fcff5d81c8f66" },
{ 121000, "b34ed4a3aa0c4b5794df3e5fe383daef02c6d92f3cdb46f39c96e95d61bb4342" },
{ 122000, "a2a398a981b50e27d2b8e8b9e4421d3988bd60767983287836f9f847e6eac934" },
{ 123000, "b065895e4ec8c8ff34ed1573d96a6dc1b204976a88930711336a508751fb2fff" },
{ 124000, "97974ceae38a246520d008c1945f379d02caffc052f122ad768a7326c8b188d2" },
{ 125000, "36f6445e1cf0375cb1ae8394ca315cb93a94a26254ce97f81690e928484af77c" },
};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS

#endif
