//
//  Helpers.c
//  CHashMap
//
//  Created by Michael Bottone on 2/18/16.
//  Copyright © 2016 Michael Bottone. All rights reserved.
//

#include "Helpers.h"

#pragma mark - Public Method Implementations

bool equalString(string a, string b)
{
    return strncmp(a, b, strlen(a)) == 0;
}