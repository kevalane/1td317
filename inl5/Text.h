# ifndef __Text__
# define __Text

#include <string>

class Text {
private:
    std::string text;
    int abs_histogram[];
    int letter_count;
public:
    Text();
    void setText(const string &text);
    bool calcHistogramAbs();
    void printHistogramAbs();
}

# endif