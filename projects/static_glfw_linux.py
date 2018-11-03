import os
import requests
from tqdm import tqdm
import zipfile
from subprocess import call

_name     = 'glfw'
_version  = '3.2.1'
_ext      = '.zip'
_dlsource = 'https://github.com/glfw/glfw/releases/download'
_url      = "{}/{}/{}-{}{}".format(_dlsource, _version, _name, _version, _ext)
_file     = _name+_ext
_folder   = "{}-{}".format(_name, _version)

_lib_name = 'libglfw3'
_lib_ext  = '.a'
_lib      = _lib_name+_lib_ext

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
    '-DGLFW_BUILD_EXAMPLES=OFF',
    '-DGLFW_BUILD_TESTS=OFF',
    '-DGLFW_BUILD_DOCS=OFF',
    '-DGLFW_INSTALL=OFF'])
call('make')
call(['cp', 'src/{}'.format(_lib), '../../'])








