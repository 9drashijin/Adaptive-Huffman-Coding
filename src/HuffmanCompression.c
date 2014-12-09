#include "HuffmanCompression.h"
#include "AdaptiveHuffman.h"
#include "InStream.h"
#include "OutStream.h"
#include "ErrorCode.h"
#include "CException.h"
#include <stdio.h>
#include <malloc.h>
#include <Utils.h>

HuffmanNode *arraySymbol[Symbol];
HuffmanNode *root;
/**
 *  
 *  START
 *   Symbol first time? seen?
 *   NO  : new symbol > newNode create, go back to parent
 *  YES : goto symbol, is this max order?
 *                       NO  : Swap with max order of same freq
 *                       YES : Increment freq
 *   Is this Root ?
 *   NO  : go back to START
 *   YES : Done END
 *
*/
void huffmanCompress(InStream *in, OutStream *out){
  HuffmanNode *rootNode = adaptiveHuffmanTreeInit();
  HuffmanNode *returnedNewNode = adaptiveHuffmanTreeInit();
  rootNode->order = Symbol;
  uint8 Symb;
  int i;
  for(i = 0 ; i < Symbol ; i++){
    arraySymbol[i] == NULL;
  }
  while(!feof(in->file)){
    if (!(Symb = streamReadBits(in->file))){break;}
    printf("symbol: %c",Symb);
    if(!arraySymbol[Symb]){
      printf(" 1stTIME \n");
      streamWriteBitsNode(out->file,returnedNewNode);
      streamWriteBits(out->file,(unsigned char)Symb);
      returnedNewNode = adaptiveHuffmanTreeBuild(rootNode,Symb);
      huffmanUpdateAndRestructure(returnedNewNode->parent->parent);
    }
    else{
    printf(" SEEN \n");
      streamWriteBitsNode(out->file,arraySymbol[Symb]);
      huffmanUpdateAndRestructure(arraySymbol[Symb]);
    }
  }
  for (i = 0 ; i < Symbol; i++){
    if (arraySymbol[i] == NULL){
      break;
    }
    freeNode(arraySymbol[i]);
  }
  freeNode(rootNode);
}



