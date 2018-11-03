import os
import requests
from tqdm import tqdm
import zipfile
from subprocess import call

_name     = 'SDL2'
_version  = '2.0.6'
_ext      = '.zip'
_dlsource = 'https://www.libsdl.org/release'
_url      = "{}/{}-{}{}".format(_dlsource, _name, _version, _ext)
_file     = _name+_ext
_folder   = "{}-{}".format(_name, _version)

_lib_name = ['libSDL2', 'libSDL2main']
_lib_ext  = '.a'
_libs     = [ x+_lib_ext for x in _lib_name]

# download and save to glfw.zip
print("Downloading file from {}".format(_url))
response = requests.get(_url, stream=True)
with open(_file, 'wb') as handle:
    for data in tqdm(response.iter_content()):
        handle.write(data)

# unzip the file
with zipfile.ZipFile(_file, 'r') as zip:
    zip.extractall('.')


# build
os.chdir(_folder)
os.makedirs("build", exist_ok=True)
os.chdir("build")
call(['cmake',
    '-DCMAKE_BUILD_TYPE=Release',
    '..',
    '-DSDL_STATIC=ON',
    '-DSDL_SHARED=OFF'])
call('make')

for lib in _libs:
    call(['cp', lib, '../../'])









