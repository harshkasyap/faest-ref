#ifndef FAEST_VOLE_H
#define FAEST_VOLE_H

#include "vc.h"

FAEST_BEGIN_C_DECL

// k_b is at most 12, so chalout needs to point to an array of at most 12 bytes
int ChalDec(const uint8_t* chal, unsigned int i, unsigned int k0, unsigned int t0, unsigned int k1,
            unsigned int t1, uint8_t* chalout);

void voleCommit(const uint8_t* rootKey, uint32_t outlen, const faest_paramset_t* params,
                uint8_t* hcom, vec_com_t* vecCom, uint8_t** c, uint8_t* u, uint8_t** v);

void voleVerify(const uint8_t* chal, uint8_t** pdec, uint8_t** com_j, uint32_t lambda,
                uint32_t lambdaBytes, uint32_t outlen, uint32_t tau, uint32_t k0, uint32_t k1,
                uint8_t* hcom, uint8_t** q, vec_com_rec_t** vecComRec);

void ConvertToVoleProver(uint32_t lambda, uint32_t lambdaBytes, const uint8_t* sd,
                         uint32_t numVoleInstances, uint32_t depth, uint32_t outLenBytes,
                         uint8_t* u, uint8_t* v);

void ConvertToVoleVerifier(uint32_t lambda, uint32_t lambdaBytes, const uint8_t* sd,
                           uint32_t numVoleInstances, uint32_t depth, uint32_t outLenBytes,
                           uint8_t* v);

FAEST_END_C_DECL

#endif