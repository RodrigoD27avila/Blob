#include <stdio.h>
#include <speex/speex.h>

#define FRAME_SIZE 160

int main(int argc, char **argv)
{
    char *in_file;
    FILE *fin;
    short in[FRAME_SIZE];
    float input[FRAME_SIZE];
    char cbits[200];
    int nb_bytes;

    void *state;
    SpeexBits bits;
    int i, tmp;

    state = speex_encoder_init(&speex_nb_mode);

    tmp = 8;
    speex_encoder_ctl(state, SPEEX_SET_QUALITY, &tmp);

    in_file = argv[1];
    fin = fopen(in_file, "r");

    speex_bits_init(&bits);

    while (1)
    {
        fread(in, sizeof(short), FRAME_SIZE, fin);
        if (feof(fin))
            break;

        for (i=0; i < FRAME_SIZE; i++)
            input[i] = in[i];

        speex_bits_reset(&bits);
        speex_encode(state, input, &bits);
        nb_bytes = speex_bits_write(&bits, cbits, 200);

        fwrite(&nb_bytes, sizeof(int), 1, stdout);
        fwrite(cbits, 1, nb_bytes, stdout);
    }

    speex_encoder_destroy(state);
    speex_bits_destroy(&bits);
    fclose(fin);
    return 0;
}
