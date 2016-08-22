#include "roman.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int args_valid(const char* num1, const char* num2)
{
    //check for null inputs
    if ((num1 == 0) || (num2 == 0))
        return 0;
    
    //check for empty inputs
    if ((num1[0] == 0) || (num2[0] == 0))
        return 0;
    
    return 1;
}

static const char* expander(const char* num)
{
    if (strcmp(num, "IV") == 0)
        num = "IIII";
    return num;
}

static char* merge(const char* num1, const char* num2)
{
    size_t len1, len2;
    char* retval;
    char* ptr;
    
    len1 = strlen(num1);
    len2 = strlen(num2);
    retval = malloc(len1 + len2 + 1);
    ptr = retval;
    
    while(*num1 == 'X')
        *ptr++ = *num1++;
    while(*num2 == 'X')
        *ptr++ = *num2++;
    while(*num1 == 'V')
        *ptr++ = *num1++;
    while(*num2 == 'V')
        *ptr++ = *num2++;
    while(*num1 == 'I')
        *ptr++ = *num1++;
    while(*num2 == 'I')
        *ptr++ = *num2++;
    *ptr = 0;
    
    return retval;
}

static char* compactor_add(char* retval)
{
    char* ptr1 = retval;
    char* ptr2 = retval;
    int changed = 0;
    int count = 0;
    int i;
    
    while (*ptr1 != 0)
    {
        if (*ptr1 == 'I')
        {
            count++;
            if (count == 5)
            {
                count = 0;
                *ptr2++ = 'V';
                changed = 1;
            }
        }
        else if ((ptr1[0] == 'V') && (ptr1[1] == 'V'))
        {
            *ptr2++ = 'X';
            ptr1++;
            changed = 1;
        }
        else
        {
            *ptr2++ = *ptr1;
            count = 0;
        }
        ptr1++;
    }
    for (i=0; i < count; i++)
        *ptr2++ = 'I';
    *ptr2++ = 0;
    
    if (changed)
        retval = compactor_add(retval);
    
    return retval;
}

static char* compactor_nice(char* retval)
{
    char* ptr1 = retval;
    char* ptr2 = retval;
    int count = 0;
    int i;
    
    while (*ptr1 != 0)
    {
        if (*ptr1 == 'I')
        {
            count++;
            if (count == 4)
            {
                count = 0;
                if ((ptr2 != retval) && (*(ptr2 - 1) == 'V'))
                { 
                    ptr2 -= 1;
                    *ptr2++ = 'I';
                    *ptr2++ = 'X';
                }
                else
                {
                    *ptr2++ = 'I';
                    *ptr2++ = 'V';
                }
            }
        }
        else
        {
            *ptr2++ = *ptr1;
            count = 0;
        }
        ptr1++;
    }
    
    for (i=0; i < count; i++)
        *ptr2++ = 'I';
    *ptr2++ = 0;
    
    return retval;
}

const char* roman_add(const char* num1, const char* num2)
{
    char* retval;
    
    if (!args_valid(num1, num2))
        return 0;
    
    //expand if needed
    num1 = expander(num1);
    num2 = expander(num2);
    
    //merge numbers to add
    retval = merge(num1, num2);
    retval = compactor_add(retval);
    retval = compactor_nice(retval);
    
    return retval;
}
