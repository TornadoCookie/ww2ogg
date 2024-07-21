#include "wwriff.h"
#include "cwwriff.h"
#include <cstdlib>

struct WWRiff {
    Wwise_RIFF_Vorbis *cl;
};

extern "C" WWRiff *WWRiff_Create(const char *name, const char *codebooks_name, bool inline_codebooks,
                      bool full_setup, CForcePacketFormat force_packet_format)
{
    WWRiff *ret = (WWRiff *)malloc(sizeof(WWRiff));

    ret->cl = new Wwise_RIFF_Vorbis(std::string(name), std::string(codebooks_name), inline_codebooks, full_setup, ForcePacketFormat(force_packet_format));

    return ret;
}

extern "C" void WWRiff_PrintInfo(WWRiff *wwriff)
{
    wwriff->cl->print_info();
}

extern "C" void WWRiff_GenerateOGG(WWRiff *wwriff, const char *outfilename)
{
    std::ofstream st;

    st.open(outfilename);
    wwriff->cl->generate_ogg(st);

    st.close();
}
