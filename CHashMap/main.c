//
//  main.c
//  CHashMap
//
//  Created by Michael Bottone on 2/4/16.
//  Copyright © 2016 Michael Bottone. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

#include "HashMap.h"

int main()
{
    HashMap* map = createHashMap();
    
    setHashValue(map, "Michael", "Bottone");
    setHashValue(map, "Neal", "Thacker");
    setHashValue(map, "Ryan", "Smith");
    setHashValue(map, "Matthew", "Huff");
    
    printf("map[\"%s\"] = %s\n", "Michael", getHashValue(map, "Michael"));
    printf("map[\"%s\"] = %s\n", "Ryan", getHashValue(map, "Ryan"));
    printf("map[\"%s\"] = %s\n", "Neal", getHashValue(map, "Neal"));
    printf("map[\"%s\"] = %s\n", "Matthew", getHashValue(map, "Matthew"));
    
    return EXIT_SUCCESS;
}
