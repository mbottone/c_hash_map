//
//  Helpers.h
//  CHashMap
//
//  Created by Michael Bottone on 2/18/16.
//  Copyright © 2016 Michael Bottone. All rights reserved.
//

#ifndef Helpers_h
#define Helpers_h

#include <string.h>

#pragma mark - Macros

#define new(size, type) ({malloc(size * sizeof(type));})
#define newNull(size, type) ({calloc(size, sizeof(type));})
#define newSize(pointer, size, type) ({realloc(pointer, size * sizeof(type));})

#pragma mark - Custom Types

typedef char* string;
typedef void* generic;
typedef unsigned long ulong;
typedef enum { false, true } bool;

#pragma mark - Public Method Definitions

bool equalString(string, string);

#endif /* Helpers_h */
