from setuptools import setup, Extension
import sys


ext = Extension(
    "libzosinotify",
    sources=["zos_inotify_impl.c",
             "zos_inotify_exports.c",
             ])

setup(name="asyncinotify-zos",
      ext_modules=[ext],
      )
