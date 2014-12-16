#ifndef HuffmanCompression_H
#define HuffmanCompression_H

#include "InStream.h"
#include "OutStream.h"
#include "AdaptiveHuffman.h"
#include "Utils.h"

extern HuffmanNode *arraySymbol[Symbol];

void huffmanCompress(InStream *in, OutStream *out);

#endif // HuffmanCompression_H
