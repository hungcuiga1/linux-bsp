/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright (C) 2012-2019 ARM Limited (or its affiliates). */

#ifndef _CC_CRYPTO_CTX_H_
#define _CC_CRYPTO_CTX_H_

#include <linux/types.h>

#define CC_DRV_DES_IV_SIZE 8
#define CC_DRV_DES_BLOCK_SIZE 8

#define CC_DRV_DES_ONE_KEY_SIZE 8
#define CC_DRV_DES_DOUBLE_KEY_SIZE 16
#define CC_DRV_DES_TRIPLE_KEY_SIZE 24
#define CC_DRV_DES_KEY_SIZE_MAX CC_DRV_DES_TRIPLE_KEY_SIZE

#define CC_AES_IV_SIZE 16
#define CC_AES_IV_SIZE_WORDS (CC_AES_IV_SIZE >> 2)

#define CC_AES_BLOCK_SIZE 16
#define CC_AES_BLOCK_SIZE_WORDS 4

#define CC_AES_128_BIT_KEY_SIZE 16
#define CC_AES_128_BIT_KEY_SIZE_WORDS	(CC_AES_128_BIT_KEY_SIZE >> 2)
#define CC_AES_192_BIT_KEY_SIZE 24
#define CC_AES_192_BIT_KEY_SIZE_WORDS	(CC_AES_192_BIT_KEY_SIZE >> 2)
#define CC_AES_256_BIT_KEY_SIZE 32
#define CC_AES_256_BIT_KEY_SIZE_WORDS	(CC_AES_256_BIT_KEY_SIZE >> 2)
#define CC_AES_KEY_SIZE_MAX			CC_AES_256_BIT_KEY_SIZE
#define CC_AES_KEY_SIZE_WORDS_MAX		(CC_AES_KEY_SIZE_MAX >> 2)

#define CC_MD5_DIGEST_SIZE	16
#define CC_SHA1_DIGEST_SIZE	20
#define CC_SHA224_DIGEST_SIZE	28
#define CC_SHA256_DIGEST_SIZE	32
#define CC_SHA256_DIGEST_SIZE_IN_WORDS 8
#define CC_SHA384_DIGEST_SIZE	48
#define CC_SHA512_DIGEST_SIZE	64

#define CC_SHA1_BLOCK_SIZE 64
#define CC_SHA1_BLOCK_SIZE_IN_WORDS 16
#define CC_MD5_BLOCK_SIZE 64
#define CC_MD5_BLOCK_SIZE_IN_WORDS 16
#define CC_SHA224_BLOCK_SIZE 64
#define CC_SHA256_BLOCK_SIZE 64
#define CC_SHA256_BLOCK_SIZE_IN_WORDS 16
#define CC_SHA1_224_256_BLOCK_SIZE 64
#define CC_SHA384_BLOCK_SIZE 128
#define CC_SHA512_BLOCK_SIZE 128

#define CC_DIGEST_SIZE_MAX CC_SHA512_DIGEST_SIZE
#define CC_HASH_BLOCK_SIZE_MAX CC_SHA512_BLOCK_SIZE /*1024b*/

#define CC_HMAC_BLOCK_SIZE_MAX CC_HASH_BLOCK_SIZE_MAX

#define CC_MULTI2_SYSTEM_KEY_SIZE              32
#define CC_MULTI2_DATA_KEY_SIZE                8
#define CC_MULTI2_SYSTEM_N_DATA_KEY_SIZE \
	(CC_MULTI2_SYSTEM_KEY_SIZE + CC_MULTI2_DATA_KEY_SIZE)
#define	CC_MULTI2_BLOCK_SIZE					8
#define	CC_MULTI2_IV_SIZE					8
#define	CC_MULTI2_MIN_NUM_ROUNDS					8
#define	CC_MULTI2_MAX_NUM_ROUNDS					128

#define CC_DRV_ALG_MAX_BLOCK_SIZE CC_HASH_BLOCK_SIZE_MAX

#define CC_CPP_NUM_SLOTS	8
#define CC_CPP_NUM_ALGS		2
#define CC_SECURE_KEY_PACKAGE_BUF_SIZE_IN_BYTES		112
#define CC_SECURE_KEY_NONCE_SIZE_IN_BYTES		12
#define CC_SECURE_KEY_MULTI2_MIN_ROUNDS			8
#define CC_SECURE_KEY_MULTI2_MAX_ROUNDS			128
#define CC_SECURE_KEY_MAX_CTR_RANGE_VALUE		0x10000

