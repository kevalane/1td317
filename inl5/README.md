# Task 5 - Classes

This task is also divided into two parts, a and bL

### Part A

1. Implement a class named Text
2. With attr:
- Text string to be analyzed
- Array with histogram of type int[]
- Number of letters in histogram
3. With functions:
- Text() std. constructor
- void setText(cont string &text)
- bool calcHistogramAbs(), calc histo. Return true if there's letters in histogram, else false
- void printHistogramAbs() prints histogram

### Part B

1. Work on same class as in (a)
2. Add attribut array with relative freq histogram
3. Add methods
- void absToRel() from relative to abs
- void plotHistogramRel() plot the histogram as in inl4
- void calcHistogram() should call calcHistogramAbs() and absToRel(). Relative should only be calculated if calcHistoAbs returns true
- string interpret() method that returns the string the text is written in

## Test report 06/18/2022
