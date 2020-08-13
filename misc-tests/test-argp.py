import argparse

parser = argparse.ArgumentParser(description="Formats .rtf files for use "
                                 "with ProPresenter6 import function. "
                                 "Or optionally, you can run without arguments"
                                 " and you will be brought to an interactive"
                                 " commandline interface.")

parser.add_argument("-c", "--confirm", action="store_true",
                    help="Skips having to confirm processing on every file")
parser.add_argument("-f", "--files", nargs="*",
                    help="Full file paths of all files "
                    "that you want to process")

args = parser.parse_args()

if args.files is not None:
    for file in args.files:
        print(file)

else:
    print(args.files)
