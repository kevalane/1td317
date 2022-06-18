#include <string>
#include "constants.h"

# ifndef __Text__
# define __Text__

class Text {
private:
    std::string text;
    int abs_histogram[ANTAL_BOKSTAVER];
    int letter_count;
public:
    Text();
    void setText(const std::string &text);
    bool calcHistogramAbs();
    void printHistogramAbs();
};

# endif