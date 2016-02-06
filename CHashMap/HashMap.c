//
//  HashMap.c
//  CHashMap
//
//  Created by Michael Bottone on 2/4/16.
//  Copyright © 2016 Michael Bottone. All rights reserved.
//

#include "HashMap.h"

HashMap* createHashMap()
{
    HashMap* map = new(1, HashMap);
    
    map->bucketSize = BUCKET_SIZE;
    map->numOfBuckets = MIN_BUCKETS;
    
    map->table = newNull(map->numOfBuckets, MapEntry*);
    map->localDepths = newNull(map->numOfBuckets, int);
    
    for (int i = 0; i < map->numOfBuckets; i++)
    {
        map->localDepths[i] = map->numOfBuckets;
    }
    
    return map;
}

ulong computeHash(string key)
{
    ulong hash = 5381;
    int c;
    
    while ((c = *key++))
    {
        hash = ((hash << 5) + hash) + c;
    }
    
    return hash;
}

MapEntry* createMapEntry(string key, generic value)
{
    MapEntry* entry = new(1, MapEntry);
    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    
    return entry;
}

bool equalString(string a, string b)
{
    return strncmp(a, b, strlen(a)) == 0;
}

void expandMap(HashMap* map)
{
    int newTableSize = map->numOfBuckets * 2;
    map->table = newSize(map->table, newTableSize, MapEntry*);
    
    for (int i = 0; i < map->numOfBuckets;i ++)
    {
        map->table[i + map->numOfBuckets] = map->table[i];
    }
    
    map->numOfBuckets = newTableSize;
}

int insertIntoBucket(HashMap* map, MapEntry* entry, int bucket)
{
    MapEntry* currentEntry = map->table[bucket];
    int count = 1;
    
    if (currentEntry == NULL)
    {
        map->table[bucket] = entry;
    }
    else
    {
        while (currentEntry != NULL)
        {
            count++;
            if (equalString(currentEntry->key, entry->key))
            {
                currentEntry->value = entry->value;
                return (count - 1);
            }
            
            if (currentEntry->next == NULL)
            {
                break;
            }
            
            currentEntry = currentEntry->next;
        }
        
        currentEntry->next = entry;
    }
    
    return count;
}

void splitBucket(HashMap* map, int bucket)
{
    MapEntry *bucketEntry = map->table[bucket];
    int localDepth = map->localDepths[bucket];
    int newDepth = localDepth * 2;
    
    for (int i = bucket; i < map->numOfBuckets; i += localDepth)
    {
        map->table[i] = NULL;
    }
    
    MapEntry* nextStorage = NULL;
    while (bucketEntry != NULL)
    {
        nextStorage = bucketEntry->next;
        bucketEntry->next = NULL;
        
        int newBucket = computeHash(bucketEntry->key) % newDepth;
        map->localDepths[newBucket] = newDepth;
        insertIntoBucket(map, bucketEntry, newBucket);
        
        bucketEntry = nextStorage;
    }
    
    for (int i = (bucket + newDepth); i < map->numOfBuckets; i += newDepth)
    {
        map->table[i] = map->table[i - newDepth];
        map->table[i + localDepth] = map->table[i - newDepth + localDepth];
    }
}

void setHashValue(HashMap* map, string key, generic value)
{
    int bucket = computeHash(key) % map->numOfBuckets;
    
    MapEntry *insertEntry = createMapEntry(key, value);
    
    int count = insertIntoBucket(map, insertEntry, bucket);
    
    if (count > map->bucketSize)
    {
        if (map->localDepths[bucket] == map->numOfBuckets)
        {
            expandMap(map);
        }
        
        splitBucket(map, bucket);
    }
}

generic getHashValue(HashMap* map, string key)
{
    int bucket = computeHash(key) % map->numOfBuckets;
    
    MapEntry *entry = map->table[bucket];
    
    while (entry != NULL && equalString(entry->key, key) == false)
    {
        entry = entry->next;
    }
    
    return (entry ? entry->value : NULL);
}
