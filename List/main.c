/**
 MIT License
 
 Copyright (c) 2018 Matias Barrientos.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "List.h"

int main(int argc, const char * argv[]) {
    
    List * lista = createList();
    
    int * data = NULL;
    
    int i;
    
    for (i = 0; i < 10; i++) {
        data = (int *)malloc(sizeof(int));
        *data = i;
        pushBack(lista, data);
    }
    
    data = firstList(lista);
    
    data = (int *)malloc(sizeof(int));
    *data = 11;
    
    pushCurrent(lista, data);
    
    data = firstList(lista);
    
    while (data != NULL) {
        printf("%d\n", *data);
        data = nextList(lista);
    }
    
    printf("\n");
    
    free(popBack(lista));
    free(popFront(lista));
    
    data = lastList(lista);
    
    while (data != NULL) {
        printf("%d\n", *data);
        free(data);
        data = prevList(lista);
    }
    
    removeAllList(lista);
    
    return 0;
}
