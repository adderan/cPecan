#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "utilities.h"

#include "seed_prob_table.h"


seedprobtable* load_prob_table(FILE* seedProbTableFile, int wordBits) {
    seedprobtable *table = malloc(sizeof(seedprobtable));
    table->probs = calloc(10, sizeof(double));

    u32 numSeeds = ((u32) 1) << wordBits;
    u64 bytesNeeded = round_up_16 (((u64) numSeeds) * sizeof(double));

    table->probs = (u64*) zalloc_or_die ("seed_prob_table", bytesNeeded);

    char line[500];
    while(fgets(line, sizeof(line), seedProbTableFile)) {
        u32 word = 0;
        double prob = 0.0;
        sscanf(line, "%lx %lf\n", &word, &prob);
        //fprintf(stderr, "Parsed probability %lf\n", prob);
        table->probs[word] = prob;
        //fprintf(stderr, "Table probability %lf\n", table->probs[word]);
        
    }

    return table;
}
