#include "../include/tokenizer.h"



tokenizer tokenizer_start(const char *src) {
    tokenizer tk = {src, 0, 0, (void*)0, 0, 0};

    return tk;
}
