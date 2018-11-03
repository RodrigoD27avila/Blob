#include <stdio.h>
#include <stdlib.h>

const char *nums[] = {
"A", "B", "C", "D", "E", "F", "G", "H", "a", "b", "c", "d", "e", "f", "g", "h", "AA", "BB", "CC", "DD", "EE", "FF", "GG", "HH", "aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "AAA", "BBB", "CCC", "DDD", "EEE", "FFF", "GGG", "HHH", "aaa", "bbb", "ccc", "ddd", "eee", "fff", "ggg", "hhh", "AAAA", "BBBB", "CCCC", "DDDD", "EEEE", "FFFF", "GGGG", "HHHH", "aaaa", "bbbb", "cccc", "dddd", "eeee", "ffff", "gggg", "hhhh", "AAAAA", "BBBBB", "CCCCC", "DDDDD", "EEEEE", "FFFFF", "GGGGG", "HHHHH", "aaaaa", "bbbbb", "ccccc", "ddddd", "eeeee", "fffff", "ggggg", "hhhhh", "AAAAAA", "BBBBBB", "CCCCCC", "DDDDDD", "EEEEEE", "FFFFFF", "GGGGGG", "HHHHHH", "aaaaaa", "bbbbbb", "cccccc", "dddddd", "eeeeee", "ffffff", "gggggg", "hhhhhh", "AAAAAAA", "BBBBBBB", "CCCCCCC", "DDDDDDD", "EEEEEEE", "FFFFFFF", "GGGGGGG", "HHHHHHH", "aaaaaaa", "bbbbbbb", "ccccccc", "ddddddd", "eeeeeee", "fffffff", "ggggggg", "hhhhhhh", "AAAAAAAA", "BBBBBBBB", "CCCCCCCC", "DDDDDDDD", "EEEEEEEE", "FFFFFFFF", "GGGGGGGG", "HHHHHHHH", "aaaaaaaa", "bbbbbbbb", "cccccccc", "dddddddd", "eeeeeeee", "ffffffff", "gggggggg", "hhhhhhhh", "AAAAAAAAA", "BBBBBBBBB", "CCCCCCCCC", "DDDDDDDDD", "EEEEEEEEE", "FFFFFFFFF", "GGGGGGGGG", "HHHHHHHHH", "aaaaaaaaa", "bbbbbbbbb", "ccccccccc", "ddddddddd", "eeeeeeeee", "fffffffff", "ggggggggg", "hhhhhhhhh", "AAAAAAAAAA", "BBBBBBBBBB", "CCCCCCCCCC", "DDDDDDDDDD", "EEEEEEEEEE", "FFFFFFFFFF", "GGGGGGGGGG", "HHHHHHHHHH", "aaaaaaaaaa", "bbbbbbbbbb", "cccccccccc", "dddddddddd", "eeeeeeeeee", "ffffffffff", "gggggggggg", "hhhhhhhhhh", "AAAAAAAAAAA", "BBBBBBBBBBB", "CCCCCCCCCCC", "DDDDDDDDDDD", "EEEEEEEEEEE", "FFFFFFFFFFF", "GGGGGGGGGGG", "HHHHHHHHHHH", "aaaaaaaaaaa", "bbbbbbbbbbb", "ccccccccccc", "ddddddddddd", "eeeeeeeeeee", "fffffffffff", "ggggggggggg", "hhhhhhhhhhh", "AAAAAAAAAAAA", "BBBBBBBBBBBB", "CCCCCCCCCCCC", "DDDDDDDDDDDD", "EEEEEEEEEEEE", "FFFFFFFFFFFF", "GGGGGGGGGGGG", "HHHHHHHHHHHH", "aaaaaaaaaaaa", "bbbbbbbbbbbb", "cccccccccccc", "dddddddddddd", "eeeeeeeeeeee", "ffffffffffff", "gggggggggggg", "hhhhhhhhhhhh", "AAAAAAAAAAAAA", "BBBBBBBBBBBBB", "CCCCCCCCCCCCC", "DDDDDDDDDDDDD", "EEEEEEEEEEEEE", "FFFFFFFFFFFFF", "GGGGGGGGGGGGG", "HHHHHHHHHHHHH", "aaaaaaaaaaaaa", "bbbbbbbbbbbbb", "ccccccccccccc", "ddddddddddddd", "eeeeeeeeeeeee", "fffffffffffff", "ggggggggggggg", "hhhhhhhhhhhhh", "AAAAAAAAAAAAAA", "BBBBBBBBBBBBBB", "CCCCCCCCCCCCCC", "DDDDDDDDDDDDDD", "EEEEEEEEEEEEEE", "FFFFFFFFFFFFFF", "GGGGGGGGGGGGGG", "HHHHHHHHHHHHHH", "aaaaaaaaaaaaaa", "bbbbbbbbbbbbbb", "cccccccccccccc", "dddddddddddddd", "eeeeeeeeeeeeee", "ffffffffffffff", "gggggggggggggg", "hhhhhhhhhhhhhh", "AAAAAAAAAAAAAAA", "BBBBBBBBBBBBBBB", "CCCCCCCCCCCCCCC", "DDDDDDDDDDDDDDD", "EEEEEEEEEEEEEEE", "FFFFFFFFFFFFFFF", "GGGGGGGGGGGGGGG", "HHHHHHHHHHHHHHH", "aaaaaaaaaaaaaaa", "bbbbbbbbbbbbbbb", "ccccccccccccccc", "ddddddddddddddd", "eeeeeeeeeeeeeee", "fffffffffffffff", "ggggggggggggggg", "hhhhhhhhhhhhhhh", "AAAAAAAAAAAAAAAA", "BBBBBBBBBBBBBBBB", "CCCCCCCCCCCCCCCC", "DDDDDDDDDDDDDDDD", "EEEEEEEEEEEEEEEE", "FFFFFFFFFFFFFFFF", "GGGGGGGGGGGGGGGG", "HHHHHHHHHHHHHHHH", "aaaaaaaaaaaaaaaa", "bbbbbbbbbbbbbbbb", "cccccccccccccccc", "dddddddddddddddd", "eeeeeeeeeeeeeeee", "ffffffffffffffff", "gggggggggggggggg", "hhhhhhhhhhhhhhhh"};


int main(int argc, char **argv)
{
    FILE *f_in = fopen(argv[1], "r");
    if (f_in == NULL) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *f_out = fopen(argv[2], "w+");
    if (f_out == NULL) {
        perror(argv[2]);
        exit(EXIT_FAILURE);
    }

    unsigned char c[1];
    while (fread(&c[0], 1, 1, f_in) > 0) {
        int index = (int)c[0];
        int len   = (index/16) + 1;
        fwrite(nums[index], 1, len, f_out);
    }

    fclose(f_in);
    fflush(f_out);
    fclose(f_out);

    return 0;
}
