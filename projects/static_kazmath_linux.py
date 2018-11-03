import os
from subprocess import call

_name     = 'kazmath'
_repo     = 'https://github.com/Kazade/kazmath.git'
_folder   = _name

_lib_name = ['libkazmath']
_lib_ext  = '.a'
_libs     = [ x+_lib_ext for x in _lib_name]

# download and save to glfw.zip
call(['git', 'clone', '--depth=1', _repo])


# build
os.chdir(_folder)
os.makedirs("build", exist_ok=True)
os.chdir("build")
call(['cmake',
    '-DCMAKE_BUILD_TYPE=Release',
    '..',
    '-DKAZMATH_BUILD_TESTS=OFF',
    '-DKAZMATH_BUILD_JNI_WRAPPER=OFF',
    '-DKAZMATH_BUILD_GL_UTILS=OFF',
    '-DKAZMATH_BUILD_LUA_WRAPPER=OFF',
    '-DKAZMATH_BUILD_TESTS=OFF',
    '-DKAZMATH_BUILD_TESTS=OFF'])
call('make')

for lib in _libs:
    call(['cp', 'kazmath/'+lib, '../../'])









