#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "utilities.h"

#include "sampling_rates_table.h"


samplingratestable* load_prob_table(FILE* samplingRatesFile, int wordBits) {
    samplingratestable *table = (samplingratestable*)malloc(sizeof(samplingratestable));

    u32 numSeeds = ((u32) 1) << wordBits;
    u64 bytesNeeded = round_up_16 (((u64) numSeeds) * sizeof(double));

    table->probs = (double*) zalloc_or_die ("sampling_rates_table", bytesNeeded);

    char line[500];
    u32 word = 0;
    double prob;
    char seed[100];
    while(fgets(line, sizeof(line), samplingRatesFile)) {
        int res = sscanf(line, "%s\t%x\t%lf", seed, &word, &prob);
        if (res != 3) continue;
        //fprintf(stderr, "Parsed probability %f\n", prob);
        table->probs[word] = prob;
        //fprintf(stderr, "table probability %f\n", table->probs[word]);
        
    }

    return table;
}
