/*
 * Compiler.h
 *
 *  Created on: Mar 25, 2016
 *      Author: Mena Safwat
 */

#ifndef COMPILER_H_
#define COMPILER_H_

#include "Compiler_Cfg.h"

#define AUTOMATIC
#define STATIC static
#define PTR_FAR


#define VAR(varType,memclass)      varType
#define FUNC(returnType,memclass)  returnType
#define P2CONST(ptrType,memclass,ptrclass)      const ptrType *
#define P2VAR(ptrType,memclass,ptrclass)        ptrType *


#endif /* COMPILER_H_ */
