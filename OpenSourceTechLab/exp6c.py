# working with files and directories
# display files available in current directory

import os

files_and_dirs = []

with os.scandir(".") as entries:
    for entry in entries:
        files_and_dirs.append(entry.name)

files_and_dirs = sorted(files_and_dirs)

print("Files and directories in current directory are:")
for x in files_and_dirs:
    print(x)
