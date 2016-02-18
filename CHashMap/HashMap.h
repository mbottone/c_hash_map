//
//  HashMap.h
//  CHashMap
//
//  Created by Michael Bottone on 2/4/16.
//  Copyright © 2016 Michael Bottone. All rights reserved.
//

#ifndef HashMap_h
#define HashMap_h

#include "Helpers.h"

#pragma mark - Constants

#define BUCKET_SIZE 4
#define MIN_BUCKETS 2

#pragma mark - Public Data Structures

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

#pragma mark - Public Method Definitions

HashMap* createHashMap();
void setHashValue(HashMap*, string, generic);
generic getHashValue(HashMap*, string);

#endif /* HashMap_h */
