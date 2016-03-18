#ifndef LIBWALLY_BIP_39_H
#define LIBWALLY_BIP_39_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

struct words;

/** Valid entropy lengths */
#define BIP39_ENTROPY_LEN_128 16u
#define BIP39_ENTROPY_LEN_160 20u
#define BIP39_ENTROPY_LEN_192 24u
#define BIP39_ENTROPY_LEN_224 28u
#define BIP39_ENTROPY_LEN_256 32u

/**
 * Get the list of default supported languages.
 *
 * The names are returned separated by ' ' as a constant string.
 */
const char *bip39_get_languages();

/**
 * Get the default word list for language @lang.
 *
 * If @lang is NULL or not found the default English list is returned.
 */
const struct words *bip39_get_wordlist(const char *lang);

/**
 * Generate a mnemonic sentence from the entropy in @bytes.
 * @w Word list to use. Pass NULL to use the default English list.
 * @bytes: Entropy to covert.
 * @len: The length of @bytes in bytes.
 */
char *bip39_mnemonic_from_bytes(const struct words *w, const uint8_t *bytes,
                                size_t len);

/**
 * Convert a mnemonic sentence into entropy at @bytes.
 * @w Word list to use. Pass NULL to use the default English list.
 * @mnemonic Mnemonic to convert.
 * @bytes: Where to store the resulting entropy.
 * @len: The length of @bytes in bytes.
 */
size_t bip39_mnemonic_to_bytes(const struct words *w, const char *mnemonic,
                               uint8_t *bytes, size_t len);

/**
 * Validate the checksum embedded in the mnemonic sentence @mnemonic.
 * @w Word list to use. Pass NULL to use the default English list.
 * @mnemonic Mnemonic to validate.
 */
bool bip39_mnemonic_is_valid(const struct words *w, const char *mnemonic);

#endif /* LIBWALLY_BIP_39_H */