/*
 * Secure key message format
 * Word No. Bits  Field Name
 * 0		31:0	Token
 * 1		31:0	Version
 * 2-4			Nonce
 * 5		2:0	Secure key type (aes128 / aes256 / multi2)
 *		3	Direction (enc / dec)
 *		7:4	Cipher mode (cbc / ctr / ofb / cbc_cts)
 *		15:8	Number of rounds (only for Multi2)
 *		31:16	reserved
 * 6		31:0	Lower bound address
 * 7		31:0	Upper bound address
 * 8-17			Restricted key
 *			(encryption of the secured key padded with zeroes)
 * 18-21		mac results
 */

#define CC_SECURE_KEY_TOKEN_OFFSET			0
#define CC_SECURE_KEY_TOKEN_VALUE			0x9DB2F60F
#define CC_SECURE_KEY_VERSION_OFFSET			1
#define CC_SECURE_KEY_NONCE_OFFSET			2

#define CC_SECURE_KEY_RESTRICT_CONFIG_OFFSET		5
#define CC_SECURE_KEY_RESTRICT_KEY_TYPE_BIT_SHIFT	0
#define CC_SECURE_KEY_RESTRICT_KEY_TYPE_BIT_SIZE	3
#define CC_SECURE_KEY_RESTRICT_DIR_BIT_SHIFT		3
#define CC_SECURE_KEY_RESTRICT_DIR_BIT_SIZE		1
#define CC_SECURE_KEY_RESTRICT_MODE_BIT_SHIFT		4
#define CC_SECURE_KEY_RESTRICT_MODE_BIT_SIZE		4
#define CC_SECURE_KEY_RESTRICT_NROUNDS_BIT_SHIFT	8
#define CC_SECURE_KEY_RESTRICT_NROUNDS_BIT_SIZE		8
#define CC_SECURE_KEY_RESTRICT_CTR_RANGE_BIT_SHIFT	16
#define CC_SECURE_KEY_RESTRICT_CTR_RANGE_BIT_SIZE	16
#define CC_SECURE_KEY_RESTRICT_LOWER_BOUNND_OFFSET	6
#define CC_SECURE_KEY_RESTRICT_UPPER_BOUND_OFFSET	8
#define CC_SECURE_KEY_RESTRICT_IV_CTR_OFFSET		10
#define CC_SECURE_KEY_RESTRICT_KEY_OFFSET		14
#define CC_SECURE_KEY_RESTRICT_KEY_SIZE_IN_BYTES	40

#define CC_SECURE_KEY_MAC_OFFSET			24
#define CC_SECURE_KEY_PACKAGE_BUF_SIZE_IN_WORDS		28

#define HW_CIPHER_MULTI2_OFB				2
#define CC_SECURE_KEY_BYTE_MASK				0xFF

#define CC_SECURE_KEY_MAINTENANCE_MIN_PAIRS		1
#define CC_SECURE_KEY_MAINTENANCE_MAX_PAIRS		5
#define CC_SECURE_KEY_MAJOR_VERSION			2
#define CC_SECURE_KEY_MINOR_VERSION			1
#define CC_SECURE_KEY_VERSION_NUM \
	(CC_SECURE_KEY_MAJOR_VERSION << 16 | CC_SECURE_KEY_MINOR_VERSION)

/*
 * CCM data structers: B0, A, text(key)
 * Note! each part should be a multiple of 16B
 */

/* B0[16B]: 0x7a,nonce[12],00,00,0x28 */
#define CC_SECURE_KEY_B0_SIZE_IN_BYTES		16
#define CC_SECURE_KEY_B0_FLAGS_OFFSET		0
#define CC_SECURE_KEY_B0_FLAGS_VALUE		0x7A
#define CC_SECURE_KEY_B0_NONCE_OFFSET		1
#define CC_SECURE_KEY_B0_DATA_LEN_OFFSET	15

/* A[32B]: 0x12,config,N,base[4],tail[4],token[4],sw_version[4],0[12]*/
#define CC_SECURE_KEY_ADATA_SIZE_IN_BYTES	48
#define CC_SECURE_KEY_ADATA_LEN_OFFSET \
	(DX_SECURE_KEY_B0_SIZE_IN_BYTES + 1)
#define CC_SECURE_KEY_ADATA_LEN_IN_BYTES	0x2E
#define CC_SECURE_KEY_ADATA_CONFIG_OFFSET	18
#define CC_SECURE_KEY_ADATA_NROUNDS_OFFSET	19
#define CC_SECURE_KEY_ADATA_LOWER_BOUND_OFFSET	20
#define CC_SECURE_KEY_ADATA_LOWER_BOUND_OFFSET_IN_WORDS \
	(CC_SECURE_KEY_ADATA_LOWER_BOUND_OFFSET / sizeof(uint32_t))
