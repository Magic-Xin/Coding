import sys
from pdf2docx import parse

pdf_file = str(sys.argv[1])
docx_file = pdf_file + '.docx'

# convert pdf to docx
parse(pdf_file, docx_file, start=0, end=None)