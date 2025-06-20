#include <iostream>
#include <htslib/sam.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " input.bam" << std::endl;
        return 1;
    }

    const char* bam_file = argv[1];
    samFile* in = sam_open(bam_file, "r");
    if (in == NULL) {
        std::cerr << "Failed to open BAM file." << std::endl;
        return 1;
    }

    bam_hdr_t* header = sam_hdr_read(in);
    bam1_t* aln = bam_init1();

    while (sam_read1(in, header, aln) >= 0) {
        std::cout << "Read: " << bam_get_qname(aln) << std::endl;
        std::cout << "CIGAR: ";
        uint32_t* cigar = bam_get_cigar(aln);
        for (uint32_t i = 0; i < aln->core.n_cigar; ++i) {
            std::cout << bam_cigar_oplen(cigar[i])
                      << bam_cigar_opchr(cigar[i]);
        }
        std::cout << std::endl;
    }

    bam_destroy1(aln);
    bam_hdr_destroy(header);
    sam_close(in);

    return 0;
}
