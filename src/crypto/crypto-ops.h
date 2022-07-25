// Copyright (c) 2018-2021 Zano Project
// Copyright (c) 2012-2013 The Cryptonote developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once
#include <stddef.h> // size_t

/* From fe.h */

typedef int32_t fe[10];

/* From ge.h */

typedef struct {
  fe X;
  fe Y;
  fe Z;
} ge_p2;

typedef struct {
  fe X;
  fe Y;
  fe Z;
  fe T;
} ge_p3;

typedef struct {
  fe X;
  fe Y;
  fe Z;
  fe T;
} ge_p1p1;

typedef struct {
  fe yplusx;
  fe yminusx;
  fe xy2d;
} ge_precomp;

typedef struct {
  fe YplusX;
  fe YminusX;
  fe Z;
  fe T2d;
} ge_cached;

/* From ge_add.c */

void ge_add(ge_p1p1 *, const ge_p3 *, const ge_cached *);

/* From ge_double_scalarmult.c, modified */

typedef ge_cached ge_dsmp[8];
extern const ge_precomp ge_Bi[8];
void ge_dsm_precomp(ge_dsmp r, const ge_p3 *s);
void ge_double_scalarmult_base_vartime(ge_p2 *, const unsigned char *, const ge_p3 *, const unsigned char *);

/* From ge_frombytes.c, modified */

extern const fe fe_sqrtm1;
extern const fe fe_d;
int ge_frombytes_vartime(ge_p3 *, const unsigned char *);

/* From ge_p1p1_to_p2.c */

void ge_p1p1_to_p2(ge_p2 *, const ge_p1p1 *);

/* From ge_p1p1_to_p3.c */

void ge_p1p1_to_p3(ge_p3 *, const ge_p1p1 *);

/* From ge_p2_dbl.c */

void ge_p2_dbl(ge_p1p1 *, const ge_p2 *);

/* From ge_p3_to_cached.c */

extern const fe fe_d2;
void ge_p3_to_cached(ge_cached *, const ge_p3 *);

/* From ge_p3_to_p2.c */

void ge_p3_to_p2(ge_p2 *, const ge_p3 *);

/* From ge_p3_tobytes.c */

void ge_p3_tobytes(unsigned char *, const ge_p3 *);

/* From ge_scalarmult_base.c */

extern const ge_precomp ge_base[32][8];
void ge_scalarmult_base(ge_p3 *, const unsigned char *);

/* From ge_tobytes.c */

void ge_tobytes(unsigned char *, const ge_p2 *);

/* From sc_reduce.c */

void sc_reduce(unsigned char *);

/* New code */

void ge_scalarmult(ge_p2 *, const unsigned char *, const ge_p3 *);
void ge_scalarmult_p3(ge_p3 *, const unsigned char *, const ge_p3 *);
void ge_double_scalarmult_precomp_vartime(ge_p2 *, const unsigned char *, const ge_p3 *, const unsigned char *, const ge_dsmp);
void ge_mul8(ge_p1p1 *, const ge_p2 *);
void ge_mul8_p3(ge_p3 *, const ge_p3 *);
void ge_fromfe_frombytes_vartime(ge_p2 *, const unsigned char *);
void ge_p2_to_p3(ge_p3 *r, const ge_p2 *t);
void ge_bytes_hash_to_ec(ge_p3 *, const void *, size_t);
void ge_bytes_hash_to_ec_32(ge_p3 *, const unsigned char *);
void ge_cached_to_p2(ge_p2 *r, const ge_cached *c);

void ge_p3_0(ge_p3 *h);
void ge_sub(ge_p1p1 *, const ge_p3 *, const ge_cached *);
void ge_double_scalarmult_base_vartime_p3(ge_p3 *r, const unsigned char *a, const ge_p3 *A, const unsigned char *b);
void ge_scalarmult_vartime_p3(ge_p3 *r, const unsigned char *a, const ge_p3 *A);
void ge_scalarmult_vartime_p3_v2(ge_p3 *r, const unsigned char *a, const ge_p3 *A);

extern const fe fe_ma2;
extern const fe fe_ma;
extern const fe fe_fffb1;
extern const fe fe_fffb2;
extern const fe fe_fffb3;
extern const fe fe_fffb4;

void sc_0(unsigned char *);
void sc_reduce32(unsigned char *);
void sc_add(unsigned char *, const unsigned char *, const unsigned char *);
void sc_sub(unsigned char *, const unsigned char *, const unsigned char *);
void sc_mulsub(unsigned char *, const unsigned char *, const unsigned char *, const unsigned char *);
void sc_mul(unsigned char *, const unsigned char *, const unsigned char *);
void sc_muladd(unsigned char* s, const unsigned char* a, const unsigned char* b, const unsigned char* c);
int sc_check(const unsigned char *);
int sc_isnonzero(const unsigned char *); /* Doesn't normalize */
void sc_invert(unsigned char*, const unsigned char*);

void fe_sq(fe h, const fe f);
int fe_isnonzero(const fe f);
void fe_sub(fe h, const fe f, const fe g);
void fe_mul(fe, const fe, const fe);
void fe_frombytes(fe h, const unsigned char *s);
void fe_invert(fe out, const fe z);
void fe_tobytes(unsigned char *s, const fe h);
int fe_isnegative(const fe f);
