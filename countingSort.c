//
//  countingSort.c
//  AlgDemo
//
//  Created by dongyuanlong on 1/30/19.
//  Copyright © 2019 dongyuanlong. All rights reserved.
//

#include "countingSort.h"
void countingSort(arr, maxValue) {
    var bucket = new Array(maxValue + 1),
    sortedIndex = 0;
    arrLen = arr.length,
    bucketLen = maxValue + 1;
    
    for (var i = 0; i < arrLen; i++) {
        if (!bucket[arr[i]]) {
            bucket[arr[i]] = 0;
        }
        bucket[arr[i]]++;
    }
    
    for (var j = 0; j < bucketLen; j++) {
        while(bucket[j] > 0) {
            arr[sortedIndex++] = j;
            bucket[j]--;
        }
    }
    
    return arr;
}
