#ifndef seed_prob_table_H
#define seed_prob_table_H

typedef struct {
    double *probs;
} seedprobtable;


seedprobtable* load_counts_table(FILE* seedProbTableFile, int wordBits);


#endif
