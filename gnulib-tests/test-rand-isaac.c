/* Test the ISAAC or ISAAC64 pseudorandom number generator.

   Copyright (C) 2010-2020 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* Written by Paul Eggert.  */

#include <config.h>

#include "rand-isaac.h"

#include <fcntl.h>
#include <stdint.h>
#include <string.h>

#include "macros.h"

/* This expected output was generated by running the programs in
   <http://burtleburtle.net/bob/rand/isaacafa.html>, as last modified
   on 2010-01-22. The 32-bit numbers were output by rand.c, and the
   64-bit by isaac64.c, both on x86, as those programs are not
   portable to 64-bit platforms.  */

static isaac_word const expected[2][ISAAC_WORDS] =
  {
   #if ISAAC_BITS == 32
    {
      UINT32_C (0xf650e4c8), UINT32_C (0xe448e96d),
      UINT32_C (0x98db2fb4), UINT32_C (0xf5fad54f),
      UINT32_C (0x433f1afb), UINT32_C (0xedec154a),
      UINT32_C (0xd8370487), UINT32_C (0x46ca4f9a),
      UINT32_C (0x5de3743e), UINT32_C (0x88381097),
      UINT32_C (0xf1d444eb), UINT32_C (0x823cedb6),
      UINT32_C (0x6a83e1e0), UINT32_C (0x4a5f6355),
      UINT32_C (0xc7442433), UINT32_C (0x25890e2e),
      UINT32_C (0x7452e319), UINT32_C (0x57161df6),
      UINT32_C (0x38a824f3), UINT32_C (0x002ed713),
      UINT32_C (0x29f55449), UINT32_C (0x51c08d83),
      UINT32_C (0xd78cb99e), UINT32_C (0xa0cc74f3),
      UINT32_C (0x8f651659), UINT32_C (0xcbc8b7c2),
      UINT32_C (0xf5f71c69), UINT32_C (0x12ad6419),
      UINT32_C (0xe5792e1b), UINT32_C (0x860536b8),
      UINT32_C (0x09b3ce98), UINT32_C (0xd45d6d81),
      UINT32_C (0xf3b26129), UINT32_C (0x17e38f85),
      UINT32_C (0x29cf72ce), UINT32_C (0x349947b0),
      UINT32_C (0xc998f9ff), UINT32_C (0xb5e13dae),
      UINT32_C (0x32ae2a2b), UINT32_C (0xf7cf814c),
      UINT32_C (0x8ebfa303), UINT32_C (0xcf22e064),
      UINT32_C (0x0b923200), UINT32_C (0xeca4d58a),
      UINT32_C (0xef53cec4), UINT32_C (0xd0f7b37d),
      UINT32_C (0x9c411a2a), UINT32_C (0xffdf8a80),
      UINT32_C (0xb40e27bc), UINT32_C (0xb4d2f976),
      UINT32_C (0x44b89b08), UINT32_C (0xf37c71d5),
      UINT32_C (0x1a70e7e9), UINT32_C (0x0bdb9c30),
      UINT32_C (0x60dc5207), UINT32_C (0xb3c3f24b),
      UINT32_C (0xd7386806), UINT32_C (0x229749b5),
      UINT32_C (0x4e232cd0), UINT32_C (0x91dabc65),
      UINT32_C (0xa70e1101), UINT32_C (0x8b87437e),
      UINT32_C (0x5781414f), UINT32_C (0xcdbc62e2),
      UINT32_C (0x8107c9ff), UINT32_C (0x69d2e4ae),
      UINT32_C (0x3b18e752), UINT32_C (0xb143b688),
      UINT32_C (0x6f4e0772), UINT32_C (0x95138769),
      UINT32_C (0x943c3c74), UINT32_C (0xafc17a97),
      UINT32_C (0x0fd43963), UINT32_C (0x6a529b0b),
      UINT32_C (0xd8c58a6a), UINT32_C (0xa8bcc22d),
      UINT32_C (0x2db35dfe), UINT32_C (0xa7a2f402),
      UINT32_C (0x6cb167db), UINT32_C (0x538e1f4e),
      UINT32_C (0x7275e277), UINT32_C (0x1d3b8e97),
      UINT32_C (0xecc5dc91), UINT32_C (0x15e3a5b9),
      UINT32_C (0x03696614), UINT32_C (0x30ab93ec),
      UINT32_C (0xac9fe69d), UINT32_C (0x7bc76811),
      UINT32_C (0x60eda8da), UINT32_C (0x28833522),
      UINT32_C (0xd5295ebc), UINT32_C (0x5adb60e7),
      UINT32_C (0xf7e1cdd0), UINT32_C (0x97166d14),
      UINT32_C (0xb67ec13a), UINT32_C (0x210f3925),
      UINT32_C (0x64af0fef), UINT32_C (0x0d028684),
      UINT32_C (0x3aea3dec), UINT32_C (0xb058bafb),
      UINT32_C (0xb8b0ccfc), UINT32_C (0xf2b5cc05),
      UINT32_C (0xe3a662d9), UINT32_C (0x814bc24c),
      UINT32_C (0x2364a1aa), UINT32_C (0x37c0ed05),
      UINT32_C (0x2b36505c), UINT32_C (0x451e7ec8),
      UINT32_C (0x5d2a542f), UINT32_C (0xe43d0fbb),
      UINT32_C (0x91c8d925), UINT32_C (0x60d4d5f8),
      UINT32_C (0x12a0594b), UINT32_C (0x9e8a51da),
      UINT32_C (0xcd49ebdb), UINT32_C (0x1b0dcdc1),
      UINT32_C (0xcd57c7f7), UINT32_C (0xe6344451),
      UINT32_C (0x7ded386f), UINT32_C (0x2f36fa86),
      UINT32_C (0xa6d12101), UINT32_C (0x33bc405d),
      UINT32_C (0xb388d96c), UINT32_C (0xdb6dbe96),
      UINT32_C (0xfe29661c), UINT32_C (0x13edc0cb),
      UINT32_C (0xcb0eee4a), UINT32_C (0x70cc94ae),
      UINT32_C (0xde11ed34), UINT32_C (0x0606cf9f),
      UINT32_C (0x3a6ce389), UINT32_C (0x23d74f4e),
      UINT32_C (0xa37f63ff), UINT32_C (0x917bdec2),
      UINT32_C (0xd73f72d4), UINT32_C (0x0e7e0e67),
      UINT32_C (0x3d77d9a2), UINT32_C (0x13add922),
      UINT32_C (0x8891b3db), UINT32_C (0x01a9bd70),
      UINT32_C (0x56a001e3), UINT32_C (0xd51f093d),
      UINT32_C (0xcc033ce3), UINT32_C (0x5ad0d3b0),
      UINT32_C (0x34105a8c), UINT32_C (0x6a123f57),
      UINT32_C (0xbd2e5024), UINT32_C (0x7364944b),
      UINT32_C (0xe89b1a3b), UINT32_C (0x21835c4d),
      UINT32_C (0x9f39e2d9), UINT32_C (0xd405ded8),
      UINT32_C (0x294d37e5), UINT32_C (0xbccaaeed),
      UINT32_C (0x35a124b5), UINT32_C (0x6708a2bc),
      UINT32_C (0xb00960ba), UINT32_C (0x2a98121a),
      UINT32_C (0x4d8fae82), UINT32_C (0x0bb3263f),
      UINT32_C (0x12595a19), UINT32_C (0x6a107589),
      UINT32_C (0x0809e494), UINT32_C (0x21c171ec),
      UINT32_C (0x884d6825), UINT32_C (0x14c8009b),
      UINT32_C (0xb0b84e7b), UINT32_C (0x03fb88f4),
      UINT32_C (0x28e7cb78), UINT32_C (0x9388b13b),
      UINT32_C (0xdd2dc1d5), UINT32_C (0x848f520a),
      UINT32_C (0x07c28cd1), UINT32_C (0x68a39358),
      UINT32_C (0x72c9137d), UINT32_C (0x127dd430),
      UINT32_C (0xc613f157), UINT32_C (0x8c2f0d55),
      UINT32_C (0xf7d3f39f), UINT32_C (0x309bfb78),
      UINT32_C (0x8406b137), UINT32_C (0x46c0a6f5),
      UINT32_C (0x3718d597), UINT32_C (0x08607f04),
      UINT32_C (0x76904b6d), UINT32_C (0x04db4e13),
      UINT32_C (0xcd7411a7), UINT32_C (0xb510ce0e),
      UINT32_C (0xbfc7f7cc), UINT32_C (0xb83f957a),
      UINT32_C (0xfdfef62d), UINT32_C (0xc35e4580),
      UINT32_C (0x3ff1e524), UINT32_C (0x4112d96c),
      UINT32_C (0x02c9b944), UINT32_C (0xd5990dfb),
      UINT32_C (0xe7e26581), UINT32_C (0x0d9c7e7e),
      UINT32_C (0x826dfa89), UINT32_C (0x66f1e0ab),
      UINT32_C (0x30bcc764), UINT32_C (0xeadebeac),
      UINT32_C (0xed35e5ee), UINT32_C (0x0c571a7d),
      UINT32_C (0xe4f3a26a), UINT32_C (0xf7f58f7b),
      UINT32_C (0xadf6bc23), UINT32_C (0x5d023e65),
      UINT32_C (0x1ed3ff4e), UINT32_C (0xec46b0b6),
      UINT32_C (0xd2a93b51), UINT32_C (0xe75b41c9),
      UINT32_C (0x7e315aeb), UINT32_C (0x61119a5a),
      UINT32_C (0x53245b79), UINT32_C (0x33f6d7b1),
      UINT32_C (0xcae8deba), UINT32_C (0x50fc8194),
      UINT32_C (0xafa92a6d), UINT32_C (0xc87c8006),
      UINT32_C (0x4188bfcd), UINT32_C (0x8bace62e),
      UINT32_C (0x78ffa568), UINT32_C (0x5597ec0f),
      UINT32_C (0xb4415f7d), UINT32_C (0x08294766),
      UINT32_C (0xad567643), UINT32_C (0x09c36f90),
      UINT32_C (0x3dde9f39), UINT32_C (0x4a0a283c),
      UINT32_C (0x18080c8e), UINT32_C (0x080c79ec),
      UINT32_C (0x79ae4c10), UINT32_C (0xcb9e1563),
      UINT32_C (0x7cdd662f), UINT32_C (0x62d31911),
      UINT32_C (0xa4ca0cf1), UINT32_C (0x5cf824cd),
      UINT32_C (0x3b708f99), UINT32_C (0x1e16614c),
      UINT32_C (0xb6b9d766), UINT32_C (0x5de87abb),
      UINT32_C (0x7229ea81), UINT32_C (0xd5b2d750),
      UINT32_C (0x56e6cd21), UINT32_C (0xfe1e42d5),
      UINT32_C (0x96da2655), UINT32_C (0xc2b9aa36),
      UINT32_C (0xb8f6fd4a), UINT32_C (0x6a158d10),
      UINT32_C (0x01913fd3), UINT32_C (0xaf7d1fb8),
      UINT32_C (0x0b5e435f), UINT32_C (0x90c10757),
      UINT32_C (0x6554abda), UINT32_C (0x7a68710f)
    },
    {
      UINT32_C (0x82ac484f), UINT32_C (0xd7e1c7be),
      UINT32_C (0x95c85eaa), UINT32_C (0x94a302f4),
      UINT32_C (0x4d3cfbda), UINT32_C (0x786b2908),
      UINT32_C (0x1010b275), UINT32_C (0x82d53d12),
      UINT32_C (0x21e2a51c), UINT32_C (0x3d1e9150),
      UINT32_C (0xb059261d), UINT32_C (0xd0638e1a),
      UINT32_C (0x31860f05), UINT32_C (0x81f2864d),
      UINT32_C (0xff4cfc35), UINT32_C (0x0451516d),
      UINT32_C (0xbd086f26), UINT32_C (0xbc5654c1),
      UINT32_C (0x65dfa427), UINT32_C (0xa82427f5),
      UINT32_C (0x582e3014), UINT32_C (0xb8d2486d),
      UINT32_C (0xc79a1749), UINT32_C (0x9a1d7745),
      UINT32_C (0x8766bb54), UINT32_C (0x1e04a7f7),
      UINT32_C (0x3d3dff8a), UINT32_C (0xd5ec6bf4),
      UINT32_C (0xdbef7d9f), UINT32_C (0x36ec0ea3),
      UINT32_C (0x1feb2e4f), UINT32_C (0x15cfcc5c),
      UINT32_C (0xd8c423fb), UINT32_C (0xd0ef3cc9),
      UINT32_C (0xeb244925), UINT32_C (0xba5590c8),
      UINT32_C (0xa5f48ac4), UINT32_C (0x33c5321c),
      UINT32_C (0x613b67b2), UINT32_C (0x479c3a22),
      UINT32_C (0xe21339cc), UINT32_C (0x10d210aa),
      UINT32_C (0x931dd7e2), UINT32_C (0xef05ee06),
      UINT32_C (0xb82f2703), UINT32_C (0xa385cb2c),
      UINT32_C (0x5d67133c), UINT32_C (0x877eb7b4),
      UINT32_C (0x1e3437f7), UINT32_C (0x5afb43ae),
      UINT32_C (0x53c078f3), UINT32_C (0x94d90481),
      UINT32_C (0x1d964589), UINT32_C (0x08063a85),
      UINT32_C (0xe1322228), UINT32_C (0x1956b1e5),
      UINT32_C (0x31860f13), UINT32_C (0x2e7b022f),
      UINT32_C (0x21182ca3), UINT32_C (0x96f703ac),
      UINT32_C (0x46819e2e), UINT32_C (0x0d28fe52),
      UINT32_C (0x3724d4dc), UINT32_C (0xa0eabe6b),
      UINT32_C (0xc66699fd), UINT32_C (0xc6112fdd),
      UINT32_C (0x19c1e69c), UINT32_C (0x04d3658a),
      UINT32_C (0x4b55dd99), UINT32_C (0x31907d62),
      UINT32_C (0xf854b522), UINT32_C (0x4d678f26),
      UINT32_C (0x22ae0582), UINT32_C (0xeafed133),
      UINT32_C (0xe4a51d21), UINT32_C (0x84bd6dd6),
      UINT32_C (0xc1a51375), UINT32_C (0x3f28ee63),
      UINT32_C (0xfb737b1a), UINT32_C (0x70a1660e),
      UINT32_C (0x8a8dfaa3), UINT32_C (0x1be79937),
      UINT32_C (0xf7476978), UINT32_C (0x513c1764),
      UINT32_C (0x531ac6bf), UINT32_C (0x12c06908),
      UINT32_C (0x001cdb95), UINT32_C (0x1a4b6a53),
      UINT32_C (0xd067fce5), UINT32_C (0x12b2cfb6),
      UINT32_C (0x9ddb477f), UINT32_C (0x740e0066),
      UINT32_C (0x39ddf25a), UINT32_C (0xcc8bfa2d),
      UINT32_C (0xf1b20eaf), UINT32_C (0x64f2632c),
      UINT32_C (0x9783cdee), UINT32_C (0x63bfd4d8),
      UINT32_C (0x0084cfe5), UINT32_C (0x75f4e9e2),
      UINT32_C (0x19b48fd0), UINT32_C (0x6c48ddd8),
      UINT32_C (0x7a36af93), UINT32_C (0x71865c4c),
      UINT32_C (0x9ce0199d), UINT32_C (0x867027d7),
      UINT32_C (0x2cb7b77f), UINT32_C (0x84ef01da),
      UINT32_C (0x72f5972f), UINT32_C (0x040f7074),
      UINT32_C (0xdf9afa29), UINT32_C (0xc921f94e),
      UINT32_C (0x75c08a36), UINT32_C (0x18c1ef9a),
      UINT32_C (0xd649a428), UINT32_C (0xc5b71937),
      UINT32_C (0x8a30738a), UINT32_C (0xd97cd348),
      UINT32_C (0x858129a6), UINT32_C (0x239e3b0a),
      UINT32_C (0xbbb8abc4), UINT32_C (0x80fac4c2),
      UINT32_C (0xecfcf20b), UINT32_C (0xd9d711f9),
      UINT32_C (0xe2a4ef71), UINT32_C (0xb5fe87c0),
      UINT32_C (0xbe8b06b2), UINT32_C (0xaafef5a7),
      UINT32_C (0x9c15db3b), UINT32_C (0x0aeb8165),
      UINT32_C (0x4389a84a), UINT32_C (0x253b1d7a),
      UINT32_C (0x19047c79), UINT32_C (0x7cdc78a2),
      UINT32_C (0xd20adf03), UINT32_C (0x56f55a71),
      UINT32_C (0x3e730fa8), UINT32_C (0xfd8650d8),
      UINT32_C (0x959e234e), UINT32_C (0xb7546681),
      UINT32_C (0xdad1b22a), UINT32_C (0x142a6e85),
      UINT32_C (0x8ef4bce6), UINT32_C (0x68235b9d),
      UINT32_C (0x85a13f85), UINT32_C (0x74096ae7),
      UINT32_C (0xa949bea2), UINT32_C (0x29322d0d),
      UINT32_C (0xd5683858), UINT32_C (0x82846526),
      UINT32_C (0x403dae08), UINT32_C (0x6dd1943a),
      UINT32_C (0xe1279bff), UINT32_C (0x9e7e4f04),
      UINT32_C (0x1c3a4524), UINT32_C (0x484525e4),
      UINT32_C (0x81d4cc5f), UINT32_C (0xe24124c0),
      UINT32_C (0x037464c0), UINT32_C (0xbf1bd691),
      UINT32_C (0x26ceb003), UINT32_C (0x275ead3a),
      UINT32_C (0xc5bde908), UINT32_C (0x26414ff3),
      UINT32_C (0xa30519ad), UINT32_C (0xd7b43abe),
      UINT32_C (0x2ce5d3d5), UINT32_C (0x88412761),
      UINT32_C (0x97ca2070), UINT32_C (0xe5fbb9c7),
      UINT32_C (0x276df0b4), UINT32_C (0x308f751f),
      UINT32_C (0x37a97df6), UINT32_C (0xc9cd808c),
      UINT32_C (0xfe4cb380), UINT32_C (0x3d469303),
      UINT32_C (0xaee19096), UINT32_C (0xc0d5d42a),
      UINT32_C (0x4e823ad3), UINT32_C (0xf5f9cc3b),
      UINT32_C (0x4286619c), UINT32_C (0x9ca45e1c),
      UINT32_C (0x66c97340), UINT32_C (0x891aec49),
      UINT32_C (0x45bae606), UINT32_C (0xc798f047),
      UINT32_C (0x52649d6c), UINT32_C (0xce86fdfc),
      UINT32_C (0x80c6e402), UINT32_C (0xd6ec2f2b),
      UINT32_C (0x27c82282), UINT32_C (0x1fe26ce0),
      UINT32_C (0x92f57ea7), UINT32_C (0xde462f4d),
      UINT32_C (0x07497cae), UINT32_C (0x5a48755c),
      UINT32_C (0x721502dd), UINT32_C (0x6cbe7935),
      UINT32_C (0x836d8003), UINT32_C (0x9ead7f70),
      UINT32_C (0x9ab3a42f), UINT32_C (0x4c8652d6),
      UINT32_C (0x32e39273), UINT32_C (0xe8fa3860),
      UINT32_C (0x1da4f25a), UINT32_C (0x0cd6ef81),
      UINT32_C (0x02503f7d), UINT32_C (0x8854a0a1),
      UINT32_C (0x9a30c4e8), UINT32_C (0x88157153),
      UINT32_C (0x05efe294), UINT32_C (0x57c4c925),
      UINT32_C (0x2887d96f), UINT32_C (0xc1a71e3c),
      UINT32_C (0xe9f84163), UINT32_C (0x2d0985de),
      UINT32_C (0xd21e796c), UINT32_C (0x6fb5ce56),
      UINT32_C (0x02614abf), UINT32_C (0xc3c7be2c),
      UINT32_C (0xb54fed6f), UINT32_C (0xa617a083),
      UINT32_C (0xc3142d8f), UINT32_C (0x6079e4ce),
      UINT32_C (0xceffc147), UINT32_C (0x1d0cb81b),
      UINT32_C (0xdc153e5f), UINT32_C (0xe36ef5bb),
      UINT32_C (0xd531161a), UINT32_C (0x165b1015),
      UINT32_C (0x7aa114ed), UINT32_C (0x3f7579b3),
      UINT32_C (0xf7f395f1), UINT32_C (0xbc6172c7),
      UINT32_C (0xa86f875e), UINT32_C (0x0e6c51b3),
      UINT32_C (0xcdfec2af), UINT32_C (0x73c0e762),
      UINT32_C (0x824c2009), UINT32_C (0xc5a87748),
      UINT32_C (0x94d40125), UINT32_C (0x8aba3ffb),
      UINT32_C (0xd32be060), UINT32_C (0x8c17eff0),
      UINT32_C (0x21e2547e), UINT32_C (0x07cffad9),
      UINT32_C (0x05340e15), UINT32_C (0xf3310c92),
      UINT32_C (0x9d8d1908), UINT32_C (0x86ba527f),
      UINT32_C (0xf943f672), UINT32_C (0xef73fbf0),
      UINT32_C (0x46d95ca5), UINT32_C (0xc54cd95b),
      UINT32_C (0x9d855e89), UINT32_C (0x4bb5af29)
    }
   #else
    {
      UINT64_C (0x12a8f216af9418c2), UINT64_C (0xd4490ad526f14431),
      UINT64_C (0xb49c3b3995091a36), UINT64_C (0x5b45e522e4b1b4ef),
      UINT64_C (0xa1e9300cd8520548), UINT64_C (0x49787fef17af9924),
      UINT64_C (0x03219a39ee587a30), UINT64_C (0xebe9ea2adf4321c7),
      UINT64_C (0x804456af10f5fb53), UINT64_C (0xd74bbe77e6116ac7),
      UINT64_C (0x7c0828dd624ec390), UINT64_C (0x14a195640116f336),
      UINT64_C (0x2eab8ca63ce802d7), UINT64_C (0xc6e57a78fbd986e0),
      UINT64_C (0x58efc10b06a2068d), UINT64_C (0xabeeddb2dde06ff1),
      UINT64_C (0x0b090a7560a968e3), UINT64_C (0x2cf9c8ca052f6e9f),
      UINT64_C (0x116d0016cb948f09), UINT64_C (0xa59e0bd101731a28),
      UINT64_C (0x63767572ae3d6174), UINT64_C (0xab4f6451cc1d45ec),
      UINT64_C (0xc2a1e7b5b459aeb5), UINT64_C (0x2472f6207c2d0484),
      UINT64_C (0xe699ed85b0dfb40d), UINT64_C (0xd4347f66ec8941c3),
      UINT64_C (0xf4d14597e660f855), UINT64_C (0x8b889d624d44885d),
      UINT64_C (0x258e5a80c7204c4b), UINT64_C (0xaf0c317d32adaa8a),
      UINT64_C (0x9c4cd6257c5a3603), UINT64_C (0xeb3593803173e0ce),
      UINT64_C (0x36f60e2ba4fa6800), UINT64_C (0x38b6525c21a42b0e),
      UINT64_C (0xf4f5d05c10cab243), UINT64_C (0xcf3f4688801eb9aa),
      UINT64_C (0x1ddc0325259b27de), UINT64_C (0xb9571fa04dc089c8),
      UINT64_C (0xd7504dfa8816edbb), UINT64_C (0x1fe2cca76517db90),
      UINT64_C (0x261e4e4c0a333a9d), UINT64_C (0x219b97e26ffc81bd),
      UINT64_C (0x66b4835d9eafea22), UINT64_C (0x4cc317fb9cddd023),
      UINT64_C (0x50b704cab602c329), UINT64_C (0xedb454e7badc0805),
      UINT64_C (0x9e17e49642a3e4c1), UINT64_C (0x66c1a2a1a60cd889),
      UINT64_C (0x7983eed3740847d5), UINT64_C (0x298af231c85bafab),
      UINT64_C (0x2680b122baa28d97), UINT64_C (0x734de8181f6ec39a),
      UINT64_C (0x53898e4c3910da55), UINT64_C (0x1761f93a44d5aefe),
      UINT64_C (0xe4dbf0634473f5d2), UINT64_C (0x4ed0fe7e9dc91335),
      UINT64_C (0xd18d8549d140caea), UINT64_C (0x1cfc8bed0d681639),
      UINT64_C (0xca1e3785a9e724e5), UINT64_C (0xb67c1fa481680af8),
      UINT64_C (0xdfea21ea9e7557e3), UINT64_C (0xd6b6d0ecc617c699),
      UINT64_C (0xfa7e393983325753), UINT64_C (0xa09e8c8c35ab96de),
      UINT64_C (0x8fe88b57305e2ab6), UINT64_C (0x89039d79d6fc5c5c),
      UINT64_C (0x9bfb227ebdf4c5ce), UINT64_C (0x7f7cc39420a3a545),
      UINT64_C (0x3f6c6af859d80055), UINT64_C (0xc8763c5b08d1908c),
      UINT64_C (0x469356c504ec9f9d), UINT64_C (0x26e6db8ffdf5adfe),
      UINT64_C (0x3a938fee32d29981), UINT64_C (0x2c5e9deb57ef4743),
      UINT64_C (0x1e99b96e70a9be8b), UINT64_C (0x764dbeae7fa4f3a6),
      UINT64_C (0xaac40a2703d9bea0), UINT64_C (0x1a8c1e992b941148),
      UINT64_C (0x73aa8a564fb7ac9e), UINT64_C (0x604d51b25fbf70e2),
      UINT64_C (0xdd69a0d8ab3b546d), UINT64_C (0x65ca5b96b7552210),
      UINT64_C (0x2fd7e4b9e72cd38c), UINT64_C (0x51d2b1ab2ddfb636),
      UINT64_C (0x9d1d84fcce371425), UINT64_C (0xa44cfe79ae538bbe),
      UINT64_C (0xde68a2355b93cae6), UINT64_C (0x9fc10d0f989993e0),
      UINT64_C (0x94ebc8abcfb56dae), UINT64_C (0xd7a023a73260b45c),
      UINT64_C (0x72c8834a5957b511), UINT64_C (0x8f8419a348f296bf),
      UINT64_C (0x1e152328f3318dea), UINT64_C (0x4838d65f6ef6748f),
      UINT64_C (0xd6bf7baee43cac40), UINT64_C (0x13328503df48229f),
      UINT64_C (0x7440fb816508c4fe), UINT64_C (0x9d266d6a1cc0542c),
      UINT64_C (0x4dda48153c94938a), UINT64_C (0x74c04bf1790c0efe),
      UINT64_C (0xe1925c71285279f5), UINT64_C (0x8a8e849eb32781a5),
      UINT64_C (0x073973751f12dd5e), UINT64_C (0xa319ce15b0b4db31),
      UINT64_C (0x6dd856d94d259236), UINT64_C (0x67378d8eccef96cb),
      UINT64_C (0x9fc477de4ed681da), UINT64_C (0xf3b8b6675a6507ff),
      UINT64_C (0xc3a9dc228caac9e9), UINT64_C (0xc37b45b3f8d6f2ba),
      UINT64_C (0xb559eb1d04e5e932), UINT64_C (0x1b0cab936e65c744),
      UINT64_C (0xaf08da9177dda93d), UINT64_C (0xac12fb171817eee7),
      UINT64_C (0x1fff7ac80904bf45), UINT64_C (0xa9119b60369ffebd),
      UINT64_C (0xbfced1b0048eac50), UINT64_C (0xb67b7896167b4c84),
      UINT64_C (0x9b3cdb65f82ca382), UINT64_C (0xdbc27ab5447822bf),
      UINT64_C (0x10dcd78e3851a492), UINT64_C (0xb438c2b67f98e5e9),
      UINT64_C (0x43954b3252dc25e5), UINT64_C (0xab9090168dd05f34),
      UINT64_C (0xce68341f79893389), UINT64_C (0x36833336d068f707),
      UINT64_C (0xdcdd7d20903d0c25), UINT64_C (0xda3a361b1c5157b1),
      UINT64_C (0x7f9d1a2e1ebe1327), UINT64_C (0x5d0a12f27ad310d1),
      UINT64_C (0x3bc36e078f7515d7), UINT64_C (0x4da8979a0041e8a9),
      UINT64_C (0x950113646d1d6e03), UINT64_C (0x7b4a38e32537df62),
      UINT64_C (0x8a1b083821f40cb4), UINT64_C (0x3d5774a11d31ab39),
      UINT64_C (0x7a76956c3eafb413), UINT64_C (0x7f5126dbba5e0ca7),
      UINT64_C (0x12153635b2c0cf57), UINT64_C (0x7b3f0195fc6f290f),
      UINT64_C (0x5544f7d774b14aef), UINT64_C (0x56c074a581ea17fe),
      UINT64_C (0xe7f28ecd2d49eecd), UINT64_C (0xe479ee5b9930578c),
      UINT64_C (0x9ff38fed72e9052f), UINT64_C (0x9f65789a6509a440),
      UINT64_C (0x0981dcd296a8736d), UINT64_C (0x5873888850659ae7),
      UINT64_C (0xc678b6d860284a1c), UINT64_C (0x63e22c147b9c3403),
      UINT64_C (0x92fae24291f2b3f1), UINT64_C (0x829626e3892d95d7),
      UINT64_C (0xcffe1939438e9b24), UINT64_C (0x79999cdff70902cb),
      UINT64_C (0x8547eddfb81ccb94), UINT64_C (0x7b77497b32503b12),
      UINT64_C (0x97fcaacbf030bc24), UINT64_C (0x6ced1983376fa72b),
      UINT64_C (0x7e75d99d94a70f4d), UINT64_C (0xd2733c4335c6a72f),
      UINT64_C (0xdbc0d2b6ab90a559), UINT64_C (0x94628d38d0c20584),
      UINT64_C (0x64972d68dee33360), UINT64_C (0xb9c11d5b1e43a07e),
      UINT64_C (0x2de0966daf2f8b1c), UINT64_C (0x2e18bc1ad9704a68),
      UINT64_C (0xd4dba84729af48ad), UINT64_C (0xb7a0b174cff6f36e),
      UINT64_C (0xe94c39a54a98307f), UINT64_C (0xaa70b5b4f89695a2),
      UINT64_C (0x3bdbb92c43b17f26), UINT64_C (0xcccb7005c6b9c28d),
      UINT64_C (0x18a6a990c8b35ebd), UINT64_C (0xfc7c95d827357afa),
      UINT64_C (0x1fca8a92fd719f85), UINT64_C (0x1dd01aafcd53486a),
      UINT64_C (0x49353fea39ba63b1), UINT64_C (0xf85b2b4fbcde44b7),
      UINT64_C (0xbe7444e39328a0ac), UINT64_C (0x3e2b8bcbf016d66d),
      UINT64_C (0x964e915cd5e2b207), UINT64_C (0x1725cabfcb045b00),
      UINT64_C (0x7fbf21ec8a1f45ec), UINT64_C (0x11317ba87905e790),
      UINT64_C (0x2fe4b17170e59750), UINT64_C (0xe8d9ecbe2cf3d73f),
      UINT64_C (0xb57d2e985e1419c7), UINT64_C (0x0572b974f03ce0bb),
      UINT64_C (0xa8d7e4dab780a08d), UINT64_C (0x4715ed43e8a45c0a),
      UINT64_C (0xc330de426430f69d), UINT64_C (0x23b70edb1955c4bf),
      UINT64_C (0x098954d51fff6580), UINT64_C (0x8107fccf064fcf56),
      UINT64_C (0x852f54934da55cc9), UINT64_C (0x09c7e552bc76492f),
      UINT64_C (0xe9f6760e32cd8021), UINT64_C (0xa3bc941d0a5061cb),
      UINT64_C (0xba89142e007503b8), UINT64_C (0xdc842b7e2819e230),
      UINT64_C (0xbbe83f4ecc2bdecb), UINT64_C (0xcd454f8f19c5126a),
      UINT64_C (0xc62c58f97dd949bf), UINT64_C (0x693501d628297551),
      UINT64_C (0xb9ab4ce57f2d34f3), UINT64_C (0x9255abb50d532280),
      UINT64_C (0xebfafa33d7254b59), UINT64_C (0xe9f6082b05542e4e),
      UINT64_C (0x35dd37d5871448af), UINT64_C (0xb03031a8b4516e84),
      UINT64_C (0xb3f256d8aca0b0b9), UINT64_C (0x0fd22063edc29fca),
      UINT64_C (0xd9a11fbb3d9808e4), UINT64_C (0x3a9bf55ba91f81ca),
      UINT64_C (0xc8c93882f9475f5f), UINT64_C (0x947ae053ee56e63c),
      UINT64_C (0xc7d9f16864a76e94), UINT64_C (0x7bd94e1d8e17debc),
      UINT64_C (0xd873db391292ed4f), UINT64_C (0x30f5611484119414),
      UINT64_C (0x565c31f7de89ea27), UINT64_C (0xd0e4366228b03343),
      UINT64_C (0x325928ee6e6f8794), UINT64_C (0x6f423357e7c6a9f9),
      UINT64_C (0x99170a5dc3115544), UINT64_C (0x59b97885e2f2ea28),
      UINT64_C (0xbc4097b116c524d2), UINT64_C (0x7a13f18bbedc4ff5),
      UINT64_C (0x071582401c38434d), UINT64_C (0xb422061193d6f6a7),
      UINT64_C (0xb4b81b3fa97511e2), UINT64_C (0x65d34954daf3cebd),
      UINT64_C (0xb344c470397bba52), UINT64_C (0xbac7a9a18531294b),
      UINT64_C (0xecb53939887e8175), UINT64_C (0x565601c0364e3228),
      UINT64_C (0xef1955914b609f93), UINT64_C (0x16f50edf91e513af),
      UINT64_C (0x56963b0dca418fc0), UINT64_C (0xd60f6dcedc314222),
      UINT64_C (0x364f6ffa464ee52e), UINT64_C (0x6c3b8e3e336139d3),
      UINT64_C (0xf943aee7febf21b8), UINT64_C (0x088e049589c432e0),
      UINT64_C (0xd49503536abca345), UINT64_C (0x3a6c27934e31188a),
      UINT64_C (0x957baf61700cff4e), UINT64_C (0x37624ae5a48fa6e9),
      UINT64_C (0x501f65edb3034d07), UINT64_C (0x907f30421d78c5de),
      UINT64_C (0x1a804aadb9cfa741), UINT64_C (0x0ce2a38c344a6eed),
      UINT64_C (0xd363eff5f0977996), UINT64_C (0x2cd16e2abd791e33),
      UINT64_C (0x58627e1a149bba21), UINT64_C (0x7f9b6af1ebf78baf)
    },
    {
      UINT64_C (0xd20d8c88c8ffe65f), UINT64_C (0x917f1dd5f8886c61),
      UINT64_C (0x56986e2ef3ed091b), UINT64_C (0x5fa7867caf35e149),
      UINT64_C (0x81a1549fd6573da5), UINT64_C (0x96fbf83a12884624),
      UINT64_C (0xe728e8c83c334074), UINT64_C (0xf1bcc3d275afe51a),
      UINT64_C (0x71f1ce2490d20b07), UINT64_C (0xe6c42178c4bbb92e),
      UINT64_C (0x0a9c32d5eae45305), UINT64_C (0x0c335248857fa9e7),
      UINT64_C (0x142de49fff7a7c3d), UINT64_C (0x64a53dc924fe7ac9),
      UINT64_C (0x9f6a419d382595f4), UINT64_C (0x150f361dab9dec26),
      UINT64_C (0xc61bb3a141e50e8c), UINT64_C (0x2785338347f2ba08),
      UINT64_C (0x7ca9723fbb2e8988), UINT64_C (0xce2f8642ca0712dc),
      UINT64_C (0x59300222b4561e00), UINT64_C (0xc2b5a03f71471a6f),
      UINT64_C (0xd5f9e858292504d5), UINT64_C (0x65fa4f227a2b6d79),
      UINT64_C (0x93cbe0b699c2585d), UINT64_C (0x1d95b0a5fcf90bc6),
      UINT64_C (0x17efee45b0dee640), UINT64_C (0x9e4c1269baa4bf37),
      UINT64_C (0xd79476a84ee20d06), UINT64_C (0x0a56a5f0bfe39272),
      UINT64_C (0x7eba726d8c94094b), UINT64_C (0x5e5637885f29bc2b),
      UINT64_C (0xd586bd01c5c217f6), UINT64_C (0x233003b5a6cfe6ad),
      UINT64_C (0x24c0e332b70019b0), UINT64_C (0x9da058c67844f20c),
      UINT64_C (0xe4d9429322cd065a), UINT64_C (0x1fab64ea29a2ddf7),
      UINT64_C (0x8af38731c02ba980), UINT64_C (0x7dc7785b8efdfc80),
      UINT64_C (0x486289ddcc3d6780), UINT64_C (0x222bbfae61725606),
      UINT64_C (0x2bc60a63a6f3b3f2), UINT64_C (0x177e00f9fc32f791),
      UINT64_C (0x522e23f3925e319e), UINT64_C (0x9c2ed44081ce5fbd),
      UINT64_C (0x964781ce734b3c84), UINT64_C (0xf05d129681949a4c),
      UINT64_C (0x046e3ecaaf453ce9), UINT64_C (0x962aceefa82e1c84),
      UINT64_C (0xf5b4b0b0d2deeeb4), UINT64_C (0x1af3dbe25d8f45da),
      UINT64_C (0xf9f4892ed96bd438), UINT64_C (0xc4c118bfe78feaae),
      UINT64_C (0x07a69afdcc42261a), UINT64_C (0xf8549e1a3aa5e00d),
      UINT64_C (0x2102ae466ebb1148), UINT64_C (0xe87fbb46217a360e),
      UINT64_C (0x310cb380db6f7503), UINT64_C (0xb5fdfc5d3132c498),
      UINT64_C (0xdaf8e9829fe96b5f), UINT64_C (0xcac09afbddd2cdb4),
      UINT64_C (0xb862225b055b6960), UINT64_C (0x55b6344cf97aafae),
      UINT64_C (0xff577222c14f0a3a), UINT64_C (0x4e4b705b92903ba4),
      UINT64_C (0x730499af921549ff), UINT64_C (0x13ae978d09fe5557),
      UINT64_C (0xd9e92aa246bf719e), UINT64_C (0x7a4c10ec2158c4a6),
      UINT64_C (0x49cad48cebf4a71e), UINT64_C (0xcf05daf5ac8d77b0),
      UINT64_C (0xabbdcdd7ed5c0860), UINT64_C (0x9853eab63b5e0b35),
      UINT64_C (0x352787baa0d7c22f), UINT64_C (0xc7f6aa2de59aea61),
      UINT64_C (0x03727073c2e134b1), UINT64_C (0x5a0f544dd2b1fb18),
      UINT64_C (0x74f85198b05a2e7d), UINT64_C (0x963ef2c96b33be31),
      UINT64_C (0x4659d2b743848a2c), UINT64_C (0x19ebb029435dcb0f),
      UINT64_C (0x4e9d2827355fc492), UINT64_C (0xccec0a73b49c9921),
      UINT64_C (0x46c9feb55d120902), UINT64_C (0x8d2636b81555a786),
      UINT64_C (0x30c05b1ba332f41c), UINT64_C (0xf6f7fd1431714200),
      UINT64_C (0x1a4ff12616eefc89), UINT64_C (0x990a98fd5071d263),
      UINT64_C (0x84547ddc3e203c94), UINT64_C (0x07a3aec79624c7da),
      UINT64_C (0x8a328a1cedfe552c), UINT64_C (0xd1e649de1e7f268b),
      UINT64_C (0x2d8d5432157064c8), UINT64_C (0x4ae7d6a36eb5dbcb),
      UINT64_C (0x57e3306d881edb4f), UINT64_C (0x0a804d18b7097475),
      UINT64_C (0xe74733427b72f0c1), UINT64_C (0x24b33c9d7ed25117),
      UINT64_C (0xe805a1e290cf2456), UINT64_C (0x3b544ebe544c19f9),
      UINT64_C (0x3e666e6f69ae2c15), UINT64_C (0xfb152fe3ff26da89),
      UINT64_C (0xb49b52e587a1ee60), UINT64_C (0xac042e70f8b383f2),
      UINT64_C (0x89c350c893ae7dc1), UINT64_C (0xb592bf39b0364963),
      UINT64_C (0x190e714fada5156e), UINT64_C (0xec8177f83f900978),
      UINT64_C (0x91b534f885818a06), UINT64_C (0x81536d601170fc20),
      UINT64_C (0xd4c718bc4ae8ae5f), UINT64_C (0x9eedeca8e272b933),
      UINT64_C (0x10e8b35af3eeab37), UINT64_C (0x0e09b88e1914f7af),
      UINT64_C (0x3fa9ddfb67e2f199), UINT64_C (0xb10bb459132d0a26),
      UINT64_C (0x2c046f22062dc67d), UINT64_C (0x5e90277e7cb39e2d),
      UINT64_C (0xd6b04d3b7651dd7e), UINT64_C (0xe34a1d250e7a8d6b),
      UINT64_C (0x53c065c6c8e63528), UINT64_C (0x1bdea12e35f6a8c9),
      UINT64_C (0x21874b8b4d2dbc4f), UINT64_C (0x3a88a0fbbcb05c63),
      UINT64_C (0x43ed7f5a0fae657d), UINT64_C (0x230e343dfba08d33),
      UINT64_C (0xb5b4071dbfc73a66), UINT64_C (0x8f9887e6078735a1),
      UINT64_C (0x08de8a1c7797da9b), UINT64_C (0xfcb6be43a9f2fe9b),
      UINT64_C (0x049a7f41061a9e60), UINT64_C (0x9f91508bffcfc14a),
      UINT64_C (0xe3273522064480ca), UINT64_C (0xcd04f3ff001a4778),
      UINT64_C (0x6bfa9aae5ec05779), UINT64_C (0x371f77e76bb8417e),
      UINT64_C (0x3550c2321fd6109c), UINT64_C (0xfb4a3d794a9a80d2),
      UINT64_C (0xf43c732873f24c13), UINT64_C (0xaa9119ff184cccf4),
      UINT64_C (0xb69e38a8965c6b65), UINT64_C (0x1f2b1d1f15f6dc9c),
      UINT64_C (0x67fef95d92607890), UINT64_C (0x31865ced6120f37d),
      UINT64_C (0x3a6853c7e70757a7), UINT64_C (0x32ab0edb696703d3),
      UINT64_C (0xee97f453f06791ed), UINT64_C (0x6dc93d9526a50e68),
      UINT64_C (0x78edefd694af1eed), UINT64_C (0x9c1169fa2777b874),
      UINT64_C (0x50065e535a213cf6), UINT64_C (0xde0c89a556b9ae70),
      UINT64_C (0xd1e0ccd25bb9c169), UINT64_C (0x6b17b224bad6bf27),
      UINT64_C (0x6b02e63195ad0cf8), UINT64_C (0x455a4b4cfe30e3f5),
      UINT64_C (0x9338e69c052b8e7b), UINT64_C (0x5092ef950a16da0b),
      UINT64_C (0x7c45d833aff07862), UINT64_C (0xa5b1cfdba0ab4067),
      UINT64_C (0x6ad047c430a12104), UINT64_C (0x6c47bec883a7de39),
      UINT64_C (0x944f6de09134dfb6), UINT64_C (0x9aeba33ac6ecc6b0),
      UINT64_C (0x52e762596bf68235), UINT64_C (0x22af003ab672e811),
      UINT64_C (0xb5635c95ff7296e2), UINT64_C (0xed2df21216235097),
      UINT64_C (0x4a29c6465a314cd1), UINT64_C (0xd83cc2687a19255f),
      UINT64_C (0x506c11b9d90e8b1d), UINT64_C (0x57277707199b8175),
      UINT64_C (0xcaf21ecd4377b28c), UINT64_C (0xc0c0f5a60ef4cdcf),
      UINT64_C (0x93b633abfa3469f8), UINT64_C (0xe846963877671a17),
      UINT64_C (0x59ac2c7873f910a3), UINT64_C (0x660d3257380841ee),
      UINT64_C (0xd813f2fab7f5c5ca), UINT64_C (0x4112cf68649a260e),
      UINT64_C (0x443f64ec5a371195), UINT64_C (0xb0774d261cc609db),
      UINT64_C (0x720bf5f26f4d2eaa), UINT64_C (0x1c2559e30f0946be),
      UINT64_C (0xe328e230e3e2b3fb), UINT64_C (0x087e79e5a57d1d13),
      UINT64_C (0x08dd9bdfd96b9f63), UINT64_C (0x64d0e29eea8838b3),
      UINT64_C (0xddf957bc36d8b9ca), UINT64_C (0x6ffe73e81b637fb3),
      UINT64_C (0x1a4e4822eb4d7a59), UINT64_C (0x5d94337fbfaf7f5b),
      UINT64_C (0xd30c088ba61ea5ef), UINT64_C (0x9d765e419fb69f6d),
      UINT64_C (0x9e21f4f903b33fd9), UINT64_C (0xb4d8f77bc3e56167),
      UINT64_C (0x733ea705fae4fa77), UINT64_C (0xa4ec0132764ca04b),
      UINT64_C (0x7976033a39f7d952), UINT64_C (0x106f72fe81e2c590),
      UINT64_C (0x8c90fd9b083f4558), UINT64_C (0xfd080d236da814ba),
      UINT64_C (0x7b64978555326f9f), UINT64_C (0x60e8ed72c0dff5d1),
      UINT64_C (0xb063e962e045f54d), UINT64_C (0x959f587d507a8359),
      UINT64_C (0x758f450c88572e0b), UINT64_C (0x1b6baca2ae4e125b),
      UINT64_C (0x61cf4f94c97df93d), UINT64_C (0x2738259634305c14),
      UINT64_C (0xd39bb9c3a48db6cf), UINT64_C (0x8215e577001332c8),
      UINT64_C (0xa1082c0466df6c0a), UINT64_C (0xef02cdd06ffdb432),
      UINT64_C (0xfc87614baf287e07), UINT64_C (0x240ab57a8b888b20),
      UINT64_C (0xbf8d5108e27e0d48), UINT64_C (0x61bdd1307c66e300),
      UINT64_C (0xb925a6cd0421aff3), UINT64_C (0x3e003e616a6591e9),
      UINT64_C (0x94c3251f06f90cf3), UINT64_C (0xbf84470805e69b5f),
      UINT64_C (0x98f076a4f7a2322e), UINT64_C (0x70cb6af7c2d5bcf0),
      UINT64_C (0xb64be8d8b25396c1), UINT64_C (0xa9aa4d20db084e9b),
      UINT64_C (0x2e6d02c36017f67f), UINT64_C (0xefed53d75fd64e6b),
      UINT64_C (0xd9f1f30ccd97fb09), UINT64_C (0xa2ebee47e2fbfce1),
      UINT64_C (0xb8d91274b9e9d4fb), UINT64_C (0x1db956e450275779),
      UINT64_C (0x4fc8e9560f91b123), UINT64_C (0x63573ff03e224774),
      UINT64_C (0x0647dfedcd894a29), UINT64_C (0x7884d9bc6cb569d8),
      UINT64_C (0x7fba195410e5ca30), UINT64_C (0x106c09b972d2e822),
      UINT64_C (0x241260ed4ad1e87d), UINT64_C (0x64c8e531bff53b55),
      UINT64_C (0xca672b91e9e4fa16), UINT64_C (0x3871700761b3f743),
      UINT64_C (0xf95cffa23af5f6f4), UINT64_C (0x8d14dedb30be846e),
      UINT64_C (0x3b097adaf088f94e), UINT64_C (0x21e0bd5026c619bf),
      UINT64_C (0x1bda0492e7e4586e), UINT64_C (0xd23c8e176d113600),
      UINT64_C (0x252f59cf0d9f04bb), UINT64_C (0xb3598080ce64a656),
      UINT64_C (0x993e1de72d36d310), UINT64_C (0xa2853b80f17f58ee),
      UINT64_C (0x1877b51e57a764d5), UINT64_C (0x001f837cc7350524)
    }
   #endif
  };

int
main (int argc, char **argv)
{
  unsigned int i;
  isaac_word r[ISAAC_WORDS];
  int iterations;

  /* Seed with zeros, and discard the first buffer of output,
     as that's what the standard programs do.  */
  static struct isaac_state s;
  isaac_seed (&s);
  isaac_refill (&s, r);

  for (i = 0; i < sizeof expected / sizeof expected[0]; i++)
    {
      isaac_refill (&s, r);
      ASSERT (memcmp (r, expected[i], sizeof r) == 0);
    }

  /* If invoked with a positive argument, run a benchmark;
     if with a negative, run a do-nothing benchmark.  */
  for (iterations = argc <= 1 ? 0 : strtol (argv[1], NULL, 10);
       iterations != 0;
       iterations += (iterations < 0 ? 1 : -1))
    if (0 <= iterations)
      isaac_refill (&s, r);

  return 0;
}