import os
import requests
from tqdm import tqdm
from subprocess import call

_name     = 'lua'
_version  = '5.3.4'
_ext      = '.tar.gz'
_dlsource = 'http://www.lua.org/ftp'
_url      = "{}/{}-{}{}".format(_dlsource, _name, _version, _ext)
_file     = _name+_ext
_folder   = "{}-{}".format(_name, _version)

_lib_name = ['liblua']
_lib_ext  = '.a'
_libs     = [ x+_lib_ext for x in _lib_name]

# download and save to glfw.zip
print("Downloading file from {}".format(_url))
response = requests.get(_url, stream=True)
with open(_file, 'wb') as handle:
    for data in tqdm(response.iter_content()):
        handle.write(data)

# unzip the file
call(['tar', '-xvf', _file])


# build
os.chdir(_folder)
call(['make', 'linux'])

for lib in _libs:
    call(['cp', 'src/' + lib, '../'])









