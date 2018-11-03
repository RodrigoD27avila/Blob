"""Command-line tool for making self-extracting Python file.

Call this program from your command line with one argument:
  (1) the file that you want to pack and compress
  (2) the output will be a file with a pyw ending
The output can run on Windows where Python is installed."""

################################################################################

import sys
import os.path
import bz2
import zlib
import base64

################################################################################

def main():
    "Extract the command-line arguments and run the packer."
    try:
        pack(sys.argv[1])
    except (IndexError, AssertionError):
        print('Usage: {} <filename>'.format(os.path.basename(sys.argv[0])))

def pack(path):
    "Get the source, compress it, and create a packed file."
    data = read_file(path)
    builder, data = optimize(data)
    with open(os.path.splitext(path)[0] + '.pyw', 'w') as file:
        builder(os.path.basename(path), base64.b64encode(data), file)

def read_file(path):
    "Read the entire file content from path in binary mode."
    assert os.path.isfile(path)
    with open(path, 'rb') as file:
        return file.read()

def optimize(data):
    "Compress the data and select the best method to write."
    bz2_data = bz2.compress(data, 9)
    zlib_data = zlib.compress(data, 9)
    sizes = tuple(map(len, (data, bz2_data, zlib_data)))
    smallest = sizes.index(min(sizes))
    if smallest == 1:
        return build_bz2_extractor, bz2_data
    if smallest == 2:
        return build_zlib_extractor, zlib_data
    return build_b64_extractor, data

################################################################################

def build_bz2_extractor(filename, data, file):
    "Write a Python program that uses bz2 data compression."
    print("import base64, bz2, os", file=file)
    print("data =", data, file=file)
    print("with open({!r}, 'wb') as file:".format(filename), file=file)
    print("    file.write(bz2.decompress(base64.b64decode(data)))", file=file)
    print("os.startfile({!r})".format(filename), file=file)

def build_zlib_extractor(filename, data, file):
    "Pack data into a self-extractor with zlib compression."
    print("import base64, zlib, os", file=file)
    print("data =", data, file=file)
    print("with open({!r}, 'wb') as file:".format(filename), file=file)
    print("    file.write(zlib.decompress(base64.b64decode(data)))", file=file)
    print("os.startfile({!r})".format(filename), file=file)

def build_b64_extractor(filename, data, file):
    "Create a Python file that may not utilize compression."
    print("import base64, os", file=file)
    print("data =", data, file=file)
    print("with open({!r}, 'wb') as file:".format(filename), file=file)
    print("    file.write(base64.b64decode(data))", file=file)
    print("os.startfile({!r})".format(filename), file=file)

################################################################################

if __name__ == '__main__':
    main()
