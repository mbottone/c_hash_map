//
//  HashMap.h
//  CHashMap
//
//  Created by Michael Bottone on 2/4/16.
//  Copyright © 2016 Michael Bottone. All rights reserved.
//

#ifndef HashMap_h
#define HashMap_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants

#define BUCKET_SIZE 4
#define MIN_BUCKETS 2

// Macros

#define new(size, type) ({malloc(size * sizeof(type));})
#define newNull(size, type) ({calloc(size, sizeof(type));})
#define newSize(pointer, size, type) ({realloc(pointer, size * sizeof(type));})

// Custom Types

typedef char* string;
typedef void* generic;
typedef unsigned long ulong;
typedef enum { false, true } bool;

// Custom Data Structures

typedef struct MapEntry
{
    string key;
    generic value;
    struct MapEntry* next;
} MapEntry;

typedef struct HashMap
{
    MapEntry** table;
    int* localDepths;
    
    int bucketSize;
    int numOfBuckets;
} HashMap;

// Public Method Signatures

HashMap* createHashMap();
void setHashValue(HashMap*, string, generic);
generic getHashValue(HashMap*, string);

#endif /* HashMap_h */
