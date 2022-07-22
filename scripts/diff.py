import os
import sys


def read_all_lines(filename: str):
    with open(filename, "r") as f:
        return set([line for line in f])

def write_lines_to_file(filename: str, lines: set):
    if os.path.exists(filename):
        os.remove(filename)
    with open(filename, "w") as f:
        for line in lines:
            f.write(line)


def main():
    if (len(sys.argv) < 4):
        print("too few parameteres!\n\n")
        print("python scripts/diff.py [what] [from] [diff dump file]\n")
        exit(1)

    what = sys.argv[1]
    from_ = sys.argv[2]
    
    resulting_file = sys.argv[3]
    
    what_lines = read_all_lines(what)
    from_lines = read_all_lines(from_)
    
    diff = from_lines - what_lines
    write_lines_to_file(resulting_file, diff)


if __name__ == "__main__":
    main()