#define CC_SECURE_KEY_ADATA_UPPER_BOUND_OFFSET	28
#define CC_SECURE_KEY_ADATA_UPPER_BOUND_OFFSET_IN_WORDS \
	(CC_SECURE_KEY_ADATA_UPPER_BOUND_OFFSET / sizeof(uint32_t))
#define CC_SECURE_KEY_ADATA_TOKEN_OFFSET	36
#define CC_SECURE_KEY_ADATA_TOKEN_OFFSET_IN_WORDS \
	(CC_SECURE_KEY_ADATA_TOKEN_OFFSET / sizeof(uint32_t))
#define CC_SECURE_KEY_ADATA_VERSION_OFFSET	40
#define CC_SECURE_KEY_ADATA_VERSION_OFFSET_IN_WORDS \
	(CC_SECURE_KEY_ADATA_VERSION_OFFSET / sizeof(uint32_t))
#define CC_SECURE_KEY_ADATA_IV_CTR_OFFSET	44
#define CC_SECURE_KEY_ADATA_IV_CTR_OFFSET_IN_WORDS \
	(CC_SECURE_KEY_ADATA_IV_CTR_OFFSET / sizeof(uint32_t))
#define CC_SECURE_KEY_ADATA_CTR_RANGE_OFFSET	60
#define CC_SECURE_KEY_ADATA_CTR_RANGE_OFFSET_IN_WORDS \
	(CC_SECURE_KEY_ADATA_CTR_RANGE_OFFSET / sizeof(uint32_t))

/* text[48B]: key[40],0[8] */
#define CC_SECURE_KEY_CCM_KEY_OFFSET \
	(CC_SECURE_KEY_B0_SIZE_IN_BYTES + \
	 CC_SECURE_KEY_ADATA_SIZE_IN_BYTES)
#define CC_SECURE_KEY_CCM_KEY_OFFSET \
	(CC_SECURE_KEY_B0_SIZE_IN_BYTES + \
	 CC_SECURE_KEY_ADATA_SIZE_IN_BYTES)
#define CC_SECURE_KEY_CCM_KEY_OFFSET_IN_WORDS \
	(CC_SECURE_KEY_CCM_KEY_OFFSET / sizeof(uint32_t))
#define CC_SECURE_KEY_CCM_KEY_SIZE_IN_BYTES	48
#define CC_SECURE_KEY_CCM_BUF_IN_BYTES \
	(CC_SECURE_KEY_B0_SIZE_IN_BYTES + \
	 CC_SECURE_KEY_ADATA_SIZE_IN_BYTES + \
	 CC_SECURE_KEY_CCM_KEY_SIZE_IN_BYTES)
#define CC_SECURE_KEY_CCM_BUF_IN_WORDS \
	(CC_SECURE_KEY_CCM_BUF_IN_BYTES / sizeof(uint32_t))

#define CC_SECURE_KEY_SET_NONCE_LEN(val, noncelen) \
	((val) |= ((noncesize & 0xF) << 4))
#define CC_SECURE_KEY_SET_CTR_LEN(val, ctrlen) \
	((val) |= ((ctrlen) & 0xF))
#define CC_SECURE_KEY_GET_NONCE_LEN(val) (((val) >> 4) & 0xF)
#define CC_SECURE_KEY_GET_CTR_LEN(val)   ((val) & 0xF)

enum cc_cpp_alg {
	CC_CPP_SM4 = 1,
	CC_CPP_AES = 0
};

enum drv_engine_type {
	DRV_ENGINE_NULL = 0,
	DRV_ENGINE_AES = 1,
	DRV_ENGINE_DES = 2,
	DRV_ENGINE_HASH = 3,
	DRV_ENGINE_RC4 = 4,
	DRV_ENGINE_DOUT = 5,
	DRV_ENGINE_RESERVE32B = S32_MAX,
};

enum drv_multi2_mode {
	DRV_MULTI2_NULL = -1,
	DRV_MULTI2_ECB = 0,
	DRV_MULTI2_CBC = 1,
	DRV_MULTI2_OFB = 2,
	DRV_MULTI2_RESERVE32B = S32_MAX
};

