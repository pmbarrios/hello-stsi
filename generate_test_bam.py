import pysam

# Create a header (chromosome name, length)
header = {
    'HD': {'VN': '1.0'},
    'SQ': [{'LN': 1000, 'SN': 'chr1'}]
}

# Create new BAM file
with pysam.AlignmentFile("test_generated.bam", "wb", header=header) as outf:
    a = pysam.AlignedSegment()
    a.query_name = "read1"
    a.query_sequence = "AAACCCGGGTTTAAACCC"  # 18 bases total
    a.flag = 0
    a.reference_id = 0
    a.reference_start = 100
    a.mapping_quality = 60
    a.cigar = [(4, 5), (0, 13)]  # 5S13M = total 18 bases
    a.query_qualities = pysam.qualitystring_to_array("FFFFFFFFFFFFFFFFFF")
    outf.write(a)
