#ifndef sampling_rates_table_H
#define sampling_rates_table_H

typedef struct {
    double *probs;
} samplingratestable;


samplingratestable* load_prob_table(FILE* samplingRatesFile, int wordBits);


#endif
