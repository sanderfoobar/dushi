__version__ = '2.0.0'

import sys
import glob
from setuptools import setup, find_packages, Extension
if not sys.version_info.major == 3:
    print("!pieton3.6")
    sys.exit(1)

dushi = Extension('dushi',
                  sources=glob.glob("src/*.cpp"),
                  include_dirs=['src'],)

setup(
    name='dushi-py',
    packages=find_packages(),
    version=__version__,
    description='Wholla',
    long_description="Wholla",
    author='xmrdsc',
    include_package_data=True,
    zip_safe=False,
    ext_modules=[dushi],
    classifiers=[
        'Environment :: Console',
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Python :: 3',
    ],
)
