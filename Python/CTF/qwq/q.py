import os
import zipfile


def unzip(path, zfile):
    file_path = path + os.sep + zfile
    desdir = path + os.sep + zfile[:zfile.index('.zip')]
    srcfile = zipfile.ZipFile(file_path)
    for filename in srcfile.namelist():
        srcfile.extract(filename, desdir)
        if filename.endswith('.zip'):
            # if zipfile.is_zipfile(filename):
            path = desdir
            zfile = filename
            unzip(path, zfile)


path = r'C:\Users\Parsifal\Desktop\a'
zfile = r'1.zip'
unzip(path, zfile)
