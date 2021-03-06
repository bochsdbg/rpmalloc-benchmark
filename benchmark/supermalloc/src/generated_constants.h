#ifndef GENERATED_CONSTANTS_H
#define GENERATED_CONSTANTS_H
// Do not edit this file.  This file is automatically generated
//  from ../src/objsizes.cc

#include "malloc_internal.h"
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
// For chunks containing small objects, we reserve the first
// several pages for bitmaps and linked lists.
//   There's a per_page struct containing 2 pointers and a
//   bitmap, and there are 512 of those.
// As a result, there is no overhead in each page, but there is
// overhead per chunk, which affects the large object sizes.

// We obtain hugepages from the operating system via mmap(2).
// By `hugepage', I mean only mmapped pages.
// By `page', I mean only a page inside a hugepage.
// Each hugepage has a bin number.
// We use a static array to keep track of the bin of each a hugepage.
//  Bins [0..first_huge_bin_number) give the size of an object.
//  Larger bin numbers B indicate the object size, coded as
//     malloc_usable_size(object) = page_size*(bin_of(object)-first_huge_bin_number;
static const size_t Ki = 1024;  /* Kibi */
static const size_t Me = Ki*Ki; /* Mebi */
extern const struct static_bin_s { uint64_t object_size, folio_size; objects_per_folio_t objects_per_folio; folios_per_chunk_t folios_per_chunk;  uint8_t overhead_pages_per_chunk, object_division_shift_magic, folio_division_shift_magic; uint64_t object_division_multiply_magic, folio_division_multiply_magic;} static_bin_info[];
static const binnumber_t bin_number_limit = 74;
static const size_t largest_small         = 14272;
static const uint64_t offset_of_first_object_in_large_chunk = 4096;
static const size_t largest_large         = 1044480;
static const binnumber_t first_large_bin_number = 40;
static const binnumber_t first_huge_bin_number   = 47;
#define REPEAT_FOR_SMALL_BINS(x) x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x
struct per_folio; // Forward decl needed here.
struct dynamic_small_bin_info {
  union {
    struct {
      per_folio *b0[514];
      per_folio *b1[2050];
      per_folio *b2[1026];
      per_folio *b3[2050];
      per_folio *b4[258];
      per_folio *b5[1026];
      per_folio *b6[514];
      per_folio *b7[1026];
      per_folio *b8[130];
      per_folio *b9[514];
      per_folio *b10[258];
      per_folio *b11[514];
      per_folio *b12[66];
      per_folio *b13[258];
      per_folio *b14[130];
      per_folio *b15[258];
      per_folio *b16[34];
      per_folio *b17[130];
      per_folio *b18[66];
      per_folio *b19[130];
      per_folio *b20[18];
      per_folio *b21[66];
      per_folio *b22[66];
      per_folio *b23[10];
      per_folio *b24[66];
      per_folio *b25[66];
      per_folio *b26[66];
      per_folio *b27[6];
      per_folio *b28[66];
      per_folio *b29[66];
      per_folio *b30[66];
      per_folio *b31[4];
      per_folio *b32[66];
      per_folio *b33[66];
      per_folio *b34[3];
      per_folio *b35[66];
      per_folio *b36[66];
      per_folio *b37[3];
      per_folio *b38[66];
      per_folio *b39[66];
    };
    per_folio *b[11920];
  };
};
// dynamic_small_bin_offset is declared const even though one implementation looks in an array.  The array is a const
static uint32_t dynamic_small_bin_offset(binnumber_t bin) __attribute((const)) __attribute__((unused)) __attribute__((warn_unused_result));
static uint32_t dynamic_small_bin_offset(binnumber_t bin) {
  if (0) {
    switch(bin) {
      case 0: return 0;
      case 1: return 514;
      case 2: return 2564;
      case 3: return 3590;
      case 4: return 5640;
      case 5: return 5898;
      case 6: return 6924;
      case 7: return 7438;
      case 8: return 8464;
      case 9: return 8594;
      case 10: return 9108;
      case 11: return 9366;
      case 12: return 9880;
      case 13: return 9946;
      case 14: return 10204;
      case 15: return 10334;
      case 16: return 10592;
      case 17: return 10626;
      case 18: return 10756;
      case 19: return 10822;
      case 20: return 10952;
      case 21: return 10970;
      case 22: return 11036;
      case 23: return 11102;
      case 24: return 11112;
      case 25: return 11178;
      case 26: return 11244;
      case 27: return 11310;
      case 28: return 11316;
      case 29: return 11382;
      case 30: return 11448;
      case 31: return 11514;
      case 32: return 11518;
      case 33: return 11584;
      case 34: return 11650;
      case 35: return 11653;
      case 36: return 11719;
      case 37: return 11785;
      case 38: return 11788;
      case 39: return 11854;
    }
    abort(); // cannot get here.
  } else {
    const static int offs[]={0, 514, 2564, 3590, 5640, 5898, 6924, 7438, 8464, 8594, 9108, 9366, 9880, 9946, 10204, 10334, 10592, 10626, 10756, 10822, 10952, 10970, 11036, 11102, 11112, 11178, 11244, 11310, 11316, 11382, 11448, 11514, 11518, 11584, 11650, 11653, 11719, 11785, 11788, 11854};
    return offs[bin];
  }
}
static binnumber_t size_2_bin(size_t size) __attribute((unused)) __attribute((const));
static binnumber_t size_2_bin(size_t size) {
  if (size <= 8) return 0;
  if (size <= 320) {
    // bit hacking to calculate the bin number for the first group of small bins.
    int nzeros = __builtin_clzl(size);
    size_t roundup = size + (1ul<<(61-nzeros)) -1;
    int nzeros2 = __builtin_clzl(roundup);
    return 4*(60-nzeros2)+ ((roundup>>(61-nzeros2))&3);
  }
  //  if (size <= 8) return 0;
  //  if (size <= 10) return 1;
  //  if (size <= 12) return 2;
  //  if (size <= 14) return 3;
  //  if (size <= 16) return 4;
  //  if (size <= 20) return 5;
  //  if (size <= 24) return 6;
  //  if (size <= 28) return 7;
  //  if (size <= 32) return 8;
  //  if (size <= 40) return 9;
  //  if (size <= 48) return 10;
  //  if (size <= 56) return 11;
  //  if (size <= 64) return 12;
  //  if (size <= 80) return 13;
  //  if (size <= 96) return 14;
  //  if (size <= 112) return 15;
  //  if (size <= 128) return 16;
  //  if (size <= 160) return 17;
  //  if (size <= 192) return 18;
  //  if (size <= 224) return 19;
  //  if (size <= 256) return 20;
  //  if (size <= 320) return 21;
  if (size <= 448) return 22;
  if (size <= 512) return 23;
  if (size <= 576) return 24;
  if (size <= 704) return 25;
  if (size <= 960) return 26;
  if (size <= 1024) return 27;
  if (size <= 1216) return 28;
  if (size <= 1472) return 29;
  if (size <= 1984) return 30;
  if (size <= 2048) return 31;
  if (size <= 2752) return 32;
  if (size <= 3904) return 33;
  if (size <= 4096) return 34;
  if (size <= 5312) return 35;
  if (size <= 7232) return 36;
  if (size <= 8192) return 37;
  if (size <= 10048) return 38;
  if (size <= 14272) return 39;
  if (size <= 16384) return 40;
  if (size <= 32768) return 41;
  if (size <= 65536) return 42;
  if (size <= 131072) return 43;
  if (size <= 258048) return 44;
  if (size <= 520192) return 45;
  if (size <= 1044480) return 46;
  if (size <= 2097152) return 47; // Special case to handle the values between the largest_large and chunksize/2
  return 47 + lg_of_power_of_two(hyperceil(size)) - log_chunksize;
}
static size_t bin_2_size(binnumber_t bin) __attribute((unused)) __attribute((const));
static size_t bin_2_size(binnumber_t bin) {
  bassert(bin < bin_number_limit);
  return static_bin_info[bin].object_size;
}

static inline uint32_t divide_offset_by_objsize(uint32_t offset, binnumber_t bin) {
  return (offset * static_bin_info[bin].object_division_multiply_magic) >> static_bin_info[bin].object_division_shift_magic;
}

static inline uint32_t divide_offset_by_foliosize(uint32_t offset, binnumber_t bin) {
  return (offset * static_bin_info[bin].folio_division_multiply_magic) >> static_bin_info[bin].folio_division_shift_magic;
}

#endif