enum secure_key_type {
	DRV_SECURE_KEY_AES_KEY128  = 0,
	DRV_SECURE_KEY_AES_KEY256  = 1,
	DRV_SECURE_KEY_MULTI2      = 2,
	DRV_SECURE_KEY_BYPASS      = 3,
	DRV_SECURE_KEY_MAINTENANCE = 7,
	DRV_SECURE_KEY_KSIZE_RESERVE32B = S32_MAX
};

enum secure_key_cipher_mode {
	DRV_SECURE_KEY_CIPHER_NULL_MODE = -1,
	DRV_SECURE_KEY_CIPHER_CBC       = 1,
	DRV_SECURE_KEY_CIPHER_CTR       = 2,
	DRV_SECURE_KEY_CIPHER_CTR_NONCE_CTR_PROT_NSP = 9,
	DRV_SECURE_KEY_CIPHER_CTR_NONCE_PROT = 10,
	DRV_SECURE_KEY_CIPHER_CBC_CTS = 11,
	DRV_SECURE_KEY_CIPHER_CBC_CTS1 = 14,
	DRV_SECURE_KEY_CIPHER_RESERVE32B = S32_MAX
};

typedef u8 skeypackagebuf_t[CC_SECURE_KEY_PACKAGE_BUF_SIZE_IN_BYTES];

typedef u8 skeynoncebuf_t[CC_SECURE_KEY_NONCE_SIZE_IN_BYTES];

enum drv_crypto_alg {
	DRV_CRYPTO_ALG_NULL = -1,
	DRV_CRYPTO_ALG_AES  = 0,
	DRV_CRYPTO_ALG_DES  = 1,
	DRV_CRYPTO_ALG_HASH = 2,
	DRV_CRYPTO_ALG_C2   = 3,
	DRV_CRYPTO_ALG_HMAC = 4,
	DRV_CRYPTO_ALG_AEAD = 5,
	DRV_CRYPTO_ALG_BYPASS = 6,
	DRV_CRYPTO_ALG_NUM = 7,
	DRV_CRYPTO_ALG_RESERVE32B = S32_MAX
};

enum drv_crypto_direction {
	DRV_CRYPTO_DIRECTION_NULL = -1,
	DRV_CRYPTO_DIRECTION_ENCRYPT = 0,
	DRV_CRYPTO_DIRECTION_DECRYPT = 1,
	DRV_CRYPTO_DIRECTION_DECRYPT_ENCRYPT = 3,
	DRV_CRYPTO_DIRECTION_RESERVE32B = S32_MAX
};

enum drv_cipher_mode {
	DRV_CIPHER_NULL_MODE = -1,
	DRV_CIPHER_ECB = 0,
	DRV_CIPHER_CBC = 1,
	DRV_CIPHER_CTR = 2,
	DRV_CIPHER_CBC_MAC = 3,
	DRV_CIPHER_XTS = 4,
	DRV_CIPHER_XCBC_MAC = 5,
	DRV_CIPHER_OFB = 6,
	DRV_CIPHER_CMAC = 7,
	DRV_CIPHER_CCM = 8,
	DRV_CIPHER_CBC_CTS = 11,
	DRV_CIPHER_GCTR = 12,
	DRV_CIPHER_ESSIV = 13,
	DRV_CIPHER_CBC_CTS1 = 14,
	DRV_CIPHER_RESERVE32B = S32_MAX
};

enum drv_hash_mode {
	DRV_HASH_NULL = -1,
	DRV_HASH_SHA1 = 0,
	DRV_HASH_SHA256 = 1,
	DRV_HASH_SHA224 = 2,
	DRV_HASH_SHA512 = 3,
	DRV_HASH_SHA384 = 4,
	DRV_HASH_MD5 = 5,
	DRV_HASH_CBC_MAC = 6,
	DRV_HASH_XCBC_MAC = 7,
	DRV_HASH_CMAC = 8,
	DRV_HASH_SM3 = 9,
	DRV_HASH_MODE_NUM = 10,
	DRV_HASH_RESERVE32B = S32_MAX
};

enum drv_hash_hw_mode {
	DRV_HASH_HW_MD5 = 0,
	DRV_HASH_HW_SHA1 = 1,
	DRV_HASH_HW_SHA256 = 2,
	DRV_HASH_HW_SHA224 = 10,
	DRV_HASH_HW_SHA512 = 4,
	DRV_HASH_HW_SHA384 = 12,
	DRV_HASH_HW_GHASH = 6,
	DRV_HASH_HW_SM3 = 14,
	DRV_HASH_HW_RESERVE32B = S32_MAX
};

#endif /* _CC_CRYPTO_CTX_H_ */
